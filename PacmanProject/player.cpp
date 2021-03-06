#include "player.h"

// Konstruktor für Pacman
Player::Player(int _xPos, int _yPos)
    : xPosition(_xPos), yPosition(_yPos), representation('*')  {}

Player::~Player() {}

// einfache get Methoden
int Player::getXPosition()          { return xPosition; }
int Player::getYPosition()          { return yPosition; }
char Player::getRepresentation()    { return representation; }

// einfache move Methoden mit denen die Koordinaten von Pacman verändert werden
void Player::moveUp()       { yPosition--; }
void Player::moveDown()     { yPosition++; }
void Player::moveLeft()     { xPosition--; }
void Player::moveRight()    { xPosition++; }



