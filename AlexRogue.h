#ifndef ALEXROGUE_H
#define ALEXROGUE_H

#include "utility.h"

enum race
{
    Human,
    Orc,
    Elf,
    Dwarf,
    Goblin,
};
enum characterClass
{
    warrior,
    mage,
    ranger,
};

class character
{
public:
    character(int x,int y);
    //spawns character at given location
    void moveChar(int input);
    bool attack();
    void setXCoordinate(int input);
    int getXCoordinate();
    void setYCoordinate(int input);
    int getYCoordinate();
    void setHealth(int input);
    int getHealth();
    void setMaxHealth(int input);
    int getMaxHealth();
    void setMapRep(char input);
    char getMapRep();
    void setCharacterName(std::string input);
    std::string getCharacterName();
    virtual int getBaseDamage();
    void setBaseDamage(int input);
    int getArmor();
    void setArmor(int input);
    int getAccuracy();
    void setAccuracy(int input);
    void setLevel(int input);
    int getLevel();

private:
    int xCoordinate;
    int yCoordinate;
    int health;
    int maxHealth;
    char mapRep;
    //character used to represent on map
    std::string characterName;
    int level;
    int experience;
    int baseDamage;
    int currentArmor;
    int accuracy;  //Base Accuracy Value
};

class player: public character
{
public:
    player(int x,int y):
                character(x,y)
    {
    }
    void setLevel(int input);
    void setExperience(int input);
    int getExperience();
    void setGender(char input);
    char getGender();
    void setRace(race input);
    race getRace();
    void setClass(characterClass input);
    characterClass getClass();
    void setXpToLevel(int input);
    void levelUp();

private:
    int level;
    int xpToLevel;
    int experience;
    char gender;
    race characterRace;
    characterClass playerClass;

};


#endif // ROGUE_H_INCLUDED
