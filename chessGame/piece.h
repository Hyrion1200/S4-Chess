#ifndef PIECE_H
#define PIECE_H


enum Type
{
    NONE = 0,
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
};

enum Color
{
    BLACK = 0,
    WHITE,
};

typedef struct Piece
{
    enum Type type;
    enum Color color;
    int hasMoved;
}Piece;

void createPiece(struct Piece* bd, int i, enum Type ty, enum Color co);
#endif
