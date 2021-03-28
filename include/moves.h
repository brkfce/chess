#ifndef MOVES_H
#define MOVES_H

#include "pieces.h"
#include <stdlib.h>

class Board;

struct move{
    int start_index;
    int end_index;
    int enpassant;
    int castling;
    Board * origin_board;
    move * prev_move;
};

move * createMove(int, int, int, int, int, Board *, move *);

int checkMove(int, int, int *);

move * knightMoves(move *, Board *, int *, int, int);
move * rookMoves(move *);
move * bishopMoves(move *);
move * queenMoves(move *);
move * kingMoves(move *);
move * whitepawnMoves(move *);
move * blackpawnMoves(move *);

#endif