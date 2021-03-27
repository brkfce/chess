#ifndef SIMPLEBOARD_H
#define SIMPLEBOARD_H

#include "pieces.h"
#include "moves.h"

class Board
{
    public:
        Board(char **);     // create a board with a FEN string
        Board(void);        // create a new board 
        Board(int *);       // create a board for internal move evaluation
        ~Board(void);

        move * generateMoves(void);
        move * deleteMoves(void);

    private:
        int board_state[64];
        int move;
        int enpassant;
        int whiteKingside, whiteQueenside, blackKingside, blackQueenside;
};

#endif