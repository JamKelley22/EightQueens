#include <stdio.h>
#include <stdbool.h>

/* Global Var Declaration */
const int BOARD_LENGTH = 8;
const char BLANK_SPACE = '-';
int QUEENS_PLACED = 0;
int QUEENS_TO_PLACE = 8;
int SOLUTIONS_FOUND = 0;
const int NUM_SOLUTIONS = 92;

/* Function Declaration */
void printBoard(char a[BOARD_LENGTH][BOARD_LENGTH]);
void clearBoard(char a[BOARD_LENGTH][BOARD_LENGTH]);
bool placeQueen(char board[BOARD_LENGTH][BOARD_LENGTH], int x, int y);
bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int x, int y);
void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]);
bool canBeAttacked(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y);
void placeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y);

int main(int argc, char *argv[]) {
	char board[BOARD_LENGTH][BOARD_LENGTH];
	clearBoard(board);	
	/*queens(board,0,0);*/
	placeQueen(board,0,0);
	placeQueen(board,0,7);
	placeQueen(board,1,4);
	printSolution(board);
	return 0;
}

void clearBoard(char a[BOARD_LENGTH][BOARD_LENGTH]) {
	int i,j;
	printf("===Clearing Current Board===\n");
	for(i = 0; i < BOARD_LENGTH; i++) {
		for(j = 0;  j < BOARD_LENGTH; j++) {
			a[i][j] = BLANK_SPACE;			
		}

	}
}

bool canBeAttacked(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y) {
	/* Check current space for Queen */
	if(board[y][x] == 'Q')
		return true;

	/* Check Vertical for other Queens */	
	int tempY;
	for(tempY = 0; tempY < BOARD_LENGTH; tempY++) {
		if(board[tempY][x] == 'Q')
			return true;
	}

	/* Check Horizontal for other Queens */
	int tempX;
	for(tempX = 0; tempX < BOARD_LENGTH; tempX++) {
		if(board[y][tempX] == 'Q')
			return true;
	}
	
	/* Check Diagnals for other Queens */	
	tempX = x;tempY = y;
	while(tempX >= 0 && tempY >= 0) {
		if(board[tempY][tempX] == 'Q') {
			return true;
		}
		tempX--;tempY--;
	}
	
	tempX = x;tempY = y;
	while(tempX < BOARD_LENGTH && tempY < BOARD_LENGTH) {
		if(board[tempY][tempX] == 'Q') {
			return true;
		}
		tempX++;tempY++;
	}

			
	tempX = x;tempY = y;
	while(tempX < BOARD_LENGTH && tempY >= 0) {
		if(board[tempY][tempX] == 'Q') {
			return true;
		}
		tempX++;tempY--;
	}	

		
	tempX = x;tempY = y;
	while(tempX >= 0 && tempY < BOARD_LENGTH) {
		if(board[tempY][tempX] == 'Q') {
			return true;
		}
		tempX--;tempY++;
	}		
	return false;
}
/*
For Manual Queen Placment, makes checks for boundries and attacks automatically
*/
bool placeQueen(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y) {
	/* Check Boundries */
	if(x > BOARD_LENGTH - 1 || y > BOARD_LENGTH - 1)
		return false;
	if(x < 0 || y < 0)
		return false;
	
	if(canBeAttacked(board,x,y))
		return false;

	/* Place Queen Sucessfully */
	board[y][x] = 'Q';
	QUEENS_PLACED++;
	printf("Queen Placed @ (%d,%d)\nTotal Queens Placed: %d\n",x,y,QUEENS_PLACED);
	return true;
}
/*
To be used for Recursive Queen Placment, assumes in bounds and checks for attacks were already made.
*/
void placeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y) {
	board[y][x] = 'Q';
	QUEENS_PLACED++;
	printf("Queen Placed @ (%d,%d)\nTotal Queens Placed: %d\n",x,y,QUEENS_PLACED);
}

bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int x, int y) {
	/* Base Case */
	if(x >= BOARD_LENGTH)
		return true;
 	
	int row;
	for(row = 0; row < BOARD_LENGTH; row++) {
		if(canBeAttacked(board,row,x)) {
			placeQueen(board,row,x);
			if(queens(board,row,x+1))
				return true;
			board[row][x] = BLANK_SPACE;
		}
	}
}

void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]) {
	int x,y;
	for(y = BOARD_LENGTH - 1; y >= 0; y--) {
		for(x = 0;  x < BOARD_LENGTH; x++) {
			if(board[y][x] == 'Q') {
				int correctedY = BOARD_LENGTH - y;
				printf("%c%d",'a' + x, correctedY);
			}			
		}

	}
	printf("\n");	
}
