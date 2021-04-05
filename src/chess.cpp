#include "../include/chess.h"

int main(void) {

    std::cout << "Welcome to my chess program!" << std::endl;

    std::cout << "Please enter a FEN to start a custom game, or press return to start a fresh game: " << std::endl;




    char inputFEN[92];  // max theoretical FEN length
    std::cin.getline(inputFEN, 92);     // I know this is horrifically unsafe, but will do for now
    

    Board * chessBoard;

    if (inputFEN[0] == '\0') {
        // create a new default board
        chessBoard = new Board();
    }

    else {
        // create a new board from the FEN string

        // construct FEN
        char * FEN[6];
        char FEN1[73], FEN2[2], FEN3[5], FEN4[3], FEN5[3], FEN6[4];    // max sizes for each part of the FEN 
        FEN[0] = FEN1; FEN[1] = FEN2; FEN[2] = FEN3; FEN[3] = FEN4; FEN[4] = FEN5; FEN[5] = FEN6;

        int validConstruct = 1;
        validConstruct = constructFEN(FEN1, FEN2, FEN3, FEN4, FEN5, FEN6, inputFEN);
        if (validConstruct == 0) {std::cout << "FEN read correctly..." << std::endl;}
        else {std::cout << "Error reading FEN...aborting" << std::endl; exit(1);} 

        // check if FEN is valid
        int validFEN = 0;

        validFEN = validateFEN(FEN);
        
        if (validFEN != 1) {
        // invalid FEN, aborting
        std::cout << "Invalid FEN, aborting..." << validFEN << std::endl;
        exit(1);
        }

        chessBoard = new Board(FEN);
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

    delete chessBoard;

    return 0;
}
