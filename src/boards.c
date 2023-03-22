#include "boards.h"

/**
 * Verify that every row in the board only has one instance of the numbers 1-9.
 *
 * Given the the solution board and the index of the row of the board to check,
 * this function uses a loop to first compare each character of the row to a
 * string containing all possible values to verify that the right input was
 * given. Then, it converts the value into an integer, and inputs the value into
 * the corresponding index in a string named check. Essentially when the loop is
 * finished iterating through the row, it should look identical to the following
 * string: "123456789".
 */
static int check_row(const board brd, int row) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++) {
    if (strchr("123456789", brd[row][i]) != NULL) {
      int index = brd[row][i] - '0';
      check[index - 1] = brd[row][i];
    }
  }
  return strcmp("123456789", check);
}

/**
 * Verify that every column in the board only has one instance of the numbers
 * 1-9.
 *
 * Given the solution board and the index of the column of the board to check,
 * this function uses a loop to first compare each character of the column to a
 * string containing all possible values to verify that the right input was
 * given. Then, it converts the value into an integer, and inputs the value into
 * the corresponding index in a string named check. Essentially when the loop is
 * finished iterating through the column, it should look identical to the
 * following string: "123456789"
 */
static int check_col(const board brd, int col) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++) {
    if (strchr("123456789", brd[i][col]) != NULL) {
      int index = brd[i][col] - '0';
      check[index - 1] = brd[i][col];
    }
  }
  return strcmp("123456789", check);
}

/**
 * Verify that every 3x3 square on the board has only one instance of the
 * numbers 1-9.
 *
 * Given the solution boards and the index of the top left corner of the square
 * to check, this function uses 2 loops to first compare each character of the
 * square to a string containing all possible values to verify that the right
 * input was given. Then, it converts the value into an integer, and inputs the
 * value into the corresponding index in a string named check. Essentially when
 * the loop is finished iterating through the square, it should look identical
 * to the following string: "123456789"
 */
static int check_square(const board brd, int row, int col) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      if (strchr("123456789", brd[i][j]) != NULL) {
        int index = brd[i][j] - '0';
        check[index - 1] = brd[i][j];
      }
    }
  }
  return strcmp("123456789", check);
}

static int check_dim(board brd) {
  int i,j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (brd[i][j] == '\0') {
        puts("It is not 9x9\n");
        printf("we stopped at i=%d, j=%d\n", i,j);
        return 1; // if there is an empty value, return 1
        }
      }
    }
  return 0; // board is 9 by 9
}

int check_solution_board(const board brd) {
  if (check_dim != 0) { // checks whether dimensions are correct
    return 1;
  }

  for (int i = 0; i < BOARD_DIM; i++) {   // checks rows and cols
    if (check_row(brd, i) != 0 || check_col(brd, i) != 0) {
      return 1;
    }
  }
  
  for (int row = 0; row < BOARD_DIM - 2; row = row + 3) { // checks squares
    for (int col = 0; col < BOARD_DIM - 2; col = col + 3) {
      if (check_square(brd, row, col) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// int check_initial_board(board init, board solution) {
//   // checks whether the initial board matches the solution board in all of
//   // spaces that are filled in
//   for (int i = 0; i < BOARD_DIM; i++) {
//     for (int j = 0; j < BOARD_DIM; j++) {
//       if (consts->init_board[i][j] != ' ' &&
//           consts->init_board[i][j] != consts->solution_board[i][j]) {
//         return 1;
//       }
//     }
//   }
//   return 0;
// }
