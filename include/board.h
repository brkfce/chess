// this "Board" class stores the board state
// functionality will be added as required

#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class Board
{
	private:
		char board_state[63];
		bool white_turn;
		char * FEN_string;
		int white_castling[1];
		int black_castling[1];
		char enpassant_square[1];
		int halfmove_clock;
		int fullmove_clock;

	public:
		Board(char *);
		void parse_FEN(void); 
		void movePiece(int, int);
		char returnPiece(int);
		//	~Board(void);

};

#endif
