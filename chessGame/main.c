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
    struct Piece* bd2 = board();
    struct Piece* bd3 = board();

    Chess* chess = malloc(sizeof(Chess));
    Chess* chess2 = malloc(sizeof(Chess));
    Chess* chess3 = malloc(sizeof(Chess));
    chess2->board = bd2;
    chess2->turn = 1;
    chess3->board = bd3;
    chess3->turn = 1;

    chess->board = bd;
    chess->nbPieces = 32;
    chess->turn = 1;
    chess->WC = 0;
    chess->BC = 0;

    int n = 0;
    while(n == 0)
    {
        printBoard(chess->board);
        Move mv = selectMove(chess,1);
        makeMove(chess,mv.start,mv.end);

        printf("---------------------------\n");
        printBoard(chess2->board);
        Move mv2 = selectMove(chess2,2);
        makeMove(chess2,mv2.start,mv2.end);

        printf("---------------------------\n");
        printBoard(chess3->board);
        Move mv3 = selectMove(chess3,3);
        makeMove(chess3,mv3.start,mv3.end);

        n++;
        /*if(n = 1)
        {
            if(legalMoves(chess->board,10,18,chess->board[10]))
                makeMove(chess,10,18);
            n++;
        }*/
        sleep(1);
    }
    printBoard(chess->board);
    free(bd);
    free(bd2);
    free(bd3);
    free(chess2);
    free(chess3);
    free(chess);
    return 0;
}
