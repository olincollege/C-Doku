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
