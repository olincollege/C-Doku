#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>

#include "../src/controller.h"

Test(check_valid_input, valid_input_given) {
  char *input = "1,2,3";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}

Test(check_valid_input, same_nums) {
  char *input = "5,5,5";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}

Test(check_valid_input, wrong_input_given) {
  char *input = "0,10,1";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, all_commas) {
  char *input = ",,,,,,";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, spaces_not_commas) {
  char *input = "1 2 3";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(check_valid_input, all_nums) {
  char *input = "123456";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}

Test(get_player_input, correct_input) {
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,2,3");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(strcmp(input,"1,2,3")==0, "Input incorrectly");
}


// Test(get_player_input, correct_input) {
//   char input[100]; // Allocate a buffer for input
//   snprintf(input, sizeof(input), "1,2,3\n"); // Write input to buffer
//   FILE *stdin_backup = freopen("/dev/null", "r", stdin); // Redirect standard input to /dev/null
//   // cr_assert(get_player_input(input) == 0, "Input incorrectly"); // Call get_player_input() and check return value
//   cr_assert(strcmp(input, "1,2,3") == 0, "Input incorrect"); // Check if input matches expected value
//   freopen("/dev/tty", "r", stdin_backup); // Restore standard input
// }


Test(get_player_input, same_input) {
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,1,1");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(strcmp(input,"1,1,1")==0, "Input incorrectly");
}

Test(add_player_move, normal_input) {
  char *input = "1,2,3";
  var_game_state test1;
  add_player_move(input, &test1);
  cr_assert(test1.p_move.row == 0, "Wrong row input!");
  cr_assert(test1.p_move.col == 1, "Wrong column input!");
  cr_assert(test1.p_move.num == '3', "Wrong num input!");
}

Test(add_player_move, input_with_same_number) {
  char * input = "1,1,1";
  var_game_state test1;
  add_player_move(input, &test1);
  cr_expect(test1.p_move.row == 0, "Wrong row input! Expected %i, got %i", 0, test1.p_move.row);
  cr_expect(test1.p_move.col == 0, "Wrong column input! Expected %i, got %i", 0, test1.p_move.col);
  cr_expect(test1.p_move.num == '1', "Wrong num input! Expected %c, got %c", '1', test1.p_move.num);
}
