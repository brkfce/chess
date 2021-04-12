#include <iostream>
#include "../include/simpleboard.h"
#include "../include/fen.h"

void FENTesting(void);
void movesTesting(void);

int main(void) {

    movesTesting();

    return 0;
}


void movesTesting(void) {
    Board * chessBoard = new Board();
    move * head_move = chessBoard->generateMoves(chessBoard);
    move * current_move = head_move;
    while (current_move != NULL) {
        std::cout << current_move->end_index << std::endl;
        current_move = current_move->prev_move;
    }
    chessBoard->deleteMoves(head_move);
    delete chessBoard;
}


/*
void FENTesting(void) {
    char * FEN[6];
    int result;
    int passed = 0; int failed = 0;

    std::cout << "Beginning Tests..." << std::endl;
    
    // test case 1
    char test1 = ' ';
    FEN[0] = FEN[1] = FEN[2] = FEN[3] = FEN[4] = FEN[5] = &test1;
    result = validateFEN(FEN);
    if (result = 2 ) {std::cout << "Test 1: Empty FEN passed" << std::endl; passed++;}
    else {std::cout << "Test 1: Empty FEN failed" << std::endl; failed++;}

    // test case 2
    char test2[] = "rnbqkbnr/pppppppp/44/8/8/8/PPPPPPPP/RNBQKBNR";
    FEN[0] = test2;
    result = validateFEN(FEN);
    if (result = 3) {std::cout << "Test 2: Two Numbers passed" << std::endl; passed++;}
    else {std::cout << "Test 2: Two Numbers failed" << std::endl; failed++;}

    // test case 3
    char test3[] = "rnbqkbnr/ppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    FEN[0] = test3;
    result = validateFEN(FEN);
    if (result = 4) {std::cout << "Test 4: Not Enough Squares passed" << std::endl; passed++;}
    else {std::cout << "Test 3: Not Enough Squares failed" << std::endl; failed++;}


    // test case 4
    char test4[] = "rnbqkbnrpppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    FEN[0] = test4;
    result = validateFEN(FEN);
    if (result = 4) {std::cout << "Test 4: Missing Slash passed" << std::endl; passed++;}
    else {std::cout << "Test 4: Missing Slash failed" << std::endl; failed++;}

    // test case 5
    char test5[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/";
    FEN[0] = test5;
    result = validateFEN(FEN);
    if (result = 5) {std::cout << "Test 5: Extra Slash passed" << std::endl; passed++;}
    else {std::cout << "Test 5: Extra Slash failed" << std::endl; failed++;}

    // test case 6
    char test6[] = "rnbqkbnr/ppppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    FEN[0] = test6;
    result = validateFEN(FEN);
    if (result = 7) {std::cout << "Test 6: Extra Pawn passed" << std::endl; passed++;}
    else {std::cout << "Test 5: Extra Pawn failed" << std::endl; failed++;}

    // test case 7
    char test7[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQRBNR";
    FEN[0] = test7;
    result = validateFEN(FEN);
    if (result = 7) {std::cout << "Test 7: Missing King passed" << std::endl; passed++;}
    else {std::cout << "Test 7: Missing King failed" << std::endl; failed++;}

    char validBoard[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    FEN[0] = validBoard;

    // test case 8
    char test8[] = "a";
    FEN[1] = test8;
    result = validateFEN(FEN);
    if (result = 9) {std::cout << "Test 8: Invalid Turn Indicator passed" << std::endl; passed++;}
    else {std::cout << "Test 8: Invalid Turn Indicator failed" << std::endl; failed++;}

    char validTurnIndicator = 'w';
    FEN[1] = &validTurnIndicator;

    // test case 9
    char test9[] = "a";
    FEN[2] = test9;
    result = validateFEN(FEN);
    if (result = 10) {std::cout << "Test 9: Invalid Castling Symbol passed" << std::endl; passed++;}
    else {std::cout << "Test 9: Invalid Castling Symbol failed" << std::endl; failed++;}

    // test case 10
    char test10[] = "KK";
    FEN[2] = test10;
    result = validateFEN(FEN);
    if (result = 11) {std::cout << "Test 10: Double Kingside passed" << std::endl; passed++;}
    else {std::cout << "Test 10: Double Kingside failed" << std::endl; failed++;}

    // test case 11
    char test11[] = "KQ-";
    FEN[2] = test11;
    result = validateFEN(FEN);
    if (result = 12) {std::cout << "Test 11: Castling And No Castling passed" << std::endl; passed++;}
    else {std::cout << "Test 11: Castling And No Castling failed" << std::endl; failed++;}

    char validCastling = '-';
    FEN[2] = &validCastling;

    // test case 12
    char test12[] = "zz";
    FEN[3] = test12;
    result = validateFEN(FEN);
    if (result = 13) {std::cout << "Test 12: Invalid Symbol passed" << std::endl; passed++;}
    else {std::cout << "Test 12: Invalid Symbol failed" << std::endl; failed++;}

    // test case 13
    char test13[] = "cc";
    FEN[3] = test13;
    result = validateFEN(FEN);
    if (result = 14) {std::cout << "Test 13: Double File passed" << std::endl; passed++;}
    else {std::cout << "Test 13: Double File failed" << std::endl; failed++;}

    // test case 14
    char test14[] = "55";
    FEN[3] = test14;
    result = validateFEN(FEN);
    if (result = 14) {std::cout << "Test 14: Double Rank passed" << std::endl; passed++;}
    else {std::cout << "Test 14: Double Rank failed" << std::endl; failed++;}

    while(1) {} // allow for reading of results
}
*/