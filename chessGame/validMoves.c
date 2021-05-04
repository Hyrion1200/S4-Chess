#include "piece.h"
#include <string.h>
#include <stdlib.h>
#include "AI/movesGen.h"
#include "board.h"
#include <stdio.h>
#include "validMoves.h"

#define MAX_COLUMN 8
#define MAX_RANK 8

int rookMoves(int start, int end)
{
    if (start < MAX_RANK)
    {
        if (end % MAX_RANK == start)
            return 1;

    }
    else
    {
        if(end % MAX_RANK == start % MAX_RANK)
            return 1;
    }

    if (start < end)
    {
        if(start % 8 == 7) // Last row can't go to the right
            return 0;
        for(int i = start + 1; i < end; i++)
        {
            if(i % 8 == 0)
                return 0;
        }
        return 2;
    }
    else
    {
        if(start % 8 == 0) // First row can't go to the left
            return 0;
        for(int i = start; i > end; i--)
        {
            if(i % 8 == 0)
                return 0;
        }
        return 2;
    }
    return 0;
}

int rookLegal(int start, int end, int dir, struct Piece* board)
{
    switch(dir)
    {
        // Vertical
        case 1:
            if(start < end)
            {
                for(int i = start + MAX_RANK; i < end; i += MAX_RANK)
                {
                    if(board[i].type != NONE)
                        return 0;
                }
            }
            else
            {
                //printf("start %i and end %i\n",start,end);
                for(int i = start-8; i > end; i -= 8)
                {
                    //printf("start: %i and end : %i || i : %i || board type %i\n",start, end, i, board[i].type);
                    if(board[i].type != NONE)
                        return 0;
                }
            }
            return 1;
            break;
            // Horizontal
        case 2:
            if(start < end)
            {
                for(int i = start+1; i < end; i++)
                {
                    if(board[i].type != NONE || i % 8 == 7)
                        return 0;
                }
            }
            else
            {
                for(int i = start-1; i > end; i--)
                {
                    if(board[i].type != NONE || i % 8 == 0)
                        return 0;
                }
            }
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

int bishopMoves(int start,int end)
{
    int b1 = 1;
    int b2 = 1;
    int b3 = 1;
    int b4 = 1;

    int x1 = start;
    int x2 = start;
    int x3 = start;
    int x4 = start;

    for(int n = 1; n < MAX_RANK; n++)
    {
        // it is not the end
        // if we are on the edge of the board with must prevent this direction
        if(x1 % 8 == 7 || x1 > 55) // Right edge or Bottom edge
            b1 = 0;
        if(x2 % 8 == 0 || x2 > 55) // Left edge or Bottom edge
            b2 = 0;
        if(x3 % 8 == 7 || x3 < 8) // Right edge or Top edge
            b3 = 0;
        if(x4 % 8 == 0 || x4 < 8) // Left edge or Top edge
            b4 = 0;

        if(end > start)
        {
            if(b1)
                x1 += MAX_RANK + 1;
            if(b2)
                x2 += MAX_RANK - 1;

            if(x1 == end && b1)
                return 1;
            if(x2 == end && b2)
                return 2;

        }
        else if(end < start)
        {
            if(b3)
                x3 += -MAX_RANK + 1;
            if(b4)
                x4 += -MAX_RANK - 1;
            if(x3 == end && b3)
                return 3;
            if(x4 == end && b4)
                return 4;
        }
    }
    return 0;
}

int bishopLegal(int start, int end, int r, struct Piece board[])
{
    if(r == 1)
    {
        int v = start;
        for(int n = 1; n < MAX_RANK; n++)
        {
            v += MAX_RANK + 1;
            if(v != end)
            {
                if(board[v].type != NONE)
                {
                    return 0;
                }
            }
            else
                return 1;
            n++;
        }
        return 1;
    }
    if(r == 2)
    {
        int v = start;
        for(int n = 1; n < MAX_RANK; n++)
        {
            v += MAX_RANK - 1;
            if(v != end)
            {
                if(board[v].type != NONE)
                {
                    return 0;
                }
            }
            else
                return 1;
            n++;
        }
        return 1;
    }
    if(r == 3)
    {
        int v = start;
        for(int n = 1; n < MAX_RANK; n++)
        {
            v += -MAX_RANK + 1;
            if(v != end)
            {
                if(board[v].type != NONE)
                {
                    return 0;
                }
            }
            else
                return 1;
            n++;
        }
        return 1;
    }
    if(r == 4)
    {
        int v = start;
        for(int n = 1; n < MAX_RANK; n++)
        {
            v += - MAX_RANK - 1;
            if(v != end)
            {

                if(board[v].type != NONE)
                {
                    return 0;
                }
            }
            else
            {
                return 1;
            }
            n++;
        }
        return 1;
    }
    return 0;
}

int pawnMoves(int start, int end, struct Piece pawn)
{
    //printf("start : %i\n",start);
    //printf("end : %i\n",end);
    if(pawn.hasMoved) // Cannot move 2 up
    {
        if(pawn.color == WHITE)
        {
            if(start - MAX_RANK == end)
                return 1;

            //Take a piece
            if(start - MAX_RANK - 1 == end || start - MAX_RANK + 1 == end)
                return 3;
        }
        else // pawn is BLACK
        {
            if(start + MAX_RANK == end)
                return 1;

            // Take a piece
            if(start + MAX_RANK - 1 == end || start + MAX_RANK + 1 == end)
                return 3;

        }
        return 0;
    }
    else
    {
        if(pawn.color == WHITE)
        {
            if(start - MAX_RANK == end)
                return 1;

            if(start - 2*MAX_RANK == end)
                return 2;

            //Take a piece
            if(start - MAX_RANK - 1 == end || start - MAX_RANK + 1 == end)
                return 3;

        }
        else // pawn is BLACK
        {
            if(start + MAX_RANK == end)
                return 1;

            if(start + 2*MAX_RANK == end)
                return 2;

            // Take a piece
            if(start + MAX_RANK - 1 == end || start + MAX_RANK + 1 == end)
                return 3;


        }
        return 0;
    }
}

int knightMoves(int start, int end)
{
    /*if(end > start) // prevent knight from doing weird movements
    {
        if(end - start < MAX_RANK)
            return 0;
    }
    else
    {
        if(start - end < MAX_RANK)
            return 0;
    }*/
    // Critical positions
    int left = 1;
    int leftM = 1;
    int right = 1;
    int rightM = 1;
    int up = 1;
    int upM = 1;
    int down = 1;
    int downM = 1;
    //
    if(start % 8 < 2) //left
        left = 0;
    if(start % 8 == 0) // leftM
        leftM = 0;
    if(start % 8 > 5) // right
        right = 0;
    if(start % 8 == 7) // rightM
        rightM = 0;
    if(start < 16)
        up = 0;
    if(start < 8)
        upM = 0;
    if(start >= 48)
        down = 0;
    if(start >= 56)
        down = 0;

    //printf("start %i ; end %i \n left %i , leftM %i, right %i, rightM %i\nup %i, upM %i, down %i, downM %i\n",start,end,left,leftM,right,rightM,up,upM,down,downM);

    if((start + 2*MAX_RANK + 1 == end && rightM && down)
            || (start + 2*MAX_RANK - 1 == end && leftM && down))
        return 1;

    if((start - 2*MAX_RANK + 1 == end && rightM && up)
            || (start - 2*MAX_RANK - 1 == end && leftM && up))
        return 1;


    if((start + MAX_RANK + 2 == end && right && downM)
            || (start + MAX_RANK - 2 == end && left && downM))
        return 1;

    if((start - MAX_RANK + 2 == end && right && downM)
            || (start - MAX_RANK - 2 == end && left && upM))
        return 1;

    return 0;
}

int queenMoves(int start, int end,Piece* board)
{
    int b = bishopMoves(start,end);
    int r = rookMoves(start,end);

    if(b)
        return bishopLegal(start,end,b,board);
    if(r)
        return rookLegal(start,end,r,board);
    return b + r;
}

int kingMoves(int start, int end)
{
    int left = 1;
    int right = 1;
    int up = 1;
    int down = 1;
    int castle = 0;

    if(start % 8 == 0)
        left = 0;
    if(start % 8 == 7)
        right = 0;
    if(start > 55)
        down = 0;
    if(start < 8)
        up = 0;
    if(start == 60 || start == 4)
        castle = 1;
    if((start + 1 == end && right ) || (start - 1 == end && left))
        return 1;

    if((start + MAX_RANK == end && down) || (start - MAX_RANK == end && up))
        return 1;

    if((start + MAX_RANK + 1 == end && down && right)
            || (start + MAX_RANK - 1 == end && down && left))
        return 1;

    if((start - MAX_RANK + 1 == end && up && right)
            || (start - MAX_RANK - 1 == end && up && left))
        return 1;
    if((start + 3 == end || start - 4 == end) && castle)
        return 2;
    return 0;
}

int castleLegal(Chess chess, int start, int end)
{
    if(chess.board[start].hasMoved || chess.board[end].hasMoved ||
            (chess.board[start].color != chess.board[end].color) ||
            chess.check)
        return 0;
    if(end > start) // Castle King side
    {
        if(chess.board[start+1].type != NONE || chess.board[start+2].type != NONE)
            return 0;
        return squareGeneration(chess,start+1,start) == 0 &&
            squareGeneration(chess,start+2,start) == 0;
    }
    else // Castle Queen side
    {
        if(chess.board[start-1].type != NONE ||
                chess.board[start-2].type != NONE ||
                chess.board[start-3].type != NONE)
            return 0;
        return squareGeneration(chess,start-1,start) == 0 &&
            squareGeneration(chess,start-2,start) == 0;
    }
}


int pawnLegal(Piece* board, int r, int start, int end)
{
    if (r != 0)
    {
        if(r == 3)
        {
            //printf("start : %i and end %i\n",start,end);
            if(board[start].color == BLACK)
            {
                if(start + MAX_RANK + 1 == end)
                {
                    if(board[start + MAX_RANK + 1].type != NONE &&
                            start % 8 != 7)
                        return 1;

                }
                if(start + MAX_RANK - 1 == end)
                {
                    if(board[start + MAX_RANK - 1].type != NONE &&
                            start % 8 != 0)
                        return 1;
                }
            }
            else
            {
                if(start - MAX_RANK + 1 == end)
                {
                    if(board[start - MAX_RANK + 1].type != NONE &&
                            start % 8 != 7)
                        return 1;
                }
                if(start - MAX_RANK - 1 == end)
                {
                    if(board[start - MAX_RANK - 1].type != NONE &&
                            start % 8 != 0)
                        return 1;
                }

            }
            return 0;
        }
        if(board[start].color == WHITE)
        {
            if (r == 1)
            {
                if(board[start - MAX_RANK].type == NONE)
                    return 1;
            }
            if(r == 2)
            {
                if(board[start - MAX_RANK].type == NONE &&
                        board[start - 2*MAX_RANK].type == NONE)
                    return 1;
            }
        }
        else
        {
            if (r == 1)
            {
                if(board[start + MAX_RANK].type == NONE)
                    return 1;
            }
            if(r == 2)
            {
                if(board[start + MAX_RANK].type == NONE &&
                        board[start + 2*MAX_RANK].type == NONE)
                    return 1;
            }
        }
        return 0;
    }
    return 0;
}

int tryMove(Chess chess, int x1, int x2)
{
    if(chess.board[x2].type == 0)
    {
        chess.board[x2].type = chess.board[x1].type;
        chess.board[x2].color = chess.board[x1].color;
        chess.board[x2].hasMoved = 1;
        chess.board[x1].type = 0;
    }
    else
    if(chess.board[x1].type == KING && chess.board[x2].type == ROOK &&
                !chess.board[x1].hasMoved && !chess.board[x2].hasMoved)
    {

        if(x2 > x1) // Castle Kingside
        {

            chess.board[x1+1] = chess.board[x2];
            chess.board[x1+1].hasMoved = 1;
            chess.board[x1+2] = chess.board[x1];
            chess.board[x1+2].hasMoved = 1;

            chess.board[x1].type = NONE;
            chess.board[x2].type = NONE;

        }
        else // Castle Queenside
        {
            chess.board[x1-1] = chess.board[x2];
            chess.board[x1-2] = chess.board[x1];
            chess.board[x1-1].hasMoved =  1;
            chess.board[x1-2].hasMoved = 1;


            chess.board[x1].type = NONE;
            chess.board[x2].type = NONE;
        }
    }
    else
    if(chess.board[x2].type != 0 && chess.board[x2].color != chess.board[x1].color)
    {
        chess.board[x2].type = chess.board[x1].type;
        chess.board[x2].color = chess.board[x1].color;
        chess.board[x2].hasMoved = 1;
        chess.board[x1].type = 0;
    }
    //printf("check after move : %i \n",check(chess,chess.board[x2].color));
    return check(chess,chess.board[x2].color);
}

int legalMoves(Chess chess,int start, int end, int check)
{
    int dir;
    int r;
    int canCastle;
    struct Piece* board = chess.board;
    //if((board[start].color == board[end].color && board[end].type == NONE) && piece.type != KING)
    //   return 0;
    if(board[start].type != NONE && board[end].type != NONE)
    {
        if(board[start].color == board[end].color &&
                !(board[start].type == KING && board[end].type == ROOK))
            return 0;
    }



    switch(board[start].type)
    {
        case PAWN:
            r = pawnMoves(start,end,board[start]);
            dir = pawnLegal(chess.board,r,start,end);
            if(dir == 0)
                return 0;
            break;

        case KNIGHT:
            dir = knightMoves(start,end);
            if(dir == 0)
                return 0;
            break;

        case BISHOP:
            dir = bishopMoves(start,end);
            dir = bishopLegal(start,end,dir,board);
            if(dir == 0)
                return 0;
            break;

        case ROOK:
            dir = rookMoves(start,end);
            dir = rookLegal(start,end,dir,board);
            if(dir == 0)
                return 0;
            break;

        case QUEEN:
            dir = queenMoves(start,end,board);
            //b = bishopLegal(start,end,dir,board);
            //r = rookLegal(start,end,dir,board);
            //printf("start %i, end %i\n",start,end);
            //printf("dir : %i\n",dir);
            if(dir == 0)
                return 0;
            break;

        case KING:
            dir = kingMoves(start,end);
            canCastle = 0;
            if(dir == 2)
            {
                if(!chess.turn && !chess.BC && !chess.check && start == 4)
                    canCastle = 1;
                if(chess.turn && !chess.WC && !chess.check && start == 60)
                    canCastle = 1;
            }
            if(dir == 1)
            {
                if(squareGeneration(chess,end,start))
                    // cannot go on attacked square // self check
                    return 0;
                break;
            }
            if(dir == 2 && !board[start].hasMoved && canCastle)
            {
                dir = castleLegal(chess,start,end);
                if(dir == 0)
                    return 0;
                break;
            }
            return 0;
            break;

        case NONE:
            break;
    }

    //        printf("I'm checked !\n");
    Chess* cs = malloc(sizeof(Chess));
    cs->check = chess.check;
    cs->BC = chess.BC;
    cs->WC = chess.WC;
    Piece* bd = malloc(64*sizeof(Piece));
    for(int i = 0; i < 64; i++)
        bd[i] = chess.board[i];
    cs->board = bd;

    check = tryMove(*cs,start,end);
    if(check)
        return 0;
    free(cs);
    free(bd);
    return 1;
}

int checkmate(Chess* chess)
{
    // generate all moves from allies
    // if any moves prevent checkmate return 0

    int size = 0;

    Move* moves = movesGeneration(*chess,&size);

    for(int i = 0; i < size; i++)
    {
        Move move = moves[i];
        Chess* chessCpy = malloc(sizeof(Chess));
        Piece* bdCpy = malloc(sizeof(Piece));
        memcpy(bdCpy,chess->board,64*sizeof(Piece));
        memcpy(chessCpy,chess,sizeof(Chess));

        chessCpy->board = bdCpy;
        makeMove(chessCpy,move.start,move.end);
        if(!chessCpy->check)
            return 0;
    }
    return 1;
}

int check(Chess chess, int color)
{
    for(int i = 0; i < 64; i++)
    {
        if(chess.board[i].type == KING && (int)chess.board[i].color == color)
        {
            //printf("pos of king %i  and current check : %i\n",i,chess.check);
            if(squareGeneration(chess,i,i))
            {
                return 1;
            }
        }
    }
    return 0;
}

void updateChess(Chess* chess)
{
    chess->check = check(*chess,chess->turn);
}
