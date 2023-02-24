#pragma once

#include <view.c>

/**
 * Print the player's current sudoku board in terminal.
 *
 * Taking values from an existing array of arrays of characters, this function
 * prints a visualization of the player's sudoku board using a series of
 * formatted print statements.
 */
void print_board_view();

/**
 * Convert an integer to a character.
 *
 * Given an integer, this function converts the integer to a character by adding
 * a null character to the integer.
 *
 * @param n The integer to be converted.
 * @return A char that represents the converted integer.
 */
char convert_to_char(int n);

/**
 * Change the value of a space on the board.
 *
 * Given a row, column, and number value (indicated by the user), this function
 * finds the corresponding spot on the visualized board (char array of arrays),
 * converts the number from an integer into a character, then inserts the
 * character into that spot on the board.
 *
 * @param row An integer representing the row on the board to edit.
 * @param col An integer representing the column on the board to edit.
 * @param n An integer representing the number value to print onto the board.
 */
void update_board(int row, int col, int n);

/**
 * Reset the player's current sudoku board in terminal.
 *
 * When the player is done playing and wants to play again, this function resets
 * the player board so the player can play again. This function iterates through
 * every cell of the player's sudoku board and sets it to an empty string.
 */
void reset_board();
