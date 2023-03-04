#include "controller.h"
#include "model.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // BEYOND MVP: create empty player board & completed board

  // initialize premade board structs
  // const_game_state consts;
  // var_game_state var;

  // consts.max_errors = 1;
  // memcpy(consts.solution_board, board_solution, sizeof(consts.solution_board));
  // memcpy(consts.init_board, board_start, sizeof(consts.init_board));

  // memcpy(var.player_board, consts.init_board, sizeof(var.player_board));
  // var.errors = 0;

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
    get_player_input(*input);
    // TO DO - check whether this returns 0 or 1 if correct
    if (check_valid_input(*input) != 0) {
      printf("Please use correct format");
      continue;
    }
    add_player_move(*input, &var);
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


  //   while (!game_over(&state)) {
  //   print_board(state.board);
  //   printf("It is now %c's move.\n", state.current_turn);
  //   board_space space;
  //   if (get_user_input(&space) == 0 || move(&state, space) == 0) {
  //     puts("Invalid move, please try again.");
  //     continue;
  //   }
  // }
  // if (player_win(&state)) {
  //   printf("%c wins in %zu moves!\n", get_opposing_player(state.current_turn),
  //          state.num_moves);
  // } else {
  //   // The only other way the game can end is if the board is full and nobody's
  //   // won, which is a draw.
  //   printf("It's a draw.\n");
  // }


  return EXIT_SUCCESS;
}
