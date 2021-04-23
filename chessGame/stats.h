#ifndef STATS_H
#define STATS_H

typedef struct
{
    int pawn;
    int knight;
    int bishop;
    int rook;
    int queen;
    int king;
    int capture;
    int checkmate;
}Stats;

Stats* initStats();

#endif
