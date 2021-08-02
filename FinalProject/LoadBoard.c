#include <General.h>
#include <StoreBoard.h>
#include <stdio.h>
#include <stdlib.h>
#include <LoadBoard.h>
#include <File.h>


void LoadBoard(char *filename, Board board)
{
    FILE *fp;
    unsigned char bits[16];
    int r,c,j,b;
    unsigned char ch1, ch2, tempChar;

    // reading to File:
    fp = fopen(filename, "rb");
    checkFile(fp);

    fread(bits, sizeof(unsigned char), 16, fp);


    for(r = 0,b = 0; r < BOARD_SIZE; r++,b=b+2)
    {
        ch1=bits[b];
        ch2=bits[b+1];
        for(c = 0,j=1; c < BOARD_SIZE/2; c++,j=j+2)
        {
            tempChar=ch1<<(j-1);
            tempChar=tempChar>>(BOARD_SIZE-2);
            if(tempChar == 1)
            {
                board[r][c]=TOP_PLAYER;
            }
            else if(tempChar == 2)
            {
                board[r][c]=BOTTOM_PLAYER;

            }
            else if(tempChar == 0)
            {
                board[r][c]=SYMBOL;
            }
        }
        for(c = BOARD_SIZE/2,j=1; c < BOARD_SIZE; c++,j=j+2)
        {
            tempChar=ch2<<(j-1);
            tempChar=tempChar>>(BOARD_SIZE-2);

            if(tempChar == 1)
            {
                board[r][c]=TOP_PLAYER;
            }
            else if(tempChar == 2)
            {
                board[r][c]=BOTTOM_PLAYER;

            }
            else if(tempChar == 0)
            {
                board[r][c]=SYMBOL;
            }
        }
    }
    fclose(fp);

}