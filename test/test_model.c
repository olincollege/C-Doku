#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/model.h"
#include "../src/constants.h"
//update_board tests: 3 correct moves, 1 incorrect move, 2 overwriting moves
//Correct Move
// Update [0][0] = 3
Test(update_board, correct_move_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {0,0,3} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 3));
}
// Update [9][9] = 4
Test(update_board, correct_move_2) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {9,9,4} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 4));
}
// Update [5][3] = 6
Test(update_board, correct_move_3) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {5,3,6} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 6));
}
//Wrong Move: value incorrect from board complete
//Update [0][2] with 4, should be 1
Test(update_board, wrong_move_overwrite_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {0,2,4} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 4));
}
//Wrong Move: overwrite a filled board with wrong number
//Overwrite [6][5] = 4 with 8 
Test(update_board, wrong_move_overwrite_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {0,0,1} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 1));
}
//Wrong Move: overwrite a filled board with wrong number
//Overwrite [6][5] = 4 with 8 
Test(update_board, wrong_move_overwrite_2) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
},
   0, {6,5,8} };
   update_board(test);
  cr_assert(eq(int, test.player_board[test.p_move.row][test.p_move.col], 8));
}
//check_fill
//Check a filled spot
Test(check_filled, filled_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
  },
   0, {0,1,2} };
  cr_assert(eq(int, check_fill(test), 1));
}
//Check a empty spot
Test(check_filled, empty_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
  },
   0, {0,0,3} };
  cr_assert(eq(int, check_fill(test), 0));
}
// check_move 

Test(move_correct, move_correct_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
  },
   0, {0,0,3} };
  cr_assert(eq(int, check_fill(test), 0));
}
Test(move_correct, move_incorrect_1) {
  var_game_state test = {{
    {0, 9, 0, 2, 8, 0, 0, 0, 6}, 
    {6, 2, 0, 0, 0, 0, 1, 0, 8},
    {0, 0, 7, 0, 0, 0, 0, 3, 0}, 
    {8, 0, 3, 1, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 7, 0, 3, 6, 0}, 
    {0, 7, 9, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 4, 9, 0, 2}, 
    {9, 4, 0, 0, 0, 0, 8, 7, 0},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
  },
   0, {0,0,4} };
  cr_assert(eq(int, check_fill(test), 1));
}
// board_complete
// complete
Test(board_complete, complete) {
  const char* empty_string = "";
  const char* substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}
//incomplete
Test(board_complete, empty_string_contains_no_substrings) {
  const char* empty_string = "";
  const char* substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}
Test(check_player_board, empty_string_contains_no_substrings) {
  const char* empty_string = "";
  const char* substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}

// check_solution_board
