// these classes store piece data, and are used to generate possible moves

#ifndef PIECES_H
#define PIECES_H

#include <stdlib.h>

#include<board.h>

class Pieces
{
	public:
		Pieces(Board *, char, char, char, char, char);
		void move(void);	// the full process for evaluating the best move
		bool canTakeKing(void);	// just evaluate possible moves to see if king can be taken
		~Pieces(void);
	
	private:
		
		Queen queens[9];	// these are all the max theoretical number
		Rook rooks[10];		// each will have a terminator, so pieces beyond that
		Bishop bishops[10];	// will not be looked for in memory
		Knight knights[10];
		Pawn pawns[8];
		King king[1];
		
		Board * mainBoard;
		Board * tempBoard;
		Board * bestBoard;
		
		Pieces * otherPieces;

		tempBoardState internalTransfer;
		int bestBoardScore;
		
		char colour;
		int enpassant_square;
		bool kingside_castle;
		bool queenside_castle;
		
		void updateTmp(void);	// update local tempBoard with current main board state
		void genAllMoves(void);	// generate all the possible moves that can be made
		void genTmp(void);	// update tempBoard with potential move
		void transferTmp(void);	// send tempBoard to transfer struct
		void evaluateTmp(void);	// evaluate a board state
		void updateBest(void);	// if tempBoard is best move so far, update bestBoard
		void updateMain(void);	// once best move is found, update main board	
};


class Queen
{
	public:
		Queen(int);
		int * listMoves(void);
		~Queen(void);

	private:
		int board_index;
		int rank;
		int file;
		int moves[28];	// max theoretical possible moves
};

class Rook
{
	public:
		Rook(int);
		int * listMoves(void);
		~Rook(void);
	
	private:
		int board_index;
		int rank;
		int file;
		int moves[14];	// max theoretical possible moves
};

class Bishop
{
	public:
		Bishop(int);
		int * listMoves(void);
		~Bishop(void);
	
	private:
		int board_index;
		int rank;
		int file;
		int moves[14];	// max theoretical possible moves
};

class Knight
{
	public: 
		Knight(int);
		int * listMoves(void);
		~Knight(void);
	
	private:
		int board_index;
		int rank;
		int file;
		int moves[8];	// max theoretical possible moves
};

class King
{
	public:
		King(int);
		int * listMoves(void);
		~King(void);
	
	private:
		int board_index;
		int rank;
		int file;
		bool inCheck;
		int moves[10];	// max theoretical possible moves
};

class Pawn
{
	public:
		Pawn(int);
		int * listMoves(void);
		~Pawn(void);

	private:
		int board_index;
		int rank;
		int file;
		int moves[4];	// max theroetical possible moves
};



#endif
