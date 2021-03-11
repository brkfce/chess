#include "..\include\board.h"

// board constructor for FEN string
Board::Board(char **) {}



// board constructor for no FEN string
Board::Board(void) {
    // this can probably be optimised by pre-calculating the corresponding value and setting in one go
    
    // white pawns
    for (int i = 8; i < 16; i++) {
        whitePawns |= 1 << i;
    }
    // white rooks;
    whiteRooks |= 1 << 0;
    whiteRooks |= 1 << 7;
    // white knights
    whiteKnights |= 1 << 1;
    whiteKnights |= 1 << 6;
    // white bishops
    whiteBishops |= 1 << 2;
    whiteBishops |= 1 << 5;
    // white queens
    whiteQueens |= 1 << 4;
    // white kings
    whiteKings |= 1 << 3;
    
    // black pawns
    for (int i = 48; i < 56; i++) {
        blackPawns |= 1 << i;
    }
    // black rooks;
    blackRooks |= 1 << 56;
    blackRooks |= 1 << 63;
    // black knights
    blackKnights |= 1 << 57;
    blackKnights |= 1 << 62;
    // black bishops
    blackBishops |= 1 << 58;
    blackBishops |= 1 << 61;
    // black queens
    blackQueens |= 1 << 60;
    // black kings
    blackKings |= 1 << 59;

    whitePieces = whitePawns | whiteRooks | whiteKnights | whiteBishops | whiteQueens | whiteKings;
    blackPieces = blackPawns | blackRooks | blackKnights | blackBishops | blackQueens | blackKings;
    allPieces = whitePieces | blackPieces;
}



// board destructor
Board::~Board(void){}



// function to check if a FEN string is valid (not if the board state is legal, only that the FEN can be interpreted)
int validateFEN(char ** FEN){
    // check main body of FEN
    char * fenBoard = FEN[1];
    int i = 0;
    // counts for the number of each piece in the FEN
    int whiteKing, whiteQueen, whiteBishop, whiteKnight, whiteRook, whitePawn, blackKing, blackQueen, blackBishop, blackKnight, blackRook, blackPawn, slashes, emptySquares, isNumber, linecounter;
    whiteKing = whiteQueen = whiteBishop = whiteKnight = whiteRook = whitePawn = blackKing = blackQueen = blackBishop = blackKnight = blackRook = blackPawn = slashes = emptySquares = isNumber = linecounter = 0;
    while (fenBoard[i] != '\0') {
        switch (fenBoard[i]) {
            case '/' : slashes++; isNumber = 0; linecounter = 0; break; // reset the linecounter
            case 'K' : whiteKing++; isNumber = 0; linecounter++; break;
            case 'Q' : whiteQueen++; isNumber = 0; linecounter++; break;
            case 'B' : whiteBishop++; isNumber = 0; linecounter++; break;
            case 'N' : whiteKnight++; isNumber = 0; linecounter++; break;
            case 'R' : whiteRook++; isNumber = 0; linecounter++; break;
            case 'P' : whitePawn++; isNumber = 0; linecounter++; break;
            case 'k' : blackKing++; isNumber = 0; linecounter++; break;
            case 'q' : blackQueen++; isNumber = 0; linecounter++; break;
            case 'b' : blackBishop++; isNumber = 0; linecounter++; break;
            case 'n' : blackKnight++; isNumber = 0; linecounter++; break;
            case 'r' : blackRook++; isNumber = 0; linecounter++; break;
            case 'p' : blackPawn++; isNumber = 0; linecounter++; break;
            case '1' : emptySquares++; isNumber++; linecounter+=1; break;
            case '2' : emptySquares+=2; isNumber++; linecounter+=2; break;
            case '3' : emptySquares+=3; isNumber++; linecounter+3; break;
            case '4' : emptySquares+=4; isNumber++; linecounter+4; break;
            case '5' : emptySquares+=5; isNumber++; linecounter+5; break;
            case '6' : emptySquares+=6; isNumber++; linecounter+6; break;
            case '7' : emptySquares+=7; isNumber++; linecounter+7; break;
            case '8' : emptySquares+=8; isNumber++; linecounter+8; break;
            default : return(0);    // invalid symbol
        }
        if (isNumber >= 1) {return(0);} // check that there are not two number in a row
        if (linecounter != 8) {return(0);} // check that there are enough empty squares or pieces per row
        if ((slashes == 0 || slashes == 7) && (whitePawn != 0 || blackPawn != 0)) {return(0);}    // there cannot be pawns in the first or last row
        i++;
    }
    if (slashes != 7) {return(0);}
    if (whitePawn > 8 || blackPawn > 8 || whiteKing != 1 || blackKing != 1) {return(0);}
    int filledSquares = whiteKing + whiteQueen + whiteBishop + whiteKnight + whiteRook + whitePawn + blackKing + blackQueen + blackBishop + blackKnight + blackRook + blackPawn;
    if (filledSquares + emptySquares != 64) {return(0);}
    

    // check turn indicator is valid
    char * fenTurn = FEN[2];
    if (fenTurn[0] != 'w' && fenTurn[0] != 'b') {return(0);}


    //check castling indicator is valid
    char * fenCastling = FEN[3];
    i = 0;
    int whiteKingside, whiteQueenside, blackKingside, blackQueenside, noneAvailable;
    whiteKingside = whiteQueenside = blackKingside = blackQueenside = noneAvailable = 0;
    while (fenCastling[i] != '\0') {
        switch (fenCastling[i]) {
            case 'K' : whiteKingside++; break;
            case 'Q' : whiteQueenside++; break;
            case 'k' : blackKingside++; break;
            case 'q' : blackQueenside++; break;
            case '-' : noneAvailable++; break;
            default: return(0); // invalid symbol
        }
        i++;
    }
    if(whiteKingside > 1 || whiteQueenside > 1 || blackKingside > 1 || blackQueenside > 1 || noneAvailable > 1) {return(0);}
    if (whiteKingside + whiteQueenside + blackKingside + blackQueenside != 0 && noneAvailable == 1) {return(0);}


    // check enpassant validity
    char * fenEnPassant = FEN[4];
    i = 0;
    int validFile, validRank;
    validFile = validRank = 0;
    while (fenEnPassant[i] != '\0') {
        switch (fenEnPassant[i]) {
            case 'a' : validFile++; break;
            case 'b' : validFile++; break;
            case 'c' : validFile++; break;
            case 'd' : validFile++; break;
            case 'e' : validFile++; break;
            case 'f' : validFile++; break;
            case 'g' : validFile++; break;
            case 'h' : validFile++; break;
            case '4' : validRank++; break;
            case '6' : validRank++; break;
            case '-' : validFile++; validRank++; break;
            default: return(0); // invalid symbol
        }
        i++;
    }
    if (validFile != 1 || validRank != 1) {return(0);}


    // check halfmove validity
    char * fenHalfMove = FEN[5];
    i = 0;
    int validHalfMove = 0;
    while (fenHalfMove[i] != '\0') {
        switch (fenHalfMove[i]) {
            case '0' : validHalfMove++; break;
            case '1' : validHalfMove++; break;
            case '2' : validHalfMove++; break;
            case '3' : validHalfMove++; break;
            case '4' : validHalfMove++; break;
            case '5' : validHalfMove++; break;
            case '6' : validHalfMove++; break;
            case '7' : validHalfMove++; break;
            case '8' : validHalfMove++; break;
            case '9' : validHalfMove++; break;
            default : return(0); // invalid symbol
        }
        i++;
    }
    if (validHalfMove == 0) {return(0);}


    // check fullmove validity
    char * fenFullMove = FEN[6];
    i = 0;
    int validFullMove = 0;
    while (fenFullMove[i] != '\0') {
        switch (fenFullMove[i]) {
            case '0' : validFullMove++; break;
            case '1' : validFullMove++; break;
            case '2' : validFullMove++; break;
            case '3' : validFullMove++; break;
            case '4' : validFullMove++; break;
            case '5' : validFullMove++; break;
            case '6' : validFullMove++; break;
            case '7' : validFullMove++; break;
            case '8' : validFullMove++; break;
            case '9' : validFullMove++; break;
            default : return(0); // invalid symbol
        }
        i++;
    }
    if (validFullMove == 0) {return(0);}

    return(1);
}