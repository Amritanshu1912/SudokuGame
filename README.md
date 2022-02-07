# Sudoku Game
A C/C++ based project that lets you play sudoku by generating a random sudoku to solve. 

## To play :
Game can be started by compiling (with makefile) and running sudoku

1. Default action is to start interactive, 9x9 game

2. To fill in cell, enter the column number, row number, and value you want to enter (1 based). Separate with spaces, commas, or any other delimiter (besides an integer of course)

3. At any time, enter "Solve" to have the backtracer solve the game for you based on your current position.

4. If you've walked yoursel into an impossible configuration you will be prompted to first clear the board

5. Once solved, you will be asked if you want to play again

6. Run speed test / alternate game configurations using command flags below

## Note : 
Sometimes generating the puzzle takes longer than solving it because puzzles are always generated using a sort of reverse backtrace (ie. filling in diagonal using random permutation, solving puzzle, and then removing cells).
