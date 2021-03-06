#ifndef PLAYER_H
#define PLAYER_H


class Player{
    private:
        int xPosition;
        int yPosition;
        char representation;
    public:
        Player(int _xPos, int _yPos);
        ~Player();
        int getXPosition();
        int getYPosition();
        char getRepresentation();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

};

#endif // PLAYER_H
