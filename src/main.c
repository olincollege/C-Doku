#include "constants.h"
#include "controller.h"
#include "model.h"
#include "view.h"
#include <stdio.h>

int main() {
  // BEYOND MVP: create empty player board & completed board

  // initialize premade board structs
  const_game_state consts = {board_solution, board_start, 1, 3};
  var_game_state var = {consts.init_board, 0, {0, 0, 0}};

  // main loop; while board is not filled keep playing game
  while (1) {
    // display player board
    print_board_view(var.player_board);
    // get player input
    char *input = get_player_input();
    // TO DO - check whether this returns 0 or 1 if correct
    if (check_valid_input(input) != 0) {
      printf("Please use correct format");
      continue;
    }
    add_player_move(input, var);
    if (check_fill(var) != 0) {
      printf("Spot is already filled. Make a new move");
      continue;
    }
    if (move_correct(var, consts) != 0) {
      printf("WRONG MOVE SUCKER. try again.");
      var.errors++; // I don't think this is correct way to do this
      continue;
    }
    update_board(var);
    if (var.errors == 3) {
      puts("you lost");
      break;
    }
    if (board_complete(var) == 0) {
      puts("you won");
      break;
    }
  }
  puts("rerun this function to play again idk");
}
