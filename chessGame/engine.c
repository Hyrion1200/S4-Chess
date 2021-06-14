#include "board.h"
#include "uci.h"
#include <stdlib.h>
#include "moves.h"
#include "AI/chessAI.h"
#include <err.h>
#include <stdio.h>
#include "visual.h"

char* engine(int* moves)
{

    struct Piece* bd = board();
    Chess* chess = malloc(sizeof(Chess));
    chess->board = bd;
    chess->turn = 1;
    chess->WC = 0;
    chess->BC = 0;
    for(int i = 0; moves[i] != 99; i+=2)
    {
        printf("C : move start : %i //",moves[i]);
        printf("C : move end : %i\n",moves[i+1]);
        /*if(chess->board[end].type == 0)
        {
            chess->board[end].type = chess->board[start].type;
            chess->board[end].color = chess->board[start].color;
            chess->board[end].hasMoved = 1;
            chess->board[start].type = 0;
        }
        else if (chess->board[start].type == KING && ((end == start-2) || end == start + 2) )
        {
            chess->board[start+1]
        }*/
        makeMoveStats(chess,moves[i],moves[i+1]);
    }

    //getStat(chess); //TODO in board.c, complete fenBoard with castling right player to play
    printBoard(chess->board);
    Move mv = selectMove(chess,4, -9999, 9999);
    free(chess->board);
    free(chess);
    printf("C: mv.start %i\n",mv.start);
    printf("C: mv.start %i\n",mv.end);
    printf("C : move %s\n",intToUci(mv.start,mv.end));
    return intToUci(mv.start,mv.end);
}
