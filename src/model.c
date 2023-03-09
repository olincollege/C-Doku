#include "model.h"

const char board_start[BOARD_DIM][BOARD_DIM] = {
  " 9 28   6", 
  "62    1 8", 
  "  7    3 ",
  "8 31  4  ", 
  "    7 36 ", 
  " 79      ",
  "1    49 2", 
  "94    87 ", 
  "     8   "};

const char board_solution[BOARD_DIM][BOARD_DIM] = {
  "391285746",
  "625437198",
  "487916235",
  "863159427",
  "514872369",
  "279643581",
  "138764952",
  "946521873",
  "752398614"};

const char board_start_easy_1[BOARD_DIM][BOARD_DIM] = {
  "   26 7 1", 
  "68  7  9 ", 
  "19   45  ",
  "82 1   4 ", 
  "  46 29  ", 
  " 5   3 28",
  "  93   74", 
  " 4  5  36", 
  "7 3 18   "};

const char board_solution_easy_1[BOARD_DIM][BOARD_DIM] = {
  "435269781",
  "682571493",
  "197834562",
  "826195347",
  "374682915",
  "951743628", 
  "519326874", 
  "248957136",
  "763418259"
  };


void update_board(var_game_state *var)
{
  var->player_board[var->p_move.row][var->p_move.col] = var->p_move.num;
}

int check_fill(var_game_state *var)
{
  if (var->player_board[var->p_move.row][var->p_move.col] != ' ')
  {
    return 1;
  }
  return 0;
}

int move_correct(var_game_state *var, const_game_state *consts)
{
  if (consts->solution_board[var->p_move.row][var->p_move.col] == var->p_move.num)
  {
    return 0;
  }
  return 1;
}

// TO DO Fix
int board_complete(var_game_state *var)
{
  for (int i = 0; i < BOARD_DIM; i++)
  {
    for (int j = 0; j < BOARD_DIM; j++)
    {
      if (var->player_board[i][j] == ' ')
      {
        return 1;
      }
    }
  }
  return 0;
}

int check_player_board(var_game_state *var, const_game_state *consts)
{
  for (int i = 0; i < BOARD_DIM; i++)
  {
    for (int j = 0; j < BOARD_DIM; j++)
    {
      if (var->player_board[i][j] != consts->solution_board[i][j])
      {
        return 1;
      }
    }
  }
  return 0;
}

static int check_row(const_game_state *consts, int row)
{
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++)
  {
    if (strchr("123456789", consts->solution_board[row][i]) != NULL)
    {
      int index = consts->solution_board[row][i] - '0';
      check[index - 1] = consts->solution_board[row][i];
    }
  }
  return strcmp("123456789", check);
}

static int check_col(const_game_state *consts, int col)
{
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++)
  {
    if (strchr("123456789", consts->solution_board[i][col]) != NULL)
    {
      int index = consts->solution_board[i][col] - '0';
      check[index - 1] = consts->solution_board[i][col];
    }
  }
  return strcmp("123456789", check);
}

static int check_square(const_game_state *consts, int row, int col)
{
  char check[BOARD_DIM + 1] = "         ";
  for (int i = row; i < row + 3; i++)
  {
    for (int j = col; j < col + 3; j++)
    {
      if (strchr("123456789", consts->solution_board[i][j]) != NULL)
      {
        int index = consts->solution_board[i][j] - '0';
        check[index - 1] = consts->solution_board[i][j];
      }
    }
  }
  return strcmp("123456789", check);
}

int check_solution_board(const_game_state *consts)
{
  // checks whether the solution board actually follows all of the rules
  // check rows and cols
  for (int i = 0; i < BOARD_DIM; i++)
  {
    if (check_row(consts, i) != 0 || check_col(consts, i) != 0)
    {
      return 1;
    }
  }
  // Check Squares
  for (int row = 0; row < BOARD_DIM - 2; row = row + 3)
  {
    for (int col = 0; col < BOARD_DIM - 2; col = col + 3)
    {
      if (check_square(consts, row, col) != 0)
      {
        return 1;
      }
    }
  }
  return 0;
}
