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
void update_board_view(int row, int col, int n);
