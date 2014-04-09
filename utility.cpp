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
<<<<<<< HEAD
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
=======
        getline(levelFile,inputLine);
        for (int i = 0; i < inputLine.size(); i++)
>>>>>>> origin/Ashley
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

<<<<<<< HEAD
void printWindow(char symbolArray[][500],character * gameObjectArray[500][500], WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{

    while(1)
    {
        int arrayX = 0;
        int arrayY = 0;
=======
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
>>>>>>> origin/Ashley
        //Sets up the map

        while (mapCreated != true)
        {
            //Checks to make sure it isnt out of bounds
            if (((X >= 0) && (X < 500)) && ((Y >= 0) && (Y <500)))
            {
                if (symbolArray[X][Y] != ' ')
                {
                    //Makes everything a block
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_DIAMOND);
                }
                else if (symbolArray[X][Y] == '^')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_DIAMOND);
                }
                else
                {
                    mvwaddch(workingWindow,yCounter,xCounter,symbolArray[X][Y]);
                }
            }

            else
            {
                //If out of bounds, make it a block
                mvwaddch(workingWindow,yCounter,xCounter,ACS_DIAMOND);
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
            }
        }

    mvwaddch(workingWindow,11,15,player.getMapRep());
    wrefresh(workingWindow);
    wclear(workingWindow);
    wrefresh(statusWindow);
    wrefresh(message);
    return;
}

<<<<<<< HEAD
=======
void playerTurn(char symbolArray[][500], character * gameObjectArray[500][500], character &player)
{
    //Save Player's current position
    int playerX = player.getXCoordinate();
    int playerY = player.getYCoordinate();

    int ch = getch();
    if (ch == KEY_UP)
    {
        if (symbolArray[playerX][playerY-1] == ' ')
        {
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    else if (ch == KEY_DOWN)
    {
        if (symbolArray[playerX][playerY+1] == ' ')
        {
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' ')
        {
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
    }
    else if (ch == KEY_RIGHT)
    {
        if (symbolArray[playerX+1][playerY] == ' ')
        {
            gameObjectArray[playerX][playerY] = NULL;
            player.moveChar(ch);
            gameObjectArray[playerX][playerY] = &player;
        }
>>>>>>> origin/Ashley
    }
    return;
}
