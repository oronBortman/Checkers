#pragma once
#include <General.h>

void PlayGame(Board board, Player starting_player);
BOOL endGame(Board board, Player player);
BOOL checkIfPlayerRunOutOfTools(Board board, Player player);
BOOL checkIfTopReachedToBottom(Board board);
BOOL checkIfBottomReachedToTop(Board board);