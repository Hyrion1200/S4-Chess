#ifndef MOVES_H
#define MOVES_H
#include "board.h"

typedef struct Move
{
    int start;
    int end;
    int value;
}Move;

struct Move initMove();
void makeMove(Chess *chess, int x1, int x2);



#endif
