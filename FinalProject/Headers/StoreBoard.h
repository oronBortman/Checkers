#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <General.h>
//void StoreBoard(Board board, char *filename);

void StoreBoard(Board board);
void printCharAsBinary(char ch);
void checkFile(FILE *fp);
void writeToFile(char *fName, unsigned char * arr, int size);
void LoadBoard(char *filename, Board board);