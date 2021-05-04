#include "piece.h"
#include "visual.h"
#include <string.h>
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
        createPiece(bd,i,NONE,BLACK); // BLACK = 0 -> default color for pieces

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


    //bd->wk = 60;
    //bd->bk = 4;
    return bd;
}

struct Piece* boardBishop()
{
    struct Piece* bd = malloc(64* sizeof(struct Piece));
    for(int i = 0; i < 64; i++)
        createPiece(bd,i,NONE,BLACK);

    bd[2].type = BISHOP;
    bd[5].type = BISHOP;

    bd[58].type = BISHOP;
    bd[58].color = WHITE;
    bd[61].type = BISHOP;
    bd[61].color = WHITE;

    return bd;
}

struct Piece* boardCastle()
{
    struct Piece* bd = malloc(64* sizeof(struct Piece));
    for(int i = 0; i < 64; i++)
        createPiece(bd,i,NONE,BLACK);

    bd[0].type = ROOK;
    bd[4].type = KING;
    bd[7].type = ROOK;

    bd[56].type = ROOK;
    bd[56].color = WHITE;
    bd[60].type = KING;
    bd[60].color = WHITE;

    bd[63].type = ROOK;
    bd[63].color = WHITE;

    return bd;
}

struct Piece* board2()
{
    struct Piece* bd = malloc(64* sizeof(struct Piece));
    for(int i = 0; i < 64; i++)
        createPiece(bd,i,NONE,BLACK);
    bd[0].type = ROOK;
    bd[4].type = KING;
    bd[7].type = ROOK;
    bd[8].type = PAWN;
    bd[10].type = PAWN;
    bd[11].type = PAWN;
    bd[12].type = QUEEN;
    bd[13].type = PAWN;
    bd[14].type = BISHOP;
    bd[16].type = BISHOP;
    bd[17].type = KNIGHT;
    bd[20].type = PAWN;
    bd[21].type = KNIGHT;
    bd[22].type = PAWN;
    bd[33].type = PAWN;
    bd[47].type = PAWN;

    bd[27].type = PAWN;
    bd[27].color = WHITE;
    bd[28].type = KNIGHT;
    bd[28].color = WHITE;
    bd[36].type = PAWN;
    bd[36].color = WHITE;

    bd[42].type = KNIGHT;
    bd[42].color = WHITE;
    bd[45].type = QUEEN;
    bd[48].type = PAWN;
    bd[49].type = PAWN;
    bd[50].type = PAWN;
    bd[51].type = BISHOP;
    bd[52].type = BISHOP;
    bd[53].type = PAWN;
    bd[54].type = PAWN;
    bd[55].type = PAWN;
    bd[56].type = ROOK;
    bd[60].type = KING;
    bd[63].type = ROOK;
    for(int i = 42; i < 64; i++)
        bd[i].color = WHITE;
    bd[47].color = BLACK;

    return bd;
}

int charToDigit(char c)
{
    return c - '0';
}

struct Piece* fenBoard(char* fen)
{
    struct Piece* bd = malloc(64* sizeof(struct Piece));
    for(int i = 0; i < 64; i++)
        createPiece(bd,i,NONE,BLACK);
    int l = strlen(fen);
    int i = 0;
    for(int s = 0; s < l; s++)
    {
        int val = charToDigit(fen[s]);
        if(val > 0 && val < 9)
            i += charToDigit(fen[s]);

        switch(fen[s])
        {
            case 'p':
                bd[i].type = PAWN;
                i++;
                break;
            case 'n':
                bd[i].type = KNIGHT;
                i++;
                break;
            case 'b':
                bd[i].type = BISHOP;
                i++;
                break;
            case 'r':
                bd[i].type = ROOK;
                i++;
                break;
            case 'q':
                bd[i].type = QUEEN;
                i++;
                break;
            case 'k':
                bd[i].type = KING;
                i++;
                break;
            case 'P':
                bd[i].type = PAWN;
                bd[i].color = WHITE;
                i++;
                break;
            case 'N':
                bd[i].type = KNIGHT;
                bd[i].color = WHITE;
                i++;
                break;
            case 'B':
                bd[i].type = BISHOP;
                bd[i].color = WHITE;
                i++;
                break;
            case 'R':
                bd[i].type = ROOK;
                bd[i].color = WHITE;
                i++;
                break;
            case 'Q':
                bd[i].type = QUEEN;
                bd[i].color = WHITE;
                i++;
                break;
            case 'K':
                bd[i].type = KING;
                bd[i].color = WHITE;
                i++;
                break;
            default:
                break;
        }
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
