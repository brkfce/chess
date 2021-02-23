#include <chess.h>

// game loop

int main(void) {

	cout << "==================\nWelcome to my chess engine!\n==================\n";
	
	char start_FEN[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        Board *game_board = new Board(&start_FEN[0]);
	
	cout << "Board created, pieces layed!\n";


	for (int i = 0; i < 64; i++) {
		cout << game_board->returnPiece(i);
	}

	delete game_board;
	
	return 0;
}
