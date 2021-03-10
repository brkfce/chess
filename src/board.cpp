// this "Board" class stores the board state
// functionality will be added as required

#include <board.h>

// board constructor
Board::Board(char * FEN)
{
	FEN_string = FEN;
	parseFEN();
}

void Board::parseFEN(void)
{
// note: minimal testing as to whether this is a valid FEN or not. Only an incorrect turn key will cause an issue, this should be resolved with more checks to the state of the board etc

	bool valid_fen = 1;
	int char_counter = 0;
	int current_square;
	char cchar;
	int slash_counter = 0;
	// this deals with the pieces on the board
	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			// FEN strings go from top left to bottom right, from white's perspective
			current_square = 64 - (8 * (rank+1)) + file;
			cchar = FEN_string[char_counter];
			char_counter++;
			if (cchar == '1' || cchar == '2' || cchar == '3' || cchar == '4' || cchar == '5' || cchar == '6' || cchar == '7' || cchar == '8') {
				// skip the number of spaces written in the FEN
				for (int gap = 0; gap < atoi(&cchar); gap++) {
					board_state[current_square + gap] = ' ';					
					file++;
				}
			}
			else if (cchar == '/') {
				// deliminates lines, can ignore but must account for lost cycle
				file--;
				slash_counter++;
			}
			else {
				board_state[current_square] = cchar;
			}
		}
	}	
	// check to see if there are enough slashes in the FEN
	if (slash_counter != 7) {
		cout << "Invalid FEN\n";
		exit(0);
	}
	// this deals with the extra data associated with the game
	char_counter++;	// skip the space after board data
	// who's turn it is
	cchar = FEN_string[char_counter];
	if (cchar == 'w') {
		white_turn = 1;
	}
	else if (cchar == 'b') {
		white_turn = 0;
	}
	else {
		valid_fen = 0;
		cout << "Invalid FEN\n";
		exit(0);
	}

	char_counter += 2; // skip a space
	// which way can each player castle
	cchar = FEN_string[char_counter];
	while (cchar != ' ') {
		if (cchar == 'K') {
			white_castling[0] = 1;
		}
		if (cchar == 'Q') {
			white_castling[1] = 1;
		}
		if (cchar == 'k') {
			black_castling[0] = 1;
		}
		if (cchar == 'q') {
			black_castling[1] = 1;
		}
		char_counter++;
		cchar = FEN_string[char_counter];
		
	}
	char_counter++; // skip a space
	// is en passant possible this move
	cchar = FEN_string[char_counter];
	if (cchar == '-') {
		enpassant_square[0] = '-';
		enpassant_square[1] = '-';
	}
	else {
		enpassant_square[0] = cchar;
		char_counter++;
		cchar = FEN_string[char_counter];
		enpassant_square[1] = cchar;
	}
		
	char_counter += 2; // skip a space
	// halfmove clock (number of moves since last capture or pawn move)
	cchar = FEN_string[char_counter];
	halfmove_clock = atoi(&cchar);	// possibility for undefined behaviour here, maybe find a better solution
	
	char_counter += 2; // skip a space
	// fullmove clock (number of full moves, starts at 1 and incremented after blacks move
	cchar = FEN_string[char_counter];
	fullmove_clock = atoi(&cchar);	// possibility for undefined behaviour here, maybe find a better solution	
	
}

void Board::updateBoard(char * new_board_state, int new_enpassant_index, char * new_white_castling, char * new_black_castling)
{
	for (int i = 0; i < 64; i++) {
		board_state[i] = new_board_state[i];
	}
	enpassant_index = new_enpassant_index;
	for (int i = 0; i < 2; i++) {
		white_castling[i] = new_white_castling[i];
		black_castling[i] = new_black_castling[i];
	}
}

void Board::updateTransfer(tempBoardState * boardTransfer) {
	for (int i = 0; i < 64; i++) {
		boardTransfer->board_state[i] = board_state[i];
	}
	boardTransfer->enpassant_index = enpassant_index;
	for (int i = 0; i < 2; i++) {
		boardTransfer->white_castling[i] = white_castling[i];
		boardTransfer->black_castling[i] = black_castling[i];
	}
}

Board::~Board(void) 
{
	cout << "Table flipped, board destroyed. Goodbye!\n";
}
