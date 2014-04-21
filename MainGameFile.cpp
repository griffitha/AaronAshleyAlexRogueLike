#include "utility.h"
#include "AlexRogue.h"

//Main CPP File for Project
//Features the Window at this moment

using namespace std;

int main()
{
    bool victoryAchieved = false;
    bool playerIsAlive = true;
    int const GAME_WINDOW_HEIGHT = 21;
    int const GAME_WINDOW_WIDTH = 31;
    int const STATUS_WINDOW_HEIGHT = 10;
    int const STATUS_WINDOW_WIDTH = 44;
    int const LOG_WINDOW_HEIGHT = 10;
    int const LOG_WINDOW_WIDTH = 44;
    char symbolArray[500][500];


    //player thePlayer = playerCreation();
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
    wbkgd(stdscr, COLOR_PAIR(1));
    wbkgd(gameWindow, COLOR_PAIR(2));
    wbkgd(statusWindow, COLOR_PAIR(3));
    wbkgd(messageWindow, COLOR_PAIR(3));
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
    readLevel(symbolArray,gameObjects,thePlayer,50);

    //create and initialize health potion vector
    vector <Consumable> healthPotionVector;
    initializeHealthPotionVector(healthPotionVector);

    //create and initialize magic potion vector
    vector <Consumable> magicPotionVector;
    initializeMagicPotionVector(magicPotionVector);

    //vector to hold corridinates for places in symbol array that contain spaces
    vector <Location> possiblePositions;

    //vector to hold items
    vector <Item> itemsVector;

    //find number of items to place
    int itemsNeeded = 0;
    itemsNeeded = numOfItems(symbolArray,possiblePositions);

    for(int i = 0; i < itemsNeeded; i++)
    {
        itemChoice(thePlayer,itemsVector,healthPotionVector,magicPotionVector);
    }

    positions(symbolArray,itemsVector,possiblePositions);

    while((victoryAchieved == false) || (playerIsAlive != false))
    {
        //Prints Windows
        printWindow(symbolArray,gameObjects,thePlayer,gameWindow,statusWindow,messageWindow);
        //Intiates player's turn
        playerTurn(symbolArray,gameObjects,thePlayer);

        victoryAchieved = checkSokabanVictory(gameObjects,symbolArray);
        playerIsAlive = checkDead(playerPointer);
    }

    endwin();
    cout << "Well Played! Do come and play again!" << endl;
    return 0;
}
