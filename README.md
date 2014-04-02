AaronAshleyAlexRogueLike
========================
void printWindow(char symbolArray[][1000], WINDOW * workingWindow, WINDOW * statusWindow, WINDOW * message)
{
    int x = 10;
    int y = 10;
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

        int newX; //added by Ashley
        int newY; //added by Ashley

        ch = wgetch(workingWindow);

        if (ch == KEY_DOWN)
        {
            newY = y + 1; //added by Ashley
            if(symbolArray[x][newY] == ' ') //added by Ashley
            { //added by Ashley
                y++;
                wclear(workingWindow);
            } //added by Ashley

        }
        if (ch == KEY_UP)
        {
            newY = y - 1; //added by Ashley
            if(symbolArray[x][newY] == ' ') //added by Ashley) //added by Ashley
            { //added by Ashley
                y--;
                wclear(workingWindow);
            } //added by Ashley

        }
        if (ch == KEY_LEFT)
        {
            newX = x - 1; //added by Ashley
            if(symbolArray[newX][y] == ' ') //added by Ashley
            { //added by Ashley
                x--;
                wclear(workingWindow);
            } //added by Ashley
        }
        if (ch == KEY_RIGHT)
        {
            newX = x + 1; //added by Ashley
            if(symbolArray[newX][y] == ' ') //added by Ashley
            { //added by Ashley
               x++;
               wclear(workingWindow);
            } //added by Ashley

        }
          //refreshes window

        wrefresh(workingWindow);
        wrefresh(statusWindow);
        wrefresh(message);
    }
    return;
}
