#pragma once

#include <General.h>
#include <List.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>
#include <FindSingleSourceOptimalMove.h>

MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player);

/*typedef struct _multipleSourceMovesListCell {
    SingleSourceMovesList *single_source_moves_list;
    struct _multipleSourceMovesListCell *next;
} MultipleSourceMovesListCell;

typedef struct _multipleSourceMovesList {
    MultipleSourceMovesListCell *head;
    MultipleSourceMovesListCell *tai;
} MultipleSourceMovesList;*/