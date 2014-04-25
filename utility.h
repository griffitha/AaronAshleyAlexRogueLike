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
void readLevel(char symbolArray[500][500],std::vector<character> &gameObjects,std::vector<enemy> &enemyList,
               vector<Location> &possibleLocations,player &thePlayer, int levelNumber,
               vector <Consumable> consumableVector, vector <Armor> armorVector, vector <Weapon> weaponVector);

//Renews the window each time
void printWindow(char symbolArray[500][500],vector<character> gameObjects,vector<enemy> enemyList, player thePlayer, WINDOW * workingWindow,WINDOW * status, WINDOW * message,Equipped playerEquipped);

//Options for players turn and carries them out
void playerTurn(char symbolArray[][500], vector<character> &gameObjects,vector<enemy> &enemyList,vector<Location> possibleLocations, player &thePlayer,
                vector <Consumable> consumableVector, vector <Armor> armorVector, vector <Weapon> weaponVector);

//Prints the status window
void printStatusWindow(player &thePlayer, WINDOW * statusWindow,Equipped playerEquipped);

//Prints Any Objects or Enemies that exist
void printObjects(int X, int Y, int xCounter, int yCounter, char symbolArray[][500],std::vector<character> gameObjects,
                  std::vector<enemy> enemyList,player thePlayer, WINDOW * workingWindow);

player playerCreation();

#endif // UTILITY_H
