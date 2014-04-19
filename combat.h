#include "utility.h"

//Basic Attack Animation
void meleeAttack(character * attacker, character * defender, std::vector<character> gameObjects);

//Check if target is dead
bool checkDead(character * target);

//Check if the location is empty of game objects
bool checkEmpty(int x, int y, std::vector<character> gameObjects);

//Returns the position in the array that has the target
int findTarget(int x, int y, std::vector<character> gameObjects);

