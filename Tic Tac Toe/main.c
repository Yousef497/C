#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

char square[10] = { '0','1','2','3','4','5','6','7','8','9' };
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;

    player = 1;

    do
    {
        displayBoard();

        // Change turns
        player = (player % 2) ? 1 : 2;

        // Get Inputs
        printf("\tPlayer %d, enter a number: ", player);
        scanf_s("%d", &choice);

        // Set the correct character based on player turn
        mark = (player == 1) ? 'X' : 'O';

        // set board based on user choice or invalid choice
        markBoard(mark);

        gameStatus = checkForWin();

        player++;

    } while (gameStatus == -1);

    if (gameStatus == 1) {
        printf("\t==>Player %d wins\n", --player);
    }
    else {
        printf("\t==>Game draw\n");
    }

    Sleep(5000);

    return 0;
}

/***********************
Function to return game status
1 For game is over with result
-1 For game is in progress
0 For game is over and no result
***********************/

int checkForWin()
{
    int returnValue;

    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;

    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;

    else
        returnValue = -1;

    return returnValue;
}

/*******************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYER MARKS
*******************************************************/

void displayBoard()
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");
    printf("\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t      |      |      \n");
    printf("\t  %c   |  %c   |  %c  \n", square[1], square[2], square[3]);

    printf("\t______|______|______\n");
    printf("\t      |      |      \n");

    printf("\t  %c   |  %c   |  %c  \n", square[4], square[5], square[6]);

    printf("\t______|______|______\n");
    printf("\t      |      |      \n");

    printf("\t  %c   |  %c   |  %c  \n", square[7], square[8], square[9]);
    printf("\t      |      |      \n\n");
}

/****************************************************************************
FUNCTION TO SET THE BOARD WITH MARKS X OR O IN THE CORRECT SPOT IN THE ARRAY
****************************************************************************/
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;

    else {
        printf("Invalid move ");

        player--;
        _getch();
    }
}
