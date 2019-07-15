#ifndef TECOSERVOTSTA_H
#define TECOSERVOTSTA_H
#include<stdint.h>
enum AddressTable:uint16_t
{
    /*7-2 Communication address table
    /All parameters allow to write data by communication excluding display parameters.

    /ParameterName_of_parameter = Address RS485 */

//System parameters+++++++++++++++++++++++++++++++++++++++++++
    Cn001_ControlMode                                =0x0001,
    Cn002_DIContactsAndAutoTunning                   =0x0002,
    Cn003_OutputTimeMechanicalBrake                  =0x0003,
    Cn004_MotorRotationdirection                     =0x0004,
    Cn005_Encoderpulseoutputscale                    =0x0005,
    Cn006_AnalogMonitorOutputSelection               =0x0006,
    Cn007_ValueSpeedReached                          =0x0007,
    Cn008_BrakeModes                                 =0x0008,
    Cn009_CW_CCW_Inhibit                             =0x0009,
    Cn010_CCW_TorqueCommandLimit                     =0x000A,
    Cn011_CW_TorqueCommandLimit                      =0x000B,
    Cn012_PowerExternalRegenerationResistor          =0x000C,
    Cn013_FrequencyNotchFilter                       =0x000D,
    Cn014_BandWidthNotchFilter                       =0x000E,
    Cn015_GainSelection                              =0x000F,
    Cn016_PI_P_SwitchModeTorque                      =0x0010,
    Cn017_PI_P_SwitchModeSpeed                       =0x0011,
    Cn018_SwitchConditionPI_P_ModeAaccelerateCommand =0x0012,
    Cn019_PI_P_SwitchModePositionError               =0x0013,
    Cn020_AutomaticGainSwitchDelayTime               =0x0014,
    Cn021_AutomaticGainSwitchConditionTorque         =0x0015,
    Cn022_AutomaticGainSwitchConditionSpeed          =0x0016,
    Cn023_AutomaticGainSwitchConditionAcceleration   =0x0017,
    Cn024_AutomaticGainSwitchConditionPositionError  =0x0018,
    Cn025_LoadInertiaRatio                           =0x0019,
    Cn026_RigiditySetting                            =0x001A,
    Cn027_AnalogMonitorOutput_1_Offset               =0x001B,
    Cn028_AnalogMonitorOutput_2_Offset               =0x001C,
    Cn029_ResetParameter                             =0x001D,
    Cn030_ServoMotorModelCode                        =0x001E,
    Cn031_CoolingFanRunningMode                      =0x001F,
    Cn032_SpeedFeedbackSmoothingFfilter              =0x0020,
    Cn033_SpeedFeedorwardSmoothingFilter             =0x0021,
    Cn034_TorqueCommandSmoothingFilter               =0x0022,
    Cn035_PanelDisplayContentSelection               =0x0023,
    Cn036_ServoIDnumber                              =0x0024,
    Cn037_BraudrateSetting                           =0x0025,
    Cn038_CommunicationProtocol                      =0x0026,
    Cn039_CommunicationTimeoutDectionTime            =0x0027,
    Cn040_CommunicationResponseDelayTime             =0x0028,
//Torque control parameters++++++++++++++++++++++++++++++++++++
    Tn101_LinearAccelerationDecelerationMethod       =0x0101,//1 - Enable,0 - Disable
    Tn102_LinearAccelerationDecelerationTimePeriod   =0x0102,//msec, 1~50000 |Torque command accelleration/deceleration time,is the time taken for the torque to rise from zero to the required level by Tn102.
    Tn103_AnalogTorqueCommandRatio                   =0x0103,//%/10V, 0~300  |Analog torque command ratio
    Tn104_AnalogTorqueCommandOffset                  =0x0104,//mV , range is -10000~10000
    Tn105_InternalSpeedLimit_1                       =0x0105,
    Tn106_InternalSpeedLimit_2                       =0x0106,
    Tn107_InternalSpeedLimit_3                       =0x0107,
    Tn108_TorqueOutputMonitorValue                   =0x0108,
//Speed control parameters+++++++++++++++++++++++++++++++++++++
    Sn201_InternalSpeedCommand_1                     =0x0201,
    Sn202_InternalSpeedCommand_2                     =0x0202,
    Sn203_InternalSpeedCommand_3                     =0x0203,
    Sn204_ZeroSpeedPresetSelection                   =0x0204,
    Sn205_SpeedCommandAcceleration_DecelerationMethods=0x0205,
    Sn206_SpeedCommandSmoothAccelerationDecelerationTime=0x0206,
    Sn207_SpeedCommandLinearAccelerationDecelerationTime=0x0207,
    Sn208_ScurveSpeedCommandAccelerationDecelerationTime=0x0208,
    Sn209_ScurveSpeedCommandAccelerationTime         =0x0209,
    Sn210_ScurveSpeedCommandDecelerationTime         =0x020A,
    Sn211_SpeedLoopGain_1                            =0x020B,
    Sn212_SpeedLoopIntegralTime_1                    =0x020C,
    Sn213_SpeedLoopGain_2                            =0x020D,
    Sn214_SpeedLoopIntegralTime_2                    =0x020E,
    Sn215_ValueOfZeroSpeed                           =0x020F,
    Sn216_AnalogSpeedCommandRatio                    =0x0210,
    Sn217_AnalogSpeedCommandOffset                   =0x0211,
    Sn218_AnalogSpeedCommandLimit                    =0x0212,
//Position control parameters++++++++++++++++++++++++++++++++++
    Pn301_PositionCommandSelection                   =0x0301,//for pulse type、logic and drive inhizibit
    Pn302_ElectronicGearRatioNumerator_1             =0x0302,
    Pn303_ElectronicGearRatioNumerator_2             =0x0303,
    Pn304_ElectronicGearRatioNumerator_3             =0x0304,
    Pn305_ElectronicGearRatioNumerator_4             =0x0305,
    Pn306_ElectronicGearRatioDenominator             =0x0306,
    Pn307_PositionCompleteValue                      =0x0307,
    Pn308_PositionErrorBandUpperLimit                =0x0308,
    Pn309_PositionErrorBandLowerLimit                =0x0309,
    Pn310_PositionLoopGain_1                         =0x030A,
    Pn311_PositionLoopGain_2                         =0x030B,
    Pn312_PositionLoopFeedForwardGain                =0x030C,
    Pn313_PositionCommandSmoothAccelDecelTime        =0x030D,
    Pn314_PositionCommandDirectionDefinition         =0x030E,
    Pn315_PositionPulseErrorClearMode                =0x030F,
    Pn316_InternalPositionCommandMode                =0x0310,
    Pn317_InternalPositionCommand_1_RotationNumber   =0x0311,
    Pn318_InternalPositionCommand_1_PulseNumber      =0x0312,
    Pn319_InternalPositionCommand_1_MoveSpeed        =0x0313,
    Pn320_InternalPositionCommand_2_RotationNnumber  =0x0314,
    Pn321_InternalPositionCommand_2_PulseNumber      =0x0315,
    Pn322_InternalPositionCommand_2_MoveSpeed        =0x0316,
    Pn323_InternalPositionCommand_3_RotatioNumber    =0x0317,
    Pn324_InternalPositionCommand_3_PulseNumber      =0x0318,
    Pn325_InternalPositionCommand_3_MovingSpeed      =0x0319,
    Pn326_InternalPositionCommand_4_RotationNumber   =0x031A,
    Pn327_InternalPositionCommand_4_PulseNumber      =0x031B,
    Pn328_InternalPositionCommand_4_MoveSpeed        =0x031C,
    Pn329_InternalPositionCommand_5_RotationNumber   =0x031D,
    Pn330_InternalPositionCommand_5_PulseNumber      =0x031E,
    Pn331_InternalPositionCommand_5_MoveSpeed        =0x031F,
    Pn332_InternalPositionCommand_6_RotationNumber   =0x0320,
    Pn333_InternalPositionCommand_6_PulseNumber      =0x0321,
    Pn334_InternalPositionCommand_6_MoveSpeed        =0x0322,
    Pn335_InternalPositionCommand_7_RotationNumber   =0x0323,
    Pn336_InternalPositionCommand_7_PulseNumber      =0x0324,
    Pn337_InternalPositionCommand_7_MoveSpeed        =0x0325,
    Pn338_InternalPositionCommand_8_RotationNumber   =0x0326,
    Pn339_InternalPositionCommand_8_PulseNumber      =0x0327,
    Pn340_InternalPositionCommand_8_MoveSpeed        =0x0328,
    Pn341_InternalPositionCommand_9_RotationNumber   =0x0329,
    Pn342_InternalPositionCommand_9_PulseNumber      =0x032A,
    Pn343_InternalPositionCommand_9_MoveSpeed        =0x032B,
    Pn344_InternalPositionCommand_10_RotationNumber  =0x032C,
    Pn345_InternalPositionCommand_10_PulseNumber     =0x032D,
    Pn346_InternalPositionCommand_10_MoveSpeed       =0x032E,
    Pn347_InternalPositionCommand_11_RotationNumber  =0x032F,
    Pn348_InternalPositionCommand_11_PulseNumber     =0x0330,
    Pn349_InternalPositionCommand_11_MoveSpeed       =0x0331,
    Pn350_InternalPositionCommand_12_RotationNumber  =0x0332,
    Pn351_InternalPositionCommand_12_PulseNumber     =0x0333,
    Pn352_InternalPositionCommand_12_MoveSpeed       =0x0334,
    Pn353_InternalPositionCommand_13_RotationNumber  =0x0335,
    Pn354_InternalPositionCommand_13_PulseNumber     =0x0336,
    Pn355_InternalPositionCommand_13_MoveSpeed       =0x0337,
    Pn356_InternalPositionCommand_14_RotationNumber  =0x0338,
    Pn357_InternalPositionCommand_14_PulseNumber     =0x0339,
    Pn358_InternalPositionCommand_14_MoveSpeed       =0x033A,
    Pn359_InternalPositionCommand_15_RotationNumber  =0x033B,
    Pn360_InternalPositionCommand_15_PulseNumber     =0x033C,
    Pn361_InternalPositionCommand_15_MoveSpeed       =0x033D,
    Pn362_InternalPositionCommand_16_RotationNumber  =0x033E,
    Pn363_InternalPositionCommand_16_PulseNumber     =0x033F,
    Pn364_InternalPositionCommand_16_MoveSpeed       =0x0340,
    Pn365_SettingHOMEroutine                         =0x0341,
    Pn366_1stPresetSpeedHOME                         =0x0342,//( high speed )
    Pn367_2ndPresetSpeedHOME                         =0x0343,//( low speed )
    Pn368_HOME_PositionOffset                        =0x0344,//( No of Revolutions )
    Pn369_HOME_BiasPulseValue                        =0x0345,//( No of pulses )
//Qu_ick Setup parameters+++++++++++++++++++++++++++++++++++++++
    qn401_SpeedLoopGain_1                            =0x0401,
    qn402_IntegralTimeConstantSpeedLoop_1            =0x0402,
    qn403_SpeedLoopGain_2                            =0x0403,
    qn404_IntegralTimeConstantForSpeedLoop_2         =0x0404,
    qn405_PositionLoopGain_1                         =0x0405,
    qn406_PositionLoopGain_2                         =0x0406,
    qn407_PositionLoopFeedForwardGain                =0x0407,
//Mu_lti-function programmable contact parameter++++++++++++++++++++++++++++++++++++++++
    Hn501_DI_1_PragrammableDigitalInupt              =0x0501,
    Hn502_DI_2_PragrammableDigitalInupt              =0x0502,
    Hn503_DI_3_PragrammableDigitalInupt              =0x0503,
    Hn504_DI_4_PragrammableDigitalInupt              =0x0504,
    Hn505_DI_5_PragrammableDigitalInupt              =0x0505,
    Hn506_DI_6_PragrammableDigitalInupt              =0x0506,
    Hn507_DI_7_PragrammableDigitalInupt              =0x0507,
    Hn508_DI_8_PragrammableDigitalInupt              =0x0508,
    Hn509_DI_9_PragrammableDigitalInupt              =0x0509,
    Hn510_DI_10_PragrammableDigitalInupt             =0x050A,
    Hn511_DI_11_PragrammableDigitalInupt             =0x050B,
    Hn512_DI_12_PragrammableDigitalInupt             =0x050C,
    Hn513_DI_13_PragrammableDigitalInupt             =0x050D,
    Hn514_DO_1_PragrammableDigitalOutput             =0x050E,
    Hn515_DO_2_PragrammableDigitalOutput             =0x050F,
    Hn516_DO_3_PragrammableDigitalOutput             =0x0510,
    Hn517_DO_4_PragrammableDigitalOutput             =0x0511,
    Hn518_DigitalInputControlMethodSelection         =0x0512,
    Hn519_DigitalInputStatusControlInCommunicationMode=0x0513,
//Display parameters+++++++++++++++++++++++++++++++++++++++++++++++++++
    Un01_ActualMotorSpeed                            =0x0601,//RPM  |Actual Motor Speed is displayed in rpm.
    Un02_ActualMotorTorque                           =0x0602,//%    |Actual motor torque %.It displays the torque as a percentage of the rated torue.
    Un03_RegenerativeLoadRate                        =0x0603,//%    |Regenerative load ratio. Value for the processable regenerative power as 100% .
    Un04_AccumulatedLoadRate                         =0x0604,//%    |Accumulated load ratio % Value for the rated torque as 100%.
    Un05_MaxLoadRate                                 =0x0605,//%    |Max load rate % Max value appeared on accumulated load rate
    Un06_SpeedCommand                                =0x0606,//RPM  |Speed command rpm Speed command is displayed in rpm.
    Un07_PositionErrorValue                          =0x0607,//pulse|Position error counter value pulse Error between position command value and the actual position feedback.
    Un08_PositionFeedbackValue                       =0x0608,//pulse|Position feedback pulse counter pulse The accumulated number of pulses from the motor encoder.
    Un09_ExternalVoltageCommand                      =0x0609,//Volts|External voltage command V External analog voltage command value in volts.
    Un10_VdcBusVoltage                               =0x060A,//Volts|Main circuit Vdc Bus Voltage V DC Bus voltage in Volts.
    Un11_ExternalSppedLimitCommandValue              =0x060B,//RPM  |External speed limit command value rpm Display external speed limit command value in rpm.
    Un12_ExternalCCWTorqueLimitCommandValue          =0x060C,//%    |External CCW Torque limit command value %
    Un13_ExternalCWTorqueLimitCommandValue           =0x060D,//%    |External CW  Torque limit command value %
    Un14_MotorFeedBackRotationValue                  =0x060E,//revolutions|Rotations value (absolute value) revolution. After power on, it displays motor rotation number as an absolute value.
    Un15_MotorFeedbackLessThanOneRotationPulseValue  =0x060F,//pulses     |Pulses value(absolute value) pulse After power on, it displays the pulse number for less than a revolution of the motor as an absolute value.
    Un16_PulseCommandRotationValue                   =0x0610,//revolutions|Rotation value(absolute value) revolutions After power on, it displays pulse command input rotation number in absolute value.
    Un17_PulseCommandPulseValueLessThanOneRotation   =0x0611,//pulses     |Pulse value(absolute value) pulse After power on, it displays pulse command input for less than a rotation.Pulse value is an absolute value.
    Un18_TorqueCommand                               =0x0612,//%    |It displays the torque command as a percentage of the rated torque.Ex: Display. 50.Means current motor torque command is 50% of rated torque.
    Un19_LoadInertiaRatio                            =0x0613,//Load inertia x0.1 When Cn002.2=0(Auto gain adjust disabled), it displays the current
                                                             //preset load inertia ratio from parameter Cn025. When Cn002.2=1(Auto gain adjust enabled), it displays the current estimated load inertia ratio.

};

enum ControlMode:unsigned char //★ Cn001 Control mode selection
{
    TorqueControl = 0,  //To use one analog voltage command signal to control
                        //torque. Please refer to 5-2.
    SpeedControl = 1,   //Input contacts SPD1 and SPD2 can be used to select
                        //4-steps of speed. Please refer to section 5-3-1.
    PositionControl = 2,//(External pulse command)Four separate selectable
                        //pulse command types are possible to control position.
                        //Please refer to section 5-4-1.
    PositionSpeedControl = 3,
                        //3 Input contact MDC can be used to switch between
                        //position & speed control. Please refer to section 5-6-2.
    SpeedTorqueControl = 4,
                        //Input contact MDC can be used to switch between speed
                        //& torque control. Please refer to section 5-6-2.
    PositionTorqueControl = 5,
                        //Input contact MDC can be used to switch between
                        //position & torque control. Please refer to section 5-6-2.
    PositionControlInternal = 6,
                        //Input contacts POS 1~POS 4 can be used to select 16
                        //programmable preset position commands to control
                        //position. Please refer to 5-4-2.
};

struct ServoControl{
    int CurrentSpeed; //RPM
    int JoySpeed;
};
struct TecoRegisterMap{
    int16_t Cn[40];//RS485 addresses is  0x001...0x028 Cn001 - Cn040
    int16_t Tn[8]; //RS485 addresses is  0x101...0x108 Tn101 - Tn108
    int16_t Sn[18];//RS485 addresses is  0x201...0x212 Sn201 - Sn218
    int16_t Pn[69];//RS485 addresses is  0x301...0x345 Pn301 - Pn369
    int16_t Qn[7]; //RS485 addresses is  0x401...0x407 Qn401 - Qn407
    int16_t Hn[19];//RS485 addresses is  0x501...0x513 Hn501 - Hn519
    int16_t Un[19];//RS485 addresses is  0x601...0x613 Un01 - Un19
};

class TecoServoTSTA
{
public:
    TecoServoTSTA();
    ~TecoServoTSTA();
    int Process(void);
    int GetRegMapValue(int RegAddr);
    ServoControl Ctrl;
    int SetInhibitMode(int isInhibited);
    int AlarmClear(void);
    bool Connected;
private:
    int SerialFD;
    int inlen;
    char inbuf[255];
    int outlen;
    char outbuf[255];
    int TransmitionStep;
    int TransmitionSubStep;
    int DriveIsInhibited;
    int ConnectionDowncounter;
    TecoRegisterMap Regs;
    int UpdateRegMap(int StartRegAddr,int datalen);
};

#endif // TECOSERVOTSTA_H
