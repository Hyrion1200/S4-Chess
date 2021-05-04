//#include "../board.h"
#include <string.h>
#include <stdlib.h>
#include "../moves.h"
#include "../validMoves.h"
#include <stdio.h>
#include "movesGen.h"
#include "chessAI.h"
#include "../board.h"
#include "../piece.h"

#define SIZE 208
#define INF 9999

//region tables
const int pawnstableB[64] = {
    0,  0,  0,  0,  0,  0,  0,  0,
    5, 10, 10,-20,-20, 10, 10,  5,
    5, -5,-10,  0,  0,-10, -5,  5,
    0,  0,  0, 20, 20,  0,  0,  0,
    5,  5, 10, 25, 25, 10,  5,  5,
    10, 10, 20, 30, 30, 20, 10, 10,
    50, 50, 50, 50, 50, 50, 50, 50,
    0,  0,  0,  0,  0,  0,  0,  0};

const int pawnstable[64] = {
    0,  0,  0,  0,  0,  0,  0,  0,
    50, 50, 50, 50, 50, 50, 50, 50,
    10, 10, 20, 30, 30, 20, 10, 10,
    5,  5, 10, 25, 25, 10,  5,  5,
    0,  0,  0, 20, 20,  0,  0,  0,
    5, -5,-10,  0,  0,-10, -5,  5,
    5, 10, 10,-20,-20, 10, 10,  5,
    0,  0,  0,  0,  0,  0,  0,  0};

const int knightstableB[64] = {
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50};

const int knightstable[64] = {
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50};

const int bishopstableB[64] = {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10,-10,-10,-10,-10,-20};

const int bishopstable[64] = {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -20,-10,-10,-10,-10,-10,-10,-20};

const int rookstableB[64] = {
    0,  0,  0,  5,  5,  0,  0,  0,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    5, 10, 10, 10, 10, 10, 10,  5,
    0,  0,  0,  0,  0,  0,  0,  0};

const int rookstable[64] = {
     0,  0,  0,  0,  0,  0,  0,  0,
     5, 10, 10, 10, 10, 10, 10,  5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
     0,  0,  0,  5,  5,  0,  0,  0};

const int queenstableB[64] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  5,  5,  5,  5,  5,  0,-10,
     0,  0,  5,  5,  5,  5,  0, -5,
    -5,  0,  5,  5,  5,  5,  0, -5,
    -10,  0,  5,  5,  5,  5,  0,-10,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20};

const int queenstable[64] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5,  5,  5,  5,  0,-10,
    -5,  0,  5,  5,  5,  5,  0, -5,
     0,  0,  5,  5,  5,  5,  0, -5,
    -10,  5,  5,  5,  5,  5,  0,-10,
    -10,  0,  5,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20};


const int kingstableB[64] = {
     20, 30, 10,  0,  0, 10, 30, 20,
     20, 20,  0,  0,  0,  0, 20, 20,
    -10,-20,-20,-20,-20,-20,-20,-10,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30};

const int kingstable[64] = {
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -10,-20,-20,-20,-20,-20,-20,-10,
     20, 20,  0,  0,  0,  0, 20, 20,
     20, 30, 10,  0,  0, 10, 30, 20};
// end of region table
int minmax(Chess *chess, int isWhite, int depth, int alpha, int beta, long long* nodes)
{
    if (depth == 0)
    {
        int bonus = 0;
        if(chess->WC)
        {
            bonus += 5000;
        }
        if(chess->BC)
            bonus -= 5000;

        return evaluateBoard(chess->board,bonus);
    }
    int size = 0;
    Move* moves = movesGeneration(*chess,&size);
    *nodes += size;

    int best = -INF;
    for(int i = 0; i < size; i++)
    {

        Move move = moves[i];
        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));
        chessCpy->board = bdCpy;

        makeMove(chessCpy,move.start,move.end);
        int val = -minmax(chessCpy,chessCpy->turn,depth-1,-beta,-alpha,nodes);

        free(bdCpy);
        free(chessCpy);

        if(val >= beta)
            return beta;
        if(val > alpha)
            alpha = val;
    }

    free(moves);
    return alpha;
}

int negamax(Chess *chess,int depth, long long * nodes)
{
    if (depth == 0)
    {
        int bonus = 0;
        if(chess->WC)
        {
            bonus += 50;
        }
        if(chess->BC)
            bonus -= 50;
        if(chess->check && chess->turn)
            bonus += 35;
        if(chess->check && !chess->turn)
            bonus -= 35;
        return evaluateBoard(chess->board,bonus);
    }
    int size = 0;
    Move* moves = movesGeneration(*chess,&size);
    *nodes += size;

    int best = -INF;
    for(int i = 0; i < size; i++)
    {

        Move move = moves[i];
        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));
        chessCpy->board = bdCpy;

        makeMove(chessCpy,move.start,move.end);
        int val = -negamax(chessCpy,depth-1,nodes);

        if(val > best)
            best = val;
        free(bdCpy);
        free(chessCpy);
    }

    free(moves);
    return best;
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
                pawnsq -= pawnstableB[i];
            }
            if(piece.type == KNIGHT)
            {
                bn++;
                knightsq -= knightstableB[i];
            }
            if(piece.type == BISHOP)
            {
                bb++;
                bishopsq -= bishopstableB[i];
            }
            if(piece.type == ROOK)
            {
                br++;
                rooksq -= rookstableB[i];
            }
            if(piece.type == QUEEN)
            {
                bq++;
                queensq -= queenstableB[i];
            }
            if(piece.type == KING)
            {
                bk++;
                kingsq -= kingstableB[i];
            }
        }
    }

    int material = 100*(wp-bp) + 320*(wn-bn) + 330*(wb-bb) + 500*(wr-br) + 900*(wq-bq);
    int boardValue = material + pawnsq + knightsq + bishopsq + rooksq + queensq + kingsq + bonus;
    //printf("boardValue : %i\n",boardValue);
    return boardValue;
//    if(bonus)
//        printf("eval with castle : %i  [C : %i]\n",material + bonus,bonus);
//    return material + bonus;
}

Move selectMove(Chess *chess, int depth, int alpha, int beta)
{
    Move bestMove = initMove();
    bestMove.value = -INF;
    int size = 0;
    long long nodes = 0;
    // generate moves
    Move* moves = movesGeneration(*chess,&size);
    printf("Number of moves : %i\n",size);
    nodes += size;
    for (int i = 0; i < size; i++)
    {

        printf(" %i |",chess->board[moves[i].start].type);
        /*if(chess->board[moves[i].start].type == 2)
            printf(" start : %i and end %i |||\n",moves[i].start,moves[i].end);
        */
        if(chess->board[moves[i].start].type == 6)
            printf(" start : %i and end %i |||", moves[i].start,moves[i].end);

        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));

        chessCpy->board = bdCpy;
        makeMove(chessCpy,moves[i].start,moves[i].end);

        int boardValue = -negamax(chessCpy,depth-1,&nodes);

        if (boardValue >= bestMove.value)
        {
            bestMove.start = moves[i].start;
            bestMove.end = moves[i].end;
            bestMove.value = boardValue;
        }
        free(bdCpy);
        free(chessCpy);

        /*if(bestMove.value > alpha)
            alpha = bestMove.value;
        if (beta <= alpha)
            break;*/
    }
    free(moves);
    printf("\nnodes parcourues : %lld\n",nodes);
    printf("move start : %i and end : %i with value %i\n",bestMove.start,bestMove.end,bestMove.value);
    return bestMove;

}

int perft(Chess* chess, int depth)
{
    int size = 0;
    long nodes = 0;
    if(depth == 0)
        return 1;

    Move* moves = movesGeneration(*chess,&size);
    for(int i = 0; i < size; i++)
    {
        Chess *chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(64*sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));

        //printf("In Perft : %i\n", moves[i].value);
        chessCpy->board = bdCpy;
        makeMove(chessCpy,moves[i].start,moves[i].end);
        chessCpy->check = check(*chessCpy,chessCpy->turn);
        nodes += perft(chessCpy,depth-1);

    }
    free(moves);
    return nodes;

}



int squareAttacked(Chess* chess,int start)
{
    int nb = squareGeneration(*chess,start,start);
    return nb;
}


