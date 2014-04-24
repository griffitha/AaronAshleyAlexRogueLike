#include "utility.h"

void enemy::setXpValue(int input)
{
    xpValue=input;
    return;
}
int enemy::getXpValue()
{
    return xpValue;
}
//Health and  Base Damage formulas taken from alpha ver of Desktop Dungeons
void enemy::createGoblin(int factor)
{
    int healthValue=((factor + 3)^2);
    int damageValue=((factor)^2 / 2) + ((5 * factor) / 2);
    int experienceValue=(factor*(factor+1));
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('G');
    setCharacterName("Goblin");
    setBaseDamage(damageValue);
    setArmor(2);
    setAccuracy(70);
    setLevel(factor);
    setXpValue(experienceValue);
}

void enemy::createBat(int factor)
{
    int healthValue= 6*factor;
    int damageValue= 2*factor;
    int experienceValue=(factor*(factor+1));
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('B');
    setCharacterName("Bat");
    setBaseDamage(damageValue);
    setArmor(1);
    setAccuracy(95);
    setLevel(factor);
    setXpValue(experienceValue);
}
void enemy::createRobot(int factor)
{
    int healthValue=((factor + 3)^2);
    int damageValue=(((factor)^2 / 2) + ((5 * factor) / 2))*.5;
    int experienceValue=(factor*(factor+1));
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('C');
    setCharacterName("Robot");
    setBaseDamage(damageValue);
    setArmor(2);
    setAccuracy(80);
    setLevel(factor);
    setXpValue(experienceValue);
}

//modified version of numOfItems created by Ashley
int numOfEnemies(char symbolArray[500][500],std::vector <Location> possiblePositions)
{
    int spaceCounter = possiblePositions.size();
    int enemiesToCreate;
    int enemiesPerSpaces = (rand()%50)+150;
    //1 enemy for every 20 spaces
    enemiesToCreate = spaceCounter/enemiesPerSpaces;
    //This guarantees at least 1 enemy to spawn in a given room
    if(enemiesToCreate==0)
    {
        enemiesToCreate++;
    }

    return enemiesToCreate;
}

vector<enemy> spawnEnemies(char symbolArray[500][500],std::vector <Location> &possiblePositions,int enemiesToCreate,player mainChar)
{
    vector<enemy> enemyList;
    for(int i=0;i<=enemiesToCreate;i++)
    {
      //determine enemy type
    const int TYPES_OF_ENEMIES=3;
    int enemyType=rand()%TYPES_OF_ENEMIES;
    //determine enemy location
    int enemyLocation=rand()%possiblePositions.size();
    Location spawnLocation=possiblePositions[enemyLocation];
    int enemyX=spawnLocation.getX();
    int enemyY=spawnLocation.getY();
    //determine enemy level
    //int enemyLevel=rand()%mainChar.getLevel();
    int enemyLevel=mainChar.getLevel();
    //spawn enemy
    enemy currentEnemy(enemyX,enemyY,enemyType,enemyLevel);
    enemyList.push_back(currentEnemy);
    }
    return enemyList;
}

void enemyTurn(char symbolArray[500][500], std::vector<enemy> &enemyList, std::vector<character> gameObjects, player &thePlayer)
{
    character * playerPointer = &thePlayer;
    //We will not make all the enemies have a turn
    for (unsigned int i = 0; i < enemyList.size(); i++)
    {
        character * currentEnemy = &enemyList.at(i);
        int playerX = thePlayer.getXCoordinate();
        int playerY = thePlayer.getYCoordinate();
        int enemyX = currentEnemy -> getXCoordinate();
        int enemyY = currentEnemy -> getYCoordinate();
        bool turnMade = false;

        //Check around the player, needs to be revamped to include other things.
        if (((enemyX == playerX+1) || (enemyX == playerX-1) || (enemyX == playerX)) &&
            ((enemyY == playerY+1) || (enemyY == playerY-1) || (enemyY == playerY)))
        {
            meleeAttack(currentEnemy,playerPointer,enemyList);
        }
        else
        {
            while (turnMade == false)
            {
                //Random Movement protocol
                int randomNumber = rand() % 4;
                int movement;
                switch(randomNumber)
                {
                    case 0:
                        movement = KEY_UP;
                        if (checkEmpty(enemyX,enemyY-1,gameObjects,enemyList) == true)
                        {
                            if (symbolArray[enemyX][enemyY-1] != '#')
                            {
                                currentEnemy -> moveChar(movement);
                                turnMade = true;
                            }
                        }
                        break;
                    case 1:
                        movement = KEY_DOWN;
                        if (checkEmpty(enemyX,enemyY+1,gameObjects,enemyList) == true)
                        {
                            if (symbolArray[enemyX][enemyY+1] != '#')
                            {
                                currentEnemy -> moveChar(movement);
                                turnMade = true;
                            }
                        }
                        break;
                    case 2:
                        movement = KEY_LEFT;
                        if (checkEmpty(enemyX-1,enemyY,gameObjects,enemyList) == true)
                        {
                            if (symbolArray[enemyX-1][enemyY] != '#')
                            {
                                currentEnemy -> moveChar(movement);
                                turnMade = true;
                            }
                        }
                        break;
                    case 3:
                        movement = KEY_RIGHT;
                        if (checkEmpty(enemyX+1,enemyY,gameObjects,enemyList) == true)
                        {
                            if (symbolArray[enemyX+1][enemyY] != '#')
                            {
                                currentEnemy -> moveChar(movement);
                                turnMade = true;
                            }
                        }
                        break;
                }

            }


        }

    }
    return;
}
