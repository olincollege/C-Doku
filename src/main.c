#include "controller.h"
#include "model.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // BEYOND MVP: create empty player board & completed board

  // initialize premade board structs
  const_game_state consts;
  consts.max_errors = 1;
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        consts.solution_board[i][j] = board_solution[i][j];
    }
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        consts.init_board[i][j] = board_start[i][j];
    }
  }

  var_game_state var;
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        var.player_board[i][j] = consts.init_board[i][j];
    }
  }
  var.errors = 0;


  // main loop; while board is not filled keep playing game
  while (1) {

    // check win/lose condition
    if (var.errors > 2) {
      puts("you lost\n"); // REPLACE WITH VIEW FUNCTION
      break;
    }
    if (board_complete(&var) == 0) {
      puts("you won\n"); // REPLACE WITH VIEW FUNCTION
      break;
    }

    // display player board
    print_board(&var);

    // get player input
    char input[BUFFER];
    get_player_input(input);
    printf("your move is %s\n", input);

    // TO DO - check whether this returns 0 or 1 if correct
    if (check_valid_input(input) != 0) {
      printf("Please use correct format");
      continue;
    }
    add_player_move(input, &var);
    if (check_fill(&var) != 0) {
      printf("Spot is already filled. Make a new move\n");
      continue;
    }
    if (move_correct(&var, &consts) != 0) {
      printf("WRONG MOVE SUCKER. try again.\n");
      var.errors++; // I don't think this is correct way to do this
      printf("errors %zu/3\n", var.errors);
      continue;
    }
    printf("correct move! good job. keep going.\n");
    update_board(&var);
  }

  return EXIT_SUCCESS;
}
