#ifndef MODBUSASCII_H
#define MODBUSASCII_H
#include <stdint.h>
typedef enum ParserMode
{
    WaitSTX = 0,//idle
    WaitAddrH=1,
    WaitAddrL=2,
    WaitFuncCodeH,
    WaitFuncCodeL,
    WaitDataLenH,
    WaitDataLenL,
    DataReciving,
    WaitLRCH,
    WaitLRCL,
    WaitCR,
    WaitLF,
    WaitExceptionH,
    WaitExceptionL,
    WaitRegAddrHH,
    WaitRegAddrHL,
    WaitRegAddrLH,
    WaitRegAddrLL,
}ParserModeT;

typedef struct ParserState{
 ParserModeT Mode;
 int Address; // Slave respond address
 int Function;// Slave respond function
 int ExceptionType;   // Type of errror from slave 0 - no error
 int RegAddress;
 int DataLen;
 char HiLo;
 int DataByteCounter;
 char Data[64];
 int LRC;
 int CalcLRC;
 unsigned int LrcErrors;
 unsigned int SlaveErrorReportCount;
 unsigned int ParserErrors;

}ParserStateT;

struct RespondData{
    int16_t StartRegAddr;
    int16_t RegsLen;
    int16_t RegsValue[27];
};

class ModBusASCII
{
public:
    ModBusASCII();
    ~ModBusASCII();
    int PackReadMultipleRequest(char* buf, unsigned char slave_addr,
                                int start_addr,unsigned char count);
    int PackWriteSingleReg(char* buf, uint8_t slave_addr,
                           uint16_t reg_addr, int16_t data);
    int PackWriteMultipleReg(char* buf, unsigned char slave_addr,
                             int reg_addr,const int *data,int count);
    int PackDiagnostickMsg(char* buf, unsigned char slave_addr);

    void ParseBuffer(char* buf, int count);

    RespondData RD;
private:
    char digt_to_ascii_hex(unsigned char digt);
    void char_to_ascii_hex(unsigned char value, char * result);
    void int_to_ascii_hex(short int value,char * result);
    unsigned char ascii_hex_to_char(unsigned char hex);
    ParserStateT PS;

};



#endif // MODBUSASCII_H
