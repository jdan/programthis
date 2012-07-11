//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>


//number of rows
#define NUM_ROW 7

//number of colums
//each number is 7 chars wide, * 10 means a MAX of 10 chars can be printed,
// and + another 10 for a 1 index thick space between printed chars
#define NUM_COL 7 * 10 + 10 			

char grid[NUM_ROW][NUM_COL];

//prints a single 7 segment LCD char to a 7 * 7 array segemnt.
void display(char *segment, int col_index) {

	int i;
	int j = col_index;
	int col_max = col_index + 7;

	for (i = 0; i < NUM_ROW; i++) {

		for(j = col_index; j < col_max; j++) {

			//top segement
			if (segment[0] != '0') {
			
				if (i == 0) {
					
					grid[i][j] = 'X';
					continue; 
				} 				
			}
			
			//top right segment
			if (segment[1] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j ==  col_index + 6) {
					
						grid[i][j] = 'X';
						continue;
					}
				}
			}
			
			//top left segment
			if (segment[2] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j == col_index) {
					
						grid[i][j] = 'X';
						continue;
					}
				}
			}

			//middle segment
			if (segment[3] != '0') {
				
				if (i == 3) {
				
					grid[i][j] = 'X';
					continue;
				}
			}

			//bottom right segment
			if (segment[4] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == col_index + 6) {
					
						grid[i][j] = 'X';
						continue;
					}
				}
			}

			//bottomleft segment
			if (segment[5] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == col_index) {
					
						grid[i][j] = 'X';
						continue;
					}
				}
			}

			//bottom segment
			if (segment[6] != '0') {
			
				if (i == NUM_ROW - 1) {
				
					grid[i][j] = 'X';
					continue;
				}
			}
			
			//prints a space in the void areas of the 7*7 grid
			grid[i][j] = ' ';
		}
	}
}

//simply prints each char in the array to stdout
void print_lcd() {
	
	int i,j;

	for (i = 0; i < NUM_ROW; i++) {
		
		for(j = 0; j < NUM_COL; j++) {
			
			
			if (grid[i][j] == 0) {
			
				printf(" ");
			
			} else {
			
				printf("%c", grid[i][j]);
			}
		}
	
		printf("\n");
	}
}

int main() {

	//each index represents number 0 through to 9
	//each 1 represents a segment to draw 
	//each 0 represents a segment not to draw
	char *numbers[] = {"1110111", "0100100","1101011","1101101","0111100",
			"1011101", "1011111","1100100","1111111","1111100"};

	int i;
	int col = 0;
	char input[12];

	//no error checking ONLY input numbers or ascii char > 48 otherwise it will segfault
	puts("enter only numbers to display");
	fgets(input, 12, stdin);

	for (i = 0; i < strlen(input) - 1; i++) { // include the -1 other wize it will include the '\n' from fgets()
	
		//convert the string char eg '1' into the integer 1 to get the correct index in the numbers[] array
		// '0' starts a ascii 48 so subtract 48 to obtain the corrent int value
		int n = input[i] - 48;
		
		//print LCD number to stdout
		display(numbers[n],col);

		col = col + NUM_ROW + 1;
	}

	print_lcd();
	
	return 0;
}
