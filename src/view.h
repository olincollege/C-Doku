#pragma once
#include "model.h"

/**
 * Print the visualization of the player's sudoku board.
 *
 * Given the variable game state struct, this function prints a visualization
 * of the player's sudoku board using a series of formatted print statements.
 *
 * @param var A struct that contains the variables in the game state.
 */
void print_board(var_game_state *var);

/**
 * Print the result of the game.
 *
 * When the player gets exactly 3 errors before the board is filled, then the
 * functions prints out that the player lost and the game ends. If the player is
 * able to fill the board before the error reaches 3, then the function prints that
 * the player won and the game ends. Otherwise, the game continues.
 *
 * @param var A struct that contains the variables in the game state.
 * @return An integer representing if the game has finished (1 if the player either wins or loses,
 *  and 0 otherwise).
 */
int print_result(var_game_state *var);
