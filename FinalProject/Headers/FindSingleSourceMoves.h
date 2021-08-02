#pragma once
#include <General.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src);
SingleSourceMovesTreeNode* checkMoveOfTopPlayerRec(Board board,char posRow,char posCol, unsigned short totalCapturesSoFar);
SingleSourceMovesTreeNode* checkMoveOfBottomPlayerRec(Board board,char posRow,char posCol, unsigned short totalCapturesSoFar);
BOOL checkIfReachToEndOfBoard(int row);
BOOL checkIfReachToTopOfBoard(int row);
void copyBoard(Board sourceBoard, Board destBoard);
//Check if reached to the right end of the board
BOOL checkIfReachToRightEndOfBoard(int col);
//Check if reached to the left end of the board
BOOL checkIfReachToLeftEndOfBoard(int col);