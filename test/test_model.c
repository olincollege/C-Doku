#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/model.h"

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
      .solution_board = {
      "391285746", 
      "625437198", 
      "487916235", 
      "863159427",        
      "514872369", 
      "279643581", 
      "138764952", 
      "946521873",
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
// incorrect_board
Test(check_solution_board, incorrect_1) {
  const_game_state answer = make_const_complete_board();
  answer.solution_board[8][8] = '5';
  cr_assert(eq(int, check_solution_board(&answer), 1));
}
