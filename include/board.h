// this "Board" class stores the board state
// functionality will be added as required

#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>
using namespace std;

struct tempBoardState {
	char board_state[64];
	int enpassant_index;
	char white_castling[2];
	char black_castling[2];
} boardTransfer;

class Board
{
	private:
		char board_state[64];
		bool white_turn;
		char * FEN_string;
		int white_castling[2];
		int black_castling[2];
		char enpassant_square[2];
		int enpassant_index;
		int halfmove_clock;
		int fullmove_clock;

	public:
		Board(char *);	// for generating with a FEN
		Board(char *, int, char *, char *);
		void parseFEN(void);	
		void updateBoard(char *, int, char *, char *);
		void updateTransfer(tempBoardState *);
		~Board(void);

};


#endif
