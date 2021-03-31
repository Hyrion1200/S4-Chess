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
    NONEC = 0,
    BLACK,
    WHITE,
};

struct Piece
{
    enum Type type;
    enum Color color;
    int hasMoved;
}Piece;


void createPiece(struct Piece* bd, int i, enum Type ty, enum Color co);
#endif
