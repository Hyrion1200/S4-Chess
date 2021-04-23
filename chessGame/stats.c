#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

Stats* initStats()
{
    Stats* stats = malloc(sizeof(Stats));
    stats->pawn = 0;
    stats->knight = 0;
    stats->bishop = 0;
    stats->rook = 0;
    stats->queen = 0;
    stats->king = 0;
    stats->capture = 0;
    stats->checkmate = 0;

    return stats;
}
