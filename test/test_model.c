#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/model.h"

// NOLINTBEGIN(*-magic-numbers)

// Create starting board for tests
var_game_state make_starting_board(void) {
  var_game_state test = {.player_board = {" 9 28   6", "62    1 8", "  7    3 ",
                                          "8 31  4  ", "    7 36 ", " 79      ",
                                          "1    49 2", "94    87 ",
                                          "     8   "},
                         .errors = 0};
  return test;
}

// Create complete board for tests
var_game_state make_complete_board(void) {
  var_game_state test = {.player_board = {"391285746", "625437198", "487916235",
                                          "863159427", "514872369", "279643581",
                                          "138764952", "946521873",
                                          "752398614"},
                         .errors = 0};
  return test;
}
const_game_state make_const_complete_board(void) {
  const_game_state solution_board = {
      .solution_board = {"391285746", "625437198", "487916235", "863159427",
                         "514872369", "279643581", "138764952", "946521873",
                         "752398614"}};
  return solution_board;
}

// update_board tests: 3 correct moves, 1 incorrect move, 2 overwriting moves
// Correct Move
//  Update [0][0] = 3

Test(update_board, correct_move_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 0, '3'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '3'));
}
// Update [9][9] = 4
Test(update_board, correct_move_2) {
  var_game_state test = make_starting_board();
  test.p_move = (move){9, 9, '4'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '4'));
}
// Update [5][3] = 6
Test(update_board, correct_move_3) {
  var_game_state test = make_starting_board();
  test.p_move = (move){5, 3, '6'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '6'));
}
// Wrong Move: value incorrect from board complete
// Update [0][2] with 4, should be 1
Test(update_board, wrong_move_overwrite_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 2, '4'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '4'));
}
// Wrong Move: overwrite a filled board with wrong number
// Overwrite [0][1] = 9 with 1
Test(update_board, wrong_move_overwrite_2) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 1, '1'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '1'));
}
// Wrong Move: overwrite a filled board with wrong number
// Overwrite [6][5] = 4 with 8
Test(update_board, wrong_move_overwrite_3) {
  var_game_state test = make_starting_board();
  test.p_move = (move){6, 5, '8'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '8'));
}

// check_fill: 2 filled case, 1 empty case
// Check a filled spot
Test(check_filled, filled_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 1, '2'};
  cr_assert(eq(int, check_fill(&test), 1));
}
Test(check_filled, filled_2) {
  var_game_state test = make_complete_board();
  test.p_move = (move){5, 8, '2'};
  cr_assert(eq(int, check_fill(&test), 1));
}
// Check a empty spot
Test(check_filled, empty_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 0, '3'};
  cr_assert(eq(int, check_fill(&test), 0));
}

// check_move
// Move correct
Test(move_correct, move_correct_1) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  test.p_move = (move){0, 0, '3'};
  cr_assert(eq(int, move_correct(&test, &answer), 0));
}
Test(move_correct, move_incorrect_1) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  test.p_move = (move){0, 0, 4};
  cr_assert(eq(int, move_correct(&test, &answer), 1));
}
// board_complete
// complete
Test(board_complete, complete_1) {
  var_game_state test = make_complete_board();
  cr_assert(eq(int, board_complete(&test), 0));
}
// incomplete starting board
Test(board_complete, incomplete_start) {
  var_game_state test = make_starting_board();
  cr_assert(eq(int, board_complete(&test), 1));
}
// incomplete complete board with last value empty
Test(board_complete, incomplete_1_less) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = ' ';
  cr_assert(eq(int, board_complete(&test), 1));
}
// check_player_board
// Correct
Test(check_player_board, correct_1) {
  var_game_state test = make_complete_board();
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 0));
}
// Incorrect: start board vs complete
Test(check_player_board, incorrect_start) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}
// Incorrect: complete board with 1 empty spot vs complete
Test(check_player_board, incorrect_missing) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = ' ';
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}
// Incorrect: complete board with 1 wrong number vs complete
Test(check_player_board, incorrect_1_number) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = '5';
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}

// check_solution_board
Test(check_solution_board, correct_1) {
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_solution_board(&answer), 0));
}

// check_solution_board easy 1
Test(check_solution_board, correct_easy_1) {
  const_game_state answer = {.solution_board = {
  "875921346", 
  "361754892", 
  "249863715",
  "584697123", 
  "713248659", 
  "926135487",
  "697412538", 
  "158379264", 
  "432586971"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board easy 2
Test(check_solution_board, correct_easy_2) {
  const_game_state answer = {.solution_board = {
  "264859317",
  "981734652",
  "753621849",
  "135297486",
  "892546731",
  "476318925", 
  "318975264", 
  "649182573",
  "527463198"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board easy 3
Test(check_solution_board, correct_easy_3) {
  const_game_state answer = {.solution_board = {
  "856917423",
  "213864597",
  "947235816",
  "185396742",
  "762148359",
  "394572681",
  "521683974",
  "439751268",
  "678429135"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board easy 4
Test(check_solution_board, correct_easy_4) {
  const_game_state answer = {.solution_board = {
  "387964215",
  "549218736",
  "162375984",
  "426893571",
  "918547623",
  "753126849",
  "635781492",
  "274639158",
  "891452367"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board easy 5
Test(check_solution_board, correct_easy_5) {
  const_game_state answer = {.solution_board = {
  "613279584",
  "789543216",
  "542861379",
  "831624795",
  "425798163",
  "967135842",
  "256917438",
  "378456921",
  "194382657"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board medium 1
Test(check_solution_board, correct_medium_1) {
  const_game_state answer = {.solution_board = {
  "517264893",
  "926835741",
  "483971562",
  "135496287",
  "792518436",
  "864327915", 
  "378642159", 
  "259183674",
  "641759328"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}

// check_solution_board medium 2
Test(check_solution_board, correct_medium_2) {
  const_game_state answer = {.solution_board = {
  "234158697",
  "956473182",
  "178269435",
  "643925718",
  "815746329",
  "729381564", 
  "592637841", 
  "381594276",
  "467812953"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board medium 3
Test(check_solution_board, correct_medium_3) {
  const_game_state answer = {.solution_board = {
  "156239784",
  "743856921",
  "982147563",
  "375412896",
  "614978235",
  "298365417",
  "469783152",
  "521694378",
  "837521649"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board medium 4
Test(check_solution_board, correct_medium_4) {
  const_game_state answer = {.solution_board = {
  "347168259",
  "258497316",
  "169532784",
  "726314895",
  "594786132",
  "831925647",
  "675843921",
  "982651473",
  "413279568"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board medium 5
Test(check_solution_board, correct_medium_5) {
  const_game_state answer = {.solution_board = {
  "126437598",
  "943658127",
  "785219346",
  "867392451",
  "394571862",
  "512846739",
  "651724983",
  "239185674",
  "478963215"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board hard 1
Test(check_solution_board, correct_hard_1) {
  const_game_state answer = {.solution_board = {
  "136524798",
  "895367124",
  "724981356",
  "583649271",
  "261873945",
  "479152683", 
  "642718539", 
  "957436812",
  "318295467"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}

// check_solution_board hard 2
Test(check_solution_board, correct_hard_2) {
  const_game_state answer = {.solution_board = {
  "491675238",
  "273981456",
  "856432917",
  "712856349",
  "564793182",
  "938124675", 
  "145267893", 
  "687349521",
  "329518764"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board hard 3
Test(check_solution_board, correct_hard_3) {
  const_game_state answer = {.solution_board = {
  "192784563",
  "537629841",
  "486153972",
  "915348726",
  "648972135",
  "723516498",
  "261495387",
  "359867214",
  "874231659"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board hard 4
Test(check_solution_board, correct_hard_4) {
  const_game_state answer = {.solution_board = {
  "187364295",
  "239578641",
  "564129387",
  "718932456",
  "496715832",
  "325846179",
  "871693524",
  "652487913",
  "943251768"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}
// check_solution_board hard 5
Test(check_solution_board, correct_hard_5) {
  const_game_state answer = {.solution_board = {
  "451392786",
  "923867145",
  "867154329",
  "136549278",
  "245783691",
  "798621453",
  "582436917",
  "619275834",
  "374918562"}};
  cr_assert(eq(int, check_solution_board(&answer), 0));
}

// incorrect_board
Test(check_solution_board, incorrect_1) {
  const_game_state answer = make_const_complete_board();
  answer.solution_board[8][8] = '5';
  cr_assert(eq(int, check_solution_board(&answer), 1));
}
Test(check_solution_board, incorrect_characters) {
  const_game_state answer = {
      .solution_board = {"abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi",
                         "abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi",
                         "abcdefghi"},
  };
  cr_assert(eq(int, check_solution_board(&answer), 1));
}
Test(check_solution_board, incorrect_range) {
  const_game_state answer = {
      .solution_board = {"390285746", "625437098", "487906235", "863059427",
                         "504872369", "279643581", "038764952", "946520873",
                         "752398604"}};
  cr_assert(eq(int, check_solution_board(&answer), 1));
}
// NOLINTEND(*-magic-numbers)
