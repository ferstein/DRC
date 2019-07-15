/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *TabRaw;
    QPushButton *pushButtonInhibit;
    QPushButton *pushButtonRun;
    QSlider *SliderRailSpeed;
    QSlider *SliderFocusSPSpeed_2;
    QPushButton *pushButtonAlclr;
    QPushButton *pushButtonReverse;
    QLCDNumber *lcdRawSpeed;
    QLCDNumber *lcdRawDistance;
    QWidget *tab;
    QSlider *SliderStopDistance;
    QLCDNumber *lcdStopDistance;
    QPushButton *pushButtonEs2Set;
    QPushButton *pushButtonEs1Set;
    QPushButton *pushButtonEsDisable;
    QPushButton *pushButtonEsEnable;
    QLCDNumber *lcdRaw2;
    QLCDNumber *lcdRaw1;
    QLCDNumber *lcdRaw4;
    QLCDNumber *lcdRaw3;
    QWidget *tab_2;
    QPushButton *pushButtonApplicationExit;
    QLabel *labelInhibit;
    QLabel *labelRev;
    QLabel *labelES2;
    QLabel *labelES1;
    QLabel *labelRun;
    QLabel *labelConnected;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setCursor(QCursor(Qt::BlankCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::BlankCursor));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(110, 70, 160, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(5, 30, 790, 425));
        tabWidget->setMinimumSize(QSize(790, 425));
        tabWidget->setMaximumSize(QSize(790, 425));
        QFont font;
        font.setPointSize(17);
        tabWidget->setFont(font);
        tabWidget->setCursor(QCursor(Qt::BlankCursor));
        tabWidget->setIconSize(QSize(16, 16));
        TabRaw = new QWidget();
        TabRaw->setObjectName(QStringLiteral("TabRaw"));
        pushButtonInhibit = new QPushButton(TabRaw);
        pushButtonInhibit->setObjectName(QStringLiteral("pushButtonInhibit"));
        pushButtonInhibit->setGeometry(QRect(590, 290, 181, 61));
        pushButtonRun = new QPushButton(TabRaw);
        pushButtonRun->setObjectName(QStringLiteral("pushButtonRun"));
        pushButtonRun->setGeometry(QRect(400, 290, 181, 61));
        SliderRailSpeed = new QSlider(TabRaw);
        SliderRailSpeed->setObjectName(QStringLiteral("SliderRailSpeed"));
        SliderRailSpeed->setGeometry(QRect(10, 120, 771, 60));
        SliderRailSpeed->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 40px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 50px;\n"
"    margin: -5px 0 ; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        SliderRailSpeed->setMaximum(100);
        SliderRailSpeed->setValue(20);
        SliderRailSpeed->setOrientation(Qt::Horizontal);
        SliderFocusSPSpeed_2 = new QSlider(TabRaw);
        SliderFocusSPSpeed_2->setObjectName(QStringLiteral("SliderFocusSPSpeed_2"));
        SliderFocusSPSpeed_2->setGeometry(QRect(10, 210, 771, 60));
        SliderFocusSPSpeed_2->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 40px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 50px;\n"
"    margin: -5px 0 ; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        SliderFocusSPSpeed_2->setMinimum(50);
        SliderFocusSPSpeed_2->setMaximum(99);
        SliderFocusSPSpeed_2->setPageStep(5);
        SliderFocusSPSpeed_2->setValue(90);
        SliderFocusSPSpeed_2->setOrientation(Qt::Horizontal);
        pushButtonAlclr = new QPushButton(TabRaw);
        pushButtonAlclr->setObjectName(QStringLiteral("pushButtonAlclr"));
        pushButtonAlclr->setGeometry(QRect(210, 290, 181, 61));
        pushButtonReverse = new QPushButton(TabRaw);
        pushButtonReverse->setObjectName(QStringLiteral("pushButtonReverse"));
        pushButtonReverse->setGeometry(QRect(20, 290, 181, 61));
        lcdRawSpeed = new QLCDNumber(TabRaw);
        lcdRawSpeed->setObjectName(QStringLiteral("lcdRawSpeed"));
        lcdRawSpeed->setGeometry(QRect(280, 10, 111, 61));
        lcdRawDistance = new QLCDNumber(TabRaw);
        lcdRawDistance->setObjectName(QStringLiteral("lcdRawDistance"));
        lcdRawDistance->setGeometry(QRect(400, 10, 111, 61));
        tabWidget->addTab(TabRaw, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        SliderStopDistance = new QSlider(tab);
        SliderStopDistance->setObjectName(QStringLiteral("SliderStopDistance"));
        SliderStopDistance->setGeometry(QRect(10, 290, 621, 60));
        SliderStopDistance->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 40px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 50px;\n"
"    margin: -5px 0 ; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        SliderStopDistance->setMinimum(50);
        SliderStopDistance->setMaximum(300);
        SliderStopDistance->setPageStep(5);
        SliderStopDistance->setValue(200);
        SliderStopDistance->setOrientation(Qt::Horizontal);
        lcdStopDistance = new QLCDNumber(tab);
        lcdStopDistance->setObjectName(QStringLiteral("lcdStopDistance"));
        lcdStopDistance->setGeometry(QRect(650, 290, 121, 61));
        pushButtonEs2Set = new QPushButton(tab);
        pushButtonEs2Set->setObjectName(QStringLiteral("pushButtonEs2Set"));
        pushButtonEs2Set->setGeometry(QRect(620, 150, 161, 61));
        pushButtonEs1Set = new QPushButton(tab);
        pushButtonEs1Set->setObjectName(QStringLiteral("pushButtonEs1Set"));
        pushButtonEs1Set->setGeometry(QRect(10, 150, 161, 61));
        pushButtonEsDisable = new QPushButton(tab);
        pushButtonEsDisable->setObjectName(QStringLiteral("pushButtonEsDisable"));
        pushButtonEsDisable->setGeometry(QRect(220, 150, 161, 61));
        pushButtonEsEnable = new QPushButton(tab);
        pushButtonEsEnable->setObjectName(QStringLiteral("pushButtonEsEnable"));
        pushButtonEsEnable->setGeometry(QRect(410, 150, 161, 61));
        lcdRaw2 = new QLCDNumber(tab);
        lcdRaw2->setObjectName(QStringLiteral("lcdRaw2"));
        lcdRaw2->setGeometry(QRect(660, 10, 121, 61));
        lcdRaw1 = new QLCDNumber(tab);
        lcdRaw1->setObjectName(QStringLiteral("lcdRaw1"));
        lcdRaw1->setGeometry(QRect(10, 10, 121, 61));
        lcdRaw4 = new QLCDNumber(tab);
        lcdRaw4->setObjectName(QStringLiteral("lcdRaw4"));
        lcdRaw4->setGeometry(QRect(270, 10, 111, 61));
        lcdRaw3 = new QLCDNumber(tab);
        lcdRaw3->setObjectName(QStringLiteral("lcdRaw3"));
        lcdRaw3->setGeometry(QRect(410, 10, 111, 61));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButtonApplicationExit = new QPushButton(tab_2);
        pushButtonApplicationExit->setObjectName(QStringLiteral("pushButtonApplicationExit"));
        pushButtonApplicationExit->setGeometry(QRect(590, 320, 181, 51));
        tabWidget->addTab(tab_2, QString());
        labelInhibit = new QLabel(centralWidget);
        labelInhibit->setObjectName(QStringLiteral("labelInhibit"));
        labelInhibit->setGeometry(QRect(740, 10, 51, 25));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelInhibit->setFont(font1);
        labelInhibit->setFrameShape(QFrame::Panel);
        labelInhibit->setAlignment(Qt::AlignCenter);
        labelRev = new QLabel(centralWidget);
        labelRev->setObjectName(QStringLiteral("labelRev"));
        labelRev->setGeometry(QRect(680, 10, 51, 25));
        labelRev->setFont(font1);
        labelRev->setFrameShape(QFrame::Panel);
        labelRev->setAlignment(Qt::AlignCenter);
        labelES2 = new QLabel(centralWidget);
        labelES2->setObjectName(QStringLiteral("labelES2"));
        labelES2->setGeometry(QRect(620, 10, 51, 25));
        labelES2->setFont(font1);
        labelES2->setFrameShape(QFrame::Panel);
        labelES2->setAlignment(Qt::AlignCenter);
        labelES1 = new QLabel(centralWidget);
        labelES1->setObjectName(QStringLiteral("labelES1"));
        labelES1->setGeometry(QRect(560, 10, 51, 25));
        labelES1->setFont(font1);
        labelES1->setFrameShape(QFrame::Panel);
        labelES1->setAlignment(Qt::AlignCenter);
        labelRun = new QLabel(centralWidget);
        labelRun->setObjectName(QStringLiteral("labelRun"));
        labelRun->setGeometry(QRect(500, 10, 51, 25));
        labelRun->setFont(font1);
        labelRun->setFrameShape(QFrame::Panel);
        labelRun->setAlignment(Qt::AlignCenter);
        labelConnected = new QLabel(centralWidget);
        labelConnected->setObjectName(QStringLiteral("labelConnected"));
        labelConnected->setGeometry(QRect(440, 10, 51, 25));
        labelConnected->setFont(font1);
        labelConnected->setFrameShape(QFrame::Panel);
        labelConnected->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButtonInhibit->setText(QApplication::translate("MainWindow", "INHIBIT", Q_NULLPTR));
        pushButtonRun->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        pushButtonAlclr->setText(QApplication::translate("MainWindow", "ALCLR", Q_NULLPTR));
        pushButtonReverse->setText(QApplication::translate("MainWindow", "REVERSE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(TabRaw), QApplication::translate("MainWindow", "CONTROL", Q_NULLPTR));
        pushButtonEs2Set->setText(QApplication::translate("MainWindow", "ES 2 SET", Q_NULLPTR));
        pushButtonEs1Set->setText(QApplication::translate("MainWindow", "ES 1 SET", Q_NULLPTR));
        pushButtonEsDisable->setText(QApplication::translate("MainWindow", "ES DISABLE", Q_NULLPTR));
        pushButtonEsEnable->setText(QApplication::translate("MainWindow", "ES ENABLE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ADJUST ES", Q_NULLPTR));
        pushButtonApplicationExit->setText(QApplication::translate("MainWindow", "APP EXIT", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "MISC", Q_NULLPTR));
        labelInhibit->setText(QApplication::translate("MainWindow", "INH", Q_NULLPTR));
        labelRev->setText(QApplication::translate("MainWindow", "REV", Q_NULLPTR));
        labelES2->setText(QApplication::translate("MainWindow", "ES2", Q_NULLPTR));
        labelES1->setText(QApplication::translate("MainWindow", "ES1", Q_NULLPTR));
        labelRun->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        labelConnected->setText(QApplication::translate("MainWindow", "CON", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
