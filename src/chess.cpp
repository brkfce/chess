#include "../include/chess.h"

int main(void) {

    std::cout << "Welcome to my chess program!" << std::endl;

    std::cout << "Please enter a FEN to start a custom game, or press return to start a fresh game: " << std::endl;

    char inputFEN[92];  // max theoretical FEN length
    std::cin.getline(inputFEN, 92);     // I know this is horrifically unsafe, but will do for now
    

    if (inputFEN[0] == '\0') {
        // create a new default board
        Board * chessBoard = new Board();
    }

    else {
        // create a new board from the FEN string

        // construct FEN
        char * FEN[6];
        char FEN1[73], FEN2[2], FEN3[5], FEN4[3], FEN5[3], FEN6[4];    // max sizes for each part of the FEN 
        int overallcounter = 0, fencounter = 0, charcounter = 0;
        char writechar;
        
        while (inputFEN[overallcounter] != '\0') {      // seperate the different parts of the FEN
            if (inputFEN[overallcounter] == ' ') {
                writechar = '\0';
            }

            else {writechar = inputFEN[overallcounter];}        // identify which part of the FEN is required
            
            switch (fencounter) {
                case 0 : FEN1[charcounter] = writechar; break;
                case 1 : FEN2[charcounter] = writechar; break;
                case 2 : FEN3[charcounter] = writechar; break;
                case 3 : FEN4[charcounter] = writechar; break;
                case 4 : FEN5[charcounter] = writechar; break;
                case 5 : FEN6[charcounter] = writechar; break;
                default : std::cout << "Error reading FEN...aborting" << std::endl; exit(1);
            }

            overallcounter++;
            charcounter++;

            if (writechar == '\0') {charcounter = 0; fencounter++;}

        } if (charcounter != 3) FEN6[charcounter] = '\0';   // to account for the loop ending eary

        FEN[0] = FEN1; FEN[1] = FEN2; FEN[2] = FEN3; FEN[3] = FEN4; FEN[4] = FEN5; FEN[5] = FEN6;

        // check if FEN is valid
        int validFEN = 0;

        validFEN = validateFEN(FEN);
        
        if (validFEN != 1) {
        // invalid FEN, aborting
        std::cout << "Invalid FEN, aborting..." << validFEN << std::endl;
        exit(1);
        }

        //Board * chessBoard = new Board(FEN);
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
