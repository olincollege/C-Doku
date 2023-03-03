#include "controller.h"
#include "model.h"
#include "view.h"
#include <stdio.h>

int main() {
  // BEYOND MVP: create empty player board & completed board

  // initialize premade board structs
  const_game_state consts = {
    .solution_board = board_solution, 
    .init_board = board_start, 
    .level = 1, 
    .max_errors = ERRORS
    };
  var_game_state var = {
    .player_board = consts.init_board, 
    .errors = 0, 
    .p_move = {0, 0, 0},
    };

  // main loop; while board is not filled keep playing game
  while (1) {
    // display player board
    print_board_view(var.player_board);
    // get player input
    char *input[BUFFER];
    get_player_input(input);
    // TO DO - check whether this returns 0 or 1 if correct
    if (check_valid_input(input) != 0) {
      printf("Please use correct format");
      continue;
    }
    add_player_move(input, &var);
    if (check_fill(&var) != 0) {
      printf("Spot is already filled. Make a new move");
      continue;
    }
    if (move_correct(&var, &consts) != 0) {
      printf("WRONG MOVE SUCKER. try again.");
      var.errors++; // I don't think this is correct way to do this
      continue;
    }
    update_board(&var);
    if (var.errors == 3) {
      puts("you lost"); // REPLACE WITH VIEW FUNCTION
      break;
    }
    if (board_complete(&var) == 0) {
      puts("you won"); // REPLACE WITH VIEW FUNCTION
      break;
    }
  }
  puts("rerun this function to play again idk");
}
