#pragma once

#include <stddef.h>

/**
 * Change the player's board according to the inputs given.
 * 
 * Given the row, column, and number that the player inputs (and assuming the input
 * is correct), this function will replace the placeholder number 0 in the game state
 * player board with the given number.
 * 
 * @param board An array of arrays of integers that represent the player board.
 * @param row An integer representing the first array to index into.
 * @param col An integer representing the second array to index into.
 * @param num An integer representing the number to input into the board.
 */
void update_board(int *board[9][9], int row, int col, int num);

/**
 * Check the validity of the move the player desires.
 * 
 * Given a row, column, and number from a player input, this function checks the
 * following: 
 *  - whether or not the spot is filled already
 *  - whether or not the number matches the answer key (is the right number)
 * If the player's move is valid, the function returns 0. Otherwise, the function
 * returns 1.
 * 
 * @param board An array of arrays of integers that represent the player board.
 * @param row An integer representing the first array to index into.
 * @param col An integer representing the second array to index into.
 * @param num An integer representing the number to input into the board.
 * @return An integer representing the validity of the move (1 if invalid, 0 if valid).
 */
int check_move(int *board[9][9], int row, int col, int num);

/**
 * Check whether the board is completely filled or not.
 * 
 * When called, checks the given board for whether each space is completely filled. 
 * If so, the function change the value of a global variable from 0 (incomplete) to 
 * 1 (complete).
 * 
 * @param board An array of arrays of integers that represent the player board.
 * @param filled A global integer representing the state of the board (filled or not).
 */
void board_complete(int *board[9][9], int *filled);

/**
 * Check whether the solution board is correct.
 * 
 * When called, checks if the given board follows the game logic/rules. The logic this
 * function checks is as follows:
 *  - whether or not each space in each row contains different numbers 1-9.
 *  - whether or not each space in each column contains different numbers 1-9.
 *  - whether or not each in a 3x3 square of the 9x9 board contains different numbers 1-9.
 * 
 * Should the solution board be correctly filled, the function returns the number 0.
 * Otherwise, it returns the number 1.
 * 
 * @param board An array of arrays of integers that represent the player board.
 * @return An integer representing the validity of the solution board.
*/
int check_board(int *board[9][9]);
