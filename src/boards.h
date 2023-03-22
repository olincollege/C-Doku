#pragma once

#include <stdio.h>
#include <string.h>

enum {
  /** Dimensions of sudoku board.*/
  BOARD_DIM = 9,
  /** Maximum number of boards for each level.*/
  NUM_BOARDS = 5,
};

// The board represented by 9 by 9 array of characters.
typedef char board[BOARD_DIM][BOARD_DIM];

// Hard coded boards
static const board init_demo = {"87 921346", "361754 92", "249863715",
                                "5846971 3", "713248659", "926135487",
                                "697412538", " 58379264", "432586971"};

static const board solution_demo = {"875921346", "361754892", "249863715",
                                    "584697123", "713248659", "926135487",
                                    "697412538", "158379264", "432586971"};

static const board init_easy_1 = {" 7  2  46", " 6    89 ", "2  8  715",
                                  " 84 97   ", "71     59", "   13 48 ",
                                  "697  2  8", " 58    6 ", "43  8  7 "};

static const board solution_easy_1 = {"875921346", "361754892", "249863715",
                                      "584697123", "713248659", "926135487",
                                      "697412538", "158379264", "432586971"};

static const board init_easy_2 = {"  4 5    ", "9  7346  ", "  3 21 49",
                                  " 35 9 48 ", " 9     3 ", " 76 1 92 ",
                                  "31 97 2  ", "  9182  3", "    6 1  "};

static const board solution_easy_2 = {"264859317", "981734652", "753621849",
                                      "135297486", "892546731", "476318925",
                                      "318975264", "649182573", "527463198"};

static const board init_easy_3 = {"8 6 1    ", "  3 64 9 ", "9     816",
                                  " 8 396   ", "7 2 4 3 9", "   572 8 ",
                                  "521     4", " 3 75 2  ", "    2 1 5"};

static const board solution_easy_3 = {"856917423", "213864597", "947235816",
                                      "185396742", "762148359", "394572681",
                                      "521683974", "439751268", "678429135"};

static const board init_easy_4 = {"38 9  2 5", "     873 ", " 6 3  98 ",
                                  "     35 1", "91 5 7 23", "7 31     ",
                                  " 35  1 9 ", " 746     ", "8 1  2 67"};

static const board solution_easy_4 = {"387964215", "549218736", "162375984",
                                      "426893571", "918547623", "753126849",
                                      "635781492", "274639158", "891452367"};

static const board init_easy_5 = {"6    9  4", " 895   16", "5   6 3 9",
                                  "831   7 5", " 2     6 ", "9 7   842",
                                  "2 6 1   8", "37   692 ", "1  3    7"};

static const board solution_easy_5 = {"613279584", "789543216", "542861379",
                                      "831624795", "425798163", "967135842",
                                      "256917438", "378456921", "194382657"};

static const board init_medium_1 = {"5 72   9 ", "  6 3 7 1", "4      6 ",
                                    "1  49   7", "   5 8   ", "8   27  5",
                                    " 7      9", "2 9 8 6  ", " 4   93 8"};

static const board solution_medium_1 = {"517264893", "926835741", "483971562",
                                        "135496287", "792518436", "864327915",
                                        "378642159", "259183674", "641759328"};

static const board init_medium_2 = {"2     69 ", " 5   3   ", "17   94 5",
                                    "  3 25 18", "    4    ", "72 38 5  ",
                                    "5 26   41", "   5   7 ", " 67     3"};

static const board solution_medium_2 = {"234158697", "956473182", "178269435",
                                        "643925718", "815746329", "729381564",
                                        "592637841", "381594276", "467812953"};

static const board init_medium_3 = {"15 2 9  4", " 4   6   ", "    4  63",
                                    " 7    8 6", "6       5", "2 8    1 ",
                                    "46  8    ", "   6   7 ", "8  5 1 49"};

static const board solution_medium_3 = {"156239784", "743856921", "982147563",
                                        "375412896", "614978235", "298365417",
                                        "469783152", "521694378", "837521649"};

static const board init_medium_4 = {"34  6 2 9", " 2 31    ", "  4   1  ",
                                    "    25 4 ", "         ", "9   514 3",
                                    "4 3 7  68"};

static const board solution_medium_4 = {"347168259", "258497316", "169532784",
                                        "726314895", "594786132", "831925647",
                                        "675843921", "982651473", "413279568"};

static const board init_medium_5 = {" 26 3   8", "9  6  1  ", "    19 4 ",
                                    "  73 2   ", "  4 7 8  ", "   8 67  ",
                                    " 5 72    ", "  9  5  4", "4   6 21 "};

static const board solution_medium_5 = {"126437598", "943658127", "785219346",
                                        "867392451", "394571862", "512846739",
                                        "651724983", "239185674", "478963215"};

static const board init_hard_1 = {"  65    8", " 95    2 ", "7  9  3  ",
                                  "    4 27 ", "   873   ", " 79 5    ",
                                  "  2  8  9", " 5    81 ", "3    54  "};

static const board solution_hard_1 = {"136524798", "895367124", "724981356",
                                      "583649271", "261873945", "479152683",
                                      "642718539", "957436812", "318295467"};

static const board init_hard_2 = {" 91 7    ", "2 3    5 ", "   4 29 7",
                                  "  28 6  9", "         ", "9  1 46  ",
                                  "1 52 7   ", " 8    5 1", "    1 76 "};

static const board solution_hard_2 = {"491675238", "273981456", "856432917",
                                      "712856349", "564793182", "938124675",
                                      "145267893", "687349521", "329518764"};

static const board init_hard_3 = {"  278   3", "     98 1", "4    3 7 ",
                                  "9 5  8   ", "    7    ", "   5  4 8",
                                  " 6 4    7", "3 98     ", "8   316  "};

static const board solution_hard_3 = {"192784563", "537629841", "486153972",
                                      "915348726", "648972135", "723516498",
                                      "261495387", "359867214", "874231659"};

static const board init_hard_4 = {" 873 4   ", " 3 5   4 ", "        7",
                                  "     245 ", " 96 1 83 ", " 258     ",
                                  "8        ", " 5   7 1 ", "   2 176 "};

static const board solution_hard_4 = {"187364295", "239578641", "564129387",
                                      "718932456", "496715832", "325846179",
                                      "871693524", "652487913", "943251768"};

static const board init_hard_5 = {"  13 2   ", "  3  7 45", "  7     9",
                                  "  65   7 ", "2       1", " 9   14  ",
                                  "5     9  ", "61 2  8  ", "   9 85  "};

static const board solution_hard_5 = {"451392786", "923867145", "867154329",
                                      "136549278", "245783691", "798621453",
                                      "582436917", "619275834", "374918562"};

// Hard coded board pointers lists
static const board *const easy_board_init[NUM_BOARDS] = {
    &init_easy_1, &init_easy_2, &init_easy_3, &init_easy_4, &init_easy_5};
static const board *const easy_board_solution[NUM_BOARDS] = {
    &solution_easy_1, &solution_easy_2, &solution_easy_3, &solution_easy_4,
    &solution_easy_5};
static const board *const medium_board_init[NUM_BOARDS] = {
    &init_medium_1, &init_medium_2, &init_medium_3, &init_medium_4,
    &init_medium_5};
static const board *const medium_board_solution[NUM_BOARDS] = {
    &solution_medium_1, &solution_medium_2, &solution_medium_3,
    &solution_medium_4, &solution_medium_5};
static const board *const hard_board_init[NUM_BOARDS] = {
    &init_hard_1, &init_hard_2, &init_hard_3, &init_hard_4, &init_hard_5};
static const board *const hard_board_solution[NUM_BOARDS] = {
    &solution_hard_1, &solution_hard_2, &solution_hard_3, &solution_hard_4,
    &solution_hard_5};

/**
 * Check whether the solution board is correct.
 *
 * When called, check if the given board follows sudoku rules. The
 * logic this function checks is as follows:
 *  - Whether each space in each row contains unique numbers 1-9.
 *  - Whether each space in each column contains unique numbers 1-9.
 *  - Whether each space in a 3x3 square of the 9x9 board contains unique
 * numbers 1-9.
 *
 * Should the solution board be correctly filled, the function returns 0.
 * Otherwise, it returns 1.
 *
 * @param brd A board type.
 * @return An integer representing whether the solution board is correct.
 */
int check_solution_board(const board brd);
