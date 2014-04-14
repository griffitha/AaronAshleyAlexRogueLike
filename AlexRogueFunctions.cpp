#include "utility.h"

character::character(int x,int y)
{
    //Constructor
    xCoordinate=x;
    yCoordinate=y;

    //Set Values
    currentArmor = 1;
    health = 0;
    accuracy = 80;
    baseDamage = 4;
}

void character::moveChar(int input)
{
        if (input == KEY_UP)
        {
            yCoordinate--;
        }
        if (input == KEY_DOWN)
        {
            yCoordinate++;
        }
        if (input == KEY_LEFT)
        {
            xCoordinate--;
        }
        if (input == KEY_RIGHT)
        {
            xCoordinate++;
        }
    return;
}

bool character::attack()
{
    return true;
}

void character::setXCoordinate(int input)
{
    xCoordinate=input;
    return;
}

int character::getXCoordinate()
{
    return xCoordinate;
}

void character::setYCoordinate(int input)
{
    yCoordinate=input;
    return;
}

int character::getYCoordinate()
{
    return yCoordinate;
}

void character::setHealth(int input)
{
    //Upon creation of character
    if (health == 0)
    {
        health = input;
        maxHealth = input;
    }
    //In other cases, just set health
    else
    {
        health = input;
    }
    return;
}

int character::getHealth()
{
    return health;
}

void character::setMaxHealth(int input)
{
    maxHealth=input;
    return;
}

int character::getMaxHealth()
{
    return maxHealth;
}

void character::setMapRep(char input)
{
    mapRep=input;
    return;
}

char character::getMapRep()
{
    return mapRep;
}

void character::setCharacterName(std::string input)
{
    characterName=input;
    return;
}

std::string character::getCharacterName()
{
    return characterName;
}

void character::setLevel(int input)
{
    level=input;
    return;
}

int character::getLevel()
{
    return level;
}

void character::setExperience(int input)
{
    experience=input;
    return;
}

int character::getExperience()
{
    return experience;
}

void character::setBaseDamage(int input)
{
    //Sets Character base damage without any kind of weaponry
    baseDamage = input;
    return;
}

int character::getBaseDamage()
{
    //Returns the base damage of the character
    return baseDamage;
}

int character::getArmor()
{
    //Returns the characters armor value
    //Will update to make sure it updates dynamically once items are issued
    return currentArmor;
}

void character::setArmor(int input)
{
    //Sets the current armor to the given input
    currentArmor = input;
    return;
}

int character::getAccuracy()
{
    //Returns the current accuracy value
    return accuracy;
}

void character::setAccuracy(int input)
{
    //Sets the current accuracy value
    accuracy = input;
}
