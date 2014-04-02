#ifndef UTILITY_H
#define UTILITY_H

#include <curses.h>
#include <fstream>
#include <iostream>


//Reads Levels from file
void readLevel(char symbolArray[1000][1000], int levelNumber);

//Renews the window each time
void printWindow(char symbolArray[1000][1000],WINDOW * workingWindow,WINDOW * status, WINDOW * message);


#endif // UTILITY_H
