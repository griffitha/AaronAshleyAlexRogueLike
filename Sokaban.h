#include "utility.h"

//Class of interactive objects
class interactiveObject: public character
{
    public:
    interactiveObject(int x, int y):
        character(x,y)
        {

        }
    void setRockAttributes();

};
