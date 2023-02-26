#pragma once
#include <stddef.h>

// structs

typedef struct {
  int row;
  int col;
  int num;
} move;

typedef struct {
  char player_board[9][9];
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
int board_start[9][9] = {
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
};

int board_complete[9][9] = {
    {3, 9, 1, 2, 8, 5, 7, 4, 6}, {6, 2, 5, 4, 3, 7, 1, 9, 8},
    {4, 8, 7, 9, 1, 6, 2, 3, 5}, {8, 6, 3, 1, 5, 9, 4, 2, 7},
    {5, 1, 4, 8, 7, 2, 3, 6, 9}, {2, 7, 9, 6, 4, 3, 5, 8, 1},
    {1, 3, 8, 7, 6, 4, 9, 5, 2}, {9, 4, 6, 5, 2, 1, 8, 7, 3},
    {7, 5, 2, 3, 9, 8, 6, 1, 4},
};

// struct computer_board board1;

// board1.solution[9][9] = {0, 9, 0, 2, 8, 0, 0, 0, 6}, {6, 2, 0, 0, 0, 0, 1, 0,
// 8},
//     {0, 0, 7, 0, 0, 0, 0, 3, 0}, {8, 0, 3, 1, 0, 0, 4, 0, 0},
//     {0, 0, 0, 0, 7, 0, 3, 6, 0}, {0, 7, 9, 0, 0, 0, 0, 0, 0},
//     {1, 0, 0, 0, 0, 4, 9, 0, 2}, {9, 4, 0, 0, 0, 0, 8, 7, 0},
//     {0, 0, 0, 0, 0, 8, 0, 0, 0};
