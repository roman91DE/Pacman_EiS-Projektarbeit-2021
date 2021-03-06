#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <string>
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainMenu; }
QT_END_NAMESPACE

class mainMenu : public QMainWindow {
Q_OBJECT

    public:
        mainMenu(QWidget *parent = nullptr);
        ~mainMenu();

    private:
        Ui::mainMenu *ui;
        std::string lvl1_path;
        std::string lvl2_path;
        std::string lvl3_path;
        // 0=easy; 1=medium, 2=hardcore
        int difficulty;
        gameWindow* gameWindowPtr;


    public slots:
        void slotStartLevel1();
        void slotStartLevel2();
        void slotStartLevel3();
        void slotStartCustomLevel();
        void slotSetDifficulty(int);


};
#endif // MAINMENU_H
