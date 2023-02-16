#include <stdio.h>

void update_board(int (*board)[9][9], int row, int col, int num) {
  *board[row][col] = num;
}

int check_move(int (*com_board)[9][9], int (*p_board)[9][9], int row, int col, int num) {
  /*
  / int check = check_move(&answer, &player, 3, 3, 1);
    switch(check) {
      case 0 :
         printf("Correct Move." );
         break;
      case 1 :
         printf("Incorrect Move." );
         break;
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
  // Fix h file 
  // 2 = invalid index input
  // 3 = invalid number input
  // 4 = filled spot
  // 0 = correct move 
  // 1 = incorrect move
  row--; 
  col--;
  if (row < 0 || row >8 || col < 0||col > 8){
    return 2;
  }
  if (num < 1 || num > 9){
    return 3;
  }
  if (*p_board[row][col] != 0){
    return 4;
  }
  else{
    if(*com_board[row][col] == num){
      return 0;
    }
    else{
      return 1;
    }
  }
}

void board_complete(int (*p_board)[9][9], int *filled) {
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        if (*p_board[i][j] == 0){
          *filled = 0;
          return;
        }
      }
    }
  *filled = 1;
}

int check_board(int (*board)[9][9]) {
  // checks whether board given is filled in correctly
}
