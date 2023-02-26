/**
 * Contains the functions relating to controller input.
*/

#pragma once

/**
 * Convert a given character into the index needed to edit array.
 * 
 * Given a character, this function converts it into an integer (assuming that all inputs
 * are numbers) and subtracts 1 from it. The intention behind this function is purely for
 * the functionality of the game. When a player inputs their desired move, the index they
 * provide for row and column will be numbers from 1-9. However, when indexing into the 
 * game board array, we need a number from 0-8, hence the subtraction. Additionally, the
 * player input will be taken in as a string since the input is coming from a keyboard. 
 * However, we need row and column to be integers in order to index into the array. 
 * Therefore, we convert it into an integer as well.
 * 
 * @param input A pointer to a character representing the character to be converted.
*/
void convert_move(char* input);

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
int check_valid_input(char* input);

/**
 * Asks player for a move and saves the raw input.
 * 
 * When called, this function uses printf() to ask the player for a board input,
 * and displays the correct format to input their move. The fgets() function is then
 * called to save the raw input from the player's keyboard. 
 * 
 * @return A string representing the raw input from the player.
*/
char* get_player_input();

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
void add_player_move(char* input, var_game_state var);
