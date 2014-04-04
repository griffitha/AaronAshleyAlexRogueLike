#ifndef ROGUE_H_INCLUDED
#define ROGUE_H_INCLUDED

#include <cstring>
#include <iostream>
#include <curses.h>

class character
{
public:
    character(int x,int y);
    //spawns character at given location
    void moveChar(char input);
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
    void setCharacterName(string input);
    string getCharacterName();
    void setLevel(int input);
    int getLevel();
    void setExperience(int input);
    int getExperience();



private:
    int xCoordinate;
    int yCoordinate;
    int health;
    int maxHealth;
    char mapRep;
    //character used to represent on map
    string characterName;
    int level;
    int experience;

};

#endif // ROGUE_H_INCLUDED
