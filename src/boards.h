#pragma once

#include <stdio.h>
#include <string.h>

enum {
  /** Dimensions of sudoku board.*/
  BOARD_DIM = 9,
  /** Maximum number of boards for each level.*/
  NUM_BOARDS = 5,
};

// The board represented by 9 by 9 array of characters.
typedef char board[BOARD_DIM][BOARD_DIM];

// Hard coded boards
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

// Hard coded board pointers lists
extern const board *const easy_board_init[NUM_BOARDS];
extern const board *const easy_board_solution[NUM_BOARDS];
extern const board *const medium_board_init[NUM_BOARDS];
extern const board *const medium_board_solution[NUM_BOARDS];
extern const board *const hard_board_init[NUM_BOARDS];
extern const board *const hard_board_solution[NUM_BOARDS];

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
 * @param brd A board type.
 * @return An integer representing whether the solution board is correct.
 */
int check_solution_board(const board brd);
