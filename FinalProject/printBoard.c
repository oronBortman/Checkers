#include <printBoard.h>

void printBoard(Board board)
{
    unsigned int r,c,i;
    char letter;
    printLine();
    printf("+ ");
    for(i = 1; i < 9; i++)
    {
        printf("|%d",i);
    }
    printf("|\n");
    printLine();
    for(r = 0,letter='A'; r < BOARD_SIZE; r++,letter++)
    {
        printf("|%c",letter);
        for(c = 0; c < BOARD_SIZE; c++)
        {
            printf("|%c", board[r][c]);
        }

        printf("|\n");
        printLine();
    }
}

void printLine()
{
    int i;
    for(i = 0; i < 9; i++)
    {
        printf("+-");
    }
    printf("+\n");
}

//void printPlayer()

