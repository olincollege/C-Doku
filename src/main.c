#include "constants.h"
#include "model.h"
// #include "view.h"
#include "controller.h"
#include <stdio.h>

int filled = 0;

int main() {
  // BEYOND MVP: create empty player board & completed board

  // initializing premade board structs
  // struct computer_board board1;
  // board1.solution = &board_complete;
  // board1.initial = &board_start;
  // board1.level = 1;

  // main loop; while board is not filled keep playing game
  while (filled == 0) {
    // display player board

    // prompt player to enter move
    // get player input (row, column, number) and convert to correct format
    // check_valid()
    // if not valid --> prompt player to make valid move
    // if valid, check_correct()
    // if check_correct returns 1, display error ("incorrect move"), add 1 to
    // error counter, continue if check_move board_complete(player_board,
    // &filled); if check_correct returns 0, update_board() to change board
    // itself
  }
  // say "re run this function to play again!"
}
