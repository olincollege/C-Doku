/**
 * Print out the visualization of the board in the terminal.
 *
 * This allows the user to update the board, then print the updated view of the board.
 */

#include <stdio.h>
#include "view.h"

char player_board[9][9] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

void print_board_view(char board[BOARD_DIM][BOARD_DIM])
{
    // prints the board which is a character array
    printf("    1   2   3   4   5   6   7   8   9");
    printf("\n  =====================================\n");
    printf("1 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("2 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("3 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8]);
    printf("\n  =====================================\n");
    printf("4 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("5 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("6 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8]);
    printf("\n  =====================================\n");
    printf("7 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("8 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8]);
    printf("\n  |---:---:---|---:---:---|---:---:---|\n");
    printf("9 | %c : %c : %c | %c : %c : %c | %c : %c : %c |", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[7][6], board[7][7], board[7][8]);
    printf("\n  =====================================\n");
}

void reset_board(char board[BOARD_DIM][BOARD_DIM])
{
    // clear board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void print_result()
{

    printf("YOU WIN! :D");
    printf("YOU LOSE :(");
}
// int main(void)
// {
//     player_board[0][0] = '1';           // sets row 1, column 1 equal to 1
//     printf("%c\n", player_board[0][0]); // prints row 1, column 1
//     print_board_view(player_board);     // prints the board view
//     player_board[0][0] = '2';           // updates row 1, column 1 to be equal to 2
//     printf("%c\n", player_board[0][0]); // prints row 1, column 1
//     print_board_view(player_board);     // prints the updated board view
//     player_board[0][1] = '9';
//     print_board_view(player_board);
//     reset_board(player_board);
//     printf("%c\n", player_board[0][1]); // prints row 1, column 1
//     print_board_view(player_board);
// }
