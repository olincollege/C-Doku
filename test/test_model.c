#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/boards.h"
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

// A correct move should be added to the first spot (upper left corner) of the
// board.
Test(update_board, correct_move_1) {
  var_game_state test = make_starting_board();
  test.p_move = (move){0, 0, '3'};
  update_board(&test);
  cr_assert(eq(chr, test.player_board[test.p_move.row][test.p_move.col], '3'));
}

// A correct move should be added to the last spot (lower right corner) of the
// board.
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
// A board that's almost complete with one empty spot should report not
// correctly filled.
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

// NOLINTEND(*-magic-numbers)
