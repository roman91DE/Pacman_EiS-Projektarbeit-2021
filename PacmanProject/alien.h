#ifndef ALIEN_H
#define ALIEN_H


#include "player.h"
#include "map.h"

// Abstrakte Klasse als Interface
class Alien {
    protected:
        int xPosition;
        int yPosition;
        Map *map;
        char cur_direction;
        int difficultySelected, waitForNRounds, counter;
    public:
        Alien(int _xPos, int _yPos, Map *_map, int _difficultySelected);
        virtual ~Alien();
        virtual char getRepresentation() = 0;
        virtual char getDirection(int xPlayer, int yPlayer) = 0;
        int getXPosition() const;
        int getYPosition() const;
        void move(int xPlayer, int yPlayer);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
   friend class Map;
};

// Aus der Aufgabenstellung ist mir nicht ganz klar geworden,
// ob die dummen Aliens ebenfalls halb so schnell wie Pacman
// laufen sollen? Ich habe es so implementiert, dass beide Arten
// von Gegnern mit der gleichen Geschwindigkeit laufen
// (...primär damit ich Level 3 schaffe...)
class stupidAlien : public Alien {
    private:
        char representation;
    public:
        stupidAlien(int _xPos, int _yPos, Map *_map, int _difficultySelected);
        virtual ~stupidAlien();
        virtual char getDirection(int xPlayer, int yPlayer) ;
        virtual char getRepresentation() ;
};


class smartAlien : public Alien {
    private:
        char representation;
    public:
        smartAlien(int _xPos, int _yPos, Map *_map, int _difficultySelected);
        ~smartAlien();
        virtual char getDirection(int xPlayer, int yPlayer);
        virtual char getRepresentation();
        static double getDistance(int x_player, int y_player, int x_alien, int y_alien);
};

// hilfsklasse um Züge für smarte Aliens zu bestimmen
struct container {
    double distance;
    char direction;
    container(double _distance, char _direction);
};

// Funktion um vector von containern aufsteigend nach ihrer Distanz zu sortieren
void bubbleSortContainerVector(std::vector <container> &distances);

#endif // ALIEN_H
