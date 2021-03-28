#ifndef MOVES_H
#define MOVES_H

#include <stdlib.h>
#include "simpleboard.h"

struct move{
    int start_index;
    int end_index;
    int enpassant;
    int castling;
    Board * origin_board;
    move * next_move;
};

move * createMove(int, int, int, int, Board *, move *);

move * knightMoves(move *, Board *, int);
move * rookMoves(move *);
move * bishopMoves(move *);
move * queenMoves(move *);
move * kingMoves(move *);
move * whitepawnMoves(move *);
move * blackpawnMoves(move *);

#endif