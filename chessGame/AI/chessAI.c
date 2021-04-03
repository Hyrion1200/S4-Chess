#include "board.h"
#include "move.h"

Move selectMove(Chess chess, int depth, int turn)
{
    Move bestMove = initMove();

    // generate moves
    Move* moves = generateMoves(Chess chess);
    //
    for (int i = 0; i < size; i++)
    {
        make_move(moves[i]);

        if(turn)
            turn = 0
        else
            turn = 1

        int boardValue = minmax(board,1, depth-1,-inf,inf,turn);
        unmake_move(board);
        if boardValue >= bestMove.value
        {
            bestMove.start = moves[i].start;
            bestMove.end = moves[i].end;
            bestMove.value = boardValue;
        }
    }

    return bestMove;

}

int minmax(Chess chess, int alt, int depth, int alpha, int beta)
{
    int min = 9999;
    int max = -9999;
    if (depth == 0)
        return evaluate_board(chess.board);

    Move* moves = generateMoves(Chess chess);

    for (int i = 0; i < 208; i++)
    {
        Move move = moves[i];
        make_move(board,move);
        chess.turn = ! chess.turn;
        Move new = minmax(chess,depth--,alpha,beta);
        if (new.value > max)
        {
            max = new.value;
            if(!alt)
                alpha = max;
        }
        if (tem_score < min)
        {
            min = new.value
            if (alt)
                beta = min;
        }
        if (alpha > beta)break;

    }
    if (minim)
        return min;
    else
        return max;
    if (chess.turn) // White to play
    {
        bestMove = -9999;
        for(int i = 0;)
    }
}

int evaluate_board(Piece* board)
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
                pawnsq += pawntable[i];
            }
            if(piece.type == KNIGHT)
            {
                wn++;
                knightsq += knightable[i];
            }
            if(piece.type == BISHOP)
            {
                wb++;
                bishopsq += bishoptable[i];
            }
            if(piece.type == ROOK)
            {
                wr++;
                rooksq += rooktable[i];
            }
            if(piece.type == QUEEN)
            {
                wq++;
                queensq += queentable[i];
            }
            if(piece.type == KING)
            {
                wk++;
                kiingsq += kingtable[i];
            }
        }
        else
        {
            if(piece.type == PAWN)
            {
                bp++;
                pawnsq -= pawntable[i];
            }
            if(piece.type == KNIGHT)
            {
                bn++;
                knightsq -= knightable[i];
            }
            if(piece.type == BISHOP)
            {
                bb++;
                bishopsq -= bishoptable[i];
            }
            if(piece.type == ROOK)
            {
                br++;
                rooksq -= rooktable[i];
            }
            if(piece.type == QUEEN)
            {
                bq++;
                queensq -= queentable[i];
            }
            if(piece.type == KING)
            {
                bk++;
                kingsq -= kingtable[i];
            }
        }
    }

    int material = 100*(wp-bp) + 320*(wn-bn) + 330*(wb-bb) + 500*(wr-br) + 900*(wq-bq);
    int boardValue = material + pawnsq + knightsq + bishopsq + rooksq + queensq + kingsq;

    return boardValue;
}
int squareAttacked(Chess chess,int start)
{
    int nb = squareGeneration(chess.board,start);
    return nb;
}


int updateEval(Chess chess,Move move)
{
    if chess.turn:

}
