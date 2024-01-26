//
// Created by ktd on 10/14/2023.
//
#include "game.h"
#include <stdio.h>

int main() {
    TicTacToe game;
    int row, col;
    char choice;
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Would you like to load a saved game? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        loadGameState(&game);
    } else {
        initializeGame(&game);
    }

    while (1) {
        displayGrid(&game);
        printf("Player %c, enter row (1-3) and column (1-3) separated by a space or -1 to save and quit: ", game.currentPlayer);
        scanf("%d %d", &row, &col);

        //In order to avoid asking for row/col 0-2, this adjusts to the more human-friendly 1-3.
        row--;
        col--;

        //This wipes the input buffer clean.
        while (getchar() != '\n');

        if (row == -2) { //The user enters -1 for row
            saveGameState(&game);
            printf("Game saved. Exiting...\n");
            break;
        }

        if (isValidMove(&game, row, col)) {
            game.board[row][col] = game.currentPlayer;

            if (checkWin(&game)) {
                displayGrid(&game);
                printf("Player %c wins!\n", game.currentPlayer);
                break;
            }

            if (isDraw(&game)) {
                displayGrid(&game);
                printf("It's a draw!\n");
                break;
            }

            game.currentPlayer = (game.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
