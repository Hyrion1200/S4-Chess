//#include "../board.h"
#include <string.h>
#include <stdlib.h>
#include "../moves.h"
#include <stdio.h>
#include "movesGen.h"
#include "chessAI.h"
#include "../board.h"
#include "../piece.h"

#define SIZE 208
#define INF 9999

//region tables
const int pawnstable[64] = {
    0,  0,  0,  0,  0,  0,  0,  0,
    5, 10, 10,-20,-20, 10, 10,  5,
    5, -5,-10,  0,  0,-10, -5,  5,
    0,  0,  0, 20, 20,  0,  0,  0,
    5,  5, 10, 25, 25, 10,  5,  5,
    10, 10, 20, 30, 30, 20, 10, 10,
    50, 50, 50, 50, 50, 50, 50, 50,
    0,  0,  0,  0,  0,  0,  0,  0};

const int knightstable[64] = {
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50};

const int bishopstable[64] = {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10,-10,-10,-10,-10,-20};

const int rookstable[64] = {
    0,  0,  0,  5,  5,  0,  0,  0,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    5, 10, 10, 10, 10, 10, 10,  5,
    0,  0,  0,  0,  0,  0,  0,  0};

const int queenstable[64] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  5,  5,  5,  5,  5,  0,-10,
    0,  0,  5,  5,  5,  5,  0, -5,
    -5,  0,  5,  5,  5,  5,  0, -5,
    -10,  0,  5,  5,  5,  5,  0,-10,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20};

const int kingstable[64] = {
    20, 30, 10,  0,  0, 10, 30, 20,
    20, 20,  0,  0,  0,  0, 20, 20,
    -10,-20,-20,-20,-20,-20,-20,-10,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30};



int minmax(Chess *chess, int alt, int depth, int alpha, int beta)
{
    int min = 9999;
    int max = -9999;
    if (depth == 0)
    {
        int bonus = 0;
        if(chess->WC)
            bonus += 50;
        if(chess->BC)
            bonus -= 50;

        return evaluateBoard(chess->board,bonus);
    }
    int size = 0;
    Move* moves = movesGeneration(*chess,&size);

    for (int i = 0; i < size; i++)
    {
        Move move = moves[i];

        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));

        chessCpy->board = bdCpy;


        //printf("chess board[48].type : %i\n",chessCpy->board[48].type);
        makeMove(chessCpy,move.start,move.end);
        int value = minmax(chessCpy, !alt, depth-1, alpha, beta);
        if (value > max)
        {
            max = value;
            if(!alt)
                alpha = max;
        }
        if (value < min)
        {
            min = value;
            if (alt)
                beta = min;
        }
        free(chessCpy);
        free(bdCpy);
        if (alpha > beta)break;

    }

    free(moves);
    if (alt)
        return min;
    else
        return max;
}

int evaluateBoard(struct Piece* board, int bonus)
{
    int wp = 0;
    int bp = 0;
    int wn = 0;
    int bn = 0;
    int wb = 0;
    int bb = 0;
    int wr = 0;
    int br = 0;
    int wq = 0;
    int bq = 0;
    int wk = 0;
    int bk = 0;
    int pawnsq = 0;
    int knightsq = 0;
    int bishopsq = 0;
    int rooksq = 0;
    int queensq = 0;
    int kingsq = 0;

    for(int i = 0; i < 64; i++)
    {
        Piece piece = board[i];
        if(piece.color == WHITE)
        {
            if(piece.type == PAWN)
            {
                wp++;
                pawnsq += pawnstable[i];
            }
            if(piece.type == KNIGHT)
            {
                wn++;
                knightsq += knightstable[i];
            }
            if(piece.type == BISHOP)
            {
                wb++;
                bishopsq += bishopstable[i];
            }
            if(piece.type == ROOK)
            {
                wr++;
                rooksq += rookstable[i];
            }
            if(piece.type == QUEEN)
            {
                wq++;
                queensq += queenstable[i];
            }
            if(piece.type == KING)
            {
                wk++;
                kingsq += kingstable[i];
            }
        }
        else
        {
            if(piece.type == PAWN)
            {
                bp++;
                pawnsq -= pawnstable[i];
            }
            if(piece.type == KNIGHT)
            {
                bn++;
                knightsq -= knightstable[i];
            }
            if(piece.type == BISHOP)
            {
                bb++;
                bishopsq -= bishopstable[i];
            }
            if(piece.type == ROOK)
            {
                br++;
                rooksq -= rookstable[i];
            }
            if(piece.type == QUEEN)
            {
                bq++;
                queensq -= queenstable[i];
            }
            if(piece.type == KING)
            {
                bk++;
                kingsq -= kingstable[i];
            }
        }
    }

    int material = 100*(wp-bp) + 320*(wn-bn) + 330*(wb-bb) + 500*(wr-br) + 900*(wq-bq);
    int boardValue = material + pawnsq + knightsq + bishopsq + rooksq + queensq + kingsq + bonus;
    //printf("boardValue : %i\n",boardValue);
    return boardValue;
}

Move selectMove(Chess *chess, int depth, int turn)
{
    Move bestMove = initMove();
    int size = 0;
    // generate moves
    Move* moves = movesGeneration(*chess,&size);
    //
    for (int i = 0; i < size; i++)
    {
        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));

        chessCpy->board = bdCpy;
        makeMove(chessCpy,moves[i].start,moves[i].end);

        int boardValue = minmax(chessCpy,1,depth-1,-INF,INF);
        //unmake_move(board); // TODO
        if (boardValue >= bestMove.value)
        {
            bestMove.start = moves[i].start;
            bestMove.end = moves[i].end;
            bestMove.value = boardValue;
        }
        free(chessCpy);
    }
    free(moves);

    printf("Color : %i\n",chess->turn);
    printf("move start : %i and end : %i\n",bestMove.start,bestMove.end);
    return bestMove;

}



int squareAttacked(Chess* chess,int start)
{
    int nb = squareGeneration(chess->board,start);
    return nb;
}


