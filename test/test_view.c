#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/view.h"

// Check that an empty board prints correctly.
Test(reset_board, empty_board, .init = cr_redirect_stdout)
{
    char player_board[9][9] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    reset_board(player_board);
    print_board_view(player_board);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str(
        "\n    1   2   3   4   5   6   7   8   9"
        "\n  =====================================\n"
        "1 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "2 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "3 |   :   :   |   :   :   |   :   :   |"
        "\n  =====================================\n"
        "4 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "5 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "6 |   :   :   |   :   :   |   :   :   |"
        "\n  =====================================\n"
        "7 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "8 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "9 |   :   :   |   :   :   |   :   :   |"
        "\n  =====================================\n");
}
// Test that a cell prints correctly

Test(print_board_view, filled_cells, .init = cr_redirect_stdout)
{
    char player_board[9][9] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    int row_number1 = 2;
    int column_number1 = 4;
    int row_number2 = 6;
    int column_number2 = 8;

    // subtract 1 from integer variables to account for index starting at 0
    player_board[row_number1 - 1][column_number1 - 1] = '9';
    player_board[row_number2 - 1][column_number2 - 1] = '2';
    print_board_view(player_board);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str(
        "\n    1   2   3   4   5   6   7   8   9"
        "\n  =====================================\n"
        "1 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "2 |   :   : 9 |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "3 |   :   :   |   :   :   |   :   :   |"
        "\n  =====================================\n"
        "4 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "5 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "6 |   :   :   |   :   :   |   : 2 :   |"
        "\n  =====================================\n"
        "7 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "8 |   :   :   |   :   :   |   :   :   |"
        "\n  |---:---:---|---:---:---|---:---:---|\n"
        "9 |   :   :   |   :   :   |   :   :   |"
        "\n  =====================================\n");
}

Test(print_result, game_loss, .init = cr_redirect_stdout)
{
    var_game_state *var;
    var->errors == 3;
    print_result(var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str(
        "YOU LOSE :(");
    cr_assert(eq(int, print_result(var), 1));
}

Test(print_result, game_win, .init = cr_redirect_stdout)
{
    var_game_state *var = 2;
    board_complete(var) == 0;
    print_result(var);
    (void)fflush(stdout);
    (void)fclose(stdout);
    cr_assert_stdout_eq_str(
        "YOU WIN! :D");
    cr_assert(eq(int, print_result(var), 1));
}
