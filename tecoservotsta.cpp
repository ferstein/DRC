#include "tecoservotsta.h"
#include "serialport.h"
#include "modbusascii.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

ModBusASCII * ModBus = new ModBusASCII;

TecoServoTSTA::TecoServoTSTA()
{
    SerialFD = serialport::init("/dev/ttyO2",Baud115200);
    TransmitionStep = 0;
    inlen=0;
    outlen=0;
}

TecoServoTSTA::~TecoServoTSTA()
{
    SetInhibitMode(0xff);
}
int TecoServoTSTA::GetRegMapValue(int RegAddr){
    if(RegAddr<=0x028 && RegAddr>0x000){return(Regs.Cn[RegAddr-0x001]);}
    if(RegAddr<=0x108 && RegAddr>0x100){return(Regs.Tn[RegAddr-0x101]);}
    if(RegAddr<=0x212 && RegAddr>0x200){return(Regs.Sn[RegAddr-0x201]);}
    if(RegAddr<=0x345 && RegAddr>0x300){return(Regs.Pn[RegAddr-0x301]);}
    if(RegAddr<=0x407 && RegAddr>0x400){return(Regs.Qn[RegAddr-0x401]);}
    if(RegAddr<=0x513 && RegAddr>0x500){return(Regs.Hn[RegAddr-0x501]);}
    if(RegAddr<=0x613 && RegAddr>0x600){return(Regs.Un[RegAddr-0x601]);}
    
    return 0;
}

int TecoServoTSTA::UpdateRegMap(int StartRegAddr,int datalen){
    if(StartRegAddr<=0x028 && StartRegAddr>0x000){
        memcpy(&Regs.Cn[StartRegAddr-0x001],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x108 && StartRegAddr>0x100){
        memcpy(&Regs.Tn[StartRegAddr-0x101],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x212 && StartRegAddr>0x200){
        memcpy(&Regs.Sn[StartRegAddr-0x201],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x345 && StartRegAddr>0x300){
        memcpy(&Regs.Pn[StartRegAddr-0x301],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x407 && StartRegAddr>0x400){
        memcpy(&Regs.Qn[StartRegAddr-0x401],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x513 && StartRegAddr>0x500){
        memcpy(&Regs.Hn[StartRegAddr-0x501],ModBus->RD.RegsValue,datalen);}
    if(StartRegAddr<=0x613 && StartRegAddr>0x600){
        memcpy(&Regs.Un[StartRegAddr-0x601],ModBus->RD.RegsValue,datalen);}
    return 0;
}
int TecoServoTSTA::SetInhibitMode(int isInhibited)
{
    TransmitionSubStep=0;
    DriveIsInhibited=isInhibited;
    TransmitionStep=300;
    return 0;
}

int TecoServoTSTA::AlarmClear(void)
{
    TransmitionSubStep=0;
    TransmitionStep=400;
    return 0;
}

int TecoServoTSTA::Process(void)
{
    inlen=read(SerialFD,inbuf,sizeof(inbuf));
    if(inlen>0)
        ModBus->ParseBuffer(inbuf,inlen);

    if(ModBus->RD.RegsLen>0){
        UpdateRegMap(ModBus->RD.StartRegAddr,ModBus->RD.RegsLen);
        ModBus->RD.RegsLen=0;
        ConnectionDowncounter=30;
        Connected = true;
    }
    if(ConnectionDowncounter==0)Connected = false;

    switch (TransmitionStep) {
    case 1:
        outlen = ModBus->PackWriteSingleReg(outbuf,1,Sn201_InternalSpeedCommand_1,Ctrl.JoySpeed);
        break;
    case 2:{
        outlen = ModBus->PackReadMultipleRequest(outbuf,1,Un14_MotorFeedBackRotationValue,2);
       TransmitionStep=0;
    }
        break;
    case 300: { //Setup inhibit mode on/off
        switch (TransmitionSubStep) {
        case 0:{
            if(DriveIsInhibited){
                outlen = ModBus->PackWriteSingleReg(outbuf,1,
                     Hn519_DigitalInputStatusControlInCommunicationMode,0x200);}
            else {outlen = ModBus->PackWriteSingleReg(outbuf,1,
                     Hn519_DigitalInputStatusControlInCommunicationMode,0x201);}
            TransmitionSubStep = 1;
        }
            break;
        case 1:{
            outlen = ModBus->PackReadMultipleRequest(outbuf,1,Hn519_DigitalInputStatusControlInCommunicationMode,1);
            TransmitionSubStep = 2;
        }
            break;
        case 2:{
            outlen = ModBus->PackReadMultipleRequest(outbuf,1,Hn519_DigitalInputStatusControlInCommunicationMode,1);
            TransmitionStep=0;
        }break;
        default:
            TransmitionStep=0;
            break;
        }

    }
        break;
    case 400 :{ //Alarm clear mode
        switch (TransmitionSubStep) {
        case 0:{
            outlen = ModBus->PackWriteSingleReg(outbuf,1,
                  Hn519_DigitalInputStatusControlInCommunicationMode,0x200);
            TransmitionSubStep = 1;
        }
            break;
        case 1:{
            outlen = ModBus->PackWriteSingleReg(outbuf,1,
                  Hn519_DigitalInputStatusControlInCommunicationMode,0x202);
                TransmitionSubStep = 2;
        }
            break;
        case 2:{
            outlen = ModBus->PackWriteSingleReg(outbuf,1,
                  Hn519_DigitalInputStatusControlInCommunicationMode,0x201);
            TransmitionSubStep = 3;
        }break;
        case 3:{
            outlen = ModBus->PackReadMultipleRequest(outbuf,1,Hn519_DigitalInputStatusControlInCommunicationMode,1);
            TransmitionStep=0;
        }
        default:
            TransmitionStep=0;
            break;
        }

    }
        break;
    default:TransmitionStep=0;
        break;
    }

    write(SerialFD,outbuf,outlen);
    if(TransmitionStep<299)TransmitionStep++;
    if(ConnectionDowncounter>0)ConnectionDowncounter--;

    return 0;
}


