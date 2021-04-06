#ifndef CHESSAI_H
#define CHESSAI_H

//region tables
extern const int pawnstable[];

extern const int knightstable[];

extern const int bishopstable[];

extern const int rookstable[];

extern const int queenstable[];

extern const int kingstable[];

int minmax(Chess *chess, int alt, int depth, int alpha, int beta);
int evaluateBoard(struct Piece* board, int bonus);
Move selectMove(Chess *chess, int depth, int turn);

//static int piecesValues[5] = {100,320,330,500,900};

/*typedef struct
{
    Piece* board;
    int nbPieces;
    int turn;
    int WC; // White Castle
    int BC; // Black Castle
}ChessOld;
*/

#endif
