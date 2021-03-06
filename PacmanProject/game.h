#ifndef __GAMEHEADER__
#define __GAMEHEADER__

#include <vector>
#include <string>
#include "player.h"
#include "alien.h"
#include "map.h"
#include <QMediaPlayer>

class Game {
    public:
        Player *player;
        Map *map;
        std::vector <Alien*> aliens;
        int roundCount;
        int score;
        int total_pill_count;
        QMediaPlayer *pillSound;
    public:
        Game(std::string filepathMap, int _difficultySelected, unsigned int numLines=28);
        ~Game();
        bool isAlive();
        void update();
        bool level_complete();
        void moveAliens(int xPlayer, int yPlayer);
        // kodierung user input: 1=links; 2=rechts, 3=oben, 4=unten
        void movePlayer(int userInput);

};

#endif
