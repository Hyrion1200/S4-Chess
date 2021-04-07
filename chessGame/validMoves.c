#include "piece.h"
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
                    if(board[i].type != NONE)
                        return 0;
                }
            }
            else
            {
                for(int i = start-1; i > end; i--)
                {
                    if(board[i].type != NONE)
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
    int n = 1;

    int b1 = 1;
    int b2 = 1;
    int b3 = 1;
    int b4 = 1;

    for(int i = start; i < MAX_RANK; i += MAX_RANK)
    {
        int x1 = start + (n*MAX_RANK) + n;
        int x2 = start + (n*MAX_RANK) - n;
        int x3 = start - (n*MAX_RANK) + n;
        int x4 = start - (n*MAX_RANK) - n;

        if(x1 == end && b1)
            return 1;
        if(x2 == end && b2)
            return 2;
        if(x3 == end && b3)
            return 3;
        if(x4 == end && b4)
            return 4;

        // it is not the end
        // if we are on the edge of the board with must prevent this direction
        if(x1 % 8 == 7 || x1 < 8) // Right edge or Top edge
            b1 = 0;
        if(x2 % 8 == 0 || x1 < 8) // Left edge or Top edge
            b2 = 0;
        if(x3 % 8 == 7 || x1 > 55) // Right edge or Bottom edge
            b3 = 0;
        if(x4 % 8 == 0 || x1 > 55) // Left edge or Bottom edge
            b4 = 0;
        n++;
    }
    return 0;
}

int bishopLegal(int start, int end, int r, struct Piece board[])
{
    if(r == 1)
    {
        int n = 1;
        for(int i = start; i < MAX_RANK; i += MAX_RANK)
        {
            if(start + (n * MAX_RANK) + n != end)
            {
                if(board[start + (n * MAX_RANK) + n].type != NONE)
                {
                    return 0;
                }
            }
            n++;
        }
        return 1;
    }
    if(r == 2)
    {
        int n = 1;
        for(int i = start; i < MAX_RANK; i += MAX_RANK)
        {
            if(start + (n * MAX_RANK) - n != end)
            {
                if(board[start + (n * MAX_RANK) - n].type != NONE)
                {
                    return 0;
                }
            }
            n++;
        }
        return 1;
    }
    if(r == 3)
    {
        int n = 1;
        for(int i = start; i < MAX_RANK; i += MAX_RANK)
        {
            if(start - (n * MAX_RANK) + n != end)
            {
                if(board[start - (n * MAX_RANK) + n].type != NONE)
                {
                    return 0;
                }
            }
            n++;
        }
        return 1;
    }
    if(r == 4)
    {
        int n = 1;
        for(int i = start; i < MAX_RANK; i += MAX_RANK)
        {
            if(start - (n * MAX_RANK) - n != end)
            {
                if(board[start - (n * MAX_RANK) - n].type != NONE)
                {
                    return 0;
                }
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
            if(start - MAX_RANK == end || start - (2*MAX_RANK) == end)
                return 1;

            //Take a piece
            if(start - MAX_RANK - 1 == end || start - MAX_RANK + 1 == end)
                return 3;

        }
        else // pawn is BLACK
        {
            if(start + MAX_RANK == end || start +(2*MAX_RANK) == end)
                return 1;

            // Take a piece
            if(start + MAX_RANK - 1 == end || start + MAX_RANK + 1 == end)
                return 3;


        }
        return 0;
    }
}

int knightMoves(int start, int end)
{
    if(end > start) // prevent knight from doing weird movements
    {
        if(end - start < MAX_RANK)
            return 0;
    }
    else
    {
        if(start - end < MAX_RANK)
            return 0;
    }
    //
    if(start + 2*MAX_RANK + 1 == end || start + 2*MAX_RANK - 1 == end)
        return 1;

    if(start - 2*MAX_RANK + 1 == end || start - 2*MAX_RANK - 1 == end)
        return 1;


    if(start + MAX_RANK + 2 == end || start + MAX_RANK - 2 == end)
        return 1;

    if(start - MAX_RANK + 2 == end || start - MAX_RANK - 2 == end)
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

    if(start + 1 == end || start - 1 == end)
        return 1;

    if(start + MAX_RANK == end || start - MAX_RANK == end)
        return 1;

    if(start + MAX_RANK + 1 == end || start + MAX_RANK - 1 == end)
        return 1;

    if(start - MAX_RANK + 1 == end || start - MAX_RANK - 1 == end)
        return 1;

    return 0;
}

int legalMoves(struct Piece board[],int start, int end, struct Piece piece)
{
    int dir;
    int r;
    //if((board[start].color == board[end].color && board[end].type == NONE) && piece.type != KING)
     //   return 0;
    if(board[start].type != NONE && board[end].type != NONE)
    {
        if(board[start].color == board[end].color)
            return 0;
    }
    switch(piece.type)
    {
        case PAWN:
            r = pawnMoves(start,end,piece);
            if (r != 0)
            {
                if(r == 3)
                {
                    //printf("start : %i and end %i\n",start,end);
                    if(piece.color == BLACK)
                    {
                        if(board[start + MAX_RANK + 1].type != NONE && start % 8 != 7)
                            return 1;
                        if(board[start + MAX_RANK - 1].type != NONE && start % 8 != 0)
                            return 1;
                    }
                    else
                    {
                        if(board[start - MAX_RANK + 1].type != NONE && start % 8 != 7)
                            return 1;
                        if(board[start - MAX_RANK - 1].type != NONE && start % 8 != 0)
                            return 1;

                    }
                    return 0;
                }
                if(piece.color == WHITE)
                {
                    if (r == 1)
                    {
                        if(board[start - MAX_RANK].type == NONE ||
                                board[start - 2*MAX_RANK].type == NONE)
                            return 1;
                    }
                    if(r == 2)
                    {
                        if(board[start - MAX_RANK + 1].type != NONE ||
                                board[start - MAX_RANK - 1].type != NONE)
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
                        if(board[start + 2*MAX_RANK].type == NONE)
                            return 1;
                    }
                }
                return 0;
            }
            return 0;
            break;

        case KNIGHT:
            return knightMoves(start,end);
            break;

        case BISHOP:
            dir = bishopMoves(start,end);
            return bishopLegal(start,end,dir,board);
            break;

        case ROOK:
            dir = rookMoves(start,end);
            return rookLegal(start,end,dir,board);
            break;

        case QUEEN:
            dir = queenMoves(start,end,board);
            //b = bishopLegal(start,end,dir,board);
            //r = rookLegal(start,end,dir,board);
            //printf("start %i, end %i\n",start,end);
            //printf("dir : %i\n",dir);
            return dir;
            break;

        case KING:
            dir = kingMoves(start,end);
            return dir;

        case NONE:
            break;
    }
    return 0;
}
