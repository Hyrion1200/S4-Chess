#ifndef CHESSAI_H
#define CHESSAI_H

//region tables
extern const int pawnstable[];

extern const int knightstable[];

extern const int bishopstable[];

extern const int rookstable[];

extern const int queenstable[];

extern const int kingstable[];

int minmax(Chess *chess, int alt, int depth, int alpha, int beta, long* nodes);
int evaluateBoard(struct Piece* board, int bonus);
Move selectMove(Chess *chess, int depth, int alpha, int beta);
int perft(Chess* chess, int depth);
//static int piecesValues[5] = {100,320,330,500,900};


#endif
