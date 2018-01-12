#include <stdio.h>
#include <stdbool.h>

/* Global Var Declaration */
const int BOARD_LENGTH = 8;
const char BLANK_SPACE = '-';
int QUEENS_PLACED = 0;

void clearBoard(char a[BOARD_LENGTH][BOARD_LENGTH]) {
	int i,j;
	for(i = 0; i < BOARD_LENGTH; i++) {
		for(j = 0;  j < BOARD_LENGTH; j++) {
			a[i][j] = BLANK_SPACE;			
		}

	}
}

bool canBeAttacked(char board[BOARD_LENGTH][BOARD_LENGTH],int i, int j) {
	/* Check Vertical for other Queens */
	int tempI;
	for(tempI = 0; tempI < BOARD_LENGTH; tempI++) {
		if(board[tempI][j] == 'Q')
			return true;
	}

	/* Check Horizontal for other Queens */	
	int tempJ;
	for(tempJ = 0; tempJ < BOARD_LENGTH; tempJ++) {
		if(board[i][tempJ] == 'Q')
			return true;
	}
	
	/* Check Diagnals for other Queens */	
	tempI = i;tempJ = j;
	while(tempI < BOARD_LENGTH && tempJ < BOARD_LENGTH) {
		if(board[tempI][tempJ] == 'Q') {
			return true;
		}
		tempI++;tempJ++;
	}
	
	tempI = i;tempJ = j;
	while(tempI >= 0 && tempJ >= 0) {
		if(board[tempI][tempJ] == 'Q') {
			return true;
		}
		tempI--;tempJ--;
	}

	
	tempI = i;tempJ = j;
	while(tempI < BOARD_LENGTH && tempJ >= 0) {
		if(board[tempI][tempJ] == 'Q') {
			return true;
		}
		tempI++;tempJ--;
	}
	
	tempI = i;tempJ = j;
	while(tempI >= 0 && tempJ > BOARD_LENGTH) {
		if(board[tempI][tempJ] == 'Q') {
			return true;
		}
		tempI--;tempJ++;
	}

	return false;
}
/*
To be used for Recursive Queen Placment, assumes in bounds and checks for attacks were already made.
*/
void placeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH],int i, int j) {
	board[i][j] = 'Q';
}

void removeQueenR(char board[BOARD_LENGTH][BOARD_LENGTH],int i, int j) {
	board[i][j] = BLANK_SPACE;
}

bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int j) {
	/* Base Case */
	if(j >= BOARD_LENGTH)
		return true;
 	
	int row; /* The i value */
	for(row = 0; row < BOARD_LENGTH; row++) {
		if(!canBeAttacked(board,row,j)) {
			placeQueenR(board,row,j);
			if(queens(board,j+1))
				return true;
			removeQueenR(board,row,j);
		}
	}
	return false;
}

void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]) {
	printf("===Solution===\n");
	int i,j;
	for(i = 0; i < BOARD_LENGTH; i++) {
		for(j = 0; j < BOARD_LENGTH; j++) {
			if(board[i][j] == 'Q')
				printf("(%d,%d) | ", i,j);
		}
	}
	/*
	for(i = 0; i < BOARD_LENGTH; i++) {
		for(j = 0; j < BOARD_LENGTH; j++) {
			if(board[i][j] == 'Q') {
				printf("%c%d",'a' + j, i);
			}			
		}

	}
	*/
	printf("\n");	
}


/*
For Manual Queen Placment, makes checks for boundries and attacks automatically
*/
bool placeQueen(char board[BOARD_LENGTH][BOARD_LENGTH],int i, int j) {
	/* Check Boundries */
	if(i > BOARD_LENGTH - 1 || j > BOARD_LENGTH - 1)
		return false;
	if(i < 0 || j < 0)
		return false;
	
	if(canBeAttacked(board,i,j))
		return false;

	/* Place Queen Sucessfully */
	board[i][j] = 'Q';
	QUEENS_PLACED++;
	printf("Queen Placed @ (%d,%d)\nTotal Queens Placed: %d\n",i,j,QUEENS_PLACED);
	return true;
}

int main(int argc, char *argv[]) {
	char board[BOARD_LENGTH][BOARD_LENGTH];
	clearBoard(board);	
	queens(board,0);
	printSolution(board);
	return 0;
}
