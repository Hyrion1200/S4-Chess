#include "moves.h"
#include "piece.h"
#include "validMoves.h"
#include <stdio.h>
#include "board.h"

struct Move initMove()
{
    Move null =
    {
        .start = 0,
        .end = 0,
        .value = 0
    };
    return null;
}

void makeMove(Chess *chess, int x1, int x2)
{
    //printf("\n");
    if(chess->turn)
        chess->turn = 0;
    else
        chess->turn = 1;

    //printf("Chess turn : %i\n",chess->turn);

    //printf("start : %i\n",x1);
    //printf("end : %i\n",x2);
    //printf("piece %i\n", chess->board[x1].type);
    if(legalMoves(chess->board, x1, x2, chess->board[x1]))
    {
        if(chess->board[x2].type == 0)
	{
            //printf("inHere\n");
            chess->board[x2].type = chess->board[x1].type;
            chess->board[x2].color = chess->board[x1].color;
            chess->board[x2].hasMoved = 1;
            chess->board[x1].type = 0;
	}
        else
        if(chess->board[x1].type == KING && chess->board[x2].type == ROOK)
        {
            //printf("inCastle\n");
            if(x2 > x1) // Castle Kingside
            {
                chess->board[x1+1] = chess->board[x2];
                chess->board[x1+2] = chess->board[x1];

                chess->board[x1].type = NONE;
                chess->board[x2].type = NONE;
            }
            else // Castle Queenside
            {
                chess->board[x1-1] = chess->board[x2];
                chess->board[x1-2] = chess->board[x1];

                chess->board[x1].type = NONE;
                chess->board[x2].type = NONE;
            }
        }
        else
        if(chess->board[x2].type != 0 && chess->board[x2].color != chess->board[x1].color)
        {
            /*printf("Taking a Piece\n");
            printf("start type : %i at %i\n",chess->board[x1].type, x1);
            printf("end type : %i at %i\n",chess->board[x2].type, x2);
            printf("color1: %i // color2: %i\n",chess->board[x1].color,chess->board[x2].color);
            */
            chess->nbPieces -= 1;
            chess->board[x2].type = chess->board[x1].type;
            chess->board[x2].color = chess->board[x1].color;
            chess->board[x2].hasMoved = 1;
	    chess->board[x1].type = 0;
        }
    }

    else
    {
        printf("Illegal move");
    }
}
