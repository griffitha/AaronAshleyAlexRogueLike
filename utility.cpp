#include "utility.h"


//Utility Functions CPP

void readLevel(char symbolArray[500][500],character * gameObjectArray[500][500], character &player, int levelNumber)
{
    //File Data Type where the file will be loaded
    std::ifstream levelFile;

    //Sets everything to a pound sign
    for (int i = 0; i < 500; i++)
    {
        for (int q = 0; q < 500; q++)
        {
            symbolArray[i][q] = '#';
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
        case 51:
            levelFile.open("testmap.txt");
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
        for (unsigned int i = 0; i < inputLine.size(); i++)
        {
            //Enter/Exit
            if (inputLine.at(i) == 'E')
            {
                symbolArray[x][y] = 'E';
            }
            //Open Space
            else if (inputLine.at(i) == '-')
            {
                //Designates empty space
                symbolArray[x][y] = ' ';
            }
            else if (inputLine.at(i) == 'p')
            {
                //This clears the spot
                symbolArray[x][y] = ' ';
                player.setXCoordinate(x);
                player.setYCoordinate(y);
            }
            else
            {
                symbolArray[x][y] = '#';
            }
            x++;
        }
        x = 0;
        y++;
    }
    //Close File
    levelFile.close();
    return;
}

void printWindow(char symbolArray[500][500],character * gameObjectArray[500][500], character player, WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{
        int X;
        int Y;
        int playerX = player.getXCoordinate();
        int playerY = player.getYCoordinate();
        X = playerX - 16;
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
                if (symbolArray[X][Y] == ' ' || symbolArray[X][Y] == '-')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,' ');
                }
                if (symbolArray[X][Y] == '^')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_BLOCK);
                }
                else if (symbolArray[X][Y] == '*')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_DIAMOND);
                }
                else if (symbolArray[X][Y] == '#')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_BLOCK);
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

            if (X == (playerX + 16))
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

/*
void playerTurn(char symbolArray[][500], character * gameObjectArray[500][500], character &player)
{
    //Save Player's current position
    int playerX = player.getXCoordinate();
    int playerY = player.getYCoordinate();
    character * playerPointer = &player;
    character * targetPointer;

    int ch = getch();
    //Move Up
    if (ch == KEY_UP)
    {
        //If space is empty
        if (symbolArray[playerX][playerY-1] == ' ')
        {
            //Checks for enemy
            if (gameObjectArray[playerX][playerY-1] != NULL)
            {
                //Battle
                targetPointer = gameObjectArray[playerX][playerY-1];
                meleeAttack(playerPointer,targetPointer);
                //Checks if target is dead
                if (checkDead(targetPointer))
                {
                    //Delete enemy
                    gameObjectArray[playerX][playerY+1] = NULL;
                }
                return;

            }
            //Resets map position to new position and moves
            else
            {
                gameObjectArray[playerX][playerY] = NULL;
                player.moveChar(ch);
                gameObjectArray[playerX][playerY] = &player;
            }
        }
    }
    //Move Down
    else if (ch == KEY_DOWN)
    {
        if (symbolArray[playerX][playerY+1] == ' ')
        {
            //WE GO TO BATTLE
            if (gameObjectArray[playerX][playerY+1] != NULL)
            {
                //Sets enemy pointer
                targetPointer = gameObjectArray[playerX][playerY+1];
                //Attacks
                meleeAttack(playerPointer,targetPointer);
                //If he is dead
                if (checkDead(targetPointer))
                {
                    //Delete
                    gameObjectArray[playerX][playerY+1] = NULL;
                }
                return;

            }
            //Resets map position to new position
            else
            {
                gameObjectArray[playerX][playerY] = NULL;
                player.moveChar(ch);
                gameObjectArray[playerX][playerY] = &player;
            }
        }
    }
    //Move Left
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' ')
        {
            //Battle
            if (gameObjectArray[playerX-1][playerY] != NULL)
            {
                targetPointer = gameObjectArray[playerX-1][playerY];
                meleeAttack(playerPointer,targetPointer);
                if (checkDead(targetPointer))
                {
                    gameObjectArray[playerX-1][playerY] = NULL;
                }
                return;

            }
            //Resets map position to new position
            else
            {
                gameObjectArray[playerX][playerY] = NULL;
                player.moveChar(ch);
                gameObjectArray[playerX][playerY] = &player;
            }
        }
    }
    //Move Right
    else if (ch == KEY_RIGHT)
    {
        //Check if empty
        if (symbolArray[playerX+1][playerY] == ' ')
        {
            //If there is an enemy
            if (gameObjectArray[playerX+1][playerY] != NULL)
            {
                //Fight
                targetPointer = gameObjectArray[playerX+1][playerY];
                meleeAttack(playerPointer,targetPointer);
                //Check if target is dead
                if (checkDead(targetPointer))
                {
                    //Enemy is dead
                    gameObjectArray[playerX+1][playerY] = NULL;
                }
                return;

            }
            //Resets map position to new position and moves
            else
            {
                gameObjectArray[playerX][playerY] = NULL;
                player.moveChar(ch);
                gameObjectArray[playerX][playerY] = &player;
            }
        }
    }
    return;
}
*/

void playerTurn(char symbolArray[][500], std::vector<character> gameObjects, character &player)
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
            player.moveChar(ch);
        }
    }
    //Move Down
    else if (ch == KEY_DOWN)
    {
        if (symbolArray[playerX][playerY+1] == ' ')
        {
            player.moveChar(ch);
        }
    }
    //Move Left
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' ')
        {
            player.moveChar(ch);
        }
    }
    //Move Right
    else if (ch == KEY_RIGHT)
    {
        //Check if empty
        if (symbolArray[playerX+1][playerY] == ' ')
        {
            player.moveChar(ch);
        }
    }
    return;
}

void printStatusWindow(character &player, WINDOW * statusWindow)
{
    //Prints player name on first line
    std::string currentString = player.getCharacterName();
    int currentInteger = player.getLevel();
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

