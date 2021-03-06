#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QErrorMessage>
#include <QValidator>
#include <QInputDialog>
#include <QComboBox>

// Konstruktor für GUI Hauptmenü
mainMenu::mainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainMenu), difficulty(1){
    gameWindowPtr = nullptr;
    ui->setupUi(this);
    ui->difficultySelection->setCurrentIndex(1);
    // setting relative paths for standard levels
    lvl1_path = "../PacmanProject/txt_maps/level1.txt";
    lvl2_path = "../PacmanProject/txt_maps/level2.txt";
    lvl3_path = "../PacmanProject/txt_maps/level3.txt";

    // connections for main menu buttons
    connect(ui->playLevel1,             SIGNAL(clicked()),                  this,                SLOT(slotStartLevel1()));
    connect(ui->playLevel2,             SIGNAL(clicked()),                  this,                SLOT(slotStartLevel2()));
    connect(ui->playLevel3,             SIGNAL(clicked()),                  this,                SLOT(slotStartLevel3()));
    connect(ui->playCustomLevel,        SIGNAL(clicked()),                  this,                SLOT(slotStartCustomLevel()));
    connect(ui->quitButton,             SIGNAL(clicked()),                  this,                SLOT(close()));
    connect(ui->difficultySelection,    SIGNAL(currentIndexChanged(int)),   this,                SLOT(slotSetDifficulty(int)));

    // setting up tool tips
    ui->playLevel1->setToolTip("Start Level 1!");
    ui->playLevel2->setToolTip("Start Level 2!");
    ui->playLevel3->setToolTip("Start Level 3!");
    ui->difficultySelection->setToolTip("Select the Level of Difficulty");
    ui->playCustomLevel->setToolTip("Play a custom Level at the specified Path!");
    ui->customLevelPathInput->setToolTip(("Enter the path to a matching txt File to play custom Levels!"));
    ui->quitButton->setToolTip("Quit Pacman");
}

// Dekonstruktor für Hauptmenü
mainMenu::~mainMenu(){
    delete ui;
    if (gameWindowPtr != nullptr)
        delete gameWindowPtr;
}

// die vier folgenden Slots werden genutzt um Level 1 bis sowie ein custom Level zu starten
void mainMenu::slotStartLevel1() {
    gameWindowPtr = new gameWindow(lvl1_path, difficulty);
    gameWindowPtr->show();
}

void mainMenu::slotStartLevel2() {
    gameWindowPtr = new gameWindow(lvl2_path, difficulty);
    gameWindowPtr->show();
}

void mainMenu::slotStartLevel3() {
    gameWindowPtr = new gameWindow(lvl3_path, difficulty);
    gameWindowPtr->show();
}

void mainMenu::slotStartCustomLevel() {
    QString strPath = ui->customLevelPathInput->toPlainText();
    // catch empty input strings
    if (strPath == "") {
        QErrorMessage *qEM = new QErrorMessage(this);
        qEM->showMessage("The File Path must not not be empty!");
        return;
    }
    // catch wrong format
    int ind = strPath.size()-1;
    if ((!(strPath[ind] == 't')) && (!(strPath[ind-1] == 'x')) && (!(strPath[ind-2] == 't'))) {
        QErrorMessage *qEM = new QErrorMessage(this);
        qEM->showMessage("Only .txt Files are possible!!");
        return;
    }
    // get number of lines for custom map file
    int _numLines= QInputDialog::getInt(this, "Specifications", "Please enter how many lines your custom Map has: ",28,1,42);
    gameWindowPtr = new gameWindow(strPath.toStdString(),difficulty, _numLines);
    gameWindowPtr->show();
}

// Setzt den Wert aus DropDown Menü als gewählte Schwierigkeit
void mainMenu::slotSetDifficulty(int) {
    this->difficulty = ui->difficultySelection->currentIndex();
}
