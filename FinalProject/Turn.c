
#include <General.h>
#include <stdlib.h>
#include <stdio.h>
#include <List.h>
#include <Tree.h>
#include <FindAllPossiblePlayerMoves.h>
#include <printBoard.h>
#include <Turn.h>
#include <curses.h>
#include <unistd.h>

void Turn(Board board, Player player)
{
    SingleSourceMovesListCell* currL=NULL; //single List
    SingleSourceMovesList turnList; //Selected list
    MultipleSourceMovesListCell* currLol; //Multiple list cell
    MultipleSourceMovesList* listOfLists; //Multiple list
    unsigned short maxCaptures=0,currListCaptures;
    char currPlayer;
    int firstCol,firstRow,secondCol,secondRow,moveCol,moveRow;
    makeEmptyList(&turnList);
  //  makeEmptyListOfLists(listOfLists);
    listOfLists=FindAllPossiblePlayerMoves(board,player);
    if(listOfLists->head==NULL)
    {
        return;
    }
    currLol=listOfLists->head;

    //Find the best route
    if(player==TOP_PLAYER)
        currPlayer=TOP_PLAYER;
    else if(player==BOTTOM_PLAYER)
        currPlayer=BOTTOM_PLAYER;

        while (currLol != NULL)
        {
            currListCaptures = currLol->single_source_moves_list->tail->captures;

            if (currListCaptures >= maxCaptures && currLol->single_source_moves_list->head->next != NULL)
            {
                maxCaptures = currListCaptures;
                turnList = *(currLol->single_source_moves_list);
            }
            currLol = currLol->next;
        }

        //Make the turn
        if(turnList.head != NULL && turnList.head->next != NULL)
            currL = turnList.head;
        else
            return;
        while (currL->next != NULL)
        {
            firstCol=currL->position->col - '0';
            firstRow=currL->position->row - '0';
            secondCol=currL->next->position->col - '0';
            secondRow=currL->next->position->row - '0';

            //Check if next turn is without eating
            if(currL->next->captures == 0)
            {
                board[firstRow][firstCol] = SYMBOL;
                board[secondRow][secondCol] = currPlayer;
            }
            //Check if next turn is with eating
            else if(currL->next->captures >= 1)
            {
                moveCol=(secondCol - firstCol) / 2;
                moveRow=(secondRow - firstRow) / 2;
                board[firstRow][firstCol] = SYMBOL;
                board[firstRow+moveRow][firstCol+moveCol] = SYMBOL;
                board[secondRow][secondCol] = currPlayer;
            }
            currL=currL->next;
        }

    firstCol=turnList.head->position->col+1;
    firstRow=turnList.head->position->row+17;
    secondCol=turnList.tail->position->col+1;
    secondRow=turnList.tail->position->row+17;
    sleep(2);
    if(player==TOP_PLAYER)
    {
        printf("player TOP_DOWN's turn\n");
    }
    else if(player==BOTTOM_PLAYER)
    {
        printf("player BOTTOM_UP's turn\n");
    }
    printf("%c%c->%c%c\n",firstRow,firstCol,secondRow,secondCol);
    clearscr();
    printBoard(board);
    //Free to the list of lists and all the lists inside of it
    freeListOfLists(listOfLists);
}

void clearscr ( )
{
    for ( int i = 0; i < 50; i++ ) // 50 is arbitrary
        printf("\n");
}