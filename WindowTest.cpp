#include <curses.h>

int main()
{
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
    keypad(stdscr,true); //Key input used in gameWindow
    //Color Settings
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    //Converts to grey
    init_pair(3,COLOR_WHITE,COLOR_BLACK);
    init_pair(4,COLOR_WHITE,COLOR_MAGENTA);
    wbkgd(gameWindow, COLOR_PAIR(1));
    refresh();

    while(1)
    {
        int ch = getw();
        if (ch != KEY_BACKSPACE || ch != KEY_ENTER)
        {
            waddch(gameWindow,ch);
        }
        else if (ch == KEY_ENTER)
        {
            break;
        }
        wclear(gameWindow);
    }
}
