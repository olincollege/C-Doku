#include <stdio.h>

void update_board(int p_board[9][9], int row, int col, int num) {
  p_board[row][col] = num;
}

int move_valid(int com_board[9][9], int p_board[9][9], int row, int col,
               int num) {
  /*
  / int check = check_move(&answer, &player, 3, 3, 1);
    switch(check) {
      case 2 :
         printf("Invalid index. Input a row and column between 1-9.\n" );
         break;
      case 3 :
         printf("Invalid number. Input a number between 1-9.\n" );
         break;
      case 4 :
         printf("Move already filled. Input a new index.\n" );
         break;
      default :
         printf("Code error :(" );
  */
  // 2 = invalid index input
  // 3 = invalid number input
  // 4 = filled spot
  if (row < 0 || row > 8 || col < 0 || col > 8) {
    return 2;
  }
  if (num < 1 || num > 9) {
    return 3;
  }
  if (p_board[row][col] != 0) {
    return 4;
  }
}

int move_correct(int com_board[9][9], int p_board[9][9], int row, int col,
                 int num) {
  // 0 = correct move
  // 1 = incorrect move
  if (com_board[row][col] == num) {
    return 0;
  }
  return 1;
}

void board_complete(int p_board[9][9], int *filled) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (p_board[i][j] == 0) {
        *filled = 0;
        return;
      }
    }
  }
  *filled = 1;
}

int check_player_board(int p_board[9][9], int com_board[9][9]) {
  // checks whether player board is filled in correctly compared to solution
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (p_board[i][j] != com_board[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

int check_solution_board(int) {
  // checks whether the solution board actually follows all of the rules
}
