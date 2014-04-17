#ifndef UTILITY_H
#define UTILITY_H

#include <curses.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "AlexRogue.h"
#include "combat.h"
#include "itemh.h"


//Reads Levels from file
//void readLevel(char symbolArray[500][500],character * gameObjectArray[500][500],character &player, int levelNumber);
void readLevel(char symbolArray[500][500],std::vector<character> gameObjects,character &player, int levelNumber);

//Renews the window each time
void printWindow(char symbolArray[500][500],std::vector<character> gameObjects, character player, WINDOW * workingWindow,WINDOW * status, WINDOW * message);

//Options for players turn and carries them out
void playerTurn(char symbolArray[][500], std::vector<character> gameObjects, character &player);

//Prints the status window
void printStatusWindow(character &player, WINDOW * statusWindow);

player playerCreation();

#endif // UTILITY_H
