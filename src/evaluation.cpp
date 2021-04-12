#include "../include/evaluation.h"

// generate the legal moves that can be chosen from by a player
move * genLegalMoves(Board * current_board) {
    
    move * pseudolegal_move = current_board->generateMoves(current_board);
    int legalmove = UNKNOWN;
    
    while (pseudolegal_move != NULL) {
        // generate child moves for each move
        pseudolegal_move->child_move = pseudolegal_move->new_board->generateMoves(pseudolegal_move->new_board);
        move * prev_move;
        move * child_move = pseudolegal_move->child_move;
        
        // check if the king can be taken on the next move, or if a piece can block castling
        int kingtracker;
        while (child_move != NULL && legalmove == UNKNOWN) {
            kingtracker = 0;
            for (int i = 0; i < 64; i++) {
                if (pseudolegal_move->new_board->turn == WHITETURN && child_move->new_board->board_state[i] == WHITEKING) {
                    kingtracker = 1;
                }
                if (pseudolegal_move->new_board->turn == BLACKTURN && child_move->new_board->board_state[i] == BLACKKING) {
                    kingtracker = 1;
                }
            }
            if (kingtracker == 0) {
                legalmove == ILLEGAL;
            }
            if (pseudolegal_move->castling == 1 && (child_move->end_index == 4 || child_move->end_index == 5 || child_move->end_index == 6)) {
                legalmove == ILLEGAL;
            }
            if (pseudolegal_move->castling == 2 && (child_move->end_index == 4 || child_move->end_index == 3 || child_move->end_index == 2)) {
                legalmove == ILLEGAL;
            }
            if (pseudolegal_move->castling == -1 && (child_move->end_index == 60 || child_move->end_index == 61 || child_move->end_index == 62)) {
                legalmove == ILLEGAL;
            }
            if (pseudolegal_move->castling == -2 && (child_move->end_index == 60 || child_move->end_index == 59 || child_move->end_index == 58)) {
                legalmove == ILLEGAL;
            }
            child_move = child_move->prev_move;
        }

        // set status of move
        if (legalmove == UNKNOWN) {
            pseudolegal_move->legality = LEGAL;
        }
        else if (legalmove == ILLEGAL) {
            pseudolegal_move->legality = ILLEGAL;
        }

        pseudolegal_move = pseudolegal_move->prev_move;
    }

    return pseudolegal_move;
}




// generate the best move to be played by the computer
move * genBestMove(Board * current_board) {

}

// update the current board with the move selected by either the player or the computer
Board * updateBoard(move * chosen_move) {

}