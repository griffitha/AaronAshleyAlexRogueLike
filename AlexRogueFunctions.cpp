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
void character::setGender(char input)
{
    gender=input;
    return;
}

char character::getGender()
{
    return gender;
}

void character::setRace(int input)
{
    race=input;
    return;
}

int character::getRace()
{
    return race;
}
void character::setClass(characterClass input)
{
    playerClass=input;
    return;
}
characterClass character::getClass()
{
    return playerClass;
}
character createWarrior(int x,int y,char gender,race race)
{

    character player(x,y);
    player.setMapRep('X');
    player.setCharacterName("Player");
    player.setRace(race);
    player.setGender(gender);
    player.setClass(warrior);
    player.setLevel(1);
    player.setExperience(0);
    player.setHealth(20);
    player.setMaxHealth(20);

    return player;
}


