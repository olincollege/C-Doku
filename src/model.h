#pragma once

// #include "constants.h"
#include <stddef.h>

// structs

typedef struct
{
    int row;
    int col;
    char num;
} move;

typedef struct
{
    char player_board[9][9];
    size_t errors;
    move p_move;
} var_game_state;

typedef struct
{
    char solution_board[9][9];
    char init_board[9][9];
    size_t level;
    size_t max_errors;
} const_game_state;

// // hard coded boards
const char board_start[9][9] = {" 9 28   6", "62    1 8", "  7    3 ",
                                "8 31  4  ", "    7 36 ", " 79      ",
                                "1    49 2", "94    87 ", "     8   "};

const char board_solution[9][9] = {"391285746", "625437198", "487916235",
                                   "863159427", "514872369", "279643581",
                                   "138764952", "946521873", "752398614"};

// struct computer_board board1;

// board1.solution[9][9] = {0, 9, 0, 2, 8, 0, 0, 0, 6}, {6, 2, 0, 0, 0, 0, 1, 0, 8},
//     {0, 0, 7, 0, 0, 0, 0, 3, 0}, {8, 0, 3, 1, 0, 0, 4, 0, 0},
//     {0, 0, 0, 0, 7, 0, 3, 6, 0}, {0, 7, 9, 0, 0, 0, 0, 0, 0},
//     {1, 0, 0, 0, 0, 4, 9, 0, 2}, {9, 4, 0, 0, 0, 0, 8, 7, 0},
//     {0, 0, 0, 0, 0, 8, 0, 0, 0};

/**
 * Change the player's board according to the inputs given.
 *
 * Given the variable game state struct, this function will replace the space in
 * the player board provided by the user with the number provided by the user.
 *
 * @param var A struct that contains the variables in the game state.
 */
void update_board(var_game_state var);

/**
 * Check whether a spot is already filled.
 *
 * Given the variable game state struct, this function checks whether the spot
 * the user wants to input a number into is already filled.
 * If the spot is empty, the function returns 0. Otherwise, the
 * function returns 1.
 *
 * @param var A struct that contains the variables in the game state.
 * @return An integer representing whether the spot is filled (0 if
 * empty, 1 if filled).
 */
int check_fill(var_game_state var);

/**
 * Check whether the move is correct.
 *
 * Given the variable game state struct and the constant game state struct, this
 * function checks whether the player's move matches the solution board at that
 * index. If the player's move is correct, the function returns 0. Otherwise, the
 * function returns 1.
 *
 * @param var A struct that contains the variables in the game state.
 * @param consts A struct that contains the constants in the game state.
 * @return An integer representing whether the move is correct (0 if
 * correct, 1 if incorrect).
 */
int move_correct(var_game_state var, const_game_state consts);

/**
 * Check whether the board is completely filled or not.
 *
 * When called, checks the given board for whether each space is
 * filled. If so, the function returns 0. Otherwise, it returns 1.
 *
 * @param var A struct that contains the game state including the board.
 * @return An integer representing whether the board is filled (0 if
 * filled, 1 if not filled).
 */
int board_complete(var_game_state var);

/**
 * Check whether the player's completed board is filled in correctly.
 *
 * When called, checks if the given board follows the game logic/rules. The
 * logic this function checks is as follows:
 *  - whether or not each space in each row contains different numbers 1-9.
 *  - whether or not each space in each column contains different numbers 1-9.
 *  - whether or not each in a 3x3 square of the 9x9 board contains different
 * numbers 1-9.
 *
 * Should the solution board be correctly filled, the function returns 0.
 * Otherwise, it returns 1.
 *
 * @param var A struct that contains the variables in the game state.
 * @param consts A struct that contains the constants in the game state.
 * @return An integer representing whether the board is correctly filled.
 */
int check_player_board(var_game_state var, const_game_state consts);

/**
 * TO DO - Fix this after implementing this function
 * Check whether the solution board is correct.
 *
 * When called, checks if the given board follows the game logic/rules. The
 * logic this function checks is as follows:
 *  - whether or not each space in each row contains different numbers 1-9.
 *  - whether or not each space in each column contains different numbers 1-9.
 *  - whether or not each in a 3x3 square of the 9x9 board contains different
 * numbers 1-9.
 *
 * Should the solution board be correctly filled, the function returns the
 * number 0. Otherwise, it returns the number 1.
 *
 * @param var A struct that contains the variables in the game state.
 * @return An integer representing the validity of the solution board.
 */
int check_solution_board(void);
