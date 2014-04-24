#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED
#include "utility.h"
#include "itemh.h"

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
            case 2: createRobot(factor);
                    break;
        }

    }
    void setXpValue(int input);
    int getXpValue();
    private:
    void createGoblin(int factor);
    void createBat(int factor);
    void createRobot(int factor);
    int xpValue;
};

int numOfEnemies(char symbolArray[500][500],std::vector <Location> &possiblePositions);
vector<enemy> spawnEnemies(char symbolArray[500][500],std::vector <Location> &possiblePositions,int enemiesToCreate,player mainChar);
void enemyTurn(char symbolArray[500][500], std::vector<enemy> &enemyList, std::vector<character> gameObjects, player &thePlayer);


#endif // ENEMIES_H_INCLUDED
