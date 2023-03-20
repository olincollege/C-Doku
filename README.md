# C-Doku

## Project Description

An interactive sudoku game implemented in C! C-Doku is a C implementation of
Sudoku in your very own terminal! The game prints a beautiful visualization of
an incomplete board for a player to solve based on the level they chose, and the
user can specify a number to input into a specific row and column. The
visualization will continue updating based on the user input. The player wins if
they complete the board before getting 3 errors!

We used [these board puzzles](https://www.rd.com/list/printable-sudoku-puzzles/)
to create our game.

## How to Play
The player starts with a partially filled 9x9 board of digit 1-9 to fill in. The player needs to fill each cell with a digit ranging from 1-9 with the following rules:
1. Every row must have one of each digit (1-9).
2. Every column must have one of each digit (1-9).
3. Every 3x3 square within the 9x9 must have one of each digit (1-9).

## How the Program Works
1. Choose difficulty: Player chooses a level (easy, medium hard).
2. Visualize board: Game displays an incomplete board for the player to complete.
3. Input move: Player inputs a row, column, and number to add to the board.
    * Move correct -> board updates accordingly
    * Move incorrect -> board does not update & error counter increases by 1
    * Move not valid -> no changes made & player will be prompted to input their move correctly.
4. Keep trying: The program prompts the player to keep filling the board until an end condition is met.
5. Win or lose: The game ends when an end condition is met.
    * Win -> board is completely filled with less than 3 errors
    * Lose -> player makes 3 errors before board is completely filled

## Dependencies

To play the game, download all the files from our
[C-Doku repository](https://github.com/olincollege/C-Doku). You can also
download it directly
[here](https://github.com/olincollege/C-Doku/archive/refs/heads/main.zip).

## Instructions

After downloading the files within the repository, make sure you are in the
C-Doku directory. Then, run these commands in the terminal to create a build
directory and compile the program:

```
$ mkdir build
$ cd build
$ make clean
$ make
```

Then run the following command to start the game:

```
$ ./src/run_sudoku
```

Have fun playing the game!
