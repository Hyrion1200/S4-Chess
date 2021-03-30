#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>

struct Piece* board()
{
    struct Piece** bd = malloc(64*sizeof(struct Piece*));
    // Black Pieces
    bd[0] = createPiece(ROOK,BLACK);
    bd[1] = createPiece(KNIGHT,BLACK);
    bd[2] = createPiece(BISHOP,BLACK);
    bd[3] = createPiece(QUEEN,BLACK);
    bd[4] = createPiece(KING,BLACK);
    bd[5] = createPiece(BISHOP,BLACK);
    bd[6] = createPiece(KNIGHT,BLACK);
    bd[7] = createPiece(ROOK,BLACK);

    for(int i = 8; i < 16; i++)
        bd[i] = createPiece(PAWN,BLACK);

    for(int i = 16; i < 48; i++)
        bd[i] = createPiece(NONE,NONEC);

    // White Pieces
    bd[56] = createPiece(ROOK,WHITE);
    bd[57] = createPiece(KNIGHT,WHITE);
    bd[58] = createPiece(BISHOP,WHITE);
    bd[59] = createPiece(QUEEN,WHITE);
    bd[60] = createPiece(KING,WHITE);
    bd[61] = createPiece(BISHOP,WHITE);
    bd[62] = createPiece(KNIGHT,WHITE);
    bd[63] = createPiece(ROOK,WHITE);

    for(int i = 48; i < 55; i++)
    {
        bd[i] = createPiece(PAWN,WHITE);
    }


    return *bd;
}

void free_board(struct Piece* bd)
{
    printf("\n\n-----------\n");
    //free()
    for (int i = 0; i < 64; i++)
    {
        printf("board i : %i\n",bd[i].type);
        free(&bd[i]);
    }
    free(bd);
}
