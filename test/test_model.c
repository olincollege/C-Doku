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

// A correct move should be added to the first spot (upper left corner) of the board.
Test(update_board, correct_move_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 0, '3'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '3'));
}

// A correct move should be added to the last spot (lower right corner) of the board.
Test(update_board, correct_move_2) {
  var_game_state test = make_starting_board();
  test.p_move = (move){9, 9, '4'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '4'));
}

// A correct move should be added to any spot in the middle of the board.
Test(update_board, correct_move_3) {
  var_game_state test = make_starting_board();
  test.p_move = (move){5, 3, '6'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '6'));
}

// A move should be added to the board even if it is wrong.
Test(update_board, wrong_move_overwrite_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 2, '4'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '4'));
}

// A move should be added to the board even if it overwrites another number.
Test(update_board, wrong_move_overwrite_2) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 1, '1'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '1'));
}

// A filled spot should report filled.
Test(check_filled, filled_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 1, '2'};
  cr_assert(eq(int, check_fill(&test), 1));
}

// An empty spot should report empty.
Test(check_filled, empty_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 0, '3'};
  cr_assert(eq(int, check_fill(&test), 0));
}

// A correct move should report correct.
Test(move_correct, move_correct_1) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  test.p_move = (move){0, 0, '3'};
  cr_assert(eq(int, move_correct(&test, &answer), 0));
}

// An incorrect move should report incorrect.
Test(move_correct, move_incorrect_1) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  test.p_move = (move){0, 0, 4};
  cr_assert(eq(int, move_correct(&test, &answer), 1));
}

// A complete board should report complete.
Test(board_complete, complete_1) {
  var_game_state test = make_complete_board();
  cr_assert(eq(int, board_complete(&test), 0));
}

// An intial board should report incomplete.
Test(board_complete, incomplete_start) {
  var_game_state test = make_starting_board();
  cr_assert(eq(int, board_complete(&test), 1));
}

// An almost complete board with one empty spot should report incomplete.
Test(board_complete, incomplete_1_less) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = ' ';
  cr_assert(eq(int, board_complete(&test), 1));
}

// A completely filled board should report correctly filled.
Test(check_player_board, correct_1) {
  var_game_state test = make_complete_board();
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 0));
}

// An initial board should report not correctly filled.
Test(check_player_board, incorrect_start) {
  var_game_state test = make_starting_board();
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}
// A board that's almost complete with one empty spot should report not correctly filled.
Test(check_player_board, incorrect_missing) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = ' ';
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}

// A board with one incorrect number should report not correctly filled.
Test(check_player_board, incorrect_1_number) {
  var_game_state test = make_complete_board();
  test.player_board[8][8] = '5';
  const_game_state answer = make_const_complete_board();
  cr_assert(eq(int, check_player_board(&test, &answer), 1));
}

// check whether the boards that we entered manually follow sudoku rules

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
// check_solution_board medium 1
Test(check_solution_board, correct_medium_1) {
  const_game_state answer = {.solution_board = {"517264893",
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
  const_game_state answer = {.solution_board = {"234158697",
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
// check_solution_board hard 1
Test(check_solution_board, correct_hard_1) {
  const_game_state answer = {.solution_board = {"136524798",
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
  const_game_state answer = {.solution_board = {"491675238",
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

// Solution board with one incorrect value should report incorrect.
Test(check_solution_board, incorrect_1) {
  const_game_state answer = make_const_complete_board();
  answer.solution_board[8][8] = '5';
  cr_assert(eq(int, check_solution_board(&answer), 1));
}

// Solution board with letters instead of numbers should report incorrect.
Test(check_solution_board, incorrect_characters) {
  const_game_state answer = {
      .solution_board = {"abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi",
                         "abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi",
                         "abcdefghi"},
  };
  cr_assert(eq(int, check_solution_board(&answer), 1));
}

// Solution board with numbers out of range (less than 1 or greater than 9) should report incorrect.
Test(check_solution_board, incorrect_range) {
  const_game_state answer = {
      .solution_board = {"390285746", "625437098", "487906235", "863059427",
                         "504872369", "279643581", "038764952", "946520873",
                         "752398604"}};
  cr_assert(eq(int, check_solution_board(&answer), 1));
}


// NOLINTEND(*-magic-numbers)
