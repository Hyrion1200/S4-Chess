#include "piece.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>

struct Piece* board()
{
    struct Piece* bd = malloc(64* sizeof(struct Piece));

    // Black Pieces
    createPiece(bd,0,ROOK,BLACK);
    createPiece(bd,1,KNIGHT,BLACK);
    createPiece(bd,2,BISHOP,BLACK);
    createPiece(bd,3,QUEEN,BLACK);
    createPiece(bd,4,KING,BLACK);
    createPiece(bd,5,BISHOP,BLACK);
    createPiece(bd,6,KNIGHT,BLACK);
    createPiece(bd,7,ROOK,BLACK);

    for(int i = 8; i < 16; i++)
        createPiece(bd,i,PAWN,BLACK);

    for(int i = 16; i < 48; i++)
        createPiece(bd,i,NONE,NONEC);

    // White Pieces
    createPiece(bd,56,ROOK,WHITE);
    createPiece(bd,57,KNIGHT,WHITE);
    createPiece(bd,58,BISHOP,WHITE);
    createPiece(bd,59,QUEEN,WHITE);
    createPiece(bd,60,KING,WHITE);
    createPiece(bd,61,BISHOP,WHITE);
    createPiece(bd,62,KNIGHT,WHITE);
    createPiece(bd,63,ROOK,WHITE);

    for(int i = 48; i < 56; i++)
    {
        createPiece(bd,i,PAWN,WHITE);
    }


    return bd;
}

void free_board(struct Piece* bd)
{
    printf("\n\n-----------\n");
    //free()
    for (int i = 0; i < 64; i++)
    {
        printf("board i : %i\n",bd[i].type);
        //free(bd[i]);
    }
    free(bd);
}
