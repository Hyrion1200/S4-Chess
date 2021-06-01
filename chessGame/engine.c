#include "board.h"
#include "uci.h"
#include <stdlib.h>
#include <AI/chessAI.h>
#include <err.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        errx(1,"Not enough args, exiting app...");
    }
    struct Piece* bd = fenBoard(argv[1]);
    Chess* chess = malloc(sizeof(Chess));
    getStat(chess); //TODO in board.c, complete fenBoard with castling right player to play

    Move mv = selectMove(chess,atoi(argv[2]), -9999, 9999);
    return intToUci(mv.start,mv.end);
}
