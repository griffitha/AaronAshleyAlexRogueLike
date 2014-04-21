#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED
#include "utility.h"

class enemy: public character
{
    public:
    enemy(int x, int y, int type, int factor)
    :character(x,y)
    {
        switch(type)
        {
            case 0: createGoblin(factor);
                    break;
            case 1: createBat(factor);
                    break;
            case 2: createCyborg(factor);
                    break;
        }

    }
    private:
    void createGoblin(int factor);
    void createBat(int factor);
    void createCyborg(int factor);
};
int numOfEnemies(char symbolArray[500][500],vector <Location> &possiblePositions);
void spawnEnemies(char symbolArray[500][500],vector <Location> &possiblePositions,int enemiesToCreate,player mainChar);


#endif // ENEMIES_H_INCLUDED
