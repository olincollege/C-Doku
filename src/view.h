#pragma once
#include "model.h"
enum
{
    BOARD_DIM = 9
};
/**
 * Print the player's current sudoku board in terminal.
 *
 * Taking values from an existing array of arrays of characters, this function
 * prints a visualization of the player's sudoku board using a series of
 * formatted print statements.
 *
 * @param board The existing char array of characters.
 */
void print_board_view(char board[9][9]);

/**
 * Reset the player's current sudoku board in terminal.
 *
 * When the player is done playing and wants to play again, this function resets
 * the player board so the player can play again. This function iterates through
 * every cell of the player's sudoku board and sets it to an empty string.
 *
 * @param board The existing char array of characters.
 */
void reset_board(char board[9][9]);

/**
 * Print the result of the game.
 *
 * When the player gets exactly 3 errors before the board is filled, then the
 * functions prints out that the player lost. If the player is able to fill
 * the board before the error reaches 3, then the function prints that the
 * player won.
 */
void print_result();
