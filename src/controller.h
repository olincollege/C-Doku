/**
 * Contains the functions relating to controller input.
 */

#pragma once

#include "model.h"

/**
 * Checks if the player's input is of the correct format.
 *
 * The correct answer format is as follows:
 *  --> row,col,num
 *
 * Where row, col, and num are integers, and there are no spaces included. The function
 * indexes through the string and checks that characters in each slot of the array are
 * of the correct type they are supposed to be in. For example, characters in index slots
 * that are even should be integers, while the odd-numbered index slots should be commas.
 * If the input is in the correct format, the function returns 0, and it otherwise returns 1.
 *
 * @param input A string representing the original string to verify.
 * @return An integer indicating the input is correct (0) or not (1).
 */
int check_valid_input(char *input);

/**
 * Asks player for a move and saves the raw input.
 *
 * When called, this function uses printf() to ask the player for their move,
 * and displays the correct format to input it. The fgets() function is then
 * called to save the raw input from the player's keyboard into a given string.
 * If the player's move is too long or not successfully obtained, the function
 * will return 1, or 0 otherwise.
 *
 * @param input A string that will hold the move that the player inputs.
 * @return An integer representing whether 
 */
int get_player_input(char *input);

/**
 * Parses the player input and saves the integer values into an array of integers.
 *
 * When called, this function indexes through the string and saves any non-comma value
 * into an array. This function assumes that the first-appearing integer is the row, the
 * second-appearing integer is the column, and the third-appearing integer is the number.
 *
 * @param input An array of characters representing the player's raw input to parse.
 * @param var 
 * @return An integer representing whether the function ran succesfully (0) or not (1).
 */
int add_player_move(char *input, var_game_state *var);
