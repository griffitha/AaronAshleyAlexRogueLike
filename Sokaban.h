#ifndef SOKABAN_H
#define SOKABAN_H

#include "utility.h"

//Class of interactive objects
class interactiveObject: public character
{
    public:
    interactiveObject(int x, int y):
        character(x,y)
        {

        }
    void setRockAttributes();
};

void basicInteraction(int movement,int x,int y, std::vector<character> &gameObjects,std::vector<enemy> &enemyList,player &thePlayer,char symbolArray[][500]);

bool checkEmptyWithOmission(int x, int y, int omittedPosition, std::vector<character> gameObjects);

bool checkSokabanVictory(std::vector<character> gameObjects, char symbolArray[][500]);
#endif // SOKABAN_H
