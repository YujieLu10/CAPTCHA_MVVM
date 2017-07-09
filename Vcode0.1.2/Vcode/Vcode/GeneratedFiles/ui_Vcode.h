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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewClass
{
public:
    QAction *importPicAction;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QTextBrowser *result;
    QPushButton *recognizeButton;
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
        ViewClass->resize(600, 400);
        importPicAction = new QAction(ViewClass);
        importPicAction->setObjectName(QStringLiteral("importPicAction"));
        centralWidget = new QWidget(ViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(170, 40, 256, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 310, 72, 15));
        result = new QTextBrowser(centralWidget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(230, 300, 211, 31));
        recognizeButton = new QPushButton(centralWidget);
        recognizeButton->setObjectName(QStringLiteral("recognizeButton"));
        recognizeButton->setGeometry(QRect(250, 250, 93, 28));
        ViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
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

        retranslateUi(ViewClass);

        QMetaObject::connectSlotsByName(ViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewClass)
    {
        ViewClass->setWindowTitle(QApplication::translate("ViewClass", "App", 0));
        importPicAction->setText(QApplication::translate("ViewClass", "\345\257\274\345\205\245\345\233\276\347\211\207", 0));
        label->setText(QApplication::translate("ViewClass", "\350\257\206\345\210\253\347\273\223\346\236\234", 0));
        recognizeButton->setText(QApplication::translate("ViewClass", "\345\274\200\345\247\213\350\257\206\345\210\253", 0));
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
