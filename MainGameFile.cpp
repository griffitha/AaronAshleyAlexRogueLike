#include "utility.h"

//Main CPP File for Project
//Features the Window at this moment

int main()
{

    int const WINDOW_HEIGHT = 20;
    int const TOP_WINDOW_WIDTH = 40;
    int const BOTTOM_WINDOW_WIDTH = 82;
    char symbolArray[1000][1000];
    //Creates Screen
    initscr();
    curs_set(0); //set visibility of cursor

    //Creates new window where the game will be played and sets up other options
    WINDOW * gameWindow = newwin(WINDOW_HEIGHT,TOP_WINDOW_WIDTH,1,2);
    WINDOW * statusWindow = newwin(WINDOW_HEIGHT ,TOP_WINDOW_WIDTH,1,44);
    WINDOW * messageWindow = newwin(WINDOW_HEIGHT,BOTTOM_WINDOW_WIDTH,22,2);
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

    //Read Level from File
    readLevel(symbolArray,1);
    //Prints windows
    printWindow(symbolArray,gameWindow,statusWindow,messageWindow);

    endwin();
    return 0;
}
