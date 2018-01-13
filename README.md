## Getting Started

1. Download project
2. Run `gcc -o queens queens.c`
3. run `./queens`

## Optional Switches

1. -n
  - Numbers lines that have solutions on them. Use this rather then piping to cat -n (that breaks -t switch)
2. -p
  - Pretty output. This prints solutions in a visually recognizable format similar to a chess board
3. -t
  - Displays the total time taken in calculating the solutions and printing them to the console
  
## Data Structures

The data sctucture in this program is a 2D Character Matrix which holds infromation about Queens that have been placed on the board. 
* '-' Represents a Blank Space
* 'Q' Represents a Queen

## Functions

*Clears Current Board by setting all spaces to BLANK_SPACE*
- void clearBoard(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Determines if a space on the board is attackable
@return true if space can be attacked, false otherwise*
- bool canBeAttacked(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Place a Queen on the board, no checks*
- void placeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Remove a Queen on the board, no checks*
- void removeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Print solution of current board configuration in required format*
- void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Prints out a visual representation of the 2D Character Matrix, like a chess board*
- void printPrettySolution(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Recursive method used to solve the 8 Queens Problem, scanns from left to right, calls itself when a space is found to place a Queen in the next collum
@return true if the next call of queens returns true or if all Queens have been placed, false otherwise*
- bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int j);

Full README in file README_EXT.md
