#include "model.h"
#include <stdio.h>

const char board_start[BOARD_DIM][BOARD_DIM] = {" 9 28   6", "62    1 8", "  7    3 ",
                                "8 31  4  ", "    7 36 ", " 79      ",
                                "1    49 2", "94    87 ", "     8   "};
const char board_solution[BOARD_DIM][BOARD_DIM] = {"391285746", "625437198", "487916235",
                                   "863159427", "514872369", "279643581",
                                   "138764952", "946521873", "752398614"};


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
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
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
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (var->player_board[i][j] != consts->solution_board[i][j])
      {
        return 1;
      }
    }
  }
  return 0;
}

int check_solution_board(const_game_state *consts)
{
  // TO DO - Implement this function
  // checks whether the solution board actually follows all of the rules
  return 0;
}
