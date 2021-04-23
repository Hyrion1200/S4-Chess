#include "uci.h"
#include <stdlib.h>

#define SIZE 4

char* intToUci(int start, int end)
{
    char* result = malloc(sizeof(char) * SIZE);

    result[0] = column(start);
    result[1] = line(start);
    result[2] = column(end);
    result[3] = line(end);

    /*switch (type)
    {
        case PAWN:
            break;
        case KNIGHT:
            break;
        case BISHOP:
            break;
        case ROOK:
            break;
        case QUEEN:
            break;
        case KING:
            break;
    }*/

    return result;
}

char column(int x)
{
    switch(x%8)
    {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        case 7:
            return 'h';
    }
    return 'x'; // err should not happen;
}

int line(int y)
{
    if(y < 8)
        return 1;
    else if(y < 16)
        return 2;
    else if(y < 24)
        return 3;
    else if(y < 32)
        return 4;
    else if(y < 40)
        return 5;
    else if(y < 48)
        return 6;
    else if(y < 56)
        return 7;
    else if(y < 64)
        return 8;

    return 0; // err should not happen;
}
