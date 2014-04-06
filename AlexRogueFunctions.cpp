#include "utility.h"

character::character(int x,int y)
{
    //Constructor
    xCoordinate=x;
    yCoordinate=y;
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
    health=input;
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

