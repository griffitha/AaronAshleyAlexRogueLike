#ifndef UTILITY_H
#define UTILITY_H

#include <curses.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Character.h"
#include "Enemies.h"
#include "combat.h"
#include "Sokaban.h"
#include "itemh.h"


//Reads Levels from file
void readLevel(char symbolArray[500][500],std::vector<character> &gameObjects,player &thePlayer, int levelNumber);

//Renews the window each time
void printWindow(char symbolArray[500][500],std::vector<character> gameObjects, player thePlayer, WINDOW * workingWindow,WINDOW * status, WINDOW * message,Inventory playerInventory);

//Options for players turn and carries them out
void playerTurn(char symbolArray[][500], std::vector<character> &gameObjects, player &thePlayer,Inventory playerInventory,WINDOW * messageWindow);

//Prints the status window
void printStatusWindow(player &thePlayer, WINDOW * statusWindow);

player playerCreation();

#endif // UTILITY_H
