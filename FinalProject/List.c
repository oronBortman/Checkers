#include <stdlib.h>
#include <General.h>
#include <List.h>

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
} SingleSourceMovesList;
 typedef struct _multipleSourceMovesListCell {
    SingleSourceMovesList *single_source_moves_list;
    struct _multipleSourceMovesListCell *next;
} MultipleSourceMovesListCell;

typedef struct _multipleSourceMovesList {
    MultipleSourceMovesListCell *head;
    MultipleSourceMovesListCell *tai;
} MultipleSourceMovesList;*/

void makeEmptyList(SingleSourceMovesList* lst)
{
    (*lst).head = (*lst).tail = NULL;
}

void insertDataToEndList(SingleSourceMovesList* lst, checkersPos position, unsigned short captures)
{
    SingleSourceMovesListCell* newTail;

    newTail = createNewListNode(position, captures, NULL);
    insertNodeToEndList(lst, newTail);
}

SingleSourceMovesListCell* createNewListNode(checkersPos position, unsigned short captures, SingleSourceMovesListCell* next)
{
    SingleSourceMovesListCell* res;

    res = (SingleSourceMovesListCell*)malloc(sizeof(SingleSourceMovesListCell));
    //checkAlloc(res);
    res->position = (checkersPos*)malloc(sizeof(checkersPos));
    res->position->row=position.row;
    res->position->col=position.col;
    res->captures = captures;
    res->next = next;

    return res;
}

void insertNodeToEndList(SingleSourceMovesList* lst, SingleSourceMovesListCell * newTail) {
    newTail->next = NULL;

    if (isEmptyList(lst))
    {
        lst->head = lst->tail = newTail;
    }
    else
    {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

int isEmptyList(const SingleSourceMovesList* lst)
{
    return lst->head == NULL;
}




//Functions for list of lists


void insertDataToEndListOfLists(MultipleSourceMovesList* lstOfLists, SingleSourceMovesList* lst)
{
    MultipleSourceMovesListCell* newTail;

    newTail = createNewListOfListsNode(lst, NULL);
    insertNodeToEndListOfLists(lstOfLists, newTail);
}


MultipleSourceMovesListCell* createNewListOfListsNode(SingleSourceMovesList* lst, MultipleSourceMovesListCell* next)
{
    MultipleSourceMovesListCell* res;

    res = (MultipleSourceMovesListCell*)malloc(sizeof(MultipleSourceMovesListCell));
    //checkAlloc(res);
    res->single_source_moves_list=lst;
    res->next=next;

    return res;
}

void insertNodeToEndListOfLists(MultipleSourceMovesList* lst, MultipleSourceMovesListCell * newTail)
{
    if (isEmptyListOfLists(lst))
    {
        lst->head = lst->tail = newTail;
    }
    else
    {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

int isEmptyListOfLists(const MultipleSourceMovesList* lst)
{
    return lst->head == NULL;
}

void makeEmptyListOfLists(MultipleSourceMovesList* lst)
{
    (*lst).head = (*lst).tail = NULL;
}

void freeListOfLists(MultipleSourceMovesList* lol)
{
    MultipleSourceMovesListCell* currlolNode;
    currlolNode=lol->head;
    while(currlolNode != NULL)
    {
        freeList(currlolNode->single_source_moves_list);
        currlolNode=currlolNode->next;
    }
    free(lol);
}

void freeList(SingleSourceMovesList* list)
{
    SingleSourceMovesListCell* curr=list->head;
    SingleSourceMovesListCell* temp;
    while(curr != NULL)
    {
        temp=curr->next;
        free(curr->position);
        free(curr);
        curr=temp;
    }
    free(list);
}