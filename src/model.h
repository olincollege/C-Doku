#pragma once

#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Define useful constants needed in the program.
enum {
  /** Dimensions of sudoku board.*/
  BOARD_DIM = 9,
  /** Number of errors allowed.*/
  ERRORS = 3,
  /** Maximum size of input.*/
  BUFFER = 7,
  /** Maximum number of boards for each level.*/
  NUM_BOARDS = 5,
};

// Define game state structs.

// The player's inputted move represented by the row, column, and number.
typedef struct {
  int row;
  int col;
  char num;
} move;

// The board represented by 9 by 9 array of characters.
typedef char board[BOARD_DIM][BOARD_DIM];

// The parts of the sudoku game that change, including the player's board, the
// number of errors the player has made, and the player's latest move.
typedef struct {
  board player_board;
  size_t errors;
  move p_move;
} var_game_state;

// The parts of the sudoku game that do not change, including the initial board,
// the solution board, and the level.
typedef struct {
  board solution_board;
  board init_board;
  size_t level;
} const_game_state;

// Hard coded boards
// extern board board_start;
// extern board board_solution;
extern const board init_demo;
extern const board solution_demo;
extern const board init_easy_1;
extern const board solution_easy_1;
extern const board init_easy_2;
extern const board solution_easy_2;
extern const board init_easy_3;
extern const board solution_easy_3;
extern const board init_easy_4;
extern const board solution_easy_4;
extern const board init_easy_5;
extern const board solution_easy_5;
extern const board init_medium_1;
extern const board solution_medium_1;
extern const board init_medium_2;
extern const board solution_medium_2;
extern const board init_medium_3;
extern const board solution_medium_3;
extern const board init_medium_4;
extern const board solution_medium_4;
extern const board init_medium_5;
extern const board solution_medium_5;
extern const board init_hard_1;
extern const board solution_hard_1;
extern const board init_hard_2;
extern const board solution_hard_2;
extern const board init_hard_3;
extern const board solution_hard_3;
extern const board init_hard_4;
extern const board solution_hard_4;
extern const board init_hard_5;
extern const board solution_hard_5;

// Hard coded board list 
const board* easy_board_init[NUM_BOARDS];
const board* easy_board_solution[NUM_BOARDS];
const board* medium_board_init [NUM_BOARDS];
const board* medium_board_solution [NUM_BOARDS];
const board* hard_board_init [NUM_BOARDS];
const board* hard_board_solution [NUM_BOARDS];


/**
 * Update the player sudoku board with the player's latest move.
 *
 * Given the variable game state struct, this function will update the player
 * board with the latest move made by the player. The player's move is
 * represented by a struct containing the row, column, and number selected by
 * the player.
 *
 * @param var A pointer to the variable game state containing the player board
 * and the player's move.
 */
void update_board(var_game_state *var);

/**
 * Check whether a spot in the player board is already filled.
 *
 * Given the variable game state struct, this function checks whether the spot
 * at the row and column specified in the latest move made by the player is
 * already filled in the player board.
 * If the spot is empty, the function returns 0. Otherwise, the
 * function returns 1.
 *
 * @param var A pointer to the variable game state struct.
 * @return An integer representing whether the spot is filled (0 if
 * empty, 1 if filled).
 */
int check_fill(var_game_state *var);

/**
 * Check whether the latest move made by the player is correct.
 *
 * Given the variable game state struct and the constant game state struct, this
 * function checks whether the player's move matches the solution board at that
 * index. If the player's move is correct, the function returns 0. Otherwise,
 * the function returns 1.
 *
 * @param var A pointer to the variable game state struct.
 * @param consts A pointer to the constant game state struct.
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
 * @param var A pointer to the variable game state struct.
 * @return An integer representing whether the board is filled (0 if
 * filled, 1 if not filled).
 */
int board_complete(var_game_state *var);

/**
 * Check whether the player's completed board is filled in correctly.
 *
 * This function iterates through every space in the player board and checks
 * whether each one matches the corresponding space in the solution board. If
 * everything matches, the function return a 0, and returns a 1 otherwise.
 *
 * @param var A pointer to the variable game state struct.
 * @param consts A pointer to the constant game state struct.
 * @return An integer representing whether the board is correctly filled.
 */
int check_player_board(var_game_state *var, const_game_state *consts);

/**
 * Check whether the solution board is correct.
 *
 * When called, check if the given board follows sudoku rules. The
 * logic this function checks is as follows:
 *  - Whether each space in each row contains unique numbers 1-9.
 *  - Whether each space in each column contains unique numbers 1-9.
 *  - Whether each space in a 3x3 square of the 9x9 board contains unique
 * numbers 1-9.
 *
 * Should the solution board be correctly filled, the function returns 0.
 * Otherwise, it returns 1.
 *
 * @param consts A pointer to the constant game state struct.
 * @return An integer representing whether the solution board is correct.
 */
int check_solution_board(const_game_state *consts);

/**
 * Set up the game state and game information structs based on the chosen level.
 *
 * This function chooses a sudoku board based on the level the player chose,
 * (easy, medium, or hard). Then it fills in the board fields of the
 * const_game_state and var_game_state structs with the intial version of the
 * chosen sudoku board (meaning the version with values missing that will be
 * presented to the player) and the solved version of the chosen sudoku board.
 *
 * @param var A pointer to the variable game state struct.
 * @param consts A pointer to the constant game state struct.
 */
void setup_game(const_game_state *consts, var_game_state *var);
