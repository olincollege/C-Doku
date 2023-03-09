#pragma once

#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Define useful constants needed in the program.
enum
{
    /** Dimensions of sudoku board.*/
    BOARD_DIM = 9,
    /** Number of errors allowed.*/
    ERRORS = 3,
    /** Maximum size of input.*/
    BUFFER = 6,
};

// Define game state structs.

// The player's inputted move represented by the row, column, and number.
typedef struct
{
    int row;
    int col;
    char num;
} move;

// The parts of the sudoku game that change, including the player's board, the
// number of errors the player has made, and the player's latest move.
typedef struct
{
    char player_board[BOARD_DIM][BOARD_DIM];
    size_t errors;
    move p_move;
} var_game_state;

// The parts of the sudoku game that do not change, including the initial board,
// the solution board, the level, and the maximum number of errors allowed.
typedef struct
{
    char solution_board[BOARD_DIM][BOARD_DIM];
    char init_board[BOARD_DIM][BOARD_DIM];
    size_t level;
    size_t max_errors;
} const_game_state;

// // hard coded boards
extern const char board_start[BOARD_DIM][BOARD_DIM];
extern const char board_solution[BOARD_DIM][BOARD_DIM];
extern const char board_start_easy_1[BOARD_DIM][BOARD_DIM];
extern const char board_solution_easy_1[BOARD_DIM][BOARD_DIM];


/**
 * Updates the player sudoku board with the player's latest move.
 *
 * Given the variable game state struct, this function will update the player
 * board with the latest move made by the player. The player's move is
 * represented by a struct containing the row, column, and number selected by
 * the player.
 *
 * @param var A pointer to the variable game state containing the player board and the player's move.
 */
void update_board(var_game_state *var);

/**
 * Checks whether a spot in the player board is already filled.
 *
 * Given the variable game state struct, this function checks whether the spot
 * at the row and column specified in the latest move made by the player is
 * already filled with a number in the player board.
 * If the spot is empty, the function returns 0. Otherwise, the
 * function returns 1.
 *
 * @param var A pointer to the variable game state
 * @return An integer representing whether the spot is filled (0 if
 * empty, 1 if filled).
 */
int check_fill(var_game_state *var);

/**
 * Checks whether the latest move made by the player is correct.
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
int move_correct(var_game_state *var, const_game_state *consts);

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
int board_complete(var_game_state *var);

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
int check_player_board(var_game_state *var, const_game_state *consts);

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
 * @param consts A struct that contains the solution board.
 * @return An integer representing the validity of the solution board.
 */
int check_solution_board(const_game_state *consts);
