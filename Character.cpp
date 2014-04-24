#include "utility.h"

character::character(int x,int y)
{
    //Constructor
    xCoordinate=x;
    yCoordinate=y;

    //Set Values
    currentArmor = 1;
    health = 1;
    accuracy = 80;
    baseDamage = 4;
    level = 1;
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
    health = input;
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
//player functions

void character::setLevel(int input)
{
    level=input;
    return;
}

int character::getLevel()
{
    return level;
}
void player::setExperience(int input)
{
    experience=input;
    if (experience > xpToLevel)
    {
        levelUp();
    }
    return;
}

int player::getExperience()
{
    return experience;
}

void player::setGender(char input)
{
    gender=input;
    return;
}

char player::getGender()
{
    return gender;
}

void player::setRace(race input)
{
    characterRace=input;
    return;
}

race player::getRace()
{
    return characterRace;
}
void player::setClass(characterClass input)
{
    playerClass=input;
    setHealth(20);
    setMaxHealth(20);
    setLevel(1);
    setExperience(0);
    setXpToLevel(10);

    return;
}

characterClass player::getClass()
{
    return playerClass;
}
void player::setXpToLevel(int input)
{
    xpToLevel=input;
    return;
}
void player::levelUp()
{
    //Assigns to a random value at this point
    int currentAttribute;
    int randomAttribute = rand() % 3;
    switch(randomAttribute)
    {
        //Increases Damage
        case 0:
            currentAttribute = getBaseDamage() + 1;
            setBaseDamage(currentAttribute);
            break;
        //Increases Armor
        case 1:
            currentAttribute = getArmor() + 1;
            setArmor(currentAttribute);
            break;
        //Increase Health
        case 2:
            currentAttribute = getMaxHealth() + 1;
            setHealth(currentAttribute);
            setMaxHealth(currentAttribute);
            break;
    }


    experience=xpToLevel%experience;
    if((xpToLevel%2)>0)
    {
        xpToLevel=xpToLevel*1.5;
        xpToLevel++;
    }
    else
    {
        xpToLevel=xpToLevel*1.5;
    }
    int levelHolder=getLevel();
    levelHolder++;
    setLevel(levelHolder);
    return;
}

void player::rest()
{
    //Heals by one point and takes up one turn
    if (getHealth() < getMaxHealth())
    {
        int newHealth = getHealth() + 1;
        setHealth(newHealth);
    }
    return;
}
