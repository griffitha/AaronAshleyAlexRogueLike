#include "utility.h"

void readLevel(char symbolArray[1000][1000], int levelNumber)
{
    //File Data Type where the file will be loaded
    std::ifstream levelFile;
    //Character save for readin
    char currentCharacter = ' ';

    //Select the level to load
    switch(levelNumber)
    {
        case 1:
            //Opens first level
            levelFile.open("level1.txt");
            break;
        default:
            std::cout << "This is not a valid file." << std::endl;

    }

    int x = 0;
    int y = 0;
    //Reads in each character of the document
    while (levelFile >> currentCharacter)
    {
        if (currentCharacter == ']')
        {
            //Sets character in position to that item
            symbolArray[x][y] = '#';
            x++;
        }
        else if (currentCharacter == '-')
        {
            //Designates empty space
            symbolArray[x][y] = ' ';
            x++;
        }
        else if (currentCharacter == 'p')
        {
            symbolArray[x][y] = 'p';
            x++;
            //Will fill with pointer information when character is implemented
        }
        else if (currentCharacter == '/')
        {
            //Moves to next roll
            symbolArray[x][y] = '/';
            y++;
            x = 0;
        }
        //Moves to next column
        else
        {
            x++;
        }
    }
    //This is a flag in the array when to stop listing data;
    symbolArray[x][y] = 'q';
    levelFile.close();
    return;
}

void printWindow(char symbolArray[][1000], WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{
    int x = 20;
    int y = 20;
    int ch; // Key input variable

    while(1)
    {
        int arrayX = 0;
        int arrayY = 0;
        //Sets up the map
        while (symbolArray[arrayX][arrayY] != 'q')
        {
            char currentCharacter = symbolArray[arrayX][arrayY];
            if (currentCharacter != '/')
            {
                //Sets character at this position
                mvwaddch(workingWindow,arrayY,arrayX,currentCharacter);
                arrayX++;
            }
            else if (currentCharacter == '/')
            {
                //Moves to next roll if it encounters this character
                arrayY++;
                arrayX = 0;
            }
            //Moves to next column
            else
            {
                arrayX++;
            }
        }

        wrefresh(workingWindow);
        wrefresh(statusWindow);
        wrefresh(message);

        //mvprintw(y,x "X");
        wmove(workingWindow,y,x);
        waddch(workingWindow,'X');

        ch = wgetch(workingWindow);
        if (ch == KEY_DOWN)
        {
            y++;
            wclear(workingWindow);
        }
        if (ch == KEY_UP)
        {
            y--;
            wclear(workingWindow);
        }
        if (ch == KEY_LEFT)
        {
            x--;
            wclear(workingWindow);
        }
        if (ch == KEY_RIGHT)
        {
            x++;
            wclear(workingWindow);
        }
          //refreshes window

        wrefresh(workingWindow);
        wrefresh(statusWindow);
        wrefresh(message);
    }
    return;
}

