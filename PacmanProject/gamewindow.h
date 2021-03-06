#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "ConsoleWindow.h"
#include "game.h"
#include <QtMultimedia>

class gameWindow : public ConsoleWindow
{
    private:
        Game *current_game;
        bool running;
        bool xPressed;
        int difficultySelected;
        QMediaPlayer *deathSound;
        QMediaPlayer *winSound;



    public:
        gameWindow(std::string lvl_ptr,int _difficultySelected, unsigned int numLines=28);
        ~gameWindow();
        void onRefresh();
        void drawCurrentState();
        void endGame(QString &str);
        void exitGame();


};

#endif // GAMEWINDOW_H
