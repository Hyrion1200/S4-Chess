#include "board.h"
#include <unistd.h>
#include "piece.h"
#include "validMoves.h"
#include "moves.h"
#include "AI/chessAI.h"
#include <stdio.h>
#include <stdlib.h>
#include "visual.h"

int main()
{
    struct Piece* bd = board();

    Chess* chess = malloc(sizeof(Chess));
    chess->board = bd;
    chess->nbPieces = 32;
    chess->turn = 1;
    chess->WC = 0;
    chess->BC = 0;

    int n = 0;
    while(1)
    {
        printBoard(chess->board);

	/*if(chess->turn)
	{
	    int x1;

	    int x2;

	    printf("Player 1, enter the coordinate of the piece you want to move : ");
	    scanf("%d", &x1);

	    printf("Player 1, enter the coordinate where you want to move this piece : ");
	    scanf("%d", &x2);

            printf("start : %i\n",x1);
            printf("end : %i\n",x2);
	    printf("type : %i\n",chess->board[x1].type);
            makeMove(chess, x1, x2);
            printf("type : %i\n", chess->board[x1].type);
            printf("type : %i\n", chess->board[x2].type);
	}

	else
	{
	    int x1;

	    int x2;

	    printf("Player 2, enter the coordinate of the piece you want to move : ");
	    scanf("%d", &x1);

	    printf("Player 2, enter the coordinate where you want to move this piece : ");
	    scanf("%d", &x2);

	    makeMove(chess, x1, x2);
	}*/
        if(n != 1)
        {
        Move mv = selectMove(chess,2,chess->turn);
        //printf("\nNew Move-------------------\n");
        makeMove(chess,mv.start,mv.end);
        n++;
        }
        else
        {
            if(legalMoves(chess->board,10,18,chess->board[10]))
                makeMove(chess,10,18);
            n++;
        }
        sleep(1);
    }
    printBoard(chess->board);
    free(bd);
    free(chess);
    return 0;
}
