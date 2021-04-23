#ifndef BOARD_H
#define BOARD_H

struct Piece* board();
struct Piece* boardBishop();
struct Piece* boardCastle();
void free_board(struct Piece* board);

typedef struct Chess
{
    struct Piece* board;
    int nbPieces;
    int turn;
    int WC; // White Castle
    int BC; // Black Castle
    int check;
}Chess;



#endif
