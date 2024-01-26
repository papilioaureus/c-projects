//
// Created by ktd on 10/14/2023.
//
#include "game.h"
#include <stdio.h>

void initializeGame(TicTacToe *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    game->currentPlayer = PLAYER_X; // Ensure this line exists
}

void displayGrid(const TicTacToe *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}
int isValidMove(const TicTacToe *game, int row, int col) {
    //Check if row and col are within bounds and the cell is empty
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && game->board[row][col] == EMPTY);
}

int checkWin(const TicTacToe *game) {
    char player = game->currentPlayer;
    for (int i = 0; i < SIZE; i++) {
        if (game->board[i][0] == player && game->board[i][1] == player && game->board[i][2] == player)
            return 1;
        if (game->board[0][i] == player && game->board[1][i] == player && game->board[2][i] == player)
            return 1;
    }
    if (game->board[0][0] == player && game->board[1][1] == player && game->board[2][2] == player)
        return 1;
    if (game->board[0][2] == player && game->board[1][1] == player && game->board[2][0] == player)
        return 1;
    return 0;
}

int isDraw(const TicTacToe *game) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (game->board[i][j] == EMPTY)
                return 0;
    return 1;
}

void saveGameState(const TicTacToe *game) {
    FILE *file = fopen("gamestate.txt", "w");
    if (!file) {
        printf("Error saving game state.\n");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fprintf(file, "%c", game->board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "%c", game->currentPlayer);
    fclose(file);
}

void loadGameState(TicTacToe *game) {
    FILE *file = fopen("gamestate.txt", "r");
    if (!file) {
        printf("Error loading game state.\n");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, " %c", &(game->board[i][j]));
        }
    }
    fscanf(file, " %c", &(game->currentPlayer));
    fclose(file);
}
