#include "controller.h"
#include "model.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Initialize game state and game info structs
  const_game_state consts;
  var_game_state var;

  // Seeding our random number generator
  srand((unsigned int)time(0)); // NOLINT(cert-msc32-c,cert-msc51-cpp)

  // Prompt player to select level
  int level_selected = 1;
  while (level_selected) {
    level_selected = get_player_level(&consts);
    if (level_selected) {
      printf("Invalid level selected. Please try again.\n");
    }
  }
  printf("Your level is %zu\n", consts.level);

  // Setup the game according to the level that player chose
  setup_game(&consts, &var);

  // Main loop keeps running while end condition has not been reached
  while (1) {

    // Check win/lose condition
    if (print_result(&var) == 1) {
      break;
    }

    // Display the player board
    print_board(&var);

    // Get the player's input
    char input[BUFFER];
    int correct_size = get_player_input(input);

    // Check whether the player's input is in a valid format
    if (correct_size != 0 || check_valid_input(input) != 0) {
      printf("Please use correct format (for example '1,1,1').\n");
      continue;
    }

    printf("Your move is %s\n", input);

    // If the player's input is in a valid format, add it to the move struct
    add_player_move(input, &var);

    // check whether the spot the player wants to fill is alread filled
    if (check_fill(&var) != 0) {
      printf("This spot is already filled. Try again.\n");
      continue;
    }

    // Check whether the player's move is correct
    if (move_correct(&var, &consts) != 0) {
      if (var.errors < 2) {
        printf("WRONG MOVE. Try again.\n");
      }
      var.errors++;
      printf("Errors: %zu/3\n", var.errors);
      continue;
    }

    printf("Correct move! Keep going :)\n");
    update_board(&var);
  }

  return EXIT_SUCCESS;
}
