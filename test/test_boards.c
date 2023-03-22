#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/boards.h"

// NOLINTBEGIN(*-magic-numbers)

// check whether the boards that we entered manually follow sudoku rules
// check_solution_board easy 1
Test(check_solution_board, correct_easy_1) {
  cr_assert(eq(int, check_solution_board(solution_easy_1), 0));
}
// check_solution_board easy 2
Test(check_solution_board, correct_easy_2) {
  cr_assert(eq(int, check_solution_board(solution_easy_2), 0));
}
// check_solution_board easy 3
Test(check_solution_board, correct_easy_3) {
  cr_assert(eq(int, check_solution_board(solution_easy_3), 0));
}
// check_solution_board easy 4
Test(check_solution_board, correct_easy_4) {
  cr_assert(eq(int, check_solution_board(solution_easy_4), 0));
}
// check_solution_board easy 5
Test(check_solution_board, correct_easy_5) {
  cr_assert(eq(int, check_solution_board(solution_easy_5), 0));
}
// check_solution_board medium 1
Test(check_solution_board, correct_medium_1) {
  cr_assert(eq(int, check_solution_board(solution_medium_1), 0));
}

// check_solution_board medium 2
Test(check_solution_board, correct_medium_2) {
  cr_assert(eq(int, check_solution_board(solution_medium_2), 0));
}
// check_solution_board medium 3
Test(check_solution_board, correct_medium_3) {
  cr_assert(eq(int, check_solution_board(solution_medium_3), 0));
}
// check_solution_board medium 4
Test(check_solution_board, correct_medium_4) {
  cr_assert(eq(int, check_solution_board(solution_medium_4), 0));
}
// check_solution_board medium 5
Test(check_solution_board, correct_medium_5) {
  cr_assert(eq(int, check_solution_board(solution_medium_5), 0));
}
// check_solution_board hard 1
Test(check_solution_board, correct_hard_1) {
  cr_assert(eq(int, check_solution_board(solution_hard_1), 0));
}

// check_solution_board hard 2
Test(check_solution_board, correct_hard_2) {
  cr_assert(eq(int, check_solution_board(solution_hard_2), 0));
}
// check_solution_board hard 3
Test(check_solution_board, correct_hard_3) {
  cr_assert(eq(int, check_solution_board(solution_hard_3), 0));
}
// check_solution_board hard 4
Test(check_solution_board, correct_hard_4) {
  cr_assert(eq(int, check_solution_board(solution_hard_4), 0));
}
// check_solution_board hard 5
Test(check_solution_board, correct_hard_5) {
  cr_assert(eq(int, check_solution_board(solution_hard_5), 0));
}

// Solution board with letters instead of numbers should report incorrect.
Test(check_solution_board, incorrect_characters) {
  const board answer = {"abcdefghi", "abcdefghi", "abcdefghi",
                        "abcdefghi", "abcdefghi", "abcdefghi",
                        "abcdefghi", "abcdefghi", "abcdefghi"};
  cr_assert(eq(int, check_solution_board(answer), 1));
}

// Solution board with numbers out of range (less than 1 or greater than 9)
// should report incorrect.
Test(check_solution_board, incorrect_range) {
  const board answer = {"390285746", "625437098", "487906235",
                        "863059427", "504872369", "279643581",
                        "038764952", "946520873", "752398604"};
  cr_assert(eq(int, check_solution_board(answer), 1));
}

// NOLINTEND(*-magic-numbers)
