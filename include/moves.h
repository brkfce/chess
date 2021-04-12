#ifndef MOVES_H
#define MOVES_H

#include "pieces.h"
#include <stdlib.h>

class Board;

struct move{
    int start_index;
    int end_index;
    int enpassant;  // the square a enpassant'ing pawn would move to
    int castling;
    Board * origin_board;
    Board * new_board;
    move * child_move;
    move * prev_move;
    int legality;
};

move * createMove(int, int, int, int, int, Board *, move *);

void deleteMoves(move *);

int checkMove(int, int, int *);

move * knightMoves(move *, Board *, int, int);
move * rookMoves(move *, Board *, int, int);
move * bishopMoves(move *, Board *, int, int);
move * queenMoves(move *, Board *, int, int);
move * kingMoves(move *, Board *, int, int, int, int);
move * whitepawnMoves(move *, Board *, int);
move * blackpawnMoves(move *, Board *, int);

#endif