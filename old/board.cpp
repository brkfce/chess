#include "../include/board.h"

// board constructor for FEN string
Board::Board(char **) {}



// board constructor for no FEN string
Board::Board(void) {
    // this can probably be optimised by pre-calculating the corresponding value and setting in one go
    
    // white pawns
    whitePawns = 65280;
    // white rooks;
    whiteRooks = 129;
    // white knights
    whiteKnights = 66;
    // white bishops
    whiteBishops = 36;
    // white queens
    whiteQueens = 8;
    // white kings
    whiteKings = 16;
    
    // black pawns
    blackPawns = 4486007441326080;
    
    // black rooks;
    blackRooks = 9295429630892703744U;
    // black knights
    blackKnights = 4755801206503243776;
    // black bishops
    blackBishops = 2594073385365405696;
    // black queens
    blackQueens = 576460752303423488;
    // black kings
    blackKings  = 1152921504606846976;

    whitePieces = whitePawns | whiteRooks | whiteKnights | whiteBishops | whiteQueens | whiteKings;
    blackPieces = blackPawns | blackRooks | blackKnights | blackBishops | blackQueens | blackKings;
    allPieces = whitePieces | blackPieces;
}



// board destructor
Board::~Board(void){}

#include <iostream>

// function to construct a readable FEN string from cin
int constructFEN(char * FEN1, char * FEN2, char * FEN3, char * FEN4, char * FEN5, char * FEN6, char *  input) {
    
    int overallcounter = 0, fencounter = 0, charcounter = 0;
    char writechar;
        
    while (input[overallcounter] != '\0') {      // seperate the different parts of the FEN
        if (input[overallcounter] == ' ') {
              writechar = '\0';
        }

        else {writechar = input[overallcounter];}        // identify which part of the FEN is required
            
        switch (fencounter) {
            case 0 : FEN1[charcounter] = writechar; break;
            case 1 : FEN2[charcounter] = writechar; break;
            case 2 : FEN3[charcounter] = writechar; break;
            case 3 : FEN4[charcounter] = writechar; break;
            case 4 : FEN5[charcounter] = writechar; break;
            case 5 : FEN6[charcounter] = writechar; break;
            default : return 1;
        }

        overallcounter++;
        charcounter++;

        if (writechar == '\0') {charcounter = 0; fencounter++;}

    } if (charcounter != 3) FEN6[charcounter] = '\0';   // to account for the loop ending early
    
    return 0; 
}

// function to check if a FEN string is valid (not if the board state is legal, only that the FEN can be interpreted)
int validateFEN(char ** FEN){
    // check main body of FEN
    char * fenBoard = FEN[0];
    int i = 0;
    // counts for the number of each piece in the FEN
    int whiteKing, whiteQueen, whiteBishop, whiteKnight, whiteRook, whitePawn, blackKing, blackQueen, blackBishop, blackKnight, blackRook, blackPawn, slashes, emptySquares, isNumber, linecounter, isPawn;
    whiteKing = whiteQueen = whiteBishop = whiteKnight = whiteRook = whitePawn = blackKing = blackQueen = blackBishop = blackKnight = blackRook = blackPawn = slashes = emptySquares = isNumber = linecounter = isPawn = 0;
    while (fenBoard[i] != '\0') {
        switch (fenBoard[i]) {
            case '/' : slashes++; isNumber = 0; linecounter = 0; isPawn = 0; break; // reset the linecounter
            case 'K' : whiteKing++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'Q' : whiteQueen++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'B' : whiteBishop++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'N' : whiteKnight++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'R' : whiteRook++; isNumber = 0; linecounter++; isPawn = 0; break;             // presumably this can be done better
            case 'P' : whitePawn++; isNumber = 0; linecounter++; isPawn = 1; break;
            case 'k' : blackKing++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'q' : blackQueen++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'b' : blackBishop++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'n' : blackKnight++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'r' : blackRook++; isNumber = 0; linecounter++; isPawn = 0; break;
            case 'p' : blackPawn++; isNumber = 0; linecounter++; isPawn = 1; break;
            case '1' : emptySquares++; isNumber++; linecounter+=1; isPawn = 0; break;
            case '2' : emptySquares+=2; isNumber++; linecounter+=2; isPawn = 0; break;
            case '3' : emptySquares+=3; isNumber++; linecounter+3; isPawn = 0; break;
            case '4' : emptySquares+=4; isNumber++; linecounter+4; isPawn = 0; break;
            case '5' : emptySquares+=5; isNumber++; linecounter+5; isPawn = 0; break;
            case '6' : emptySquares+=6; isNumber++; linecounter+6; isPawn = 0; break;
            case '7' : emptySquares+=7; isNumber++; linecounter+7; isPawn = 0; break;
            case '8' : emptySquares+=8; isNumber++; linecounter+8; isPawn = 0; break;
            default : return(2);    // invalid symbol
        }
        if (isNumber > 1) {return(3);} // check that there are not two number in a row
        if (linecounter > 8) {return(4);} // check that there aren't too many pieces per row
        if ((slashes == 0 && isPawn == 1) || (slashes == 7 && isPawn ==1)) {return(5);}    // there cannot be pawns in the first or last row
        i++;
    }
    if (slashes != 7) {return(6);}
    if (whitePawn > 8 || blackPawn > 8 || whiteKing != 1 || blackKing != 1) {return(7);}
    int filledSquares = whiteKing + whiteQueen + whiteBishop + whiteKnight + whiteRook + whitePawn + blackKing + blackQueen + blackBishop + blackKnight + blackRook + blackPawn;
    if (filledSquares + emptySquares != 64) {return(8);}
    

    // check turn indicator is valid
    char * fenTurn = FEN[1];
    if (fenTurn[0] != 'w' && fenTurn[0] != 'b') {return(9);}


    //check castling indicator is valid
    char * fenCastling = FEN[2];
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
            default: return(10); // invalid symbol
        }
        i++;
    }
    if(whiteKingside > 1 || whiteQueenside > 1 || blackKingside > 1 || blackQueenside > 1 || noneAvailable > 1) {return(11);}
    if (whiteKingside + whiteQueenside + blackKingside + blackQueenside != 0 && noneAvailable == 1) {return(12);}


    // check enpassant validity
    char * fenEnPassant = FEN[3];
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
            default: return(13); // invalid symbol
        }
        i++;
    }
    if (validFile != 1 || validRank != 1) {return(14);}


    // check halfmove validity
    char * fenHalfMove = FEN[4];
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
            default : return(15); // invalid symbol
        }
        i++;
    }
    if (validHalfMove == 0) {return(16);}


    // check fullmove validity
    char * fenFullMove = FEN[5];
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
            default : return(17); // invalid symbol
        }
        i++;
    }
    if (validFullMove == 0) {return(18);}

    return(1);
}