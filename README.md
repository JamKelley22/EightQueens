Full README in README_EXT.md

## Switches

1. -n
  - Numbers lines with solutions.
2. -p
  - Pretty output
3. -t
  - Displays time taken
  
## Data Structures

Character Matrix stores Queens on board. 
* '-' Blank Space
* 'Q' Queen

## Functions

*Setts all spaces to BLANK_SPACE*
- void clearBoard(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Determines if space is attackable
@return true if space can be attacked, false otherwise*
- bool canBeAttacked(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Place Queen, no checks*
- void placeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Remove Queen, no checks*
- void removeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH], int i, int j);

*Print solution of current board in required format*
- void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Prints visual representation of the 2D Character Matrix*
- void printPrettySolution(char board[BOARD_LENGTH][BOARD_LENGTH]);

*Recursive method used to solve the 8 Queens Problem
@return true if all Queens could be placed, false otherwise*
- bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int j);

