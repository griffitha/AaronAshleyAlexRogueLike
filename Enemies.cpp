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
    int healthValue=((factor + 3)^2) - 10;
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
    int healthValue=(((factor + 3)^2) - 10)*.7;
    int damageValue=(((factor)^2 / 2) + ((5 * factor) / 2))*.7;
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
    int healthValue=(((factor + 3)^2) - 10)*2;
    int damageValue=(((factor)^2 / 2) + ((5 * factor) / 2))*.5;
    int experienceValue=(factor*(factor+1));
    setMaxHealth(healthValue);
    setHealth(getMaxHealth());
    setMapRep('R');
    setCharacterName("Robot");
    setBaseDamage(damageValue);
    setArmor(2);
    setAccuracy(80);
    setLevel(factor);
    setXpValue(experienceValue);
}
//modified version of numOfItems created by Ashley
int numOfEnemies(char symbolArray[500][500],vector <Location> possiblePositions)
{
    int spaceCounter = 0;
    int enemiesToCreate = 0;
    int enemiesPerSpaces = (rand()%20)+35;
    //1 enemy for every 20 spaces
    enemiesToCreate = spaceCounter/enemiesPerSpaces;
    //This guarantees at least 1 enemy to spawn in a given room
    if(enemiesToCreate==0)
    {
        enemiesToCreate++;
    }

    return enemiesToCreate;
}
void spawnEnemies(char symbolArray[500][500],vector <Location> &possiblePositions,int enemiesToCreate,player mainChar)
{
    for(int i=0;i>enemiesToCreate;i++)
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
