#include "controller.h"
#include <stdio.h>
#include <string.h>

/**
 * Read the remaining inputs in input line and does nothing with it.
 *
 * In cases where the input is too long for stdin to read (or other varying
 * situations where input lines would fail to get saved in the destination
 * properly), the input line needs to be "flushed" and the remaining parts
 * of the input must be discarded for future reads. This function reads the
 * remainders into a local variable that does not get used, which essentially
 * gets rid of it.
 */
static void flush_input_line(void) {
  char null_buffer[BUFFER];
  do {
    (void)fgets(null_buffer, sizeof(null_buffer), stdin);
  } while (strchr(null_buffer, '\n') == NULL);
}

/**
 * Convert a given character into the index needed to edit the player board.
 *
 * This function converts a given character into an integer (assuming that
 * all inputs are numbers) and subtracts 1 from it. When a player inputs
 * their desired move, the index they provide for row and column is a number
 * from 1-9. However, when indexing into the game board array, we need a number
 * from 0-8, hence the subtraction. Additionally, the player input will be taken
 * in as a string since the input is coming from a keyboard. However, we need
 * row and column to be integers in order to index into the array. Therefore, we
 * convert it into an integer as well.
 *
 * @param input A pointer to a character representing the character to be
 * converted.
 * @return An integer version of the character integer it is passed.
 */
static int convert_to_int(const char input) { return (input - '0') - 1; }

int check_valid_input(char *input) {
  const char *valid_nums = "123456789";
  int size = (int)strlen(input);
  if (size != BUFFER - 1) { // checking size of string is 5
    return 1;
  }
  for (int i = 0; i < size - 1; i++) { // looping through player's input string
    if (i % 2 == 0) {                  // if its even
      if (strchr(valid_nums, input[i]) ==
          NULL) { // if integers are actually correct
        return 1;
      }
    } else {
      if (input[i] != ',') { // if the commas are correct
        return 1;
      }
    }
  }
  return 0;
}

int get_player_input(
    char *input) { // is required for player to follow the correct
  char temp[BUFFER];
  printf("Insert next move (format should be row,col,value): ");
  (void)fgets(temp, sizeof(temp),
              stdin); // scans player input into char pointer
  if (strchr(temp, '\n') == NULL) {
    flush_input_line();
    return 1;
  }
  // NOLINTBEGIN(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
  (void)strncpy(input, temp, BUFFER);
  // NOLINTEND(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
  return 0;
}

int add_player_move(char *input, var_game_state *var) {
  for (size_t i = 0; i < strlen(input);
       i++) { // if not a comma, write into struct
    if (input[i] != ',') {
      switch (i) {
      case 0:
        var->p_move.row = convert_to_int(input[i]);
        break;
      case 2:
        var->p_move.col = convert_to_int(input[i]);
        break;
      case 4:
        var->p_move.num = input[i];
        break;
      default:
        return 1;
      }
    }
  }
  return 0;
}

int get_player_level(const_game_state *consts) {
  printf("Select your level -> Demo (Enter 0), Easy (Enter 1), Medium (Enter "
         "2), Hard (Enter 3): ");
  char temp = (char)getchar();
  flush_input_line();
  if (temp == '0') {
    consts->level = 0;
  } else if (temp == '1') {
    consts->level = 1;
  } else if (temp == '2') {
    consts->level = 2;
  } else if (temp == '3') {
    consts->level = 3;
  } else {
    return 1;
  }
  return 0;
}
