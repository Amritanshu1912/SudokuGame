# Sudoku Game
A C/C++ based project that lets you play sudoku by generating a random sudoku to solve. 

## To play :
Game can be started by compiling and running in C++ ide and game will start in terminal window.

1. Default action is to generate an interactive, 9x9 game.

2. To fill in cell, enter the column number(1-9), row number(1-9), and value(1-9) you want to enter. Separate with spaces or commas.

3. At any time, enter "Solve" / "solve" to have the backtracking algorithm, solve the game for you.

4. If you've walked yoursel into an impossible configuration you will be prompted to first clear the board.

5. Once solved, you will be asked if you want to play again (enter y/n).

## Note : 
Sometimes generating the puzzle takes longer than solving it because puzzles are always generated using a sort of reverse backtrace (ie. filling in diagonal using random permutation, solving puzzle, and then removing cells).
