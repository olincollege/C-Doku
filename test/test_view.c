#include "../src/model.h"
#include "../src/view.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

// Check that an empty board prints correctly.
Test(print_board, empty_board, .init = cr_redirect_stdout)
{
    var_game_state var;
    for (size_t i = 0; i < BOARD_DIM; i++)
    {
        for (size_t j = 0; j < BOARD_DIM; j++)
        {
            var.player_board[i][j] = ' ';
        }
    }
    print_board(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str("\n    1   2   3   4   5   6   7   8   9\n"
                            "  =====================================\n"
                            "1 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "2 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "3 |   :   :   |   :   :   |   :   :   |\n"
                            "  =====================================\n"
                            "4 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "5 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "6 |   :   :   |   :   :   |   :   :   |\n"
                            "  =====================================\n"
                            "7 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "8 |   :   :   |   :   :   |   :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "9 |   :   :   |   :   :   |   :   :   |\n"
                            "  =====================================\n");
}

// Check that a partially filled board prints correctly.
Test(print_board, partially_filled_board, .init = cr_redirect_stdout)
{
    var_game_state var;
    const char board[BOARD_DIM][BOARD_DIM] = {
        " 9 28   6", "62    1 8", "  7    3 ", "8 31  4  ", "    7 36 ",
        " 79      ", "1    49 2", "94    87 ", "     8   "};
    for (size_t i = 0; i < BOARD_DIM; i++)
    {
        for (size_t j = 0; j < BOARD_DIM; j++)
        {
            var.player_board[i][j] = board[i][j];
        }
    }
    print_board(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str("\n    1   2   3   4   5   6   7   8   9\n"
                            "  =====================================\n"
                            "1 |   : 9 :   | 2 : 8 :   |   :   : 6 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "2 | 6 : 2 :   |   :   :   | 1 :   : 8 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "3 |   :   : 7 |   :   :   |   : 3 :   |\n"
                            "  =====================================\n"
                            "4 | 8 :   : 3 | 1 :   :   | 4 :   :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "5 |   :   :   |   : 7 :   | 3 : 6 :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "6 |   : 7 : 9 |   :   :   |   :   :   |\n"
                            "  =====================================\n"
                            "7 | 1 :   :   |   :   : 4 | 9 :   : 2 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "8 | 9 : 4 :   |   :   :   | 8 : 7 :   |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "9 |   :   :   |   :   : 8 |   :   :   |\n"
                            "  =====================================\n");
}

// Check that a complete board prints correctly.
Test(print_board, filled_cells, .init = cr_redirect_stdout)
{
    var_game_state var;
    const char board[BOARD_DIM][BOARD_DIM] = {
        "391285746", "625437198", "487916235", "863159427", "514872369",
        "279643581", "138764952", "946521873", "752398614"};

    for (size_t i = 0; i < BOARD_DIM; i++)
    {
        for (size_t j = 0; j < BOARD_DIM; j++)
        {
            var.player_board[i][j] = board[i][j];
        }
    }
    print_board(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str("\n    1   2   3   4   5   6   7   8   9\n"
                            "  =====================================\n"
                            "1 | 3 : 9 : 1 | 2 : 8 : 5 | 7 : 4 : 6 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "2 | 6 : 2 : 5 | 4 : 3 : 7 | 1 : 9 : 8 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "3 | 4 : 8 : 7 | 9 : 1 : 6 | 2 : 3 : 5 |\n"
                            "  =====================================\n"
                            "4 | 8 : 6 : 3 | 1 : 5 : 9 | 4 : 2 : 7 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "5 | 5 : 1 : 4 | 8 : 7 : 2 | 3 : 6 : 9 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "6 | 2 : 7 : 9 | 6 : 4 : 3 | 5 : 8 : 1 |\n"
                            "  =====================================\n"
                            "7 | 1 : 3 : 8 | 7 : 6 : 4 | 9 : 5 : 2 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "8 | 9 : 4 : 6 | 5 : 2 : 1 | 8 : 7 : 3 |\n"
                            "  |---:---:---|---:---:---|---:---:---|\n"
                            "9 | 7 : 5 : 2 | 3 : 9 : 8 | 6 : 1 : 4 |\n"
                            "  =====================================\n");
}

// Check that the game result is a loss when the number of errors equals 3.
Test(print_result, game_loss, .init = cr_redirect_stdout)
{
    var_game_state var;
    var.errors = 3;
    print_result(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_expect(eq(int, print_result(&var), 1));
    cr_expect_stdout_eq_str("YOU LOSE :(\n");
}

// Check that the game result is a win when the number of errors is less than 3
// and the board is complete.
Test(print_result, game_win, .init = cr_redirect_stdout)
{
    var_game_state var = {.player_board = {"391285746", "625437198", "487916235",
                                           "863159427", "514872369", "279643581",
                                           "138764952", "946521873",
                                           "752398614"}};
    var.errors = 2;

    print_result(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_expect_stdout_eq_str("YOU WIN! :D\n");
    cr_expect(eq(int, print_result(&var), 1));
}

// Check that the game continues when the number of errors is less than 3
// and the board is incomplete.
Test(print_result, game_continue, .init = cr_redirect_stdout)
{
    var_game_state var = {.player_board = {" 9 28   6", "62    1 8", "  7    3 ",
                                           "8 31  4  ", "    7 36 ", " 79      ",
                                           "1    49 2", "94    87 ",
                                           "     8   "}};
    var.errors = 1;
    print_result(&var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert(eq(int, print_result(&var), 0));
}
