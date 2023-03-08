#include <stdio.h>
#include <string.h>
#include "view.h"

void print_board(var_game_state *var)
{
    const char *row_divider = "  |---:---:---|---:---:---|---:---:---|";
    const char *outer_border = "  =====================================";
    printf("\n    1   2   3   4   5   6   7   8   9\n");

    for (int row = 0; row < BOARD_DIM; ++row)
    {
        if (row == 0 || (row % 3 == 0 && row >= 3))
        {
            printf("%s\n", outer_border);
        }
        else
        {
            printf("%s\n", row_divider);
        }
        printf("%c ", row + 1 + '0');
        for (int col = 0; col < BOARD_DIM; ++col)
        {
            if (col == 0 || (col % 3 == 0 && col >= 3))
            {

                printf("| %c ", var->player_board[row][col]);
            }
            else
            {
                printf(": %c ", var->player_board[row][col]);
            }
        }
        printf("|\n");
    }
    printf("%s\n", outer_border);
}

int print_result(var_game_state *var)
{
    if (var->errors == 3)
    {
        printf("YOU LOSE :(\n");
        return 1;
    }
    if (board_complete(var) == 0)
    {
        printf("YOU WIN! :D\n");
        return 1;
    }
    return 0;
}
