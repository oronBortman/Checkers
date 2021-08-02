#pragma once
#include <General.h>

SingleSourceMovesList *FindSingleSourceOptimalMove(SingleSourceMovesTree *moves_tree);
void cleanBranches(SingleSourceMovesTreeNode* curr, int* length);
void buildList(SingleSourceMovesList* lst,SingleSourceMovesTreeNode* currTreeNode);