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
    BLACK = 1,
    WHITE,
};

struct Piece
{
    enum Type type;
    enum Color color;
    int hasMoved;
};


struct Piece createPiece(enum Type ty, enum Color co);
#endif
