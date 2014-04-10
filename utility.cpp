#include "utility.h"


//Utility Functions CPP

void readLevel(char symbolArray[500][500],character * gameObjectArray[500][500], character &player, int levelNumber)
{
    //File Data Type where the file will be loaded
    std::ifstream levelFile;
    //Character save for readin
    char currentCharacter = ' ';

    for (int i = 0; i < 500; i++)
    {
        for (int q = 0; q < 500; q++)
        {
            symbolArray[i][q] == '#';
        }
    }

    //Select the level to load
    switch(levelNumber)
    {
        case 1:
            //Opens first level
            levelFile.open("level1.txt");
            break;
        case 2:
            levelFile.open("level2.txt");
            break;
        default:
            std::cout << "This is not a valid file." << std::endl;

    }

    int x = 0;
    int y = 0;
    std::string inputLine;
    //Reads in each character of the document
    while (!levelFile.eof())
    {
        getline(levelFile,inputLine);
        for (int i = 0; i < inputLine.size(); i++)
        {
            if ((inputLine.at(i) == ']') || (inputLine.at(i) == ' ') || (inputLine.at(i) == '/'))
            {
                //Sets character in position to that item
                symbolArray[x][y] = '#';
                x++;
            }
            else if (inputLine.at(i) == 'E')
            {
                symbolArray[x][y] = 'E';
                x++;
            }
            else if (inputLine.at(i) == '-')
            {
                //Designates empty space
                symbolArray[x][y] = ' ';
                x++;
            }
            else if (inputLine.at(i) == 'p')
            {
                //This clears the spot
                symbolArray[x][y] = ' ';
                gameObjectArray[x][y] = &player;
                player.setXCoordinate(x);
                player.setYCoordinate(y);
                x++;
            }
        }
        x = 0;
        y++;
    }
    levelFile.close();
    return;
}

void printWindow(char symbolArray[500][500],character * gameObjectArray[500][500], character player, WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{
        int X;
        int Y;
        int playerX = player.getXCoordinate();
        int playerY = player.getYCoordinate();
        X = playerX - 15;
        Y = playerY - 11;
        //These are finding positions in the window
        int xCounter = 0;
        int yCounter = 0;
        bool mapCreated = false;
        //Sets up the map

        while (mapCreated != true)
        {
            //Checks to make sure it isnt out of bounds
            if (((X >= 0) && (X < 500)) && ((Y >= 0) && (Y <500)))
            {
                if (symbolArray[X][Y] != ' ')
                {
                    //Makes everything a block
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_BLOCK);
                }
                else if (symbolArray[X][Y] == '^')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_BLOCK);
                }
                else
                {
                    mvwaddch(workingWindow,yCounter,xCounter,symbolArray[X][Y]);
                }
            }

            else
            {
                //If out of bounds, make it a block
                mvwaddch(workingWindow,yCounter,xCounter,ACS_BLOCK);
            }
            //Move up to the next column
            X++;
            xCounter++;

            if (X == (playerX + 17))
            {
                if (Y == (playerY + 11))
                {
                    mapCreated = true;
                    break;
                }
                //Move to the next row
                Y++;
                yCounter++;
                //reset column work
                X = playerX - 15;
                xCounter = 0;
                wrefresh(workingWindow);
            }
        }

    //Prints Status Window based on player stats
    printStatusWindow(player,statusWindow);

    mvwaddch(workingWindow,11,15,player.getMapRep());
    wrefresh(workingWindow);
    wrefresh(statusWindow);
    wrefresh(message);
    wclear(workingWindow);
    return;
}

void playerTurn(char symbolArray[][500], character * gameObjectArray[500][500], character &player)
{
    //Save Player's current position
    int playerX = player.getXCoordinate();
    int playerY = player.getYCoordinate();

    int ch = getch();
    //Move Up
    if (ch == KEY_UP)
    {
        if (symbolArray[playerX][playerY-1] == ' ')
        {
            //Resets map position to new position
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    //Move Down
    else if (ch == KEY_DOWN)
    {
        if (symbolArray[playerX][playerY+1] == ' ')
        {
            //Resets map position to new position
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    //Move Left
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' ')
        {
            //Resets map position to new position
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    //Move Right
    else if (ch == KEY_RIGHT)
    {
        if (symbolArray[playerX+1][playerY] == ' ')
        {
            //Resets map position to new position
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    return;
}

void printStatusWindow(character &player, WINDOW * statusWindow)
{
    //Prints player name on first line
    std::string currentString = player.getCharacterName();
    int currentInteger = player.getLevel();
    char currentCharacter = currentInteger;
    char * characterPointer = &currentString.at(0);
    mvwprintw(statusWindow,0,3,characterPointer);

    //Second line features level number
    currentString = "Level: ";
    //Pointer is set to read the entire string
    characterPointer = &currentString.at(0);
    mvwprintw(statusWindow,1,3,characterPointer);
    mvwprintw(statusWindow,1,10,"%d",currentInteger);

    //Third line features health number
    currentString = "Health: ";
    currentInteger = player.getHealth();
    mvwprintw(statusWindow,2,3,characterPointer);
    //Prints total health value
    mvwprintw(statusWindow,2,11,"%d",currentInteger);
    currentString = "/";
    currentInteger = player.getMaxHealth();
    mvwprintw(statusWindow,2,14,characterPointer);
    mvwprintw(statusWindow,2,16,"%d",currentInteger);






    return;
}

