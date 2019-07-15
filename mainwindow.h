#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void get_joystick_raw_data(void);
    void ServoProcess(void);
    void on_pushButtonInhibit_pressed();
    void on_pushButtonRun_pressed();
    void on_SliderRailSpeed_valueChanged(int value);
    void on_SliderFocusSPSpeed_2_valueChanged(int value);

    void on_pushButtonEs1Set_clicked();

    void on_pushButtonEs2Set_clicked();

    void on_pushButtonEsDisable_clicked();

    void on_pushButtonEsEnable_clicked();

    void on_pushButtonAlclr_clicked();

    void on_pushButtonReverse_clicked();

    void on_SliderStopDistance_valueChanged(int value);

    void on_tabWidget_currentChanged(int index);

    void on_pushButtonApplicationExit_clicked();

private:
    Ui::MainWindow *ui;
    QTimer JoyTimer;
    QTimer ModbusTimer;
    QPalette palette;
    QPalette palette2;
    float PositionMeters ;
    float fRotations;
    int Rotations ;
    int LessThanOneRotation;
    int SpeedRpm ;

    float ES1Value;
    float ES2Value;
    float StopDistance;
    int EndStopsIsEnabled;
};

#endif // MAINWINDOW_H
