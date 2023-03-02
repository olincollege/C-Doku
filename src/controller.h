/**
 * Contains the functions relating to controller input.
 */

#pragma once

#include "model.h"
// #include "constants.h"

/**
 * Checks if the player's input was of the correct format.
 *
 * The correct answer format is as follows:
 *  --> row,col,num
 *
 * Where row, col, and num are integers, and there are no spaces included. The function
 * indexes through the string and checks that characters in each slot of the array are
 * of the correct type they are supposed to be in. For example, characters in index slots
 * that are even should be integers, while the odd-numbered index slots should be commas.
 * Should the input be of the wrong type, the function returns 1. However, if the input
 * was correct, the function returns 0.
 *
 * @param input An array of characters representing the original string to verify.
 * @return An integer indicating the input is correct (0) or not (1).
 */
int check_valid_input(char *input);

/**
 * Asks player for a move and saves the raw input.
 *
 * When called, this function uses printf() to ask the player for a board input,
 * and displays the correct format to input their move. The fgets() function is then
 * called to save the raw input from the player's keyboard.
 *
 * @return A string representing the raw input from the player.
 */
char *get_player_input();

/**
 * Parses the player input and saves the integer values into an array of integers.
 *
 * When called, this function indexes through the string and saves any non-comma value
 * into an array. This function assumes that the first-appearing integer is the row, the
 * second-appearing integer is the column, and the third-appearing integer is the number.
 *
 * @param move An array of characters representing the player's raw input to parse.
 * @return An array of integers representing the row, column, and number of the player's
 * move, in that order.
 */
void add_player_move(char *input, var_game_state var);
