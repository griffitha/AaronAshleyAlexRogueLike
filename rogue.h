#ifndef ROGUE_H_INCLUDED
#define ROGUE_H_INCLUDED

using namespace std;

class character
{
public:
    character(int x,int y);
    //spawns character at given location
    bool moveChar();
    bool attack();
private:
    int xCoordinate;
    int yCoordinate;
    char mapRep;
    //Health
    //Max Health
    //
    //character used to represent on map
    string characterName;
    int level;
    int Experience;

};
character::character(int x,int y)
{
    xCoordinate=x;
    yCoordinate=y;
}
bool character::moveChar()
//wgetch
{
    //North
    yCoordinate--;
    //South
    yCoordinate++;
    //East
    xCoordinate++;
    //West
    xCoordinate--;
    return true;
}
bool character::attack()
{
    return true;
}

#endif // ROGUE_H_INCLUDED
