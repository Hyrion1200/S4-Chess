#include "piece.h"
#include "board.h"
#include <stdlib.h>

struct Piece* board()
{
    struct Piece *board = malloc(64*sizeof(struct Piece));
    // Black Pieces
    board[0] = createPiece(ROOK,BLACK);
    board[1] = createPiece(KNIGHT,BLACK);
    board[2] = createPiece(BISHOP,BLACK);
    board[3] = createPiece(QUEEN,BLACK);
    board[4] = createPiece(KING,BLACK);
    board[5] = createPiece(BISHOP,BLACK);
    board[6] = createPiece(KNIGHT,BLACK);
    board[7] = createPiece(ROOK,BLACK);

    for(int i = 8; i < 16; i++)
    {
        board[i] = createPiece(PAWN,BLACK);
    }

    // White Pieces
    board[56] = createPiece(ROOK,WHITE);
    board[57] = createPiece(KNIGHT,WHITE);
    board[58] = createPiece(BISHOP,WHITE);
    board[59] = createPiece(QUEEN,WHITE);
    board[60] = createPiece(KING,WHITE);
    board[61] = createPiece(BISHOP,WHITE);
    board[62] = createPiece(KNIGHT,WHITE);
    board[63] = createPiece(ROOK,WHITE);

    for(int i = 48; i < 55; i++)
    {
        board[i] = createPiece(PAWN,WHITE);
    }


    return board;
}

void free_board(struct Piece* board)
{
    for (int i = 0; i < 64; i++)
    {
        free(&board[i]);
    }
    free(board);
}
