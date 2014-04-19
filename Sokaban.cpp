#include "utility.h"

void interactiveObject::setRockAttributes()
{
    //Set character representation
    setMapRep('R');
    //In the situation where the player may damage the object
    setHealth(10000000);
    //Armor will act as a unique identifier for the object
    setArmor(9001);
}

//Basic interaction between objects
void basicInteraction(int movement,int x,int y, std::vector<character> &gameObjects,player &thePlayer,char symbolArray[][500])
{
    bool nextSpaceOpen = true;
    int currentObjectNumber = findTarget(x,y,gameObjects);
    character currentObject = gameObjects.at(currentObjectNumber);

    if (currentObject.getMapRep() == 'R')
    {
        if (movement == KEY_UP)
        {
            //Sokaban your way up
            //Checks if this is a valid move
            nextSpaceOpen = checkEmptyWithOmission(x,y-1,currentObjectNumber,gameObjects);
            if ((symbolArray[x][y-1] == ' ' || symbolArray[x][y-1] == 'O') && nextSpaceOpen == true)
            {
                //Moves player and Object then saves change
                thePlayer.moveChar(movement);
                currentObject.moveChar(movement);
                gameObjects.at(currentObjectNumber) = currentObject;
            }
        }
        else if (movement == KEY_DOWN)
        {
            //Sokaban down south!
            //Checks if this is a valid move
            nextSpaceOpen = checkEmptyWithOmission(x,y+1,currentObjectNumber,gameObjects);
            if ((symbolArray[x][y+1] == ' ' || symbolArray[x][y+1] == 'O') && nextSpaceOpen == true)
            {
                //Moves player and Object then saves change
                thePlayer.moveChar(movement);
                currentObject.moveChar(movement);
                gameObjects.at(currentObjectNumber) = currentObject;
            }
        }
        else if (movement == KEY_LEFT)
        {
            //Sokaban to the Left!
            //Checks if this is a valid move
            nextSpaceOpen = checkEmptyWithOmission(x-1,y,currentObjectNumber,gameObjects);
            if ((symbolArray[x-1][y] == ' ' || symbolArray[x-1][y] == 'O') && nextSpaceOpen == true)
            {
                //Moves player and Object then saves change
                thePlayer.moveChar(movement);
                currentObject.moveChar(movement);
                gameObjects.at(currentObjectNumber) = currentObject;
            }
        }
        else if (movement == KEY_RIGHT)
        {
            //Sokaban to the Right!
            //Checks if this is a valid move
            nextSpaceOpen = checkEmptyWithOmission(x+1,y,currentObjectNumber,gameObjects);
            if ((symbolArray[x+1][y] == ' ' || symbolArray[x+1][y] == 'O') && nextSpaceOpen == true)
            {
                //Moves player and Object then saves change
                thePlayer.moveChar(movement);
                currentObject.moveChar(movement);
                gameObjects.at(currentObjectNumber) = currentObject;
            }
        }
    }
}

//Checks to make sure no other units exist with designated values except that value
bool checkEmptyWithOmission(int x, int y, int omittedPosition, std::vector<character> gameObjects)
{
    //Function will go through and see if spot is occupied
    if (gameObjects.size() != 0)
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            //Ignore this value
            if (i != omittedPosition)
            {
                character currentObject = gameObjects.at(i);
                int designatedX = currentObject.getXCoordinate();
                int designatedY = currentObject.getYCoordinate();
                //If X and Y match up
                if (designatedX == x && designatedY == y)
                {
                    return false;
                }
            }
        }
    }
    return true;
}


bool checkSokabanVictory(std::vector<character> gameObjects, char symbolArray[][500])
{
    if (gameObjects.size() != 0)
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            character currentObject = gameObjects.at(i);
            int objectX = currentObject.getXCoordinate();
            int objectY = currentObject.getYCoordinate();
            if (symbolArray[objectX][objectY] != 'O')
            {
                return false;
            }
        }
    }
    //if it gets this far, that means all of the objects met the criteria
    return true;
}
