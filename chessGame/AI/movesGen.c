#include "piece.h"
#include "moves.h"
#include "chess.h"

#define MAX_RANK 8


Move* movesGeneration(Chess chess)
{
    int size = 0;
    Move* moves = malloc(208*sizeof(Move));

    for(int i = 0; i < 64; i++)
    {
        Piece p = chess.board[i];
        if(p.color = chess.turn)
        {

            for(int j = 0; j < 64; j++)
            {
                if(legalMoves(chess.board,start,j,p))
                {
                    Move new = initMove();
                    new.start = start;
                    new.end = start - MAX_RANK;
                    moves[size] = new;
                    size++;
                }

            }
        }
    }
    return moves;
}

int squareGeneration(Piece* board, int square)
{
    int nb = 0;

    for(int i = 0; i < 64; i++)
    {
        if(board[i].type != NONE)
        {
            if(legalMoves(board,i,square,board[i]))
            {
                nb++;
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

