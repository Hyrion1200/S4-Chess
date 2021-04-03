#include "board.h"
#include "piece.h"
#include "validMoves.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Piece* bd = board();
    int n = 1;
    
    while(n < 4)
    {
        for (size_t i = 0; i < 64; i++)
	{
	    if(i%8 == 0)
	        printf("\n|");

	    if(bd[i].type == 1)
	        printf("P | ");

	    if(bd[i].type == 2)
	        printf("R | ");

	    if(bd[i].type == 3)
	        printf("B | ");

	    if(bd[i].type == 4)
	        printf("N | ");

	    if(bd[i].type == 5)
	        printf("Q | ");

	    if(bd[i].type == 6)
	        printf("K | ");

	    if(bd[i].type == 0)
	        printf("  | ");
	}

	printf("\n|");
	
	if(n%2 != 0)
	{
	    int x1;

	    int x2;
	    
	    printf("Player 1, enter the coordinate of the piece you want to move : ");
	    scanf("%d", &x1);

	    printf("Player 1, enter the coordinate where you want to move this piece : ");
	    scanf("%d", &x2);

	    if(legalMoves(bd, x1, x2, bd[x1]))
	    {
	        int p = bd[x1].type;
		bd[x1].type = 0;
		bd[x2].type = p;
		n += 1;
	    }

	    else
	    {
	        printf("Illegal move");
	    }
	}

	else
	{
	    int x1;

	    int x2;
	    
	    printf("Player 2, enter the coordinate of the piece you want to move : ");
	    scanf("%d", &x1);

	    printf("Player 2, enter the coordinate where you want to move this piece : ");
	    scanf("%d", &x2);

	    if(legalMoves(bd, x1, x2, bd[x1].type))
	    {
	        int p = bd[x1].type;
		bd[x1].type = 0;
		bd[x2].type = p;
		n += 1;
	    }

	    else
	    {
	        printf("Illegal move");
	    }
	}
    }

    free(bd);
    return 0;
}
