#include "utility.h"

//Health and  Base Damage formulas taken from alpha ver of Desktop Dungeons
void enemy::createGoblin(int factor)
{
    int healthValue=((factor + 3)^2) - 10;
    int damageValue=((factor)^2 / 2) + ((5 * factor) / 2);
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('G');
    setCharacterName("Goblin");
    setBaseDamage(damageValue);
    setArmor(2);
    setAccuracy(70);
    setLevel(factor);
}
void enemy::createBat(int factor)
{
    int healthValue=(((factor + 3)^2) - 10)*.7;
    int damageValue=(((factor)^2 / 2) + ((5 * factor) / 2))*.7;
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('B');
    setCharacterName("Bat");
    setBaseDamage(damageValue);
    setArmor(1);
    setAccuracy(95);
    setLevel(factor);
}
void enemy::createCyborg(int factor)
{
    int healthValue=(((factor + 3)^2) - 10)*2;
    int damageValue=(((factor)^2 / 2) + ((5 * factor) / 2))*.5;
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('C');
    setCharacterName("Cyborg");
    setBaseDamage(damageValue);
    setArmor(2);
    setAccuracy(80);
    setLevel(factor);
}
//modified version of numOfItems created by Ashley
int numOfEnemies(char symbolArray[500][500],vector <Location> &possiblePositions)
{
    int spaceCounter = 0;
    int enemiesToCreate = 0;
    const int ENEMIES_PER_SPACES = 20;

    for(int x = 0; x < 500; x++)
    {
        for(int y = 0; y < 500; y++)
        {
            if(symbolArray[x][y] == ' ')
            {
                if(symbolArray[x][y+1] == ' ' && symbolArray[x][y-1] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possiblePositions.push_back(newLocation);
                }
                if(symbolArray[x+1][y] == ' ' && symbolArray[x-1][y] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possiblePositions.push_back(newLocation);
                }
            }
        }
    }

    //1 enemy for every 20 spaces
    enemiesToCreate = spaceCounter/ENEMIES_PER_SPACES;
    //This guarantees at least 1 enemy to spawn in a given room
    if(enemiesToCreate==0)
    {
        enemiesToCreate++;
    }

    return enemiesToCreate;
}
void spawnEnemies(char symbolArray[500][500],vector <Location> &possiblePositions,int enemiesToCreate,player mainChar)
{
    for(int i;i>enemiesToCreate;i++)
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
    int enemyLevel=rand()%mainChar.getLevel();
    //spawn enemy
    enemy currentEnemy(enemyX,enemyY,enemyType,enemyLevel);
    //place enemy on map
    symbolArray[enemyX][enemyY]=currentEnemy.getMapRep();
    }
    return;
}
