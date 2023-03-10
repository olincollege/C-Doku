#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>

#include "../src/controller.h"
// feeds a valid input into check_valid_input.
Test(check_valid_input, valid_input_given) {
  char *input = "1,2,3\n";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}
// feeds a valid input with all same numbers into check_valid_input.
Test(check_valid_input, same_nums) {
  char *input = "5,5,5\n";
  const int ans = 0;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as wrong");
}
// feeds an incorrect input into check_valid_input.
Test(check_valid_input, wrong_input_given) {
  char *input = "0,10,1\n";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}
// feeds an incorrect input into check_valid_input.
Test(check_valid_input, all_commas) {
  char *input = ",,,,,,\n";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}
// feeds an incorrect input into check_valid_input.
Test(check_valid_input, spaces_not_commas) {
  char *input = "1 2 3\n";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}
// feeds an incorrect input into check_valid_input.
Test(check_valid_input, all_nums) {
  char *input = "123456\n";
  const int ans = 1;
  cr_assert(check_valid_input(input) == ans, "Incorrectly verified as correct");
}
// feeds a correct size input into get_player_input.
Test(get_player_input, correct_input) {
  puts("test 7");
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,2,3\n");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(eq(int, result, 0));
  cr_assert(strcmp(input, "1,2,3\n") == 0, "Input incorrectly");
}
// feeds a correct input of same nums into get_player_input.
Test(get_player_input, same_input) {
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,1,1\n");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(eq(int, result, 0));
  cr_assert(strcmp(input, "1,1,1\n") == 0, "Input incorrectly");
}
// feeds an incorrect input of wrong size into get_player_input.
Test(get_player_input, incorrect_size_input1) {
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1,1,1 \n");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(eq(int, result, 1));
}
// feeds an incorrect input of wrong size into get_player_input.
Test(get_player_input, incorrect_size_input2) {
  char input[BUFFER];
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "12345 \n");
  (void)fclose(stdin_file);
  int result = get_player_input(input);
  cr_assert(eq(int, result, 1));
}
// feeds a correct input into add_player_move.
Test(add_player_move, normal_input) {
  char *input = "1,2,3\n";
  var_game_state test1;
  add_player_move(input, &test1);
  cr_assert(test1.p_move.row == 0, "Wrong row input!");
  cr_assert(test1.p_move.col == 1, "Wrong column input!");
  cr_assert(test1.p_move.num == '3', "Wrong num input!");
}
// feeds a correct input of same nums into add_player_move.
Test(add_player_move, input_with_same_number) {
  char *input = "1,1,1\n";
  var_game_state test1;
  add_player_move(input, &test1);
  cr_expect(test1.p_move.row == 0, "Wrong row input! Expected %i, got %i", 0,
            test1.p_move.row);
  cr_expect(test1.p_move.col == 0, "Wrong column input! Expected %i, got %i", 0,
            test1.p_move.col);
  cr_expect(test1.p_move.num == '1', "Wrong num input! Expected %c, got %c",
            '1', test1.p_move.num);
}
// feeds a correct input into get_player_level.
Test(get_player_level, correct_level_input1) {
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1\n");
  (void)fclose(stdin_file);
  const_game_state test;
  int result = get_player_level(&test);
  cr_assert(test.level == 1, "Wrong level input!");
  cr_assert(eq(int, result, 0));
}
// feeds a correct input into get_player_level.
Test(get_player_level, correct_level_input2) {
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "2\n");
  (void)fclose(stdin_file);
  const_game_state test;
  int result = get_player_level(&test);
  cr_assert(test.level == 2, "Wrong level input!");
  cr_assert(eq(int, result, 0));
}
// feeds an incorrect input into get_player_level.
Test(get_player_level, wrong_level_input1) {
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "0\n");
  (void)fclose(stdin_file);
  const_game_state test;
  int result = get_player_level(&test);
  cr_assert(eq(int, result, 1));
}
// feeds an incorrect input into get_player_level.
Test(get_player_level, wrong_level_input2) {
  FILE *stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, " \n");
  (void)fclose(stdin_file);
  const_game_state test;
  int result = get_player_level(&test);
  cr_assert(eq(int, result, 1));
}
