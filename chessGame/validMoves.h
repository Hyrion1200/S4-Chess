#ifndef VALIDMOVES_H
#define VALIDMOVES_H

int rookMoves(int start, int end); // return 1 if the move can be legal, 0 otherwise

int bishopMoves(int start, int end); // return 1 SE / 2 SW / 3 NE / 4 NW / 0 otherwise

int pawnMoves(int start, int end, struct Piece pawn);
// return 1 if the moves forward 2 for 2 moves, 3 if he wants to take another piece, 0 otherwise

int knightMoves(int start, int end); // same

int queenMoves(int start, int end); // same

int kingMoves(int start, int end); // return 1 if the move CAN be legal, 0 otherwise
                                   // return 2 if castle
                                   //
int legalMoves(struct Piece* board, int start, int end, struct Piece piece);

#endif
