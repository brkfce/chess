#include "../include/simpleboard.h"

// board constructor for FEN string
Board::Board(char ** FEN) {

    // board state
    for (int i = 0; i < 64; i++) {
        int j;      // to be used for empty spaces later
        // no validation necessary, as the FEN should have already been validated
        switch (FEN[0][i]) {
            case 'N' :
                board_state[i] = WHITEKNIGHT; break;
            case 'R' :
                board_state[i] = WHITEROOK; break;
            case 'B' : 
                board_state[i] = WHITEBISHOP; break;
            case 'Q' :
                board_state[i] = WHITEQUEEN; break;
            case 'K' :
                board_state[i] = WHITEKING; break;
            case 'P' :
                board_state[i] = WHITEPAWN; break;
            case 'n' :
                board_state[i] = BLACKKNIGHT; break;
            case 'r' :
                board_state[i] = BLACKROOK; break;
            case 'b' : 
                board_state[i] = BLACKBISHOP; break;
            case 'q' :
                board_state[i] = BLACKQUEEN; break;
            case 'k' :
                board_state[i] = BLACKKING; break;
            case 'p' :
                board_state[i] = BLACKPAWN; break;
            case '/' :
                i--;    // deliminator, should be ignored and the counter reset to start
                break;
            case '1' :
                board_state[i] = EMPTY;
                break;
            case '2' :
                for (j = i; j < 2; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '3' :
                for (j = i; j < 3; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '4' :
                for (j = i; j < 4; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '5' :
                for (j = i; j < 5; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '6' :
                for (j = i; j < 6; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '7' :
                for (j = i; j < 7; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
            case '8' :
                for (j = i; j < 8; j++) {
                    board_state[j] = EMPTY;
                }
                i = j;
                break;
        }
    }

    // turn indicator
    switch(FEN[1][0]) {
        case 'w' :
            turn = WHITETURN; break;
        case 'b' :
            turn = BLACKTURN; break;
    }

    // castling
    int i = 0;
    if (FEN[2][0] == '-') {
        whiteKingside = whiteQueenside = blackKingside = blackQueenside = 0;
    }
    else {
        while (FEN[2][i] != '\0') {
            switch (FEN[2][i]) {
             case 'K' : whiteKingside = 1; break;
             case 'Q' : whiteQueenside = 1; break;
             case 'k' : blackKingside = 1; break;
             case 'q' : blackQueenside = 1; break;
            }
            i++;
        }
    }
    

    // enpassant
    if (FEN[3][0] == '-') {
        enpassant = NOENPASSANT;
    }
    else {
        enpassant = 0;
        switch (FEN[3][0]) {
            case 'a' :
                enpassant = enpassant + 0; break;
            case 'b' :
                enpassant = enpassant + 1; break;
            case 'c' :
                enpassant = enpassant + 2; break;
            case 'd' :
                enpassant = enpassant + 3; break;
            case 'e' :
                enpassant = enpassant + 4; break;
            case 'f' :
                enpassant = enpassant + 5; break;
            case 'g' :
                enpassant = enpassant + 6; break;
            case 'h' :
                enpassant = enpassant + 7; break;
        }
        switch(FEN[3][1]) {
            case '3' :
                enpassant = enpassant + 16; break;
            case '6' :
                enpassant = enpassant + 40; break;
        }
    }

    // halfmove
    int temp;
    halfmove = 0;
    while (FEN[4][i] != '\0') {
        switch (FEN[4][i]) {
             case '0' : temp = 0; break;
             case '1' : if (i == 1) temp = 1; if (i == 0) temp = 10; break;
             case '2' : if (i == 1) temp = 2; if (i == 0) temp = 20; break;
             case '3' : if (i == 1) temp = 3; if (i == 0) temp = 30; break;
             case '4' : if (i == 1) temp = 4; if (i == 0) temp = 40; break;
             case '5' : if (i == 1) temp = 5; if (i == 0) temp = 50; break;
             case '6' : if (i == 1) temp = 6; if (i == 0) temp = 60; break;
             case '7' : if (i == 1) temp = 7; if (i == 0) temp = 70; break;
             case '8' : if (i == 1) temp = 8; if (i == 0) temp = 80; break;
             case '9' : if (i == 1) temp = 9; if (i == 0) temp = 90; break;
        }
        i++;
        halfmove = halfmove + temp;
    }

    // fullmove
    int temp;
    fullmove = 0;
    while (FEN[4][i] != '\0') {
        switch (FEN[4][i]) {
             case '0' : temp = 0; break;
             case '1' : if (i == 2) temp = 1; if (i == 1) temp = 10; if (i == 0) temp = 100; break;
             case '2' : if (i == 2) temp = 2; if (i == 1) temp = 20; if (i == 0) temp = 200; break;
             case '3' : if (i == 2) temp = 3; if (i == 1) temp = 30; if (i == 0) temp = 300; break;
             case '4' : if (i == 2) temp = 4; if (i == 1) temp = 40; if (i == 0) temp = 400; break;
             case '5' : if (i == 2) temp = 5; if (i == 1) temp = 50; if (i == 0) temp = 500; break;
             case '6' : if (i == 2) temp = 6; if (i == 1) temp = 60; if (i == 0) temp = 600; break;
             case '7' : if (i == 2) temp = 7; if (i == 1) temp = 70; if (i == 0) temp = 700; break;
             case '8' : if (i == 2) temp = 8; if (i == 1) temp = 80; if (i == 0) temp = 800; break;
             case '9' : if (i == 2) temp = 9; if (i == 1) temp = 90; if (i == 0) temp = 900; break;
        }
        i++;
        fullmove = fullmove + temp;
    }
}

// board constructor for new game
Board::Board(void) {

    board_state[0] = board_state[7] = WHITEROOK;
    board_state[1] = board_state[6] = WHITEKNIGHT;
    board_state[2] = board_state[5] = WHITEBISHOP;
    board_state[3] = WHITEQUEEN; board_state[4] = WHITEKING;
    board_state[8] = board_state[9] = board_state[10] = board_state[11] = WHITEPAWN;
    board_state[12] = board_state[13] = board_state[14] = board_state[15] = WHITEPAWN;
    board_state[16] = board_state[17] = board_state[18] = board_state[19] = EMPTY;
    board_state[20] = board_state[21] = board_state[22] = board_state[23] = EMPTY;
    board_state[24] = board_state[25] = board_state[26] = board_state[27] = EMPTY;
    board_state[28] = board_state[29] = board_state[30] = board_state[31] = EMPTY;
    board_state[32] = board_state[33] = board_state[34] = board_state[35] = EMPTY;
    board_state[36] = board_state[37] = board_state[38] = board_state[39] = EMPTY;
    board_state[40] = board_state[41] = board_state[42] = board_state[43] = EMPTY;
    board_state[44] = board_state[45] = board_state[46] = board_state[47] = EMPTY;
    board_state[48] = board_state[49] = board_state[50] = board_state[51] = BLACKPAWN;
    board_state[52] = board_state[53] = board_state[54] = board_state[55] = BLACKPAWN;
    board_state[56] = board_state[63] = BLACKROOK;
    board_state[57] = board_state[62] = BLACKKNIGHT;
    board_state[58] = board_state[61] = BLACKBISHOP;
    board_state[59] = BLACKQUEEN; board_state[60] = BLACKKING;

    turn = WHITETURN;
    enpassant = 0;
    whiteKingside = whiteQueenside = blackKingside = blackQueenside = 1;
    halfmove = 0;
    fullmove = 1;

}


// board destructor
Board::~Board(void) {}

int Board::checkSquare(int index) {
    return board_state[index];
}

move * Board::generateMoves(Board * this_board) {
    // go through the board, generating a list of moves that are pseudolegal
    move * current_move;
    for (int i = 0; i < 64; i++) {
        switch(board_state[i]) {
            case WHITEKNIGHT:
                current_move = knightMoves(current_move, this_board, board_state, i, WHITETURN);
                break;
            case BLACKKNIGHT:
                current_move = knightMoves(current_move, this_board, board_state, i, BLACKTURN);
                break;
            case WHITEROOK:
                current_move = rookMoves(current_move, this_board, board_state, i, WHITETURN);
                break;
            case BLACKROOK:
                current_move = rookMoves(current_move, this_board, board_state, i, BLACKTURN);
                break;
            case WHITEBISHOP:
                current_move = bishopMoves(current_move, this_board, board_state, i, WHITETURN);
                break;
            case BLACKBISHOP:
                current_move = bishopMoves(current_move, this_board, board_state, i, BLACKTURN);
                break;
            case WHITEQUEEN:
                current_move = queenMoves(current_move, this_board, board_state, i, WHITETURN);
                break;
            case BLACKQUEEN:
                current_move = queenMoves(current_move, this_board, board_state, i, BLACKTURN);
                break;
            case WHITEKING:
                current_move = kingMoves(current_move, this_board, board_state, i, WHITETURN, whiteKingside, whiteQueenside);
                break;
            case BLACKKING:
                current_move = kingMoves(current_move, this_board, board_state, i, BLACKTURN, blackKingside, blackQueenside);
                break;
            case WHITEPAWN:
                current_move = whitepawnMoves(current_move, this_board, board_state, i, enpassant);
                break;
            case BLACKPAWN:
                current_move = blackpawnMoves(current_move, this_board, board_state, i, enpassant);
        }
    }
    return current_move;
}

void Board::deleteMoves(move * starting_move) {
    // go through the list of moves, deallocating the space for each
    move * current_move = starting_move;
    move * temp_move;
    while (current_move != NULL) {
        temp_move = current_move;
        current_move = current_move->prev_move;
        free(temp_move);
    }
}

