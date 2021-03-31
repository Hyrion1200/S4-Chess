#include "piece.h"
#include <stdlib.h>


void createPiece(struct Piece* bd, int i, enum Type ty, enum Color co)
{
    bd[i].type = ty;
    bd[i].color = co;
    bd[i].hasMoved = 0;

}


