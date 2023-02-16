#include <stdio.h>
#include <boards.c>


int filled = 0;



int main() {
  // get empty player board & completed board

// initializing premade boards
  struct computer_board board1;
  board1.solution = &board_complete;
  board1.initial = &board_start;
  board1.level = 1;



  while (filled == 0) {
    // display player board
    // get player input (row, column, number)
    // check_move()
    // if check_move returns 1, display error ("incorrect move"), add 1 to error
    // counter, continue if check_move board_complete(player_board, &filled);
  }
  // say "re run this function to play again!"
}
