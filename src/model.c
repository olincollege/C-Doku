#include "model.h"
//To Do: Delete 
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

const char init_easy_1[BOARD_DIM][BOARD_DIM] = {
  " 7  2  46", 
  " 6    89 ", 
  "2  8  715",
  " 84 97   ", 
  "71     59", 
  "   13 48 ",
  "697  2  8", 
  " 58    6 ", 
  "43  8  7 "};

const char solution_easy_1[BOARD_DIM][BOARD_DIM] = {
  "875921346", 
  "361754892", 
  "249863715",
  "584697123", 
  "713248659", 
  "926135487",
  "697412538", 
  "158379264", 
  "432586971"};
const char init_easy_2[BOARD_DIM][BOARD_DIM] = {
  "  4 5    ", 
  "9  7346  ", 
  "  3 21 49",
  " 35 9 48 ", 
  " 9     3 ", 
  " 76 1 92 ",
  "31 97 2  ", 
  "  9182  3", 
  "    6 1  "};

const char solution_easy_2[BOARD_DIM][BOARD_DIM] = {
  "264859317",
  "981734652",
  "753621849",
  "135297486",
  "892546731",
  "476318925", 
  "318975264", 
  "649182573",
  "527463198"
  };

const char init_medium_1[BOARD_DIM][BOARD_DIM] = {
    "5 72   9 ",
    "  6 3 7 1",
    "4      6 ",
    "1  49   7",
    "   5 8   ",
    "8   27  5", 
    " 7      9", 
    "2 9 8 6  ",
    " 4   93 8"
  };

const char solution_medium_1[BOARD_DIM][BOARD_DIM] = {
  "517264893",
  "926835741",
  "483971562",
  "135496287",
  "792518436",
  "864327915", 
  "378642159", 
  "259183674",
  "641759328"
  };

const char init_medium_2[BOARD_DIM][BOARD_DIM] = {
  "2     69 ",
  " 5   3   ",
  "17   94 5",
  "  3 25 18",
  "    4    ",
  "72 38 5  ", 
  "5 26   41", 
  "   5   7 ",
  " 67     3"
  };

const char solution_medium_2[BOARD_DIM][BOARD_DIM] = {
  "234158697",
  "956473182",
  "178269435",
  "643925718",
  "815746329",
  "729381564", 
  "592637841", 
  "381594276",
  "467812953"
  };
const char init_hard_1[BOARD_DIM][BOARD_DIM] = {
  "  65    8",
  " 95    2 ",
  "7  9  3  ",
  "    4 27 ",
  "   873   ",
  " 79 5    ", 
  "  2  8  9", 
  " 5    81 ",
  "3    54  "
  };

const char solution_hard_1[BOARD_DIM][BOARD_DIM] = {
  "136524798",
  "895367124",
  "724981356",
  "583649271",
  "261873945",
  "479152683", 
  "642718539", 
  "957436812",
  "318295467"
  };

  const char init_hard_2[BOARD_DIM][BOARD_DIM] = {
  " 91 7    ",
  "2 3    5 ",
  "   4 29 7",
  "  28 6  9",
  "         ",
  "9  1 46  ", 
  "1 52 7   ", 
  " 8    5 1",
  "    1 76 "
  };

const char solution_hard_2[BOARD_DIM][BOARD_DIM] = {
  "491675238",
  "273981456",
  "856432917",
  "712856349",
  "564793182",
  "938124675", 
  "145267893", 
  "687349521",
  "329518764"
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

void setup_game(const_game_state *consts, var_game_state *var) {
  const char (*solution)[BOARD_DIM][BOARD_DIM];
  const char (*initial)[BOARD_DIM][BOARD_DIM];
  switch (consts->level){
    case 1:
      solution = &solution_easy_1;
      initial = &init_easy_1;
      break;
    case 2:
      solution = &solution_medium_1;
      initial = &init_medium_1;
      break;
    case 3:
      solution = &solution_hard_1;
      initial = &init_hard_1;
      break;
    default:
      puts("uh, shwoopsies\n"); // DELETE AFTER DEBUGGING
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        consts->solution_board[i][j] = (*solution)[i][j];
    }
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        consts->init_board[i][j] = (*initial)[i][j];
    }
  }
  for (size_t i = 0; i < BOARD_DIM; i++) {
    for (size_t j = 0; j < BOARD_DIM; j++) {
        var->player_board[i][j] = consts->init_board[i][j];
    }
  }
  var->errors = 0;
}
