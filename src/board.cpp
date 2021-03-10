#include "..\include\board.h"

// board constructor for FEN string
Board::Board(char *) {}



// board constructor for no FEN string
Board::Board(void) {
    // this can probably be optimised by pre-calculating the corresponding value and setting in one go
    
    // white pawns
    for (int i = 8; i < 16; i++) {
        whitePawns |= 1UL << i;
    }
    // white rooks;
    whiteRooks |= 1UL << 0;
    whiteRooks |= 1UL << 7;
    // white knights
    whiteKnights |= 1UL << 1;
    whiteKnights |= 1UL << 6;
    // white bishops
    whiteBishops |= 1UL << 2;
    whiteBishops |= 1UL << 5;
    // white queens
    whiteQueens |= 1UL << 4;
    // white kings
    whiteKings |= 1UL << 3;
    
    // black pawns
    for (int i = 48; i < 56; i++) {
        blackPawns |= 1UL << i;
    }
    // black rooks;
    blackRooks |= 1UL << 56;
    blackRooks |= 1UL << 63;
    // black knights
    blackKnights |= 1UL << 57;
    blackKnights |= 1UL << 62;
    // black bishops
    blackBishops |= 1UL << 58;
    blackBishops |= 1UL << 61;
    // black queens
    blackQueens |= 1UL << 60;
    // black kings
    blackKings |= 1UL << 59;

    whitePieces = whitePawns | whiteRooks | whiteKnights | whiteBishops | whiteQueens | whiteKings;
    blackPieces = blackPawns | blackRooks | blackKnights | blackBishops | blackQueens | blackKings;
    allPieces = whitePieces | blackPieces;
}



// board destructor
Board::~Board(void){}



// function to check if a FEN string is valid
int validateFEN(char *){}