/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *playLevel1;
    QPushButton *playLevel2;
    QPushButton *playLevel3;
    QLabel *label;
    QPushButton *quitButton;
    QPushButton *playCustomLevel;
    QTextEdit *customLevelPathInput;
    QComboBox *difficultySelection;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->resize(800, 600);
        centralwidget = new QWidget(mainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        playLevel1 = new QPushButton(centralwidget);
        playLevel1->setObjectName(QString::fromUtf8("playLevel1"));
        playLevel1->setGeometry(QRect(30, 190, 151, 51));
        playLevel2 = new QPushButton(centralwidget);
        playLevel2->setObjectName(QString::fromUtf8("playLevel2"));
        playLevel2->setGeometry(QRect(220, 190, 151, 51));
        playLevel3 = new QPushButton(centralwidget);
        playLevel3->setObjectName(QString::fromUtf8("playLevel3"));
        playLevel3->setGeometry(QRect(410, 190, 151, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 50, 471, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(36);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(610, 280, 151, 51));
        playCustomLevel = new QPushButton(centralwidget);
        playCustomLevel->setObjectName(QString::fromUtf8("playCustomLevel"));
        playCustomLevel->setGeometry(QRect(410, 280, 151, 51));
        customLevelPathInput = new QTextEdit(centralwidget);
        customLevelPathInput->setObjectName(QString::fromUtf8("customLevelPathInput"));
        customLevelPathInput->setGeometry(QRect(30, 280, 341, 51));
        difficultySelection = new QComboBox(centralwidget);
        difficultySelection->addItem(QString());
        difficultySelection->addItem(QString());
        difficultySelection->addItem(QString());
        difficultySelection->setObjectName(QString::fromUtf8("difficultySelection"));
        difficultySelection->setGeometry(QRect(610, 190, 151, 51));
        mainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        mainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(mainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainMenu->setStatusBar(statusbar);

        retranslateUi(mainMenu);

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *mainMenu)
    {
        mainMenu->setWindowTitle(QCoreApplication::translate("mainMenu", "mainMenu", nullptr));
        playLevel1->setText(QCoreApplication::translate("mainMenu", "Level 1", nullptr));
        playLevel2->setText(QCoreApplication::translate("mainMenu", "Level 2", nullptr));
        playLevel3->setText(QCoreApplication::translate("mainMenu", "Level 3", nullptr));
        label->setText(QCoreApplication::translate("mainMenu", "Let's Play Pacman!", nullptr));
        quitButton->setText(QCoreApplication::translate("mainMenu", "Quit", nullptr));
        playCustomLevel->setText(QCoreApplication::translate("mainMenu", "Self Made Level", nullptr));
        customLevelPathInput->setHtml(QCoreApplication::translate("mainMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#d69545;\">../PacmanProject/txt_maps/customLevel.txt</span></p></body></html>", nullptr));
        difficultySelection->setItemText(0, QCoreApplication::translate("mainMenu", "n00b", nullptr));
        difficultySelection->setItemText(1, QCoreApplication::translate("mainMenu", "Medium", nullptr));
        difficultySelection->setItemText(2, QCoreApplication::translate("mainMenu", "Hardcore", nullptr));

    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
