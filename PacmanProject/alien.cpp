#include "alien.h"
#include "map.h"
#include <cstdlib>
#include <random>
#include <cmath>
#include <iostream>

Alien::Alien(int _xPos, int _yPos, Map *_map, int _difficultySelected)
    : xPosition(_xPos), yPosition(_yPos), map(_map), cur_direction('u'), difficultySelected(_difficultySelected) {
    // set up level of difficulty
    if      (difficultySelected == 0) { waitForNRounds = 4; }   // easy
    else if (difficultySelected == 1) { waitForNRounds = 2; }   // medium
    else                              { waitForNRounds = 1; }   // hardcore
    counter = 0;

}

Alien::~Alien(){};


int Alien::getXPosition()       const { return xPosition; }
int Alien::getYPosition()       const { return yPosition; }

void Alien::move(int xPlayer, int yPlayer) {
    counter++;
    if(counter>=waitForNRounds) { counter = 0; }
    else                        { return; }
    char direction = getDirection(xPlayer, yPlayer);
    if      (direction == 'u') { moveUp(); }
    else if (direction == 'd') { moveDown(); }
    else if (direction == 'l') { moveLeft(); }
    else if (direction == 'r') { moveRight(); }
    // dont move alien
    else if (direction == '!') { return; }

}

void Alien::moveUp()       { yPosition--; }
void Alien::moveDown()     { yPosition++; }
void Alien::moveLeft()     { xPosition--; }
void Alien::moveRight()    { xPosition++; }



// stupid Aliens Subclass

stupidAlien::stupidAlien(int _xPos, int _yPos, Map *_map, int _difficultySelected)
    : Alien(_xPos, _yPos, _map, _difficultySelected), representation('g') {}


stupidAlien::~stupidAlien() {};

char stupidAlien::getRepresentation()  { return representation; }


char stupidAlien::getDirection(int xPlayer, int yPlayer) {
    // if current direction is possible: keep moving in that direction
    if (cur_direction == 'u' && (map->isFree(xPosition, yPosition-1))) { return cur_direction; }
    if (cur_direction == 'd' && (map->isFree(xPosition, yPosition+1))) { return cur_direction; }
    if (cur_direction == 'l' && (map->isFree(xPosition-1, yPosition))) { return cur_direction; }
    if (cur_direction == 'r' && (map->isFree(xPosition+1, yPosition))) { return cur_direction; }
    // zufallsgenerator: 1=hoch; 2=runter; 3=links; 4=rechts
    while (true) {
        int zv = 1+ rand()%4;
        if (zv == 1) {
            if (map->isFree(xPosition, yPosition-1)) {
                cur_direction = 'u';
                return 'u';
            }
        }
        else if (zv == 2) {
            if (map->isFree(xPosition, yPosition+1)) {
                cur_direction = 'd';
                return 'd';
            }
        }
        else if (zv == 3) {
            if (map->isFree(xPosition-1, yPosition)) {
                cur_direction = 'l';
                return 'l';
            }
        }
        else if (zv == 4) {
            if (map->isFree(xPosition+1, yPosition)) {
                cur_direction = 'r';
                return 'r';
            }
        }
    }
}


smartAlien::smartAlien(int _xPos, int _yPos, Map *_map, int _difficultySelected)
    : Alien(_xPos, _yPos, _map, _difficultySelected), representation('G') {}


smartAlien::~smartAlien() {}

char smartAlien::getRepresentation() { return representation; }

double smartAlien::getDistance(int x_player, int y_player, int x_alien, int y_alien) {
    double left    = (x_player-x_alien)*(x_player-x_alien);
    double right   = (y_player-y_alien)*(y_player-y_alien);
    double sum = left+right;
    return (std::sqrt(sum));
}

// hilfscontainer der eine Distanz als double und die dazugehörige Richtung speichert
container::container(double _distance, char _direction)
    : distance(_distance), direction(_direction){}


// Sortiert einen Vektor aus Hilfscontainern aufsteigend nach ihrer Distanz zum Spieler
void bubbleSortContainerVector(std::vector <container> &distances) {
    unsigned int n = distances.size();
    char    tempChar;
    double  tempDouble;
    for (unsigned int i = 0; i < (n-1); i++){
        for (unsigned int j = 0; j < (n-1); j++) {
            if (distances[j].distance > distances[j+1].distance) {
                // swap values
                tempChar = distances[j].direction;
                tempDouble = distances[j].distance;

                distances[j].direction = distances[j+1].direction;
                distances[j].distance = distances[j+1].distance;

                distances[j+1].distance = tempDouble;
                distances[j+1].direction = tempChar;
            }
        }
    }
}

char smartAlien::getDirection(int xPlayer, int yPlayer) {
    // speichert die Distanzen zwischen Alien und Spieler für alle 4 Richtungen in Hilfskonstrukt
    container cUp      = container(getDistance(xPlayer,yPlayer,getXPosition(),getYPosition()-1),'u');
    container cDown    = container(getDistance(xPlayer, yPlayer,getXPosition(),getYPosition()+1),'d');
    container cLeft    = container(getDistance(xPlayer, yPlayer,getXPosition()-1,getYPosition()),'l');
    container cRight   = container(getDistance(xPlayer, yPlayer,getXPosition()+1,getYPosition()),'r');
    std::vector <container> distances = {cUp, cDown, cLeft, cRight};
    // sortiere container Hilfskonstrukte aufsteigend nach distanz
    bubbleSortContainerVector(distances);
    // Durchlaufe startend mit der geringsten Distanz die Container,  ....
    for (unsigned int k = 0; k < distances.size(); k++) {
        int x_alien_temp  = getXPosition();
        int y_alien_temp  = getYPosition();
        char dir = '!';
        if      (distances[k].direction == 'u') { y_alien_temp--; dir = 'u'; }
        else if (distances[k].direction == 'd') { y_alien_temp++; dir = 'd'; }
        else if (distances[k].direction == 'l') { x_alien_temp--; dir = 'l'; }
        else if (distances[k].direction == 'r') { x_alien_temp++; dir = 'r'; }
        // ... die Richtung des ersten Zugs der möglich ist wird an die move() Funktion weitergebenen
        if (map->isFree(x_alien_temp, y_alien_temp) == true)    {
            // Ausnahme: Zwei Richtungen führen zu selben Distanz zu Pacman, in dem Fall bleibe stehen
            if (k<3) {
                if (distances[k].distance == distances[k+1].distance) { dir = '!'; }
            }
            return dir;
        }
    }
    return '!';
}



