#include "board.h"
#include "piece.h"
#include "validMoves.h"
#include <stdio.h>

int main()
{
    printf("?");
    struct Piece** bd = board();
    for (size_t i = 0; i < 64; i++)
    {
        if(i%8 == 0)
            printf("\n");
        printf("%i | ",bd[i]->type);
    }
    printf("Hey !");

    free_board(bd);
    return 0;
}
