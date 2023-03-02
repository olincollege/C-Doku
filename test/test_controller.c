#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/controller.h"
// edit
Test(add_player_move, empty_string_contains_no_substrings) {
  const char *empty_string = "";
  const char *substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}

// edit
Test(check_valid_input, empty_string_contains_no_substrings) {
  const char *empty_string = "";
  const char *substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/controller.h"
// edit
Test(get_player_input, empty_string_contains_no_substrings) {
  const char *empty_string = "";
  const char *substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}

// edit
Test(check_valid_input, empty_string_contains_no_substrings) {
  const char *empty_string = "";
  const char *substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}
