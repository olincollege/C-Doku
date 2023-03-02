#include "model.h"
#include <stdio.h>

void update_board(var_game_state var)
{
  var.player_board[var.p_move.row][var.p_move.col] = var.p_move.num;
}

int check_fill(var_game_state var)
{
  if (var.player_board[var.p_move.row][var.p_move.col] != ' ')
  {
    return 1;
  }
  return 0;
}

int move_correct(var_game_state var, const_game_state consts)
{
  if (consts.solution_board[var.p_move.row][var.p_move.col] == var.p_move.num)
  {
    return 0;
  }
  return 1;
}

// TO DO Fix
int board_complete(var_game_state var)
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (var.player_board[i][j] == ' ')
      {
        return 1;
      }
    }
  }
  return 0;
}

int check_player_board(var_game_state var, const_game_state consts)
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (var.player_board[i][j] != consts.solution_board[i][j])
      {
        return 1;
      }
    }
  }
  return 0;
}

int check_solution_board(void)
{
  // TO DO - Implement this function
  // checks whether the solution board actually follows all of the rules
  return 0;
}
