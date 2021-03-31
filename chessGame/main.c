#include "board.h"
#include "piece.h"
#include "validMoves.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("?");
    struct Piece* bd = board();
    for (size_t i = 0; i < 64; i++)
    {
        if(i%8 == 0)
            printf("\n");

	if(bd[i].type == 1)
	    printf("P | ");

	if(bd[i].type == 2)
	    printf("R | ");

	if(bd[i].type == 3)
	    printf("B | ");

	if(bd[i].type == 4)
	    printf("k | ");

	if(bd[i].type == 5)
	    printf("Q | ");

	if(bd[i].type == 6)
	    printf("K | ");
    }
    printf("Hey !");

    //free_board(bd);
    free(bd);
    return 0;
}
