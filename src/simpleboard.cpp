#include "../include/simpleboard.h"
#include <iostream>

// board constructor for FEN string
Board::Board(char ** FEN) {

    std::cout << "Starting Board..." << std::endl;

    // board state
    int i = 0;  // FEN counter
    int j = 0;  // board state counter
    int k = 0;  // temp counter
    while (FEN[0][i] != '\0') {
        // no validation necessary, as the FEN should have already been validated
        switch (FEN[0][i]) {
            case 'N' :
                board_state[j] = WHITEKNIGHT; break;
            case 'R' :
                board_state[j] = WHITEROOK; break;
            case 'B' : 
                board_state[j] = WHITEBISHOP; break;
            case 'Q' :
                board_state[j] = WHITEQUEEN; break;
            case 'K' :
                board_state[j] = WHITEKING; break;
            case 'P' :
                board_state[j] = WHITEPAWN; break;
            case 'n' :
                board_state[j] = BLACKKNIGHT; break;
            case 'r' :
                board_state[j] = BLACKROOK; break;
            case 'b' : 
                board_state[j] = BLACKBISHOP; break;
            case 'q' :
                board_state[j] = BLACKQUEEN; break;
            case 'k' :
                board_state[j] = BLACKKING; break;
            case 'p' :
                board_state[j] = BLACKPAWN; break;
            case '/' :
                std::cout << "Line Read..." << std::endl;
                j--;    // deliminator, should be ignored and the counter reset to start
                break;
            case '1' :
                board_state[j] = EMPTY; break;
            case '2' :
                for (k = j; k < j + 2; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '3' :
                for (k = j; k < j + 3; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '4' :
                for (k = j; k < j + 4; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '5' :
                for (k = j; k < j + 5; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '6' :
                for (k = j; k < j + 6; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '7' :
                for (k = j; k < j + 7; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
            case '8' :
                for (k = j; k < j + 8; k++) {
                    board_state[k] = EMPTY;
                }
                j = k - 1;
                break;
        }
        i++;
        j++;
    }
    std::cout << "Board set..." << std::endl;

    // turn indicator
    switch(FEN[1][0]) {
        case 'w' :
            turn = WHITETURN; break;
        case 'b' :
            turn = BLACKTURN; break;
    }
    std::cout << "Turn set..." << std::endl;

    // castling
    i = 0;
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
    std::cout << "Castling set..." << std::endl;

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
    std::cout << "Enpassant set..." << std::endl;

    // halfmove
    int temp;
    halfmove = 0;
    i = 0;
    while (FEN[4][i] != '\0') {
        switch (FEN[4][i]) {
             case '0' : temp = 0; break;
             case '1' : temp = 1; break;
             case '2' : temp = 2; break;
             case '3' : temp = 3; break;
             case '4' : temp = 4; break;
             case '5' : temp = 5; break;
             case '6' : temp = 6; break;
             case '7' : temp = 7; break;
             case '8' : temp = 8; break;
             case '9' : temp = 9; break;
        }
        halfmove = halfmove * 10;
        halfmove = halfmove + temp;
        i++;
    }
    std::cout << "Halfmove set..." << std::endl;

    // fullmove
    fullmove = 0;
    i = 0;
    while (FEN[5][i] != '\0') {
        switch (FEN[5][i]) {
             case '0' : temp = 0; break;
             case '1' : temp = 1; break;
             case '2' : temp = 2; break;
             case '3' : temp = 3; break;
             case '4' : temp = 4; break;
             case '5' : temp = 5; break;
             case '6' : temp = 6; break;
             case '7' : temp = 7; break;
             case '8' : temp = 8; break;
             case '9' : temp = 9; break;
        }
        fullmove = fullmove * 10;
        fullmove = fullmove + temp;
        i++;
    }
    std::cout << "Fullmove set..." << std::endl;

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

// board constructor for move evaluation
Board::Board(Board * origin_board) {
    for (int i = 0; i < 64; i++) {
        board_state[i] = origin_board->board_state[i];
    }
    turn = origin_board->turn;
    enpassant = origin_board->enpassant;
    whiteKingside = origin_board->whiteKingside;
    whiteQueenside = origin_board->whiteQueenside;
    blackKingside = origin_board->blackKingside;
    blackQueenside = origin_board->blackQueenside;
    halfmove = origin_board->halfmove;
    fullmove = origin_board->fullmove;
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
        if (this_board->turn == WHITETURN) {
            switch(this_board->board_state[i]) {
                case WHITEKNIGHT:
                    current_move = knightMoves(current_move, this_board, i, WHITETURN);
                    break;
                case WHITEROOK:
                    current_move = rookMoves(current_move, this_board, i, WHITETURN);
                    break;
                case WHITEBISHOP:
                    current_move = bishopMoves(current_move, this_board, i, WHITETURN);
                    break;
                case WHITEQUEEN:
                    current_move = queenMoves(current_move, this_board, i, WHITETURN);
                    break; 
                case WHITEKING:
                    current_move = kingMoves(current_move, this_board, i, WHITETURN, whiteKingside, whiteQueenside);
                    break;
                case WHITEPAWN:
                    current_move = whitepawnMoves(current_move, this_board, i);
                    break;
            }
        }
        else {
            switch(this_board->board_state[i]) {
                case BLACKKNIGHT:
                    current_move = knightMoves(current_move, this_board, i, BLACKTURN);
                    break;
                case BLACKROOK:
                    current_move = rookMoves(current_move, this_board, i, BLACKTURN);
                    break;
                 case BLACKBISHOP:
                    current_move = bishopMoves(current_move, this_board, i, BLACKTURN);
                    break;
                case BLACKQUEEN:
                    current_move = queenMoves(current_move, this_board, i, BLACKTURN);
                    break;
                case BLACKKING:
                    current_move = kingMoves(current_move, this_board, i, BLACKTURN, blackKingside, blackQueenside);
                    break;
                case BLACKPAWN:
                    current_move = blackpawnMoves(current_move, this_board, i);
                    break;
            }
        }
    }
    return current_move;
}


