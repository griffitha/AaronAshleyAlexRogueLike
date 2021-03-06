#include "utility.h"


//Utility Functions CPP

void readLevel(char symbolArray[500][500],vector<character> &gameObjects, vector<enemy> &enemyList,vector<Location> &possibleLocations, player &thePlayer, int levelNumber,
               vector <Consumable> consumableVector, vector <Armor> armorVector, vector <Weapon> weaponVector)
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

    //If there are objects in the array, clear them
    gameObjects.clear();
    //Clears enemies from map
    enemyList.clear();

    possibleLocations.clear();

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

        case 4:
            levelFile.open("level4.txt");
            break;

        case 50:
            levelFile.open("SokabanLevel.txt");
            break;

        case 51:
            levelFile.open("testmap.txt");
            break;
        case 52:
            levelFile.open("easySokabanLevel.txt");
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
                thePlayer.setXCoordinate(x);
                thePlayer.setYCoordinate(y);
            }
            else if (inputLine.at(i) == 'B' || inputLine.at(i) == 'b' || inputLine.at(i) == 'O' || inputLine.at(i) == 'o')
            {
                if (inputLine.at(i) == 'B' || inputLine.at(i) == 'b')
                {
                    //Creates a Boulder and a Button
                    interactiveObject newRock(x,y);
                    newRock.setRockAttributes();
                    gameObjects.push_back(newRock);
                    symbolArray[x][y] = 'O';
                }
                else
                {
                    //Simply creates a button
                    symbolArray[x][y] = 'O';
                }
            }
            else if (inputLine.at(i) == 'R' || inputLine.at(i) == 'r')
            {
                //Creates a Boulder
                interactiveObject newRock(x,y);
                newRock.setRockAttributes();
                gameObjects.push_back(newRock);
                symbolArray[x][y] = ' ';
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

    int spaceCounter = 0;
    for(int x = 0; x < 500; x++)
    {
        for(int y = 0; y < 500; y++)
        {
            if(symbolArray[x][y] == ' ')
            {
                if(symbolArray[x][y+1] == ' ' && symbolArray[x][y-1] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possibleLocations.push_back(newLocation);
                }
                if(symbolArray[x+1][y] == ' ' && symbolArray[x-1][y] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possibleLocations.push_back(newLocation);
                }
            }
        }
    }

    /*int itemsNeeded = 0;
    itemsNeeded =  numOfItems(symbolArray,possibleLocations);

    for(int i = 0; i < itemsNeeded; i++)
    {
        itemChoice(thePlayer,consumableVector,armorVector,weaponVector,
                    healthPotionVector,magicPotionVector,
                    leatherArmorVector,metalArmorVector,crystalArmorVector,
                    daggerVector, clubVector,heavyMaceVector,spearVector,
                    heavyCrossBowVector, lightCrossBowVector,battleaxeVector,longBowVector);
    }
*/
    matchItemWithPosition(symbolArray,possibleLocations,consumableVector,armorVector,weaponVector);
    positions(symbolArray,consumableVector,armorVector,weaponVector,possibleLocations);


    int enemiesNeeded = numOfEnemies(symbolArray,possibleLocations);
    enemyList=spawnEnemies(symbolArray,possibleLocations,enemiesNeeded,thePlayer);
    return;
}

void printWindow(char symbolArray[][500],std::vector<character> gameObjects,std::vector<enemy> enemyList, player thePlayer, WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message,Equipped playerEquipped)
{
        int X;
        int Y;
        int playerX = thePlayer.getXCoordinate();
        int playerY = thePlayer.getYCoordinate();
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
                else if (symbolArray[X][Y] == 'c' || symbolArray[X][Y] == 'a' || symbolArray[X][Y] == 'w')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,ACS_DIAMOND);
                }
                else if (symbolArray[X][Y] == 'O')
                {
                    mvwaddch(workingWindow,yCounter,xCounter,'O');
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

            //This will print any objects that are available
            if (gameObjects.size() > 0 || enemyList.size() > 0)
            {
                printObjects(X,Y,xCounter,yCounter,symbolArray,gameObjects,enemyList,thePlayer,workingWindow);
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
    printStatusWindow(thePlayer,statusWindow,playerEquipped);

    mvwaddch(workingWindow,11,15,thePlayer.getMapRep());
    wrefresh(workingWindow);
    wrefresh(statusWindow);
    wrefresh(message);
    wclear(workingWindow);
    return;
}

void playerTurn(char symbolArray[][500], std::vector<character> &gameObjects,std::vector<enemy> &enemyList,std::vector<Location> possibleLocations, player &thePlayer,
                vector <Consumable> consumableVector, vector <Armor> armorVector, vector <Weapon> weaponVector)
{
    //Save Player's current position
    int playerX = thePlayer.getXCoordinate();
    int playerY = thePlayer.getYCoordinate();
    character * targetObject = NULL;
    bool openSpace = true;
    int ch = getch();
    //Move Up
    if (ch == KEY_UP)
    {
        //If there is a movable spot
        if (symbolArray[playerX][playerY-1] == ' '|| symbolArray[playerX][playerY-1] == 'c' ||
            symbolArray[playerX][playerY-1] == 'a' || symbolArray[playerX][playerY-1] == 'w' ||
            symbolArray[playerX][playerY-1] == 'O')

        {
            //Checks for object
            openSpace = checkEmpty(playerX,playerY-1,gameObjects,enemyList);
            if (!openSpace)
            {
                //If there, do something about it.
                basicInteraction(ch,playerX,playerY-1,gameObjects,enemyList,thePlayer,symbolArray);
            }
            else if (openSpace)
            {
                thePlayer.moveChar(ch);
            }
        }

        else if (symbolArray[playerX][playerY-1] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 2;

            readLevel(symbolArray,gameObjects,enemyList,possibleLocations,thePlayer,1,consumableVector,armorVector,weaponVector);
            positions(symbolArray,consumableVector,armorVector,weaponVector,possibleLocations);
            matchItemWithPosition(symbolArray,possibleLocations,consumableVector,armorVector,weaponVector);
        }
    }
    //Move Down
    else if (ch == KEY_DOWN)
    {
        //Checks for the different open spaces
        if (symbolArray[playerX][playerY+1] == ' '|| symbolArray[playerX][playerY+1] == 'c' ||
            symbolArray[playerX][playerY+1] == 'a' || symbolArray[playerX][playerY+1] == 'w' ||
            symbolArray[playerX][playerY+1] == 'O')

        {
            //Checks if there is an open space
            openSpace = checkEmpty(playerX,playerY+1,gameObjects,enemyList);
            if (!openSpace)
            {
                //If there is something, let's do something with it
                basicInteraction(ch,playerX,playerY+1,gameObjects,enemyList,thePlayer,symbolArray);
            }
            else if (openSpace)
            {
                thePlayer.moveChar(ch);
            }
        }
        else if(symbolArray[playerX][playerY+1] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 2;

            readLevel(symbolArray,gameObjects,enemyList,possibleLocations,thePlayer,3,consumableVector,armorVector,weaponVector);
            matchItemWithPosition(symbolArray,possibleLocations,consumableVector,armorVector,weaponVector);
            positions(symbolArray,consumableVector,armorVector,weaponVector,possibleLocations);
        }
    }
    //Move Left
    else if (ch == KEY_LEFT)
    {
        if (symbolArray[playerX-1][playerY] == ' '|| symbolArray[playerX-1][playerY] == 'c' ||
            symbolArray[playerX-1][playerY] == 'a' || symbolArray[playerX-1][playerY] == 'w' ||
            symbolArray[playerX-1][playerY] == 'O')

        {
            //Checks if it was opened
            openSpace = checkEmpty(playerX-1,playerY,gameObjects,enemyList);
            if (!openSpace)
            {
                //Do something to do the object
                basicInteraction(ch,playerX-1,playerY,gameObjects,enemyList,thePlayer,symbolArray);
            }
            else if (openSpace)
            {
                thePlayer.moveChar(ch);
            }
        }
        else if (symbolArray[playerX-1][playerY] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 2;


            readLevel(symbolArray,gameObjects,enemyList,possibleLocations,thePlayer,2,consumableVector,armorVector,weaponVector);
            matchItemWithPosition(symbolArray,possibleLocations,consumableVector,armorVector,weaponVector);
            positions(symbolArray,consumableVector,armorVector,weaponVector,possibleLocations);
        }
    }
    //Move Right
    else if (ch == KEY_RIGHT)
    {
        //Check if the spot is empty
        if (symbolArray[playerX+1][playerY] == ' '|| symbolArray[playerX+1][playerY] == 'c' ||
            symbolArray[playerX+1][playerY] == 'a' || symbolArray[playerX+1][playerY] == 'w' ||
            symbolArray[playerX+1][playerY] == 'O')

        {
            //Check if empty of enemies
            openSpace = checkEmpty(playerX+1,playerY,gameObjects,enemyList);
            if (!openSpace)
            {
                //Do something to the object
                basicInteraction(ch,playerX+1,playerY,gameObjects,enemyList,thePlayer,symbolArray);
            }
            else if (openSpace)
            {
                //otherwise, move
                thePlayer.moveChar(ch);
            }
        }
        else if (symbolArray[playerX+1][playerY] == 'E')
        {
            //Level Transistion
            int randomLevel = (rand() % 3) + 2;

            readLevel(symbolArray,gameObjects,enemyList,possibleLocations,thePlayer,4,consumableVector,armorVector,weaponVector);
            matchItemWithPosition(symbolArray,possibleLocations,consumableVector,armorVector,weaponVector);
            positions(symbolArray,consumableVector,armorVector,weaponVector,possibleLocations);
        }
    }
    else if (ch == 'R' || ch == 'r')
    {
        thePlayer.rest();
    }
    return;
}

void printStatusWindow(player &thePlayer, WINDOW * statusWindow,Equipped playerEquipped)
{
    wclear(statusWindow);
    //Prints player name on first line
    std::string currentString = thePlayer.getCharacterName();
    int currentInteger = thePlayer.getLevel();
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
    characterPointer = &currentString.at(0);
    currentInteger = thePlayer.getHealth();
    mvwprintw(statusWindow,2,3,characterPointer);

    //Prints total health value
    mvwprintw(statusWindow,2,11,"%d",currentInteger);
    currentString = "/";
    characterPointer = &currentString.at(0);
    currentInteger = thePlayer.getMaxHealth();
    mvwprintw(statusWindow,2,14,characterPointer);
    mvwprintw(statusWindow,2,16,"%d",currentInteger);

    //Prints Armor value
    currentString = "Armor: ";
    currentInteger = thePlayer.getArmor();
    characterPointer = &currentString.at(0);
    mvwprintw(statusWindow,3,3,characterPointer);
    mvwprintw(statusWindow,3,11,"%d",currentInteger);

    //Prints Damage
    currentString = "Damage: ";
    characterPointer = &currentString.at(0);
    currentInteger = thePlayer.getBaseDamage();
    mvwprintw(statusWindow,4,28,characterPointer);
    mvwprintw(statusWindow,4,31,"%d",currentInteger);

    //Prints X coordinate
    currentString = "X:";
    currentInteger = thePlayer.getXCoordinate();
    characterPointer = &currentString.at(0);
    mvwprintw(statusWindow,0,28,characterPointer);
    mvwprintw(statusWindow,0,31,"%d",currentInteger);

    //Prints Y coordinate
    currentString = "Y:";
    characterPointer = &currentString.at(0);
    currentInteger = thePlayer.getYCoordinate();
    mvwprintw(statusWindow,1,28,characterPointer);
    mvwprintw(statusWindow,1,31,"%d",currentInteger);

    //Prints current Experience
    currentString = "EXP: ";
    characterPointer = &currentString.at(0);
    currentInteger = thePlayer.getExperience();
    mvwprintw(statusWindow,2,28,characterPointer);
    mvwprintw(statusWindow,2,32,"%d",currentInteger);

    playerEquipped.printEquipped(statusWindow);

    wrefresh(statusWindow);
    return;
}

player playerCreation()
{
    player returnedPlayer(0,0);
    returnedPlayer.setMapRep('X');
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

void printObjects(int X, int Y, int xCounter, int yCounter, char symbol[][500], std::vector<character> gameObjects,
                  std::vector<enemy> enemyList, player thePlayer, WINDOW * workingWindow)
{
    //Prints any objects on the map
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {
        character currentObject = gameObjects.at(i);
        if (currentObject.getXCoordinate() == X && currentObject.getYCoordinate() == Y)
        {
            mvwaddch(workingWindow,yCounter,xCounter,currentObject.getMapRep());
        }
    }

    //Prints any enemies on the map
    for (unsigned int i = 0; i < enemyList.size(); i++)
    {
        enemy currentEnemy = enemyList.at(i);
        if (currentEnemy.getXCoordinate() == X && currentEnemy.getYCoordinate() == Y)
        {
            mvwaddch(workingWindow,yCounter,xCounter,currentEnemy.getMapRep());
        }
    }

    return;
}
