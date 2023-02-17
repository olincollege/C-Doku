#include "boards.h"
#include "model.h"
#include "view.h"
#include <stdio.h>

int filled = 0;

int main() {
  // BEYOND MVP: create empty player board & completed board

  // initializing premade board structs
  struct computer_board board1;
  board1.solution = &board_complete;
  board1.initial = &board_start;
  board1.level = 1;

  // main loop; while board is not filled keep playing game
  while (filled == 0) {
    // display player board
    // get player input (row, column, number)
    // check_move()
    // if check_move returns 1, display error ("incorrect move"), add 1 to error
    // counter, continue if check_move board_complete(player_board, &filled);
  }
  // say "re run this function to play again!"
}
