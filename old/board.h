#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

// will be attempting to represent the board state using bitboards
typedef uint64_t BitBoard;


class Board
{
    public:
        Board(char **);
        Board(void);
        ~Board(void);


    private:
        BitBoard whitePawns;
        BitBoard whiteRooks;
        BitBoard whiteKnights;
        BitBoard whiteBishops;
        BitBoard whiteQueens;
        BitBoard whiteKings;

        BitBoard blackPawns;
        BitBoard blackRooks;
        BitBoard blackKnights;
        BitBoard blackBishops;
        BitBoard blackQueens;
        BitBoard blackKings;

        BitBoard whitePieces;
        BitBoard blackPieces;
        BitBoard allPieces;



};

// construct a FEN string from cin
int constructFEN(char *, char *, char *, char *, char *, char *, char *);

// function to check if a FEN string is valid
int validateFEN(char **);


#endif