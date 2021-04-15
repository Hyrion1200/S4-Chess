#include "../piece.h"
#include "../moves.h"
#include "chess.h"
#include "../validMoves.h"
#include <stdlib.h>
#include "../board.h"
#include <stdio.h>

#define MAX_RANK 8
#define MAX_MOVE 256

Move* movesGeneration(Chess chess, int *size)
{
    int nbP = 0;
    int nbN = 0;
    Move* moves = malloc(MAX_MOVE*sizeof(Move));

    for(int i = 0; i < 64; i++)
    {
        struct Piece p = chess.board[i];
        if((int)p.color == chess.turn && p.type)
        {
            int start = i;
            for(int j = 0; j < 64; j++)
            {
                if(legalMoves(chess.board,start,j,p) && i != j )
                {
                    if(p.type == PAWN)
                        nbP += 1;
                    if(p.type == KNIGHT)
                    {
                        nbN += 1;
                        //printf("move start %i and end %i\n",i,j);
                    }
                    /*if(p.type != PAWN && p.type != KNIGHT)
                    {
                        printf("start : %i and end %i\n",i,j);
                    }*/
                    Move new = initMove();
                    new.start = start;
                    new.end = j;
                    moves[*size] = new;
                    *size += 1;
                }

            }
        }
    }
    //printf("nbP : %i and nbK : %i\n",nbP,nbN);
    //printf("Chess turn : %i\n",chess.turn);
    //printf("Size of possible moves : %i\n",*size);
    return moves;
}

int squareGeneration(Piece* board, int square, int preMove)
{
    // how many pieces except the one who should go on square
    // can go on square

    int nb = 0;

    for(int i = 0; i < 64; i++)
    {
        if(board[i].color != board[preMove].color)
        {
            if(board[i].type != NONE && i != preMove && board[i].type != KING)
            {
                if(legalMoves(board,i,square,board[i]))
                {
                    nb++;
                }
            }
        }
    }
    return nb;
}


//old
/*void genPawn(Piece* board,int start, Move* moves,int* i)
{
    // MOVE 1
    if (board[start].color == WHITE)
    {
        if(legalMoves(board,start,start-MAX_RANK)) // move 1 up
        {
            Move new =
            {
                .start = start,
                .end = start-MAX_RANK,
                .value = 0
            };
            moves[i] = new;
            i++;
        }
        if(legalMoves(board,start,start-MAX_RANK*2)) // move 2 up
    }
}*/

