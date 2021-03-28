#ifndef SIMPLEBOARD_H
#define SIMPLEBOARD_H


#include "moves.h"

class Board
{
    public:
        Board(char **);     // create a board with a FEN string
        Board(void);        // create a new board 
        Board(int *);       // create a board for internal move evaluation
        ~Board(void);

        int checkSquare(int);
        move * generateMoves(Board *);
        void deleteMoves(move *);

    private:
        int board_state[64];
        int turn;
        int enpassant;
        int whiteKingside, whiteQueenside, blackKingside, blackQueenside;
};

#endif