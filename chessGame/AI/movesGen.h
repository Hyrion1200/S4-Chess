#ifndef MOVEGEN_H
#define MOVEGEN_H
#include "../board.h"
#include "../piece.h"
#include "../moves.h"
Move* movesGeneration(Chess chess, int *size);

int squareGeneration(Chess chess,int square, int preMove);


#endif
