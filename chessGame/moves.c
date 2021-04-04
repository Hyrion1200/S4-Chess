#include "moves.h"
#include "validMoves.h"

struct Move initMove()
{
    Move null =
    {
        .start = 0;
        .end = 0;
        .value = 0;
    }
    return null;
}

struct Move makeMove(struct Piece bd[], int x1, int x2)
{
    printf("\n|");

    if(legalMoves(bd, x1, x2, bd[x1]))
    {
        if(bd[x2].type == 0)
	{
	    int p = bd[x1].type;
	    bd[x1].type = 0;
	    bd[x2].type = p;
	    n += 1;
	}
    }

    else
    {
        printf("Illegal move");
    }
}
