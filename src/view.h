#pragma once
#include "model.h"

/**
 * Print the visualization of the player's sudoku board.
 *
 * Given the variable game state struct, this function prints a visualization
 * of the player's sudoku board using a series of formatted print statements.
 *
 * @param var A pointer to the variable game state struct.
 */
void print_board(var_game_state *var);

/**
 * Print the result of the game.
 *
 * If the player gets exactly 3 errors before the board has been filled, then
 * the function prints out that the player has lost and the function returns 1,
 * indicating a game end condition. If the player has filled the board before
 * the error counter reaches 3, then the function prints that the player has won
 * and returns 1. Otherwise, the function returns 0, indicating that the game 
 * continues.
 *
 * @param var A pointer to the variable game state struct.
 * @return An integer representing whether the game has finished (1 if the player either wins or loses,
 *  and 0 otherwise).
 */
int print_result(var_game_state *var);
