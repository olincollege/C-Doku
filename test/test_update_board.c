#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/model.h"
//edit 
Test(update_board, empty_string_contains_no_substrings) {
  const char* empty_string = "";
  const char* substr = "a";
  cr_assert(zero(int, count(empty_string, substr)));
}
