#include "uci.h"
#include <stdio.h>
#include "moves.h"
#include <stdlib.h>

#define SIZE 5

char* intToUci(int start, int end)
{
    char* result = malloc(sizeof(char) * SIZE);

    result[0] = column(start);
    result[1] = line(start);
    result[2] = column(end);
    result[3] = line(end);
    result[4] = '\0';
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
    printf("C : result result : %s",result);
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

char line(int y)
{
    if(y < 8)
        return 8 + '0';
    else if(y < 16)
        return 7 + '0';
    else if(y < 24)
        return 6 + '0';
    else if(y < 32)
        return 5 + '0';
    else if(y < 40)
        return 4 + '0';
    else if(y < 48)
        return 3 + '0';
    else if(y < 56)
        return 2 + '0';
    else if(y < 64)
        return 1 + '0';

    return 0 + '0'; // err should not happen;
}
