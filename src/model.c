#include "model.h"

#include "boards.h"

void update_board(var_game_state *var) {
  var->player_board[var->p_move.row][var->p_move.col] = var->p_move.num;
}

int check_fill(var_game_state *var) {
  if (var->player_board[var->p_move.row][var->p_move.col] != ' ') {
    return 1;
  }
  return 0;
}

int move_correct(var_game_state *var, const_game_state *consts) {
  if (consts->solution_board[var->p_move.row][var->p_move.col] ==
      var->p_move.num) {
    return 0;
  }
  return 1;
}

int board_complete(var_game_state *var) {
  for (int i = 0; i < BOARD_DIM; i++) {
    for (int j = 0; j < BOARD_DIM; j++) {
      if (var->player_board[i][j] == ' ') {
        return 1;
      }
    }
  }
  return 0;
}

int check_player_board(var_game_state *var, const_game_state *consts) {
  for (int i = 0; i < BOARD_DIM; i++) {
    for (int j = 0; j < BOARD_DIM; j++) {
      if (var->player_board[i][j] != consts->solution_board[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

void setup_game(const_game_state *consts, var_game_state *var) {
  const board *solution = &solution_easy_1;
  const board *initial = &init_easy_1;
  int board_number =
      (rand() % NUM_BOARDS); // NOLINT(cert-msc30-c,
                             // cert-msc50-cpp,concurrency-mt-unsafe)
  switch (consts->level) {
  case 0:
    solution = &solution_demo;
    initial = &init_demo;
    break;
  case 1:
    solution = easy_board_solution[board_number];
    initial = easy_board_init[board_number];
    break;
  case 2:
    solution = medium_board_solution[board_number];
    initial = medium_board_init[board_number];
    break;
  case 3:
    solution = hard_board_solution[board_number];
    initial = hard_board_init[board_number];
    break;
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
      consts->solution_board[i][j] = (*solution)[i][j];
    }
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
      consts->init_board[i][j] = (*initial)[i][j];
    }
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
      var->player_board[i][j] = consts->init_board[i][j];
    }
  }
  var->errors = 0;
}
