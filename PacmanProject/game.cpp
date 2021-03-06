#include "game.h"
#include "player.h"
#include "alien.h"
#include "map.h"


// Erstellt ein Spielobjekt mit der übergebenen .txt. Datei, der gewählten Schwierigkeit (sowie der Anzahl von Zeilen bei custom maps)
Game::Game(std::string filepathMap,int _difficultySelected, unsigned int numLines) : roundCount(0), score(0), total_pill_count(0) {
    map = new Map(filepathMap, numLines);
    char temp;
    for(unsigned int iy = 0; iy < map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < map->vec[iy].size(); ix++) {
            temp = map->vec[iy][ix];
            // spieler erstellen
            if      (temp == '*')   {
                 player = new Player(ix, iy); 
                 map->vec[iy][ix] = ' ';
            }
            // pillen zählen
            else if (temp=='.') { total_pill_count++; }
            // stupid Aliens erstellen
            else if (temp == 'g')   {
                aliens.push_back(new stupidAlien(ix, iy, map, _difficultySelected));
                map->vec[iy][ix] = '.';
                total_pill_count++;
            }
            // smarte Aliens erstellen
             else if (temp == 'G') {
                 aliens.push_back(new smartAlien(ix, iy, map, _difficultySelected));
                 map->vec[iy][ix] = '.';
                 total_pill_count++;
             }
        }
    }
    // sound Generator der beim Aufnehmen von Pillen abspielt
    pillSound = new QMediaPlayer();
    pillSound->setMedia(QUrl("qrc:/new/sounds/wav_sounds/cembalo-3.wav"));
    pillSound->setVolume(10000);
}

// checkt ob alle Pillen auf der Karte von Pacman eingesammelt wurden
bool Game::level_complete() {
    if (score == total_pill_count) { return true; }
    else                           { return false; }
}

// gibt alle untergordneten Ressourcen wieder frei
Game::~Game() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        delete aliens[i];
    }
    delete player;
    delete map;
    delete pillSound;
}

// checkt ob Pacman mit einem Alien kollidiert ist
bool Game::isAlive() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        if ( (aliens[i]->getXPosition() == player->getXPosition()) &&
             (aliens[i]->getYPosition() == player->getYPosition()) )
                { return false; }
    }
    return true;
}

// rundenbasierte Updates für Zähler, PillScore und Soundeffekte
void Game::update() {
    roundCount++;
    if (map->vec[player->getYPosition()][player->getXPosition()] == '.') {
        map->vec[player->getYPosition()][player->getXPosition()] = ' ';
        pillSound->play();
        score++;
    }
}

// Bewegt Pacman, wenn möglich, in die vom User angegebene Richtung
void Game::movePlayer(int userInput) {
    int x = player->getXPosition();
    int y = player->getYPosition();
    if      (userInput == 1) { 
        if (map->isFree(x-1, y)) { player->moveLeft(); }
    }
    else if (userInput == 2) { 
        if (map->isFree(x+1, y)) { player->moveRight(); }
    }
    else if (userInput == 3) { 
        if (map->isFree(x, y-1)) { player->moveUp(); }
    }
    else if (userInput == 4) { 
        if (map->isFree(x, y+1)) { player->moveDown(); }
    }
}

// Bewegt Aliens (ruft die Unterfunktion getDirection() auf um unterschiedliches Verhalten je nach Alien Unterklasse zu erreichen)
void Game::moveAliens(int xPlayer, int yPlayer) {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        aliens[i]->move(xPlayer, yPlayer);
    }
}

