#include "modbusascii.h"
#include <stdint.h>
#include <string.h>

enum FunctionCodes:unsigned char
{
    READ_N_REGS = 0x03,
    WRITE_SINGLE_REG = 0x06,
    DIAGNOSTIC_FUNCTION = 0x08,
    WRITE_MULTIPLE_REGS = 0x10,
    ERROR_MASK = 0x80,

};
enum ExceptionCodes {
    IllegalFunction = 1, 	    //Function code received in the query is not recognized or allowed by slave
    IllegalDataAddress =2,	    //Data address of some or all the required entities are not allowed or do not exist in slave
    IllegalDataValue = 3,  	    //Value is not accepted by slave
    SlaveDeviceFailure = 4,	    //Unrecoverable error occurred while slave was attempting to perform requested action
    Acknowledge = 5,            //Slave has accepted request and is processing it, but a long duration of time is required.
    //This response is returned to prevent a timeout error from occurring in the master.
    //Master can next issue a Poll Program Complete message to determine whether processing is completed
    SlaveDeviceBusy = 6,        //Slave is engaged in processing a long-duration command. Master should retry later
    NegativeAcknowledge = 7,    //Slave cannot perform the programming functions. Master should request diagnostic or error information from slave
    MemoryParityError = 8,      //Slave detected a parity error in memory. Master can retry the request, but service may be required on the slave device
    GatewayPathUnavailable = 10,//Specialized for Modbus gateways. Indicates a misconfigured gateway
    GatewayTargetDeviceFailedToRespond =11,//Specialized for Modbus gateways. Sent when slave fails to respond
};



ModBusASCII::ModBusASCII()
{
    PS.Mode=WaitSTX;
    PS.ParserErrors=0;
    PS.SlaveErrorReportCount=0;
    PS.DataByteCounter=0;
    PS.LrcErrors=0;
}
ModBusASCII::~ModBusASCII()
{

}
char ModBusASCII::digt_to_ascii_hex(unsigned char digt)
{
    switch(digt&0x0f){
    case 0:return('0');break;
    case 1:return('1');break;
    case 2:return('2');break;
    case 3:return('3');break;
    case 4:return('4');break;
    case 5:return('5');break;
    case 6:return('6');break;
    case 7:return('7');break;
    case 8:return('8');break;
    case 9:return('9');break;
    case 10:return('A');break;
    case 11:return('B');break;
    case 12:return('C');break;
    case 13:return('D');break;
    case 14:return('E');break;
    case 15:return('F');break;
    default:return(0);            //unpossible case !
    }
}
unsigned char ModBusASCII::ascii_hex_to_char(unsigned char hex)
{
    switch(hex)
    {
    case'0':return 0x00;break;
    case'1':return 0x01;break;
    case'2':return 0x02;break;
    case'3':return 0x03;break;
    case'4':return 0x04;break;
    case'5':return 0x05;break;
    case'6':return 0x06;break;
    case'7':return 0x07;break;
    case'8':return 0x08;break;
    case'9':return 0x09;break;
    case'A':return 0x0A;break;
    case'B':return 0x0B;break;
    case'C':return 0x0C;break;
    case'D':return 0x0D;break;
    case'E':return 0x0E;break;
    case'F':return 0x0F;break;

    default:return 0xF0;break;//error
    }
}

void ModBusASCII::char_to_ascii_hex(unsigned char value,char * result)
{
    unsigned char value1 = value&0x0f;
    unsigned char value2 = value>>4;
    result[0]=digt_to_ascii_hex(value2);
    result[1]=digt_to_ascii_hex(value1);
}
void ModBusASCII::int_to_ascii_hex(short int value,char * result)
{
    char_to_ascii_hex(value&0xff,&result[2]);
    char_to_ascii_hex(value>>8,&result[0]);
}


int ModBusASCII::PackReadMultipleRequest(char* buf, unsigned char slave_addr,
                                         int reg_addr,unsigned char count)
{
    PS.RegAddress = reg_addr;

    if(slave_addr>247)return (-1); //bed address
    if(count>29)return(-2);//maximum count of registers for reading is 29 for TSTA servodriver
    if(reg_addr<0)return(-3);
    int lrc =-(slave_addr+READ_N_REGS+(reg_addr>>8)+(reg_addr&0xff)+(count>>8)+(count&0xff));
    buf[0]=':';
    char_to_ascii_hex(slave_addr,&buf[1]);
    char_to_ascii_hex(READ_N_REGS,&buf[3]);
    int_to_ascii_hex (reg_addr,&buf[5]);
    int_to_ascii_hex (count,&buf[9]);
    char_to_ascii_hex (lrc&0xff,&buf[13]);
    buf[15]=0x0D;buf[16]=0x0A;
    return 17;
}


int ModBusASCII::PackWriteSingleReg(char* buf, uint8_t slave_addr,
                                    uint16_t reg_addr, int16_t data)
{
    if(slave_addr>247)return (-1); //bed address
    uint16_t lrc =(slave_addr+WRITE_SINGLE_REG+
               (reg_addr>>8)+(reg_addr&0xff)+
               (data>>8)+(data&0xff));

    buf[0]=':';
    char_to_ascii_hex(slave_addr,&buf[1]);
    char_to_ascii_hex(WRITE_SINGLE_REG,&buf[3]);
    int_to_ascii_hex (reg_addr,&buf[5]);
    int_to_ascii_hex (data,&buf[9]);
    char_to_ascii_hex (-lrc,&buf[13]);
    buf[15]=0x0D;
    buf[16]=0x0A;
    return 17;
}

int ModBusASCII::PackWriteMultipleReg(char* buf, unsigned char slave_addr,
                                      int reg_addr,const int *data,int count)
{
    int i;
    if(slave_addr>247)return (-1); //bed address
    if(count<0 || count>27)return(-2);//maximum count of registers for writing is 27 for TSTA servodriver
    if(reg_addr<0)return(-3);
    int lrc =slave_addr+WRITE_MULTIPLE_REGS+(reg_addr>>8)+(reg_addr&0xff);
    buf[0]=':';
    char_to_ascii_hex(slave_addr,&buf[1]);
    char_to_ascii_hex(WRITE_MULTIPLE_REGS,&buf[3]);
    int_to_ascii_hex (reg_addr,&buf[5]);
    for(i = 0;i<count;i++)
    {
        lrc+=(data[i]&0x00ff)+((data[i]&0xff00)>>8);
        int_to_ascii_hex (data[i],&buf[i+9]);
    }
    lrc=-lrc;
    char_to_ascii_hex (lrc&0xff,&buf[i+13]);
    buf[i+15]='\r';buf[i+16]='\n';
    return i+17;
}

int ModBusASCII::PackDiagnostickMsg(char* buf, unsigned char slave_addr)
{
    if(slave_addr>247)return (-1); //bed address
    int lrc =-(slave_addr+DIAGNOSTIC_FUNCTION+0xA5+0x37);
    buf[0]=':';
    char_to_ascii_hex(slave_addr,&buf[1]);
    char_to_ascii_hex(DIAGNOSTIC_FUNCTION,&buf[3]);
    int_to_ascii_hex (0,&buf[5]);
    int_to_ascii_hex (0xA537,&buf[9]);
    char_to_ascii_hex (lrc&0xff,&buf[13]);
    buf[15]='\r';buf[16]='\n';
    return 17;
}

//MODBUS parser +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ModBusASCII::ParseBuffer(char* buf, int count)
{
    unsigned char tmp;
    int i;
    for(i=0;i<count;i++)
    {
        //Synchronisation ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if(buf[i]==':'){
            if(PS.Mode!=WaitSTX){PS.ParserErrors++;}
            PS.Mode=WaitSTX;
        }

        //Bed charster detection++++++++++++++++++++++++++++++++++++++++++++++++++++
        switch (buf[i]){
        case ':':break;
        case '\r':break;
        case '\n':break;
        default :
            tmp=ascii_hex_to_char(buf[i]);
            if(tmp > 0x0f){
                PS.Mode=WaitSTX;
                PS.ParserErrors++;
            }
            break;
        }

        //Parsing ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        switch(PS.Mode){
        case WaitSTX:
            if(buf[i]==':'){PS.Mode = WaitAddrH;}
            else {
                PS.ParserErrors++;
            }
            PS.CalcLRC=0;
            break;
        case WaitAddrH:
            PS.Address = tmp<<4;
            PS.Mode = WaitAddrL;
            break;
        case WaitAddrL:
            PS.Address+=tmp;
            PS.CalcLRC+=PS.Address;
            PS.Mode=WaitFuncCodeH;
            break;
        case WaitFuncCodeH:
            PS.Function = tmp<<4;
            PS.Mode = WaitFuncCodeL;
            break;
        case WaitFuncCodeL:
            PS.Function+=tmp;
            PS.CalcLRC+=PS.Function;
            if((PS.Function&ERROR_MASK)!=0)
            {
                //Modbus slave error
                PS.Mode=WaitExceptionH;
            }
            else
            {
                if(PS.Function==READ_N_REGS){
                    PS.Mode = WaitDataLenH;
                }
                else {
                    PS.Mode= WaitRegAddrHH;
                }
            }
            break;
        case WaitRegAddrHH:
            PS.RegAddress = tmp<<12;
            PS.Mode=WaitRegAddrHL;
            break;
        case WaitRegAddrHL:
            PS.RegAddress += tmp<<8;
            PS.CalcLRC+=PS.RegAddress>>8;
            PS.Mode=WaitRegAddrLH;
            break;
        case WaitRegAddrLH:
            PS.RegAddress+=tmp<<4;
            PS.Mode=WaitRegAddrLL;
            break;
        case WaitRegAddrLL:
            PS.RegAddress+=tmp;
            PS.CalcLRC+=(PS.RegAddress&0xff);
            PS.DataLen=2;
            PS.DataByteCounter=0;
            PS.Mode=DataReciving;
            break;
        case WaitDataLenH:
            PS.DataLen=tmp<<4;
            PS.Mode=WaitDataLenL;
            break;
        case WaitDataLenL:
            PS.DataLen+=tmp;
            PS.CalcLRC+=PS.DataLen;
            PS.Mode=DataReciving;
            PS.DataByteCounter=0;
            PS.HiLo = 0;
            break;
        case DataReciving:
            if(PS.HiLo==0){
                PS.Data[PS.DataByteCounter]=tmp<<4;
                PS.HiLo=1;
            }
            else {
                PS.Data[PS.DataByteCounter]+=tmp;
                PS.CalcLRC+=PS.Data[PS.DataByteCounter];
                PS.HiLo=0;
                PS.DataByteCounter++;
            }
            if(PS.DataByteCounter==PS.DataLen)
            {
                PS.Mode=WaitLRCH;
            }
            break;
            //IF error code recived-------------
        case WaitExceptionH:
            PS.ExceptionType=tmp<<4;
            PS.Mode=WaitExceptionL;
            break;
        case WaitExceptionL:
            PS.ExceptionType+=tmp;
            PS.CalcLRC+=PS.ExceptionType;
            PS.Mode=WaitLRCH;
            break;
            //FI error code recived-------------
        case WaitLRCH:
            PS.LRC=tmp<<4;
            PS.Mode=WaitLRCL;
            break;
        case WaitLRCL:
            PS.LRC+=tmp;
            PS.Mode = WaitCR;
            break;
        case WaitCR:
            if(buf[i]=='\r' || buf[i]=='\n')
            {
                PS.Mode=WaitLF;
            }
            else
            {
                PS.ParserErrors++;
                PS.Mode = WaitSTX;
            }
            break;
        case WaitLF:
            if(buf[i]=='\n')
            {
                PS.CalcLRC=(0-(PS.CalcLRC&0xff))&0xff;
                if(PS.LRC!=PS.CalcLRC)
                {
                    PS.LrcErrors++;
                }
                else
                {
                    switch(PS.Function)//Calling to callback functions
                    {
                    case READ_N_REGS: // = 0x03,
                        RD.StartRegAddr=PS.RegAddress;
                        RD.RegsLen=PS.DataLen;
                        for(int i =0;i<RD.RegsLen;){     //copy with changing endian
                            char * p =(char*) RD.RegsValue;
                            p[i] = PS.Data[i+1];
                            p[i+1] = PS.Data[i];
                            i+=2;
                        }
                        break;
                    case WRITE_SINGLE_REG:// = 0x06,
                    {
                        RD.StartRegAddr=PS.RegAddress;
                        RD.RegsLen=PS.DataLen;
                        char * p =(char*) RD.RegsValue;
                        p[0] = PS.Data[1];
                        p[1] = PS.Data[0];
                    }
                        break;
                    case WRITE_MULTIPLE_REGS:// = 0x10,

                        break;
                    default :
                        if(PS.Function&ERROR_MASK)// = 0x80,
                        {

                        }
                        break;
                    }
                }
            }
            else
            {
                PS.ParserErrors++;
            }
            PS.Mode = WaitSTX;
            break;
        }
    }
}
