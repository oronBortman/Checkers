
#include <General.h>
#include <StoreBoard.h>
#include <stdio.h>
#include <stdlib.h>
#include <LoadBoard.h>
#include <File.h>
#include <Turn.h>
#include <FindSingleSourceMoves.h>
#include <PlayGame.h>
#include <printBoard.h>

/*
 The function PlayGame starts the game.
 The computer plays against itself. Each turn it checks which is the best move and plays it.
 */
void PlayGame(Board board, Player starting_player)
{
    char currPlayer, otherPlayer;

    for ( int i = 0; i < 50; i++ ) // 50 is arbitrary
        printf("\n");

    printBoard(board);

    if(starting_player==TOP_PLAYER)
    {
        currPlayer=TOP_PLAYER;
        otherPlayer=BOTTOM_PLAYER;
    }
    else if(starting_player==BOTTOM_PLAYER)
    {
        currPlayer=BOTTOM_PLAYER;
        otherPlayer=TOP_PLAYER;
    }
    StoreBoard(board);
    while(!endGame(board,currPlayer))
    {
        if(!endGame(board,currPlayer))
        {
            LoadBoard("board.bin",board);
            Turn(board,currPlayer);
            StoreBoard(board);
        }

        if(!endGame(board,otherPlayer))
        {
            LoadBoard("board.bin",board);
            Turn(board,otherPlayer);
            StoreBoard(board);
        }

        else
        {
            return;
        }
    }
}

/*
    The function endGame Checks the following:
    If one of the player runout of player tools
    If TOP_PLAYER reached to row H
    if BOTTOM_PLAYER reached to row A
 */
BOOL endGame(Board board, Player player)
{


    if(checkIfPlayerRunOutOfTools(board,player) || checkIfTopReachedToBottom(board) || checkIfBottomReachedToTop(board))
        return TRUE;
    else
        return FALSE;
}

/*
 The function checkIfPlayerRunOutOfTools checks if a player run out of tools in the playing board
 */
BOOL checkIfPlayerRunOutOfTools(Board board, Player player)
{
    int r,c;
    for(r = 0; r < BOARD_SIZE; r++)
    {
        for(c = 0; c < BOARD_SIZE; c++)
        {
            if(board[r][c]==player)
                return FALSE;
        }
    }
    return TRUE;
}

/*
 The function checkIfTopReachedToBottom checks if the top player reached to the bottom of the board
 */

BOOL checkIfTopReachedToBottom(Board board)
{
    int c;
    for(c = 0; c < BOARD_SIZE; c++)
    {
        if(board[7][c] == TOP_PLAYER)
            return TRUE;
    }
    return FALSE;
}

/*
 The function checkIfBottomReachedToTop checks if the bottom player reached to the top of the board
 */

BOOL checkIfBottomReachedToTop(Board board)
{
    int c;
    for(c = 0; c < BOARD_SIZE; c++)
    {
        if(board[0][c] == BOTTOM_PLAYER)
            return TRUE;
    }
    return FALSE;
}
