#include "utility.h"
#include "AlexRogue.h"
#include "itemh.h"

//Main CPP File for Project
//Features the Window at this moment

using namespace std;

int main()
{
    srand(time(NULL));

    int const GAME_WINDOW_HEIGHT = 21;
    int const GAME_WINDOW_WIDTH = 31;
    int const STATUS_WINDOW_HEIGHT = 10;
    int const STATUS_WINDOW_WIDTH = 44;
    int const LOG_WINDOW_HEIGHT = 10;
    int const LOG_WINDOW_WIDTH = 44;
    char symbolArray[500][500];

    //Creates Screen
    initscr();
    curs_set(0); //set visibility of cursor

    //Creates new window where the game will be played and sets up other options
    WINDOW * gameWindow = newwin(GAME_WINDOW_HEIGHT,GAME_WINDOW_WIDTH,1,1);
    WINDOW * statusWindow = newwin(STATUS_WINDOW_HEIGHT,STATUS_WINDOW_WIDTH,1,35);
    WINDOW * messageWindow = newwin(LOG_WINDOW_HEIGHT,LOG_WINDOW_WIDTH,12,35);
    keypad(stdscr,true);
    keypad(gameWindow,true); //Key input used in gameWindow
    noecho();
    //Color Settings
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    //Converts to grey
    init_pair(3,COLOR_WHITE,COLOR_BLACK);
    init_pair(4,COLOR_WHITE,COLOR_MAGENTA);
    wbkgd(stdscr, COLOR_PAIR(1));
    wbkgd(gameWindow, COLOR_PAIR(2));
    wbkgd(statusWindow, COLOR_PAIR(3));
    wbkgd(messageWindow, COLOR_PAIR(4));
    cbreak();
    refresh();

    //Player Creation TEST STUFF
    player thePlayer(0,0);
    player * playerPointer = &thePlayer;
    thePlayer.setCharacterName("Tim the Viking");
    thePlayer.setHealth(10);
    thePlayer.setMaxHealth(10);
    thePlayer.setMapRep('X');
    vector<character> gameObjects;

    //Read Level from File
    readLevel(symbolArray,gameObjects,thePlayer,2);

    //create and initialize health potion vector
    vector <Consumable> healthPotionVector;
    initializeHealthPotionVector(healthPotionVector);

    //create and initialize magic potion vector
    vector <Consumable> magicPotionVector;
    initializeMagicPotionVector(magicPotionVector);

    //create and initialize armor vectors
    vector <Armor> leatherArmorVector;
    vector <Armor> metalArmorVector;
    vector <Armor> crystalArmorVector;
    initializeArmorVector(leatherArmorVector,metalArmorVector,crystalArmorVector);

    //create and initialize weapon vectors
    vector <Weapon> daggerVector;
    initializeDaggerVector(daggerVector);

    vector <Weapon> clubVector;
    initializeClubVector(clubVector);

    vector <Weapon> heavyMaceVector;
    initializeHeavyMaceVector(heavyMaceVector);

    vector <Weapon> spearVector;
    initializeSpearVector(spearVector);

    vector <Weapon> lightCrossBowVector;
    initializeLightCrossBowVector(lightCrossBowVector);

    vector <Weapon> longBowVector;
    initializeLongBowVector(longBowVector);

    vector <Weapon> battleaxeVector;
    initializeBattleaxeVector(battleaxeVector);

    vector <Weapon> heavyCrossBowVector;
    initializeHCrossBowVector(heavyCrossBowVector);

    //vector to hold corridinates for places in symbol array that contain spaces
    vector <Location> possiblePositions;

    //vector to hold items
    vector <Consumable> consumableVector;
    vector <Armor> armorVector;
    vector <Weapon> weaponsVector;

    //find number of items to place
    int itemsNeeded = 0;
    itemsNeeded = numOfItems(symbolArray,possiblePositions);

    for(int i = 0; i < itemsNeeded; i++)
    {
        itemChoice(thePlayer,consumableVector,armorVector,weaponsVector,
                   healthPotionVector,magicPotionVector,
                   leatherArmorVector,metalArmorVector,crystalArmorVector,
                   daggerVector, clubVector,heavyMaceVector,spearVector,
                   heavyCrossBowVector, lightCrossBowVector,battleaxeVector,longBowVector);
    }

    positions(symbolArray,consumableVector,armorVector,weaponsVector,possiblePositions);

    writeTests(consumableVector,armorVector,weaponsVector,possiblePositions,healthPotionVector,
               magicPotionVector,leatherArmorVector, metalArmorVector,crystalArmorVector,
               daggerVector,clubVector,heavyMaceVector,spearVector, heavyCrossBowVector,
               lightCrossBowVector,battleaxeVector,longBowVector);

    while(!checkDead(playerPointer))
    {
        //Prints Windows
        printWindow(symbolArray,gameObjects,thePlayer,gameWindow,statusWindow,messageWindow);
        //Intiates player's turn
        playerTurn(symbolArray,gameObjects,thePlayer);
        //call function to check if new x and y have an item
        checkForItem(thePlayer,symbolArray,consumableVector,armorVector,weaponsVector,messageWindow);
    }

    endwin();
    return 0;
}
