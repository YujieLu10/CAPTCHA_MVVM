/********************************************************************************
** Form generated from reading UI file 'Vcode.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCODE_H
#define UI_VCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewClass
{
public:
    QAction *importPicAction;
    QAction *action_2;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGraphicsView *leftOriginView;
    QPushButton *recognizeButton;
    QTextBrowser *resultText;
    QLabel *label;
    QGroupBox *groupBox_2;
    QGraphicsView *removeBgView;
    QGraphicsView *denoiseView;
    QGraphicsView *grayView;
    QGraphicsView *binaryzationView;
    QGraphicsView *rightOriginView;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QRadioButton *aveButton;
    QRadioButton *maxbutton;
    QRadioButton *weightAveButton;
    QLabel *label_6;
    QPushButton *confirmButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewClass)
    {
        if (ViewClass->objectName().isEmpty())
            ViewClass->setObjectName(QStringLiteral("ViewClass"));
        ViewClass->resize(1071, 790);
        importPicAction = new QAction(ViewClass);
        importPicAction->setObjectName(QStringLiteral("importPicAction"));
        action_2 = new QAction(ViewClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(ViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 460, 701));
        leftOriginView = new QGraphicsView(groupBox);
        leftOriginView->setObjectName(QStringLiteral("leftOriginView"));
        leftOriginView->setGeometry(QRect(110, 50, 256, 192));
        recognizeButton = new QPushButton(groupBox);
        recognizeButton->setObjectName(QStringLiteral("recognizeButton"));
        recognizeButton->setGeometry(QRect(190, 270, 93, 28));
        recognizeButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        resultText = new QTextBrowser(groupBox);
        resultText->setObjectName(QStringLiteral("resultText"));
        resultText->setGeometry(QRect(110, 450, 261, 201));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 390, 91, 31));
        label->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        label->setFrameShape(QFrame::Box);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 20, 460, 701));
        removeBgView = new QGraphicsView(groupBox_2);
        removeBgView->setObjectName(QStringLiteral("removeBgView"));
        removeBgView->setGeometry(QRect(160, 370, 256, 81));
        denoiseView = new QGraphicsView(groupBox_2);
        denoiseView->setObjectName(QStringLiteral("denoiseView"));
        denoiseView->setGeometry(QRect(160, 480, 256, 81));
        grayView = new QGraphicsView(groupBox_2);
        grayView->setObjectName(QStringLiteral("grayView"));
        grayView->setGeometry(QRect(160, 260, 256, 81));
        binaryzationView = new QGraphicsView(groupBox_2);
        binaryzationView->setObjectName(QStringLiteral("binaryzationView"));
        binaryzationView->setGeometry(QRect(160, 590, 256, 81));
        rightOriginView = new QGraphicsView(groupBox_2);
        rightOriginView->setObjectName(QStringLiteral("rightOriginView"));
        rightOriginView->setGeometry(QRect(160, 41, 256, 171));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(35, 380, 101, 51));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(35, 490, 101, 51));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(35, 600, 101, 51));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(35, 280, 101, 50));
        label_5->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Plain);
        label_5->setLineWidth(1);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(false);
        aveButton = new QRadioButton(groupBox_2);
        aveButton->setObjectName(QStringLiteral("aveButton"));
        aveButton->setGeometry(QRect(30, 120, 115, 19));
        aveButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        maxbutton = new QRadioButton(groupBox_2);
        maxbutton->setObjectName(QStringLiteral("maxbutton"));
        maxbutton->setGeometry(QRect(30, 150, 115, 19));
        maxbutton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        weightAveButton = new QRadioButton(groupBox_2);
        weightAveButton->setObjectName(QStringLiteral("weightAveButton"));
        weightAveButton->setGeometry(QRect(30, 180, 115, 19));
        weightAveButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 50, 81, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\"\357\274\233"));
        confirmButton = new QPushButton(groupBox_2);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(40, 210, 93, 28));
        ViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1071, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        ViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(importPicAction);
        menu->addSeparator();
        menu->addAction(action_2);

        retranslateUi(ViewClass);

        QMetaObject::connectSlotsByName(ViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewClass)
    {
        ViewClass->setWindowTitle(QApplication::translate("ViewClass", "App", 0));
        importPicAction->setText(QApplication::translate("ViewClass", "\345\257\274\345\205\245\345\233\276\347\211\207", 0));
        action_2->setText(QApplication::translate("ViewClass", "\351\200\200\345\207\272", 0));
        groupBox->setTitle(QString());
        recognizeButton->setText(QApplication::translate("ViewClass", "\345\274\200\345\247\213\350\257\206\345\210\253", 0));
        label->setText(QApplication::translate("ViewClass", "\350\257\206\345\210\253\347\273\223\346\236\234", 0));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("ViewClass", "\345\216\273\350\203\214\346\231\257", 0));
        label_3->setText(QApplication::translate("ViewClass", "\345\216\273\345\231\252\347\202\271", 0));
        label_2->setText(QApplication::translate("ViewClass", "\344\272\214\345\200\274\345\214\226", 0));
        label_5->setText(QApplication::translate("ViewClass", "\347\201\260\345\272\246", 0));
        aveButton->setText(QApplication::translate("ViewClass", "\345\271\263\345\235\207\345\200\274\346\263\225", 0));
        maxbutton->setText(QApplication::translate("ViewClass", "\346\234\200\345\244\247\345\200\274\346\263\225", 0));
        weightAveButton->setText(QApplication::translate("ViewClass", "\345\212\240\346\235\203\345\271\263\345\235\207", 0));
        label_6->setText(QApplication::translate("ViewClass", "\347\201\260\345\272\246\346\226\271\345\274\217", 0));
        confirmButton->setText(QApplication::translate("ViewClass", "\347\241\256\345\256\232", 0));
        menu->setTitle(QApplication::translate("ViewClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("ViewClass", "\350\256\276\347\275\256", 0));
        menu_3->setTitle(QApplication::translate("ViewClass", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewClass: public Ui_ViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCODE_H
