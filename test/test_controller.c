#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

#include "../src/controller.h"


Test(check_valid_input, valid_input_given) {
  const char *input = "1,2,3";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}

Test(check_valid_input, same_nums) {
  const char *input = "5,5,5";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}

Test(check_valid_input, wrong_input_given) {
  const char *input = "0,10,1";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, all_commas) {
  const char *input = ",,,,,,";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, spaces_not_commas) {
  const char *input = "1 2 3";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, all_nums) {
  const char *input = "123456";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(get_player_input, correct_input) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,2,3\n");
  (void)fclose(stdin_file);
  const char* output = get_player_input();
  cr_assert(output == "1,2,3", "Input incorrectly");
}

Test(get_player_input, same_input) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,1,1\n");
  (void)fclose(stdin_file);
  const char* output = get_player_input();
  cr_assert(output == "1,1,1", "Input incorrectly");
}

Test(add_player_move, normal_input) {
  const char* input = "1,2,3";
  var_game_state test1;
  test1.player_board[9][9] = board_start;
  test1.errors = 0;
  add_player_move(input, &test1);
  cr_assert(test1.p_move.row == 1, "Wrong row input!");
  cr_assert(test1.p_move.col == 2, "Wrong column input!");
  cr_assert(test1.p_move.num == 3, "Wrong num input!");
}

Test(add_player_move, input_with_same_number) {
  const char* input = "1,1,1";
  var_game_state test1;
  test1.player_board[9][9] = board_start;
  test1.errors = 0;
  add_player_move(input, &test1);
  cr_assert(test1.p_move.row == 1, "Wrong row input!");
  cr_assert(test1.p_move.col == 1, "Wrong column input!");
  cr_assert(test1.p_move.num == 1, "Wrong num input!");
}
