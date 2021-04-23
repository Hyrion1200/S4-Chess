#include "piece.h"
#include <stdio.h>

void updateSquare(Piece* board, int start, int end)
{
    //TODO
    //update board[start] and board[end]

    board[end] = board[start];
    board[start].type = NONE;
}

void printBoard(Piece* bd)
{
    //TODO
    //print board regarding piece type and piece color
    //Ex: P (Pawn White) // p (Pawn Black)
    for (size_t i = 0; i < 64; i++)
    {
        if(i%8 == 0)
            printf("\n|");
        if(bd[i].color == WHITE)
        {
        if(bd[i].type == 1)
            printf("P | ");

        if(bd[i].type == 2)
            printf("N | ");

        if(bd[i].type == 3)
            printf("B | ");

        if(bd[i].type == 4)
            printf("R | ");

        if(bd[i].type == 5)
            printf("Q | ");

        if(bd[i].type == 6)
            printf("K | ");

        if(bd[i].type == 0)
            printf("  | ");
        }
        else // bd[i].color == BLACK
        {
            if(bd[i].type == 1)
                printf("p | ");

            if(bd[i].type == 2)
                printf("n | ");

            if(bd[i].type == 3)
                printf("b | ");

            if(bd[i].type == 4)
                printf("r | ");

            if(bd[i].type == 5)
                printf("q | ");

            if(bd[i].type == 6)
                printf("k | ");

            if(bd[i].type == 0)
                printf("  | ");
        }
    }

    printf("\n|");


}

