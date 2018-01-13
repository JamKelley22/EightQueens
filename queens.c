#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

/* Global Var Declaration */
const int BOARD_LENGTH = 8;
const char BLANK_SPACE = '-';
int QUEENS_PLACED = 0;
int SOLUTIONS_FOUND = 0;
const char ATTACK_SPACE = '*';
bool PRETTY_PRINT = false;
bool NUMBER_LINES = false;

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



void markAttacks(char board[BOARD_LENGTH][BOARD_LENGTH],int i, int j) {
	/* Mark Vertical */
	int tempI;
	for(tempI = 0; tempI < BOARD_LENGTH; tempI++) {
		if(board[tempI][j] == BLANK_SPACE)
			board[tempI][j] = ATTACK_SPACE;
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

void printSolution(char board[BOARD_LENGTH][BOARD_LENGTH]) {
	int i,j;
	if(NUMBER_LINES)
		printf("%d. ", SOLUTIONS_FOUND);	
	for(i = 0; i < BOARD_LENGTH; i++) {
		for(j = 0; j < BOARD_LENGTH; j++) {
			if(board[i][j] == 'Q') {
				printf("%c%d",'a' + j, i + 1);
			}			
		}

	}
	printf("\n");	
}

void printPrettySolution(char board[BOARD_LENGTH][BOARD_LENGTH]) {
	int i,j;
	for(i = 0; i < BOARD_LENGTH; i++) {
		printf("%d|",BOARD_LENGTH - i);
		for(j = 0; j < BOARD_LENGTH; j++) {
			printf("%c ",board[i][j]);
		}
		if(i == BOARD_LENGTH - 1) {
			char character = '_';
			int pos;
			
			printf("\n  ");
			for(pos = 0; pos < BOARD_LENGTH; pos++) {
				printf("%c ",character);
			}
			character = 'a';
			printf("\n  ");
			for(pos = 0; pos < BOARD_LENGTH; pos++) {
				printf("%c ",character);
				character++;
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool queens(char board[BOARD_LENGTH][BOARD_LENGTH], int j) {
	/* Base Case */
	if(j >= BOARD_LENGTH) {
		SOLUTIONS_FOUND++;
		if(PRETTY_PRINT)
			printPrettySolution(board); 
		else 
			printSolution(board);
	}
	
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

int main(int argc, char **argv) {
	/* 
	======Switches======
	Pretty Print Switch = -p
	Number Lines Switch = -n
	*/

	/* Get & Parse Args */
	bool validArgs = true;
	int opt;
	while((opt = getopt(argc,argv, "np")) != -1) {
		switch(opt) {
		case 'n':
			NUMBER_LINES = true;
			break;
		case 'p':		
			PRETTY_PRINT = true;
			break;
		default:
			printf("Usage: %s [-np]\n", argv[0]);
			return 1;
		}
	}
	
	/* Setup */
	char board[BOARD_LENGTH][BOARD_LENGTH];
	clearBoard(board);	
	
	queens(board,0);

	return 0;
}
