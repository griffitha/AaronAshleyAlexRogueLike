#ifndef ALEXROGUE_H
#define ALEXROGUE_H

#include "utility.h"

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
    void setLevel(int input);
    int getLevel();
    void setExperience(int input);
    int getExperience();
    int getBaseDamage();
    void setBaseDamage(int input);
    int getArmor();
    void setArmor(int input);
    int getAccuracy();
    void setAccuracy(int input);

private:
    int xCoordinate;
    int yCoordinate;
    int health = 0;
    int maxHealth;
    char mapRep;
    //character used to represent on map
    std::string characterName;
    int level = 1;
    int experience;
    int baseDamage = 1;
    int currentArmor = 0;
    int accuracy = 80;  //Base Accuracy Value
};

#endif // ROGUE_H_INCLUDED
