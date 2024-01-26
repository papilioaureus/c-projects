//
// Created by ktd on 10/14/2023.
//
#ifndef GAME_H
#define GAME_H

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} TicTacToe;

void initializeGame(TicTacToe *game);
void displayGrid(const TicTacToe *game);
int isValidMove(const TicTacToe *game, int row, int col);
int checkWin(const TicTacToe *game);
int isDraw(const TicTacToe *game);
void saveGameState(const TicTacToe *game);
void loadGameState(TicTacToe *game);

#endif
