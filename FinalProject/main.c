//#define _CRT_SECURE_NO_WARNINGS
//Maissa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <createBoard.h>
#include <printBoard.h>
#include <General.h>
#include <TestingFindAllPossiblePlayerMoves.h>
#include <Tree.h>
#include <StoreBoard.h>
#include <Turn.h>
#include <LoadBoard.h>
#include <StoreBoard.h>
#include <PlayGame.h>
//Define Functions

/*SingleSourceMovesList *FindSingleSourceOptimalMove(SingleSourceMovesTree *moves_tree); //2
MultipleSourceMovesList *FindAllPossiblePlayerMoves(Board board, Player player); //3
void Turn(Board board, Player player); //4
void StorBoard(Board board, char *filename); //5
void LoadBoard(char *filename, Board board); //6
void PlayGame(Board board, Player starting_player); //7*/

void main()
{

    Board board;
    createBoard(board);

    //Problem that Player two stuck on H5->H5
    /*board[1][2]=SYMBOL;
    board[1][4]=SYMBOL;
    board[1][6]=SYMBOL;
    board[2][1]=SYMBOL;
    board[2][5]=BOTTOM_PLAYER;
    board[2][7]=SYMBOL;
    board[3][4]=BOTTOM_PLAYER;
    board[5][2]=SYMBOL;
    board[5][6]=SYMBOL;
    board[7][6]=SYMBOL;
*/
    //Prolbem Top player doesnt eat
    /*board[0][3]=SYMBOL;
    board[1][0]=SYMBOL;
    board[1][2]=BOTTOM_PLAYER;
    board[1][4]=SYMBOL;
    board[1][6]=SYMBOL;
    board[2][1]=SYMBOL;
    board[2][3]=SYMBOL;
    board[2][5]=BOTTOM_PLAYER;
    board[2][7]=SYMBOL;

    board[5][2]=SYMBOL;

    board[6][3]=SYMBOL;

    board[6][7]=SYMBOL;
    board[7][7]=SYMBOL;*/





    PlayGame(board,TOP_PLAYER);
    //printBoard(board);
    //StoreBoard(board);
    //LoadBoard("board.bin",boardA);
    //Turn(board,TOP_PLAYER);
    //printBoard(boardA);
    //Turn(board,BOTTOM_PLAYER);
    //printBoard(board);

    // printBoard(board);
}