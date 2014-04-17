#include "utility.h"


//Utility Functions CPP

void readLevel(char symbolArray[500][500],std::vector<character> gameObjects, character &player, int levelNumber)
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

        case 3:
            levelFile.open("level3.txt");
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
            //Found player starting position
            else if (inputLine.at(i) == 'p' || inputLine.at(i) == 'P')
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

void printWindow(char symbolArray[500][500],std::vector<character> gameObjects, character player, WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
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
                else if (symbolArray[X][Y] == 'E')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,'E');
                }
                else if (symbolArray[X][Y] == '^')
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

void playerTurn(char symbolArray[][500], std::vector<character> gameObjects, character &player)
{
    //Save Player's current position
    int playerX = player.getXCoordinate();
    int playerY = player.getYCoordinate();

    int ch = getch();
    //Move Up
    if (ch == KEY_UP)
    {
        if (symbolArray[playerX][playerY-1] == ' ' || symbolArray[playerX][playerY-1] == '*')
        {
            player.moveChar(ch);
        }
        else if (symbolArray[playerX][playerY-1] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 1;
            readLevel(symbolArray,gameObjects,player,randomLevel);
        }
    }
    //Move Down
    else if (ch == KEY_DOWN)
    {
        if (symbolArray[playerX][playerY+1] == ' '|| symbolArray[playerX][playerY+1] == '*')
        {
            player.moveChar(ch);
        }
        else if(symbolArray[playerX][playerY+1] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 1;
            readLevel(symbolArray,gameObjects,player,randomLevel);
        }
    }
    //Move Left
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' ' || symbolArray[playerX-1][playerY] == '*')
        {
            player.moveChar(ch);
        }
        else if (symbolArray[playerX-1][playerY] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 1;
            readLevel(symbolArray,gameObjects,player,randomLevel);
        }
    }
    //Move Right
    else if (ch == KEY_RIGHT)
    {
        //Check if empty
        if (symbolArray[playerX+1][playerY] == ' ' || symbolArray[playerX+1][playerY] == '*')
        {
            player.moveChar(ch);
        }
        else if (symbolArray[playerX+1][playerY] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 1;
            readLevel(symbolArray,gameObjects,player,randomLevel);
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

    //Prints Armor value
    currentString = "Armor: ";
    currentInteger = player.getArmor();
    mvwprintw(statusWindow,3,3,characterPointer);
    mvwprintw(statusWindow,3,11,"%d",currentInteger);

    //Prints X coordinate
    currentString = "X:";
    currentInteger = player.getXCoordinate();
    mvwprintw(statusWindow,0,28,characterPointer);
    mvwprintw(statusWindow,0,31,"%d",currentInteger);

    //Prints Y coordinate
    currentString = "Y:";
    currentInteger = player.getYCoordinate();
    mvwprintw(statusWindow,1,28,characterPointer);
    mvwprintw(statusWindow,1,31,"%d",currentInteger);

    return;
}

player playerCreation()
{
    player returnedPlayer(0,0);
    std::string userInput;
    std::string playerClass;
    std::string playerRace;
    int userNumber;
    bool playerIsReady = false;

    //While player is not ready
    while (!playerIsReady)
    {
        //Set Name
        std::cout << "What is your name?" << std::endl;
        std::cin >> userInput;
        returnedPlayer.setCharacterName(userInput);

        //Set Gender
        std::cout << std::endl << "What is your gender? Press 1 for Male, Press 2 for Female." << endl;
        std::cin >> userNumber;
        if (userNumber == 1)
        {
            //Set to Male
            returnedPlayer.setGender('M');
        }
        else
        {
            //Set to Female
            returnedPlayer.setGender('F');
        }

        //Set Class
        std::cout << std::endl << "What do you want your class to be?" << std::endl;
        std::cout << "1. Warrior" << std::endl;
        std::cout << "2. Mage" << std::endl;
        std::cout << "3. Ranger" << std::endl;
        std::cin >> userNumber;
        if (userNumber == 1)
        {
            //We can set more default values now
            returnedPlayer.setClass(warrior);
            playerClass = "Warrior";
        }
        else if (userNumber == 2)
        {
            returnedPlayer.setClass(mage);
            playerClass = "Mage";
        }
        else
        {
            returnedPlayer.setClass(ranger);
            playerClass = "Ranger";
        }

        //Set Race
        std::cout << std::endl << "What do you want your race to be?" << std::endl;
        std::cout << "1. Human" << std::endl;
        std::cout << "2. Orc" << std::endl;
        std::cout << "3. Goblin" << std::endl;
        std::cout << "4. Elf" << std::endl;
        std::cout << "5. Dwarf" << std::endl;
        std::cin >> userNumber;
        if (userNumber == 1)
        {
            returnedPlayer.setRace(Human);
            playerRace = "Human";
        }
        else if (userNumber == 2)
        {
            returnedPlayer.setRace(Orc);
            playerRace = "Orc";
        }
        else if (userNumber == 3)
        {
            returnedPlayer.setRace(Goblin);
            playerRace = "Goblin";
        }
        else if (userNumber == 4)
        {
            returnedPlayer.setRace(Elf);
            playerRace = "Elf";
        }
        else
        {
            returnedPlayer.setRace(Dwarf);
            playerRace = "Dwarf";
        }

        //Confirmation from the user.
        std::cout << "You are " << returnedPlayer.getCharacterName() << " the " << playerRace << " " <<
            playerClass << "." << std::endl;
        std::cout << "Is this what you want? Yes or No." << std::endl;
        cin >> userInput;
        if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y")
        {
            playerIsReady = true;
        }
        else
        {
            playerIsReady = false;
        }
    }
    return returnedPlayer;
}
