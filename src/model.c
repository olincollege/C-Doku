#include "constants.h"
#include "model.h"
#include <stdio.h>

void update_board(var_game_state var) {
  var.player_board[var.p_move.row][var.p_move.col] = var.p_move.num;
}

int check_fill(var_game_state var) {
  // checks whether that spot is already filled
  if (var.player_board[var.p_move.row][var.p_move.col] != ' ') {
    return 1;
  }
  return 0;
}

int move_correct(var_game_state var, const_game_state consts) {
  // 0 = correct move
  // 1 = incorrect move
  if (consts.solution_board[var.p_move.row][var.p_move.col] == var.p_move.num) {
    return 0;
  }
  return 1;
}

void board_complete(var_game_state var) {
  // checks whether board is filled
  // 0 = complete
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (var.player_board[i][j] == ' ') {
        return 1;
      }
    }
  }
  return 0;
}

int check_player_board(var_game_state var, const_game_state consts) {
  // checks whether player board is filled in correctly compared to solution
  // 1 means incorrect
  // 0 means correct
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (var.player_board[i][j] != consts.solution_board[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

int check_solution_board(int) {
  // checks whether the solution board actually follows all of the rules
}
