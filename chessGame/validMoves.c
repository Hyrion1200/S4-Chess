#include "piece.h"
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
                for(int i = start; i < (end - MAX_RANK); i += MAX_RANK)
                {
                    if(board[i].type != NONE)
                        return 0;
                }
            }
            else
            {
                for(int i = start; i > (end + MAX_RANK); i -= MAX_RANK)
                {
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
                for(int i = start; i < end-1; i++)
                {
                    if(board[i].type != NONE)
                        return 0;
                }
            }
            else
            {
                for(int i = start; i > end+1; i--)
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
    for(int i = start; i < MAX_RANK; i += MAX_RANK)
    {
        if(start + (n * MAX_RANK) + n == end)
            return 1;
        if(start + (n * MAX_RANK) - n == end)
            return 2;
        if(start - (n * MAX_RANK) + n == end)
            return 3;
        if(start - (n * MAX_RANK) - n == end)
            return 4;
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
    if(pawn.hasMoved) // Cannot move 2 up
    {
        if(WHITE)
        {
            if(start - MAX_RANK == end)
                return 1;

            //Take a piece
            if(start - MAX_RANK - 1 == end || start - MAX_RANK + 1 == end)
                return 1;
        }
        else // pawn is BLACK
        {
            if(start + MAX_RANK == end)
                return 1;

            // Take a piece
            if(start + MAX_RANK - 1 == end || start + MAX_RANK + 1 == end)
                return 1;

        }
        return 0;
    }
    else
    {
        if(WHITE)
        {
            if(start - MAX_RANK == end || start - (2*MAX_RANK) == end)
                return 1;

            //Take a piece
            if(start - MAX_RANK - 1 == end || start - MAX_RANK + 1 == end)
                return 1;

        }
        else // pawn is BLACK
        {
            if(start + MAX_RANK == end || start -(2*MAX_RANK) == end)
                return 1;

            // Take a piece
            if(start + MAX_RANK - 1 == end || start + MAX_RANK + 1 == end)
                return 1;


        }
        return 0;
    }
}

int knightMoves(int start, int end)
{
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

int queenMoves(int start, int end)
{
    int b = bishopMoves(start,end);
    int r = rookMoves(start,end);

    return (b || r);
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
    int b;
    int r;
    switch(piece.type)
    {
        case PAWN:
            r = pawnMoves(start,end,piece);
            if (r != 0)
            {
                if(r == 3)
                    return 1;

                if(WHITE)
                {
                    if (r == 1)
                    {
                        if(board[start - MAX_RANK].type == NONE)
                            return 1;
                    }
                    if(r == 2)
                    {
                        if(board[start - 2*MAX_RANK].type == NONE)
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
            dir = queenMoves(start,end);
            b = bishopLegal(start,end,dir,board);
            r = rookLegal(start,end,dir,board);
            return b || r;
            break;

        case KING:
            dir = kingMoves(start,end);
            return dir;

        case NONE:
            break;
    }
    return 0;
}
