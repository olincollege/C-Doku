#include "controller.h"
#include "constants.h"
#include <stdio.h>


/**
 * Convert a given character into the index needed to edit array.
 * 
 * Given a character, this function converts it into an integer (assuming that all inputs
 * are numbers) and subtracts 1 from it. The intention behind this function is purely for
 * the functionality of the game. When a player inputs their desired move, the index they
 * provide for row and column will be numbers from 1-9. However, when indexing into the 
 * game board array, we need a number from 0-8, hence the subtraction. Additionally, the
 * player input will be taken in as a string since the input is coming from a keyboard. 
 * However, we need row and column to be integers in order to index into the array. 
 * Therefore, we convert it into an integer as well.
 * 
 * @param input A pointer to a character representing the character to be converted.
*/
static void convert_move(char *input) {
  // converts input into 0-8 index
  input = (int)input - 1;
}

int check_valid_input(char *input) {
  const char *valid_nums =
      "12345689"; // verifying input is an int (in char form at this pt)

  for (int i = 0; i < strlen(input) - 1;
       i++) {         // looping through player's input string
    if (i % 2 == 0) { // if its even
      if (strstr(valid_nums, input[i]) == NULL) { // if integers are actually correct
        return 1;
      }
    } else {
      if (input[i] != ",") { // if the commas are correct
        return 1;
      }
    }
  }

  return 0;
}

char* get_player_input() {
    char* input[6];                                         // is required for player to follow the correct format when typing, otherwise it will be rejected
    printf("Insert next move in row,col,num format: ");
    fgets(input, sizeof(input),stdin);                      // scans player input into char pointer
    return *input;
}   // **MAKE SURE UR RETURNING A POINTER TO SOMETHING**

void add_player_move(char *input, var_game_state var) {
  // int* move[3];

  for (int i = 0; i < strlen(input) - 1; i++) { // if not a comma, copy into final array
    if (input[i] != ",") {
      // move[i] = (int)input[i];                // casting input as integer
      // before storing

      switch(i) {
        case 0: 
          convert_move(&input[i]);
          input[i] = var.p_move.row;
          break;
        case 2:
          convert_move(&input[i]);
          input[i] = var.p_move.col;
          break;
        case 4:
          input[i] = var.p_move.num;
          break;
      }
    }
  }   
}

