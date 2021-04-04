#ifndef MOVES_H
#define MOVES_H

typedef struct Move
{
    int start;
    int end;
    int value;
}

struct Move initMove();
struct Move makeMove(struct Piece* bd, int x1, int x2);



#endif
