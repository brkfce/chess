#include "../include/simpleboard.h"

// board constructor for FEN string
Board::Board(char **) {}

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