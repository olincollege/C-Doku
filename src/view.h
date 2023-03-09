#pragma once
#include "model.h"

/**
 * Prints the visualization of the player's sudoku board.
 *
 * Given the variable game state struct, this function prints a visualization
 * of the player's sudoku board using a series of formatted print statements.
 *
 * @param var A pointer to a struct that contains the variables in the game state.
 */
void print_board(var_game_state *var);

/**
 * Prints the result of the game.
 *
 * If the player gets exactly 3 errors before the board has been filled, then
 * the function prints out that the player lost and the function returns 1,
 * indicating a game end condition. If the player has filled the board before
 * the error counter reaches 3, then the function prints that the player won and
 * returns 1. Otherwise, the function returns 0, indicating that the game
 * continues.
 *
 * @param var A pointer to a struct that contains the variables in the game state.
 * @return An integer representing whether the game has finished (1 if the player either wins or loses,
 *  and 0 otherwise).
 */
int print_result(var_game_state *var);
