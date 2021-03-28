#include "../include/moves.h"

move * createMove(int start, int end, int enp, int cast, Board * board, move * prev_move) {
    move * created_move = (move *) malloc(sizeof(move));
    created_move->start_index = start;
    created_move->end_index = end;
    created_move->enpassant = enp;
    created_move->castling = cast;
    created_move->origin_board = board;
    created_move->next_move = NULL;
    prev_move->next_move = created_move;
    return created_move;
}

move * knightMoves(move * prev_move, Board * board, int start_index) {
    