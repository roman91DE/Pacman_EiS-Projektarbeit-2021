#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include <string>


class Map {
    private:
        std::vector < std::vector<char> > vec;
    public:
        Map(std::string filepath, unsigned int numLines=28);
        ~Map();
        bool isFree(int xPosition, int yPosition);
        // for debugging only
        void printToStdOut();

    friend class Game;
    friend class gameWindow;
};

#endif // MAP_H
