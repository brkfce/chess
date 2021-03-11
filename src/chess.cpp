#include "..\include\chess.h"

int main(int argc, char * argv[]) {

    std::cout << "Welcome to my chess program!" << std::endl;


    

    if (argc == 1) {
        // no arguments, so start a new standard game
        // create a new default board
        Board * chessBoard = new Board::Board();
    }

    else if (argc == 7) {
        // arguments should comprise of a FEN string, which will be parsed into a board state
        // create a new board from the FEN string
        // but first, check if FEN is valid
        int validFEN = 0;

        validFEN = validateFEN(argv);
        
        if (validFEN != 1) {
        // invalid FEN, aborting
        std::cout << "Invalid FEN, aborting..." << std::endl;
        exit(0);
        }

        Board * chessBoard = new Board::Board(argv);
    }

    else {
        std::cout << "Invalid FEN, aborting..." << std::endl;
        exit(0);
    }

    

    


    int validColour = 0;
    char colour;
    int computerColour;     // 1 if white, 0 if black

    while (validColour == 0) {
        std::cout << "Will you be playing white? Y/N:" << std::endl;
        std::cin >> colour;
        if (colour == 'Y' || colour == 'y') {
            validColour = 1;
            computerColour = 0;
        }
        else if (colour == 'N' || colour == 'n') {
            validColour = 1;
            computerColour = 1;
        }
    }

    
    int gameEnd = 0;
    
    while (gameEnd == 0) {
        // game loop
    }

    return 0;
}
