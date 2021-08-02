#pragma once

#include <General.h>
//SingleSourceMovesListCell;
//SingleSourceMovesList;


/*typedef struct _SingleSourceMovesTreeNode{
    Board board;
    checkersPos *pos;
    unsigned short total_captures_so_far;
    struct _SingleSourceMovesTreeNode  *next_move[2];
} SingleSourceMovesTreeNode;

typedef struct _SingleSourceMovesTree {
    SingleSourceMovesTreeNode *source;
} SingleSourceMovesTree;

typedef struct _SingleSourceMovesListCell {
    checkersPos *position;
    unsigned short captures;
    struct _SingleSourceMovesListCell *next;
} SingleSourceMovesListCell;

typedef struct _SingleSourceMovesList {
    SingleSourceMovesListCell *head;
    SingleSourceMovesListCell *tail;
} SingleSourceMovesList;*/

void makeEmptyList(SingleSourceMovesList* lst);
void insertDataToEndList(SingleSourceMovesList* lst, checkersPos position, unsigned short captures);
SingleSourceMovesListCell* createNewListNode(checkersPos position, unsigned short captures, SingleSourceMovesListCell* next);
void insertNodeToEndList(SingleSourceMovesList* lst, SingleSourceMovesListCell * newTail);
int isEmptyList(const SingleSourceMovesList* lst);
void insertDataToEndListOfLists(MultipleSourceMovesList* lstOfLists, SingleSourceMovesList* lst);
MultipleSourceMovesListCell* createNewListOfListsNode(SingleSourceMovesList* lst, MultipleSourceMovesListCell* next);
void insertNodeToEndListOfLists(MultipleSourceMovesList* lst, MultipleSourceMovesListCell * newTail);
int isEmptyListOfLists(const MultipleSourceMovesList* lst);
void makeEmptyListOfLists(MultipleSourceMovesList* lst);
void freeListOfLists(MultipleSourceMovesList* lol);
void freeList(SingleSourceMovesList* list);