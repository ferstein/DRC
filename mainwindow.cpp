#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analogjoystick.h"
#include "tecoservotsta.h"

AnalogJoystick3Axis *Joy;
TecoServoTSTA *Servo;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint
                         |Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->showFullScreen();

    Joy = new AnalogJoystick3Axis;
    Servo = new TecoServoTSTA;

    connect(&this->JoyTimer,SIGNAL(timeout()),this,SLOT(get_joystick_raw_data()));
    this->JoyTimer.start(30);

    connect(&this->ModbusTimer,SIGNAL(timeout()),this,SLOT(ServoProcess()));
    this->ModbusTimer.start(40);

    EndStopsIsEnabled = 0;
    StopDistance = 2.0f;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_joystick_raw_data(void)
{
    Joy->Process();
}

void MainWindow::ServoProcess(void)
{   bool es1 = false, es2 = false;
    const float MetersPerOneRevolution = 44*0.005f;
    float SpeedWithEndStops = 0;
    Rotations = Servo->GetRegMapValue(Un14_MotorFeedBackRotationValue);
    LessThanOneRotation = Servo->GetRegMapValue(Un15_MotorFeedbackLessThanOneRotationPulseValue);
    SpeedRpm = Servo->GetRegMapValue(Sn201_InternalSpeedCommand_1);
    fRotations =  LessThanOneRotation;
    fRotations/=32768.0;
    fRotations+=Rotations;
    PositionMeters = MetersPerOneRevolution *  fRotations;
    float k = 0;
    es1= false;
    es2= false;
    if(EndStopsIsEnabled){
        SpeedWithEndStops = Joy->State.Out[Joy->Rail];

        if((int)SpeedWithEndStops<0){
            if(PositionMeters<=(ES1Value + StopDistance)){
                k=(ES1Value - PositionMeters)/-StopDistance;
                SpeedWithEndStops = SpeedWithEndStops*k;
                es1=true;
            }
        }
        else{
            if(PositionMeters >= (ES2Value - StopDistance)){
                k=(ES2Value - PositionMeters)/StopDistance;
                SpeedWithEndStops = SpeedWithEndStops*k;
                es2=true;
            }
        }

        Servo->Ctrl.JoySpeed=((int)SpeedWithEndStops);
    }

    else {
        Servo->Ctrl.JoySpeed=((int)Joy->State.Out[Joy->Rail]);
    }

    Servo->Process();
    //____________________________________________
    //Redrav section
    //____________________________________________

    ui->lcdRaw4->display(k);
    ui->lcdRawSpeed->display(SpeedRpm);
    ui->lcdRawDistance->display(PositionMeters);
    ui->lcdRaw3->display(PositionMeters);
    ui->lcdRaw1->display(ES1Value);
    ui->lcdRaw2->display(ES2Value);

    //Label inhibit and run
    palette = ui->labelInhibit->palette();
    palette2 = ui->labelRun->palette();
    ui->labelInhibit->setAutoFillBackground(true);
    ui->labelRun->setAutoFillBackground(true);
    //palette.setColor(ui->pLabel->foregroundRole(), Qt::yellow);
    if(Servo->GetRegMapValue(Hn519_DigitalInputStatusControlInCommunicationMode)&0x001){
        palette.setColor(ui->labelInhibit->backgroundRole(), Qt::gray);
        palette2.setColor(ui->labelRun->backgroundRole(), Qt::green);
    }
    else {
        palette.setColor(ui->labelInhibit->backgroundRole(), Qt::red);
        palette2.setColor(ui->labelRun->backgroundRole(), Qt::gray);
    }
    ui->labelInhibit->setPalette(palette);
    ui->labelRun->setPalette(palette2);

    //Label ES1
    palette = ui->labelES1->palette();
    ui->labelES1->setAutoFillBackground(true);
    if(es1){
        palette.setColor(ui->labelES1->backgroundRole(), Qt::red);
    }
    else{
        if(EndStopsIsEnabled){
            palette.setColor(ui->labelES1->backgroundRole(), Qt::green);
        }
        else{
            palette.setColor(ui->labelES1->backgroundRole(), Qt::gray);
        }
    }
    ui->labelES1->setPalette(palette);

    //Label ES2
    palette = ui->labelES2->palette();
    ui->labelES2->setAutoFillBackground(true);
    if(es2){
        palette.setColor(ui->labelES2->backgroundRole(), Qt::red);
    }
    else{
        if(EndStopsIsEnabled){
            palette.setColor(ui->labelES2->backgroundRole(), Qt::green);
        }
        else {
            palette.setColor(ui->labelES2->backgroundRole(), Qt::gray);
        }
    }
    ui->labelES2->setPalette(palette);

    //Label Connected
    palette = ui->labelConnected->palette();
    ui->labelConnected->setAutoFillBackground(true);
    if(Servo->Connected){
        palette.setColor(ui->labelConnected->backgroundRole(), Qt::green);
    }
    else{
        palette.setColor(ui->labelConnected->backgroundRole(), Qt::red);
    }
    ui->labelConnected->setPalette(palette);

}

void MainWindow::on_pushButtonInhibit_pressed()
{
    Servo->SetInhibitMode(0xff);
}

void MainWindow::on_pushButtonRun_pressed()
{
    Servo->SetInhibitMode(0x00);
}
void MainWindow::on_pushButtonAlclr_clicked()
{
    Servo->AlarmClear();
}

void MainWindow::on_SliderRailSpeed_valueChanged(int value)
{
    Joy->State.volume[Joy->Rail]=value;
}

void MainWindow::on_SliderFocusSPSpeed_2_valueChanged(int value)//Fluid
{
    Joy->State.FilterKoef[Joy->Rail]=value;
}

void MainWindow::on_pushButtonEs1Set_clicked(){ES1Value = PositionMeters;}
void MainWindow::on_pushButtonEs2Set_clicked(){ES2Value = PositionMeters;}
void MainWindow::on_pushButtonEsDisable_clicked()
{

    EndStopsIsEnabled=0;
}
void MainWindow::on_pushButtonEsEnable_clicked()
{
    if(ES1Value>ES2Value)
    {
        float value = ES1Value;
        ES1Value = ES2Value;
        ES2Value = value;
    }
    EndStopsIsEnabled=0xff;
}

void MainWindow::on_pushButtonReverse_clicked()
{
    palette = ui->labelRev->palette();
    ui->labelRev->setAutoFillBackground(true);
    if(Joy->State.rev[Joy->Rail]==0){
        Joy->State.rev[Joy->Rail]=0xff;
        palette.setColor(ui->labelRev->backgroundRole(), Qt::green);
    }
    else  {
        Joy->State.rev[Joy->Rail]=0x00;
        palette.setColor(ui->labelRev->backgroundRole(), Qt::gray);
    }
    ui->labelRev->setPalette(palette);
}

void MainWindow::on_SliderStopDistance_valueChanged(int value)
{
    StopDistance = ((float)(value))/100;
    ui->lcdStopDistance->display(StopDistance);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index){
    case 0:{
        ui->SliderRailSpeed->setValue(Joy->State.volume[Joy->Rail]);
        ui->SliderFocusSPSpeed_2->setValue(Joy->State.FilterKoef[Joy->Rail]);
        break;
    }
    case 1:{
        int disp = StopDistance*100;
        ui->lcdStopDistance->display(StopDistance);
        ui->SliderStopDistance->setValue(disp);
    }break;
    }
}

void MainWindow::on_pushButtonApplicationExit_clicked()
{
    QApplication::quit();
}
