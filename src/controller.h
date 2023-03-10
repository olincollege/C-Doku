/**
 * Contains the functions relating to controller input.
 */

#pragma once

#include "model.h"

/**
 * Check if the player's input is of the correct format.
 *
 * The correct answer format is as follows:
 *  --> row,col,num
 *
 * Row, col, and num are integers, and there are no spaces included in the
 * string. The function first checks that the size of the string is 6, since it
 * should include the 3 ints, 2 commas, and 1 null character. The function
 * indexes through the string and checks that characters in each slot of the
 * array are of the correct type they are supposed to be in. For example,
 * characters in index slots that are even should be integers, while the
 * odd-numbered index slots should be commas. Should the input be of the wrong
 * type/size, the function returns 1. However if the input was correct, the
 * function returns 0.
 *
 * @param input A string representing the original string to verify.
 * @return An integer indicating the input is correct (0) or not (1).
 */
int check_valid_input(char *input);

/**
 * Ask player for a move and saves the raw input.
 *
 * When called, this function uses printf() to ask the player for a board input,
 * and displays the correct format to input their move. The fgets() function is
 * then called to save the raw input from the player's keyboard. Since the
 * fgets() function requires a maximum size, which we've set to 7 (to include 3
 * ints, 2 commas, 1 null character, 1 new-line character), if the input exceeds
 * that size, then new-line character gets cut off when saved. Therefore there
 * is a check in the function that verifies the new-line character is in the
 * string, and if it doesn't it flushes the input using a static function in
 * controller.c. If the size is correct, then it copies the string into the
 * address passed to the function.
 *
 * @param input An aray of characters representing the destination to copy the
 * input into.
 * @return An integer representing the input successfully saved (0) or not (1).
 */
int get_player_input(char *input);

/**
 * Parse the player input and save the integer values into an array of integers.
 *
 * When called, this function indexes through the string and saves any non-comma
 * value into an array. This function assumes that the first-appearing integer
 * is the row, the second-appearing integer is the column, and the
 * third-appearing integer is the number.
 *
 * @param input An array of characters representing the player's raw input to
 * parse.
 * @param var A struct object pointer representing the destination to save the
 * player's moves to.
 * @return An integer 0 if the parsing was successful and 1 otherwise.
 */
int add_player_move(char *input, var_game_state *var);

/**
 * Ask player which level they want to play, and returns the level.
 *
 * This function prints out a statement asking the player which level they want
 * to play easy (1), medium (2), or hard (3). The getchar() function is called
 * get the single character input from the player's keyboard. Then the function
 * edits the level field of the constant game state to reflect the level that
 * the player chose. If the player inputted a valid level, the level field is
 * updated and the function returns 0. Otherwise, it returns 1, showing that the
 * level was not valid.
 *
 * @param consts A pointer to the constant game state struct.
 * @return An integer 0 if the level was successfully chosen, and 1 otherwise.
 *
 */
int get_player_level(const_game_state *consts);
