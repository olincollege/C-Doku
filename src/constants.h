#pragma once
#include <stddef.h>

// structs

typedef struct {
  int row;
  int col;
  char num;
} move;

typedef struct {
  int player_board[9][9];
  size_t errors;
  move p_move;
} var_game_state;

typedef struct {
  char solution_board[9][9];
  char init_board[9][9];
  size_t level;
  size_t max_errors;
} const_game_state;

// hard coded boards
const char board_start[9][9] = {
  " 9 28   6", 
  "62    1 8",
  "  7    3 ", 
  "8 31  4  ",
  "    7 36 ", 
  " 79      ",
  "1    49 2", 
  "94    87 ",
  "     8   "
};

const char board_complete[9][9] = {
  "391285746", 
  "625437198",
  "487916235", 
  "863159427",
  "514872369", 
  "279643581",
  "138764952", 
  "946521873",
  "752398614"
};

// struct computer_board board1;

// board1.solution[9][9] = {0, 9, 0, 2, 8, 0, 0, 0, 6}, {6, 2, 0, 0, 0, 0, 1, 0,
// 8},
//     {0, 0, 7, 0, 0, 0, 0, 3, 0}, {8, 0, 3, 1, 0, 0, 4, 0, 0},
//     {0, 0, 0, 0, 7, 0, 3, 6, 0}, {0, 7, 9, 0, 0, 0, 0, 0, 0},
//     {1, 0, 0, 0, 0, 4, 9, 0, 2}, {9, 4, 0, 0, 0, 0, 8, 7, 0},
//     {0, 0, 0, 0, 0, 8, 0, 0, 0};
