#include "board.h"
#include <string.h>
#include <unistd.h>
#include "piece.h"
#include "validMoves.h"
#include "moves.h"
#include "AI/chessAI.h"
#include <stdio.h>
#include <stdlib.h>
#include "visual.h"
#include <err.h>

int main(int argc, char** argv)
{
    if(argc < 2)
        errx(EXIT_FAILURE,"Not enough arg\n Ex : ./main [depth]\n");
//    struct Piece* bd = boardBishop();
    struct Piece* bd = board();
//    struct Piece* bd = boardCastle();
    struct Piece* bd2 = board();
    struct Piece* bd3 = board();
    struct Piece* bd4 = board();
    struct Piece* bd5 = board();
    struct Piece* bd6 = board();


    Chess* chess = malloc(sizeof(Chess));
    Chess* chess2 = malloc(sizeof(Chess));
    Chess* chess3 = malloc(sizeof(Chess));
    Chess* chess4 = malloc(sizeof(Chess));
    Chess* chess5 = malloc(sizeof(Chess));
    Chess* chess6 = malloc(sizeof(Chess));

    chess2->board = bd2;
    chess2->turn = 1;
    chess2->check = 0;
    chess3->board = bd3;
    chess3->turn = 1;
    chess3->check = 0;
    chess4->board = bd4;
    chess4->turn = 1;
    chess4->check = 0;
    chess5->board = bd5;
    chess5->turn = 1;
    chess5->check = 0;
    chess6->board = bd6;
    chess6->turn = 1;
    chess6->check = 0;

    chess->board = bd;
    chess->nbPieces = 32;
    chess->turn = 1;
    chess->WC = 0;
    chess->BC = 0;
    chess->check = 0;

    //int n = 0;
    if(atoi(argv[1]) == 0) //perf test
    {
        //printBoard(chess->board);
        printf("-----Perf test 1 ----------\n");
        Move mv = selectMove(chess,1,9999,-9999);
        makeMove(chess,mv.start,mv.end);

        printf("-----Perf test 2 ----------\n");
        int nodes2 = perft(chess2,2);
        printf("nodes2 : %i\n",nodes2);
        printf("-----Perf test 3 ----------\n");
        int nodes3 = perft(chess3,3);
        printf("nodes3 : %i\n",nodes3);

        printf("-----Perf test 4 ----------\n");
        int nodes4 = perft(chess4,4);
        printf("nodes4 : %i\n",nodes4);

        printf("-----Perf test 5 ----------\n");
        int nodes5 = perft(chess5,5);
        printf("nodes5 : %i\n",nodes5);

        printf("-----Perf test 6 ----------\n");
        int nodes6 = perft(chess6,6);
        printf("nodes6 : %i\n",nodes6);


    }
    else
    {
        while(1)
        {
            printf("--------New Turn -------------\n");
            printBoard(chess->board);
            printf("chess CHECK : %i || chess WC : %i || chess BC : %i \n",
                    chess->check,chess->WC,chess->BC);
            Move mv = selectMove(chess,atoi(argv[1]),-9999,9999);
            if(mv.start == 0 && mv.end == 0)
                break;
            makeMove(chess,mv.start,mv.end);
            //updateChess(chess);
            Chess* chessCpy = malloc(sizeof(Chess));
            memcpy(chessCpy,chess,sizeof(Chess));
            chess->check = check(*chessCpy,chessCpy->turn);
            printf("Value of Board: %i\n",evaluateBoard(chess->board,0));
            sleep(1);

        }
        printf("-----------------Game Over---------------\n");
    }
    printBoard(chess->board);
    free(bd);
    free(bd2);
    free(bd3);
    free(bd4);
    free(bd5);
    free(bd6);

    free(chess2);
    free(chess3);
    free(chess);
    free(chess4);
    free(chess5);
    free(chess6);

    return 0;
}
