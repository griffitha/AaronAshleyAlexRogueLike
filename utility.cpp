#include "utility.h"


//Utility Functions CPP

void readLevel(char symbolArray[500][500],character * gameObjectArray[500][500], character &player, int levelNumber)
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
            gameObjectArray[x][y] = &player;
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

void printWindow(char symbolArray[][500],character * gameObjectArray[500][500], WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{

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

    }
    return;
}

