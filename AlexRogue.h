#ifndef ALEXROGUE_H
#define ALEXROGUE_H

#include <string>
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
    std::string characterName;
    int level;
    int experience;
};
character createWarrior(int x,int y,char gender);

#endif // ROGUE_H_INCLUDED
