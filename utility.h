#ifndef UTILITY_H
#define UTILITY_H

#include <curses.h>
#include <fstream>
#include <iostream>
#include "AlexRogue.h"


//Reads Levels from file
void readLevel(char symbolArray[500][500],character * gameObjectArray[500][500],character &player, int levelNumber);

//Renews the window each time
void printWindow(char symbolArray[500][500],character * gameObjectArray[500][500],character player, WINDOW * workingWindow,WINDOW * status, WINDOW * message);

//Options for players turn and carries them out
void playerTurn(char symbolArray[500][500], character * gameObjectArray[500][500], character &player);

#endif // UTILITY_H
