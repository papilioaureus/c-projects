//
// Created by ktd on 10/14/2023.
//
#include <stdio.h>
#include "C:/CUnit-2.1-2/CUnit/Headers/Basic.h"
#include "game.h"

void test_initializeGame() {
    TicTacToe game;
    initializeGame(&game); //Call the initialization function for the game

    //Assert that the current player is set to 'X' at the start
    CU_ASSERT(game.currentPlayer == PLAYER_X);
    //Assert that the game board is completely empty at the start
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        CU_ASSERT(game.board[i][j] == EMPTY);
}

//Test to check if the win condition is properly detected
void test_checkWin() {
    TicTacToe game;
    initializeGame(&game);
    //Set the top row of the board to all 'X' values
    game.board[0][0] = PLAYER_X;
    game.board[0][1] = PLAYER_X;
    game.board[0][2] = PLAYER_X;

    //Assert that the game detects a win condition
    CU_ASSERT(checkWin(&game) == 1);
}

//Test to check if the draw condition is properly detected
void test_isDraw() {
    TicTacToe game;
    initializeGame(&game);
    // Fill the entire board with 'X' values
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            game.board[i][j] = PLAYER_X;

    // Assert that the game detects a draw condition
    CU_ASSERT(isDraw(&game) == 1);
}

int main() {
    //Initialize the CUnit test registry
    CU_initialize_registry();

    //Create a test suite for the TicTacToe game
    CU_pSuite suite = CU_add_suite("TicTacToe Test Suite", NULL, NULL);

    //Add tests to the suite
    CU_add_test(suite, "test_initializeGame", test_initializeGame);
    CU_add_test(suite, "test_checkWin", test_checkWin);
    CU_add_test(suite, "test_isDraw", test_isDraw);

    //Run all the tests in the suite
    CU_basic_run_tests();

    //Clean up the CUnit registry and exit
    CU_cleanup_registry();
    return 0;
}
