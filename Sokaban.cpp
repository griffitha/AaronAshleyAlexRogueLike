#include "utility.h"

void interactiveObject::setRockAttributes()
{
    //Set character representation
    setMapRep('R');
    //In the situation where the player may damage the object
    setHealth(10000000);
    //Armor will act as a unique identifier for the object
    setArmor(9001);
}
