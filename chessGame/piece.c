#include "piece.h"
#include <stdlib.h>


struct Piece createPiece(enum Type ty, enum Color co)
{
    struct Piece *piece = malloc(sizeof(struct Piece));

    piece->type = ty;
    piece->color = co;
    piece->hasMoved = 0;

    return *piece;
}


