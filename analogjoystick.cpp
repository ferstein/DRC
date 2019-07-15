#include "analogjoystick.h"
#include "SimpleGPIO.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
int Inited = 0;
AnalogJoystick3Axis::AnalogJoystick3Axis()
{
    printf("Process Joystick created\n");
    Init();

}
AnalogJoystick3Axis::~AnalogJoystick3Axis()
{

}

void AnalogJoystick3Axis::Init()
{
    //printf("Start of Joystick Init ");
    for(int i=0;i<3;i++)
    {
        State.FilterKoef[i]=90;
        State.center[i]=2048;
        State.deadZone[i]=12;
        State.raw[i]=2048;
        State.Out[i]=0;
        State.volume[i] = 100;
        State.offset[i] = 0;
        State.rev[i]=0;
    }

    Rail = 0;
    F1=1;
    F2=2;
    CalibrateZeros();
    Inited=0xffff;

}

void AnalogJoystick3Axis::Process(void)
{   if(Inited)
    {
        ReadRaw();
        ApplyValueAndOffset();
    }
    else
    {
        Init();
    }
}

void AnalogJoystick3Axis::CalibrateZeros()
{
    //printf("Start of Joystick  calibration");
    int i,j;
    for(i=0;i<3;i++)State.Out[i]=0;
    for(i=0;i<1000;i++)
    {
        ReadRaw();
        for(j=0;j<3;j++)
        {
            State.center[j] = (State.center[j]* 9+State.raw[j])/10;
            //printf("Calibration %i:  %i \n",j,State.center[j]);
        }
    }
//printf("Calibration of Joystick finished");
}
void AnalogJoystick3Axis::ReadRaw()
{
    int raw[3],i;
    //raw[0]=analog_read(AIN4);//LEFT X
    //raw[3]=analog_read(AIN5);//RIGHT X
    //raw[1]=analog_read(AIN3);//LEFT Y

    raw[0]=analog_read(AIN2);//X
    raw[1]=analog_read(AIN0);//Y
    raw[2]=analog_read(AIN1);//Z

    for(i=0;i<3;i++)
    {
        State.raw[i]=(State.raw[i]*State.FilterKoef[i]+raw[i]*(100-State.FilterKoef[i]))/100;//Filter / Fluid
    }
}
void AnalogJoystick3Axis::ApplyValueAndOffset()
{
    int i,v;
    for(i=0;i<3;i++)
    {
        v=State.raw[i]-State.center[i];
        //deadZones
        if(abs(v)<State.deadZone[i])State.Out[i]=0;
        else{
            if(v>0 && v>State.deadZone[i]){
                State.Out[i]=v-State.deadZone[i];}
            if(v<0 && -v>State.deadZone[i]){
                State.Out[i]=v+State.deadZone[i];
            }
        }
        // Volume
        State.Out[i]= State.Out[i]*State.volume[i]/100;
        // Reverses
        if(State.rev[i])State.Out[i]*=-1;
        // Offsets
        State.Out[i]+=State.offset[i];

        //printf("Joystick channel %i: raw %i,  Center %i, Volume %i \n",i,State.raw[i],State.center[i],State.volume[i]);
    }
}
