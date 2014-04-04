#include "rogue.h"

using namespace std;
int main()
{
    return 0;
}
character::character(int x,int y)
{
    xCoordinate=x;
    yCoordinate=y;
    cout<<xCoordinate<<endl;
    cout<<yCoordinate<<endl;
}
bool character::moveChar(WINDOW * workingWindow)
{
    ch=wgetch(workingWindow);
      ch = wgetch(workingWindow);
        if (ch == KEY_UP)
        {
            yCoordinate--;
            wclear(workingWindow);
        }
        if (ch == KEY_DOWN)
        {
            yCoordinate++;
            wclear(workingWindow);
        }
        if (ch == KEY_LEFT)
        {
            xCoordinate--;
            wclear(workingWindow);
        }
        if (ch == KEY_RIGHT)
        {
            xCoordinate++;
            wclear(workingWindow);
        }
    return true;
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
void character::setCharacterName(string input)
{
    characterName=input;
    return;
}
string character::getCharacterName()
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
