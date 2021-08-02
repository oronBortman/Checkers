
#include <FindAllPossiblePlayerMoves.h>
#include <General.h>
#include <List.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>
#include <FindSingleSourceOptimalMove.h>
#include <stdlib.h>

/*
 * typedef struct _multipleSourceMovesListCell {
    SingleSourceMovesList *single_source_moves_list;
    struct _multipleSourceMovesListCell *next;
} MultipleSourceMovesListCell;

typedef struct _multipleSourceMovesList {
    MultipleSourceMovesListCell *head;
    MultipleSourceMovesListCell *tai;
} MultipleSourceMovesList;
 */
MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player)
{
    int r,c;
    char row='0',col='0';
    checkersPos* pos;
    pos = (checkersPos*)malloc(sizeof(checkersPos));
    SingleSourceMovesTree* tree;
    SingleSourceMovesList* lst;
    MultipleSourceMovesList* listOfLists;
    listOfLists = (MultipleSourceMovesList*)malloc(sizeof(MultipleSourceMovesList));
    makeEmptyListOfLists(listOfLists);

    for(r = 0, row='0'; r < BOARD_SIZE; r++,row++)
    {
        for(c = 0,col='0'; c < BOARD_SIZE; c++,col++)
        {
            //Check if player exists in position
            if(board[r][c] == player)
            {
                pos->row=row;
                pos->col=col;
                tree=FindSingleSourceMoves(board,pos);
                if(tree != NULL)
                {
                    lst=FindSingleSourceOptimalMove(tree);
                    insertDataToEndListOfLists(listOfLists,lst);
                }
            }
        }
    }
    return listOfLists;

}