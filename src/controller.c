#include "boards.h"
#include "controller.h"
#include <stdio.h>


void convert_move(char* input) {
    // converts input into 0-8 index
    input = (int)input -1;

}
char* get_player_input() {
    char* input[6];                                         // is required for player to follow the correct format when typing, otherwise it will be rejected
    printf("Insert next move in row,col,num format: ");
    fgets(input, sizeof(input),stdin);                      // scans player input into char pointer
    return *input;
}   // **MAKE SURE UR RETURNING A POINTER TO SOMETHING**

int check_valid_input(char* input) {
    const char* valid_nums = "123456789";                   // verifying input is an int (in char form at this pt)

    for (int i = 0; i < strlen(input)-1; i++) {             // looping through player's input string
        if (i % 2 == 0) {       // if its even
            if (strstr(valid_nums, input[i]) == NULL) {     // if integers are actually correct 
                return 1;
            }
        } else {
            if (input[i] != ",") {                          // if the commas are correct
                return 1;
            }
        }
    }

    return 0;
}

void add_player_move(char* input, var_game_state var) {
    // int* move[3];

    for (int i = 0; i < strlen(input)-1; i++) {     // if not a comma, copy into final array
        if (input[i] != ",") {
            // move[i] = (int)input[i];                // casting input as integer before storing

            switch(i) {
                case 0: 
                    convert_move(&input[i]);
                    input[i] = var.p_move.row;
                    break;
                case 2:
                    convert_move(&input[i]);
                    input[i] = var.p_move.col;
                    break;
                case 4:
                    input[i] = var.p_move.num;
                    break;
            }
        }
    }
    
}



