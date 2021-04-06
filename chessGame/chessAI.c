#include "moves.h"
#include "movesGen.h"
#include "chessAI.h"
#include "board.h"
#include "piece.h"

#define SIZE 208
#define INF 9999

int minmax(Chess chess, int alt, int depth, int alpha, int beta)
{
    int min = 9999;
    int max = -9999;
    if (depth == 0)
    {
        int bonus = 0;
        if(chess.WC)
            bonus += 50;
        if(chess.BC)
            bonus -= 50;

        return evaluateBoard(*chess.board,bonus);
    }
    Move* moves = movesGenerations(chess);

    for (int i = 0; i < SIZE; i++)
    {
        Move move = moves[i];
        makeMove(&chess,move.start,move.end);
        chess.turn = ! chess.turn;
        int value = minmax(chess, !alt, depth-1, alpha, beta);
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
        if (alpha > beta)break;

    }
    if (alt)
        return min;
    else
        return max;
}

int evaluate_board(struct Piece* board, int bonus)
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

    return boardValue;
}

Move selectMove(Chess *chess, int depth, int turn)
{
    Move bestMove = initMove();

    // generate moves
    Move* moves = movesGenerations(*chess);
    //
    for (int i = 0; i < SIZE; i++)
    {
        makeMove(chess,moves[i].start,moves[i].end);

        if(turn)
            turn = 0;
        else
            turn = 1;

        int boardValue = minmax(*chess,1,depth-1,-INF,INF);
        //unmake_move(board); // TODO
        if (boardValue >= bestMove.value)
        {
            bestMove.start = moves[i].start;
            bestMove.end = moves[i].end;
            bestMove.value = boardValue;
        }
    }

    return bestMove;

}



int squareAttacked(Chess* chess,int start)
{
    int nb = squareGeneration(*chess->board,start);
    return nb;
}


