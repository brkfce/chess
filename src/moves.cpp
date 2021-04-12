#include "../include/moves.h"
#include "../include/simpleboard.h"

// instantiate a move struct for a given pseudolegal move
move * createMove(int start, int end, int enp, int cast, Board * origin_board, move * prev) {
    move * created_move = (move *) malloc(sizeof(move));
    created_move->start_index = start;
    created_move->end_index = end;
    created_move->enpassant = enp;
    created_move->castling = cast;
    created_move->origin_board = origin_board;
    created_move->new_board = new Board(origin_board);

    // adjust new board
    if ((created_move->new_board->board_state[end] != EMPTY && cast == 0) || created_move->new_board->board_state[start] == WHITEPAWN || created_move->new_board->board_state[start] == BLACKPAWN) {
            created_move->new_board->halfmove = 0;
        }
    else {
            created_move->new_board->halfmove++;    // increment halfmove if no pawn move or capture
    }

    created_move->new_board->board_state[end] = created_move->new_board->board_state[start];
    created_move->new_board->board_state[start] = EMPTY;
    
    if (origin_board->enpassant == end) {
        created_move->new_board->board_state[end - 8] = EMPTY;  // remove enpassant'd pawn
    }

    if (cast != 0) {
        switch (cast) {
            case 1:
                created_move->new_board->board_state[5] = WHITEROOK;    // swap rooks for castling
                created_move->new_board->board_state[7] = EMPTY;
                break;
            case 2:
                created_move->new_board->board_state[3] = WHITEROOK;
                created_move->new_board->board_state[0] = EMPTY;
                break;
             case -1:
                created_move->new_board->board_state[61] = WHITEROOK;
                created_move->new_board->board_state[63] = EMPTY;
                break;
            case -2:
                created_move->new_board->board_state[59] = WHITEROOK;
                created_move->new_board->board_state[56] = EMPTY;
                break;
        }
    }

    created_move->new_board->fullmove++;
    created_move->child_move = NULL;
    created_move->prev_move = prev;
    return created_move;
}

// return 1 if move is pseudolegal, return 0 if move is impossible due to friendly piece
int checkMove(int end_index, int piece_colour, int * board_state) {
    int end_piece = board_state[end_index];
    if (end_piece == EMPTY || (piece_colour == WHITETURN && end_piece < EMPTY) || (piece_colour == BLACKTURN && end_piece > EMPTY)){
        return 1;
    }
    else return 0;
}

// generate all the pseudolegal moves for a knight
move * knightMoves(move * prev_move, Board * board, int start_index, int piece_colour) {

    move * current_move = prev_move;

    // probably a smarter way to do this (not doing redundant checks) but this is easiest for now
    /*      8 1
           7   2
             K   
           6   3
            5 4
    */
    int end_index;
    // move 1
    if (start_index < 47 && (start_index % 8) < 7) {
        end_index = start_index + (8*2 + 1);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 2
    if (start_index < 54 && (start_index % 8) < 6) {
        end_index = start_index + (8*1 + 2);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 3
    if (start_index > 7 && (start_index % 8) < 6) {
        end_index = start_index + (-8*1 + 2);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 4
    if (start_index > 15 && (start_index % 8) < 7) {
        end_index = start_index + (-8*2 + 1);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 5
    if (start_index > 15 && (start_index % 8) > 0) {
        end_index = start_index + (-8*2 - 1);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 6
    if (start_index > 7 && (start_index % 8) > 1) {
        end_index = start_index + (-8*1 - 2);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 7
    if (start_index < 54 && (start_index % 8) >1) {
        end_index = start_index + (8*1 - 2);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // move 8
    if (start_index < 47 && (start_index % 8) > 0) {
        end_index = start_index + (8*2 - 1);
        if (checkMove(end_index, piece_colour, board->board_state) == 1){
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    return current_move;
}

// generate all the pseudolegal moves for a rook 
move * rookMoves(move * prev_move, Board * board, int start_index, int piece_colour) {
   
    move * current_move = prev_move;
    int end_index;
    int hit_friendly;

    // moving vertically up
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index < 56) && (hit_friendly = 0)) {
        end_index = end_index + 8;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving horizontally right
    end_index = start_index;
    hit_friendly = 0;
    while (((end_index % 8) < 7) && (hit_friendly = 0)) {
        end_index = end_index + 1;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving vertically down
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index > 7) && (hit_friendly = 0)) {
        end_index = end_index - 8;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving horizontally left
    end_index = start_index;
    hit_friendly = 0;
    while (((end_index % 8) > 0) && (hit_friendly = 0)) {
        end_index = end_index - 1;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    return current_move;
}

// generate all the pseudolegal bishop moves
move * bishopMoves(move * prev_move, Board * board, int start_index, int piece_colour) {
   
    move * current_move = prev_move;
    int end_index;
    int hit_friendly;

    // moving up right
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index < 56) && ((end_index % 8) < 7) && (hit_friendly = 0)) {
        end_index = end_index + 9;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving down right
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index > 7) && ((end_index % 8) < 7) && (hit_friendly = 0)) {
        end_index = end_index - 7;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving up left
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index < 56) && ((end_index % 8) > 0) && (hit_friendly = 0)) {
        end_index = end_index + 7;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    // moving down left
    end_index = start_index;
    hit_friendly = 0;
    while ((end_index > 7) && ((end_index % 8) > 0) && (hit_friendly = 0)) {
        end_index = end_index - 9;
        if (checkMove(end_index, piece_colour, board->board_state) == 0) {
            hit_friendly = 1;
        }
        else {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }
    return current_move;
}

// generate the pseudolegal queen moves, from the bishop and rook moves
move * queenMoves(move * prev_move, Board * board, int start_index, int piece_colour) {
    
    move * current_move = prev_move;

    current_move = rookMoves(current_move, board, start_index, piece_colour);
    current_move = bishopMoves(current_move, board, start_index, piece_colour);

    return current_move;
}

// generate the pseudolegal king moves, including castling (but without checking if castling passes through check)
// that will be verified when identifying check
move * kingMoves(move * prev_move, Board * board, int start_index, int piece_colour, int kingside, int queenside) {

    move * current_move = prev_move;

    // normal movement

    int end_index;

    int checkRight, checkLeft, checkUp, checkDown;
    checkRight = checkLeft = checkUp = checkDown = 0;

    if ((start_index % 8) < 7) {checkRight = 1;}
    if ((start_index % 8) > 0) {checkLeft = 1;}
    if (start_index > 7) {checkDown = 1;}
    if (start_index < 56) {checkUp = 1;}

    if (checkRight == 1) {
        
        // right horizontal
        end_index = start_index + 1;
        if (checkMove(end_index, piece_colour, board->board_state)) { 
            current_move = createMove(start_index, end_index, 0, 0, board, current_move); 
        }
        
        // right up diagonal
        end_index = start_index + 9;
        if (checkUp == 1 && checkMove(end_index, piece_colour, board->board_state)) { 
            current_move = createMove(start_index, end_index, 0, 0, board, current_move); 
        }
        
        // right down diagonal
        end_index = start_index - 7;
        if (checkDown == 1 && checkMove(end_index, piece_colour, board->board_state)) {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }

    if (checkLeft == 1) {

         // left horizontal
        end_index = start_index - 1;
        if (checkMove(end_index, piece_colour, board->board_state)) { 
            current_move = createMove(start_index, end_index, 0, 0, board, current_move); 
        }
        
        // left up diagonal
        end_index = start_index + 7;
        if (checkUp == 1 && checkMove(end_index, piece_colour, board->board_state)) { 
            current_move = createMove(start_index, end_index, 0, 0, board, current_move); 
        }
        
        // left down diagonal
        end_index = start_index - 9;
        if (checkDown == 1 && checkMove(end_index, piece_colour, board->board_state)) {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }

    if (checkUp == 1) {
        
        // up vertical
        end_index = start_index + 8;
        if (checkMove(end_index, piece_colour, board->board_state)) {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }

        // down vertical
        end_index = start_index - 8;
        if (checkMove(end_index, piece_colour, board->board_state)) {
            current_move = createMove(start_index, end_index, 0, 0, board, current_move);
        }
    }

    // castling (only pseudolegal, does not account for potential checks that could prevent)

    if (piece_colour == WHITETURN) {
        if (kingside && board->board_state[5] == 0 && board->board_state[6] == 0) {
            current_move = createMove(4, 6, 0, 1, board, current_move);
        }
        if (queenside && board->board_state[3] == 0 && board->board_state[2] == 0 && board->board_state[1] == 0) {
            current_move = createMove(4, 2, 0, 2, board, current_move);
        }
    }
    if (piece_colour == BLACKTURN) {
        if (kingside && board->board_state[61] == 0 && board->board_state[62] == 0) {
            current_move = createMove(60, 62, 0, -1, board, current_move);
        }
        if (queenside && board->board_state[59] == 0 && board->board_state[58] == 0 && board->board_state[57] == 0) {
            current_move = createMove(60, 58, 0, -2, board, current_move);
        }
    }

    return current_move;
}


// note: cannot use checkMove for pawn moves, as pawns cannot capture going forwards
// must instead use a manual board_state check for moves and captures

// create pseudolegal white pawn moves including enpassant, but not including promotion (handled by board)
move * whitepawnMoves(move * prev_move, Board * board, int start_index) {
    
    move * current_move = prev_move;

    int end_index;

    // single move forwards
    end_index = start_index + 8;
    if (board->board_state[end_index] == 0) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // double move forwards
    int middle_index = start_index + 8;
    end_index = start_index + 16;
    if (board->board_state[middle_index] == 0 && board->board_state[end_index] == 0 && start_index < 16) {
        current_move = createMove(start_index, end_index, middle_index, 0, board, current_move);
    }

    // capture left
    end_index = start_index + 7;
    if ((start_index & 8) > 0 && board->board_state[end_index] < EMPTY) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // capture right
    end_index = start_index + 9;
    if ((start_index & 8) < 7 && board->board_state[end_index] < EMPTY) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // enpassant capture
    if (board->enpassant == start_index + 7 || board->enpassant == start_index + 9) {
        current_move = createMove(start_index, board->enpassant, 0, 0, board, current_move);
    }

    return current_move;
}

// create pseudolegal black pawn moves including enpassant, but not including promotion (handled by board)
move * blackpawnMoves(move * prev_move, Board * board, int start_index) {
    
    move * current_move = prev_move;

    int end_index;

    // single move forwards
    end_index = start_index - 8;
    if (board->board_state[end_index] == 0) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // double move forwards
    int middle_index = start_index - 8;
    end_index = start_index - 16;
    if (board->board_state[middle_index] == 0 && board->board_state[end_index] == 0 && start_index < 16) {
        current_move = createMove(start_index, end_index, middle_index, 0, board, current_move);
    }

    // capture left
    end_index = start_index - 9;
    if ((start_index & 8) > 0 && board->board_state[end_index] > EMPTY) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // capture right
    end_index = start_index - 7;
    if ((start_index & 8) < 7 && board->board_state[end_index] > EMPTY) {
        current_move = createMove(start_index, end_index, 0, 0, board, current_move);
    }

    // enpassant capture
    if (board->enpassant == start_index - 7 || board->enpassant == start_index - 9) {
        current_move = createMove(start_index, board->enpassant, 0, 0, board, current_move);
    }

    return current_move;
}