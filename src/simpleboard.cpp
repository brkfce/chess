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

    move = WHITEMOVE;
    enpassant = 0;
    whiteKingside = whiteQueenside = blackKingside = blackQueenside = 1;

}


// board destructor
Board::~Board(void) {}

int Board::checkSquare(int index) {
    return board_state[index];
}

move * Board::generateMoves(void) {}

move * Board::deleteMoves(void) {}