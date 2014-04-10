#include "utility.h"
#include "AlexRogue.h"

//Main CPP File for Project
//Features the Window at this moment

int main()
{

    int const GAME_WINDOW_HEIGHT = 21;
    int const GAME_WINDOW_WIDTH = 31;
    int const STATUS_WINDOW_HEIGHT = 10;
    int const STATUS_WINDOW_WIDTH = 44;
    int const LOG_WINDOW_HEIGHT = 10;
    int const LOG_WINDOW_WIDTH = 44;
    char symbolArray[500][500];
    character * gameObjectArray[500][500];

    //Creates Screen
    initscr();
    curs_set(0); //set visibility of cursor

    //Creates new window where the game will be played and sets up other options
    WINDOW * gameWindow = newwin(GAME_WINDOW_HEIGHT,GAME_WINDOW_WIDTH,1,1);
    WINDOW * statusWindow = newwin(STATUS_WINDOW_HEIGHT,STATUS_WINDOW_WIDTH,1,35);
    WINDOW * messageWindow = newwin(LOG_WINDOW_HEIGHT,LOG_WINDOW_WIDTH,12,35);
<<<<<<< HEAD
=======
    keypad(stdscr,true);
>>>>>>> origin/Ashley
    keypad(gameWindow,true); //Key input used in gameWindow
    noecho(); //Don't echo() while we go do getch
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    init_pair(3,COLOR_WHITE,COLOR_CYAN);
    init_pair(4,COLOR_WHITE,COLOR_MAGENTA);
    wbkgd(stdscr, COLOR_PAIR(1));
    wbkgd(gameWindow, COLOR_PAIR(2));
    wbkgd(statusWindow, COLOR_PAIR(3));
    wbkgd(messageWindow, COLOR_PAIR(4));
    refresh();
    //Player Creation
    character player(0,0);
    player.setMapRep('X');

    //Read Level from File
<<<<<<< HEAD
    readLevel(symbolArray,gameObjectArray,player,1);
    //Prints windows
    printWindow(symbolArray,gameObjectArray,gameWindow,statusWindow,messageWindow);
=======
    readLevel(symbolArray,gameObjectArray,player,2);
    //Prints windows
    printWindow(symbolArray,gameObjectArray,player,gameWindow,statusWindow,messageWindow);

    while(1)
    {
        printWindow(symbolArray,gameObjectArray,player,gameWindow,statusWindow,messageWindow);
        playerTurn(symbolArray,gameObjectArray,player);
    }
>>>>>>> origin/Ashley

    endwin();
    return 0;
}
