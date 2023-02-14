#include <stdio.h>

void update_board(int (*board)[][], int row, int col, int num) {
  // updates player board
  // add num to index given
  (*board)[row][col] = num;
}

int check_move(int (*board)[][], int row, int col, int num) {
  // checks if move is valid
  // check whether that index already filled in
  // if yes return 1
  // compare input to correct board
  // if they match, return 0
  // otherwise return 1
}

void board_complete(int (*board)[][], int *filled) {
  // checks whether board is filled
  // if yes, changes filled variable to 1
}

int check_board(int (*board)[][]) {
  // checks whether board given is filled in correctly
}
