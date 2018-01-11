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

int main(int argc, char *argv[]) {
	char board[BOARD_LENGTH][BOARD_LENGTH];
	clearBoard(board);	
	/*
	placeQueen(board,1,1);	
	placeQueen(board,2,4);
	placeQueen(board,0,7);
	queens(board,0,0);
	*/	
	placeQueen(board,0,0);
	placeQueen(board,1,1);
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

bool placeQueen(char board[BOARD_LENGTH][BOARD_LENGTH],int x, int y) {
	/* Check Boundries */
	if(x > BOARD_LENGTH - 1 || y > BOARD_LENGTH - 1)
		return false;
	if(x < 0 || y < 0)
		return false;

	/* Check current space for Queen */
	if(board[x][y] == 'Q')
		return false;

	/* Check Vertical for other Queens */	
	int tempY;
	for(tempY = 0; tempY < BOARD_LENGTH; tempY++) {
		if(board[x][tempY] == 'Q')
			return false;
	}

	/* Check Horizontal for other Queens */
	int tempX;
	for(tempX = 0; tempX < BOARD_LENGTH; tempX++) {
		if(board[tempX][y] == 'Q')
			return false;
	}
	
	printf("BEGIN DIAGS");
	/* Check Diagnals for other Queens */	
	tempX = x;tempY = y;
	while(tempX >= 0 && tempY >= 0) {
		if(board[tempX][tempY] == 'Q') {
			return false;
		}
		x--;y--;
	}	
	printf("Finish UL");
	
	tempX = x;tempY = y;
	while(tempX < BOARD_LENGTH && tempY < BOARD_LENGTH) {
		if(board[tempX][tempY] == 'Q') {
			return false;
		}
		x++;y++;
	}	
	printf("Finish LR");	

	/* Place Queen Sucessfully */
	board[x][y] = 'Q';
	QUEENS_PLACED++;
	printf("Queen Placed @ (%d,%d)\nTotal Queens Placed: %d\n",x,y,QUEENS_PLACED);
	return true;
}

bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int x, int y) {
	if(x == BOARD_LENGTH) {
		printSolution(board);
		return true;
	}
	int iY;
	bool placedQueen = false;
	for(iY = 0; iY < BOARD_LENGTH; iY++) {
		if(placeQueen(board,x,iY)) {
			queens(board,++x,0);
			return true;
		}
	}
	
}

void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]) {
	int x,y;
	for(x = BOARD_LENGTH - 1; x >= 0; x--) {
		for(y = 0;  y < BOARD_LENGTH; y++) {
			if(board[x][y] == 'Q') {
				int correctedY = BOARD_LENGTH - y;
				printf("%c%d",'a' + x, correctedY);
			}			
		}

	}
	printf("\n");	
}
