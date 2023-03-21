#include "model.h"

const board init_demo = {"87 921346", "361754 92", "249863715",
                         "5846971 3", "713248659", "926135487",
                         "697412538", " 58379264", "432586971"};

const board solution_demo = {"875921346", "361754892", "249863715",
                             "584697123", "713248659", "926135487",
                             "697412538", "158379264", "432586971"};

const board init_easy_1 = {" 7  2  46", " 6    89 ", "2  8  715",
                           " 84 97   ", "71     59", "   13 48 ",
                           "697  2  8", " 58    6 ", "43  8  7 "};

const board solution_easy_1 = {"875921346", "361754892", "249863715",
                               "584697123", "713248659", "926135487",
                               "697412538", "158379264", "432586971"};

const board init_easy_2 = {"  4 5    ", "9  7346  ", "  3 21 49",
                           " 35 9 48 ", " 9     3 ", " 76 1 92 ",
                           "31 97 2  ", "  9182  3", "    6 1  "};

const board solution_easy_2 = {"264859317", "981734652", "753621849",
                               "135297486", "892546731", "476318925",
                               "318975264", "649182573", "527463198"};

const board init_easy_3 = {"8 6 1    ", "  3 64 9 ", "9     816",
                           " 8 396   ", "7 2 4 3 9", "   572 8 ",
                           "521     4", " 3 75 2  ", "    2 1 5"};

const board solution_easy_3 = {"856917423", "213864597", "947235816",
                               "185396742", "762148359", "394572681",
                               "521683974", "439751268", "678429135"};

const board init_easy_4 = {"38 9  2 5", "     873 ", " 6 3  98 ",
                           "     35 1", "91 5 7 23", "7 31     ",
                           " 35  1 9 ", " 746     ", "8 1  2 67"};

const board solution_easy_4 = {"387964215", "549218736", "162375984",
                               "426893571", "918547623", "753126849",
                               "635781492", "274639158", "891452367"};

const board init_easy_5 = {"6    9  4", " 895   16", "5   6 3 9",
                           "831   7 5", " 2     6 ", "9 7   842",
                           "2 6 1   8", "37   692 ", "1  3    7"};

const board solution_easy_5 = {"613279584", "789543216", "542861379",
                               "831624795", "425798163", "967135842",
                               "256917438", "378456921", "194382657"};

const board init_medium_1 = {"5 72   9 ", "  6 3 7 1", "4      6 ",
                             "1  49   7", "   5 8   ", "8   27  5",
                             " 7      9", "2 9 8 6  ", " 4   93 8"};

const board solution_medium_1 = {"517264893", "926835741", "483971562",
                                 "135496287", "792518436", "864327915",
                                 "378642159", "259183674", "641759328"};

const board init_medium_2 = {"2     69 ", " 5   3   ", "17   94 5",
                             "  3 25 18", "    4    ", "72 38 5  ",
                             "5 26   41", "   5   7 ", " 67     3"};

const board solution_medium_2 = {"234158697", "956473182", "178269435",
                                 "643925718", "815746329", "729381564",
                                 "592637841", "381594276", "467812953"};

const board init_medium_3 = {"15 2 9  4", " 4   6   ", "    4  63",
                             " 7    8 6", "6       5", "2 8    1 ",
                             "46  8    ", "   6   7 ", "8  5 1 49"};

const board solution_medium_3 = {"156239784", "743856921", "982147563",
                                 "375412896", "614978235", "298365417",
                                 "469783152", "521694378", "837521649"};

const board init_medium_4 = {"34  6 2 9", " 2 31    ", "  4   1  ", "    25 4 ",
                             "         ", "9   514 3", "4 3 7  68"};

const board solution_medium_4 = {"347168259", "258497316", "169532784",
                                 "726314895", "594786132", "831925647",
                                 "675843921", "982651473", "413279568"};

const board init_medium_5 = {" 26 3   8", "9  6  1  ", "    19 4 ",
                             "  73 2   ", "  4 7 8  ", "   8 67  ",
                             " 5 72    ", "  9  5  4", "4   6 21 "};

const board solution_medium_5 = {"126437598", "943658127", "785219346",
                                 "867392451", "394571862", "512846739",
                                 "651724983", "239185674", "478963215"};

const board init_hard_1 = {"  65    8", " 95    2 ", "7  9  3  ",
                           "    4 27 ", "   873   ", " 79 5    ",
                           "  2  8  9", " 5    81 ", "3    54  "};

const board solution_hard_1 = {"136524798", "895367124", "724981356",
                               "583649271", "261873945", "479152683",
                               "642718539", "957436812", "318295467"};

const board init_hard_2 = {" 91 7    ", "2 3    5 ", "   4 29 7",
                           "  28 6  9", "         ", "9  1 46  ",
                           "1 52 7   ", " 8    5 1", "    1 76 "};

const board solution_hard_2 = {"491675238", "273981456", "856432917",
                               "712856349", "564793182", "938124675",
                               "145267893", "687349521", "329518764"};

const board init_hard_3 = {"  278   3", "     98 1", "4    3 7 ",
                           "9 5  8   ", "    7    ", "   5  4 8",
                           " 6 4    7", "3 98     ", "8   316  "};

const board solution_hard_3 = {"192784563", "537629841", "486153972",
                               "915348726", "648972135", "723516498",
                               "261495387", "359867214", "874231659"};

const board init_hard_4 = {" 873 4   ", " 3 5   4 ", "        7",
                           "     245 ", " 96 1 83 ", " 258     ",
                           "8        ", " 5   7 1 ", "   2 176 "};

const board solution_hard_4 = {"187364295", "239578641", "564129387",
                               "718932456", "496715832", "325846179",
                               "871693524", "652487913", "943251768"};

const board init_hard_5 = {"  13 2   ", "  3  7 45", "  7     9",
                           "  65   7 ", "2       1", " 9   14  ",
                           "5     9  ", "61 2  8  ", "   9 85  "};

const board solution_hard_5 = {"451392786", "923867145", "867154329",
                               "136549278", "245783691", "798621453",
                               "582436917", "619275834", "374918562"};

const board *const easy_board_init[NUM_BOARDS] = {
    &init_easy_1, &init_easy_2, &init_easy_3, &init_easy_4, &init_easy_5};
const board *const easy_board_solution[NUM_BOARDS] = {
    &solution_easy_1, &solution_easy_2, &solution_easy_3, &solution_easy_4,
    &solution_easy_5};
const board *const medium_board_init[NUM_BOARDS] = {
    &init_medium_1, &init_medium_2, &init_medium_3, &init_medium_4,
    &init_medium_5};
const board *const medium_board_solution[NUM_BOARDS] = {
    &solution_medium_1, &solution_medium_2, &solution_medium_3,
    &solution_medium_4, &solution_medium_5};
const board *const hard_board_init[NUM_BOARDS] = {
    &init_hard_1, &init_hard_2, &init_hard_3, &init_hard_4, &init_hard_5};
const board *const hard_board_solution[NUM_BOARDS] = {
    &solution_hard_1, &solution_hard_2, &solution_hard_3, &solution_hard_4,
    &solution_hard_5};

void update_board(var_game_state *var) {
  var->player_board[var->p_move.row][var->p_move.col] = var->p_move.num;
}

int check_fill(var_game_state *var) {
  if (var->player_board[var->p_move.row][var->p_move.col] != ' ') {
    return 1;
  }
  return 0;
}

int move_correct(var_game_state *var, const_game_state *consts) {
  if (consts->solution_board[var->p_move.row][var->p_move.col] ==
      var->p_move.num) {
    return 0;
  }
  return 1;
}

// TO DO Fix
int board_complete(var_game_state *var) {
  for (int i = 0; i < BOARD_DIM; i++) {
    for (int j = 0; j < BOARD_DIM; j++) {
      if (var->player_board[i][j] == ' ') {
        return 1;
      }
    }
  }
  return 0;
}

int check_player_board(var_game_state *var, const_game_state *consts) {
  for (int i = 0; i < BOARD_DIM; i++) {
    for (int j = 0; j < BOARD_DIM; j++) {
      if (var->player_board[i][j] != consts->solution_board[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

/**
 * Verify that every row in the board only has one instance of the numbers 1-9.
 *
 * Given the struct object containing the solution boards and the index of the
 * row of the board to check, this function uses a loop to first compare each
 * character of the row to a string containing all possible values to verify
 * that the right input was given. Then, it converts the value into an integer,
 * and inputs the value into the corresponding index in a string named check.
 * Essentially when the loop is finished iterating through the row, it should
 * look identical to the following string: "123456789".
 *
 * @return An integer representing the index of the strings when compared. If
 * the row is correct, it returns the number 0.
 *
 */
static int check_row(const_game_state *consts, int row) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++) {
    if (strchr("123456789", consts->solution_board[row][i]) != NULL) {
      int index = consts->solution_board[row][i] - '0';
      check[index - 1] = consts->solution_board[row][i];
    }
  }
  return strcmp("123456789", check);
}

/**
 * Verify that every column in the board only has one instance of the numbers
 * 1-9.
 *
 * Given the struct object containing the solutions boards and the index of the
 * column of the board to check, this function uses a loop to first compare each
 * character of the column to a string containing all possible values to verify
 * that the right input was given. Then, it converts the value into an integer,
 * and inputs the value into the corresponding index in a string named check.
 * Essentially when the loop is finished iterating through the column, it should
 * look identical to the following string: "123456789"
 *
 * @return An integer representing the index of the strings when compared. If
 * the column is correct, it returns the number 0.
 */
static int check_col(const_game_state *consts, int col) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = 0; i < BOARD_DIM; i++) {
    if (strchr("123456789", consts->solution_board[i][col]) != NULL) {
      int index = consts->solution_board[i][col] - '0';
      check[index - 1] = consts->solution_board[i][col];
    }
  }
  return strcmp("123456789", check);
}

/**
 * Verify that every 3x3 square on the board has only one instance of the
 * numbers 1-9.
 *
 * Given the struct object containing the solutions boards and the index of the
 * top left corner of the square to check, this function uses 2 loops to first
 * compare each character of the square to a string containing all possible
 * values to verify that the right input was given. Then, it converts the value
 * into an integer, and inputs the value into the corresponding index in a
 * string named check. Essentially when the loop is finished iterating through
 * the square, it should look identical to the following string: "123456789"
 *
 * @return An integer representing the index of the strings when compared. If
 * the square is correct, it returns the number 0.
 */
static int check_square(const_game_state *consts, int row, int col) {
  char check[BOARD_DIM + 1] = "         ";
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      if (strchr("123456789", consts->solution_board[i][j]) != NULL) {
        int index = consts->solution_board[i][j] - '0';
        check[index - 1] = consts->solution_board[i][j];
      }
    }
  }
  return strcmp("123456789", check);
}

int check_solution_board(const_game_state *consts) {
  // checks whether the solution board actually follows all of the rules
  // check rows and cols
  for (int i = 0; i < BOARD_DIM; i++) {
    if (check_row(consts, i) != 0 || check_col(consts, i) != 0) {
      return 1;
    }
  }
  // Check Squares
  for (int row = 0; row < BOARD_DIM - 2; row = row + 3) {
    for (int col = 0; col < BOARD_DIM - 2; col = col + 3) {
      if (check_square(consts, row, col) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

void setup_game(const_game_state *consts, var_game_state *var) {
  const board *solution = &solution_easy_1;
  const board *initial = &init_easy_1;
  int board_number =
      (rand() % NUM_BOARDS); // NOLINT(cert-msc30-c,
                             // cert-msc50-cpp,concurrency-mt-unsafe)
  switch (consts->level) {
  case 0:
    solution = &solution_demo;
    initial = &init_demo;
    break;
  case 1:
    solution = easy_board_solution[board_number];
    initial = easy_board_init[board_number];
    break;
  case 2:
    solution = medium_board_solution[board_number];
    initial = medium_board_init[board_number];
    break;
  case 3:
    solution = hard_board_solution[board_number];
    initial = hard_board_init[board_number];
    break;
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
