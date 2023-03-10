# C-Doku

## Project Description

An interactive sudoku game implemented in C! C-Doku is a C implementation of
Sudoku in your very own terminal! The game prints a beautiful visualization of
an incomplete board for a player to solve based on the level they chose, and the
user can specify a number to input into a specific row and column. The
visualization will continue updating based on the user input. The player wins if
they complete the board before getting 3 errors!

We used
[these board puzzles](<[https://www.rd.com/wp-content/uploads/2020/12/Sudoku-Puzzle_01.pdf](https://www.rd.com/list/printable-sudoku-puzzles/)>)
to create our game.

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
