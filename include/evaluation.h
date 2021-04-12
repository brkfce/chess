#ifndef EVALUATION_H
#define EVALUATION_H

#include "pieces.h"
#include "simpleboard.h"
#include "moves.h"

move * genLegalMoves(Board *);

move * genBestMove(Board *);

Board * updateBoard(move *);



#endif