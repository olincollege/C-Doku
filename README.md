# C-Doku

## Project Description

C-Doku is a C implementation of Sudoku in your very own terminal! The game prints a minimalist visualization of an incomplete board for a player to solve based on the level they chose, and the user can specify a number to input into a specific row and column. The
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
[C-Doku repository](https://github.com/olincollege/C-Doku). You can also download it directly [here](https://github.com/olincollege/C-Doku/archive/refs/heads/main.zip). You should have the following files:
* src
   * CMakeLists.txt
   * controller.c
   * controller.h
   * main.c
   * model.c
   * model.h
   * view.c
   * view.h 
* test
   * CMakeLists.txt
   * test_controller.c
   * test_model.c
   * test_view.c
* CMakeLists.txt
* README.md 

This code only relies on C standard libraries, which means that you won't need to worry about importing any additional libraries.

## Instructions
To get started, please ensure that you are using a Unix environment to follow the instructions below.

Once you have downloaded the files from the repository, navigate to the C-Doku directory. From there, you can create a build directory and compile the program by running the following commands in your terminal:

```
$ mkdir build
$ cd build
$ cmake ..
$ make clean
$ make
```

Then run the following command to start the game:

```
$ ./src/run_sudoku
```

Have fun playing the game!
