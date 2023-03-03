#include "controller.h"
#include "model.h"
#include <stdio.h>
#include <string.h>

/**
 * Convert a given character into the index needed to edit array.
 *
 * Given a character, this function converts it into an integer (assuming that
 * all inputs are numbers) and subtracts 1 from it. The intention behind this
 * function is purely for the functionality of the game. When a player inputs
 * their desired move, the index they provide for row and column will be numbers
 * from 1-9. However, when indexing into the game board array, we need a number
 * from 0-8, hence the subtraction. Additionally, the player input will be taken
 * in as a string since the input is coming from a keyboard. However, we need
 * row and column to be integers in order to index into the array. Therefore, we
 * convert it into an integer as well.
 *
 * @param input A pointer to a character representing the character to be
 * converted.
 */
int convert_move(const char input) { return (input - '0') - 1; }

int check_valid_input(char *input) {
  const char *valid_nums = "12345689";

  for (size_t i = 0; i < strlen(input) - 1;
       i++) {         // looping through player's input string
    if (i % 2 == 0) { // if its even
      if (strchr(valid_nums, input[i]) ==
          NULL) { // if integers are actually correct
        return 1;
      }
    } else {
      if (input[i] != ',') { // if the commas are correct
        return 1;
      }
    }
  }
  return 0;
}

void get_player_input(char *input) { // is required for player to follow the correct
                           // format when typing, otherwise it will be rejected
  printf("Insert next move in row,col,num format: ");
  (void)fgets(input, sizeof(input),
              stdin); // scans player input into char pointer
}

int add_player_move(char *input, var_game_state *var) {
  for (size_t i = 0; i < strlen(input) - 1;
       i++) { // if not a comma, write into struct
    if (input[i] != ',') {
      switch (i) {
      case 0:
        var->p_move.row = convert_move(input[i]);
        break;
      case 2:
        var->p_move.col = convert_move(input[i]);
        break;
      case 4:
        input[i] = var->p_move.num;
        break;
      default:
        return 1;
      }
    }
  }
  return 0;
}
