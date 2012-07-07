//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

#define MAX 7

//prints a single 7 segment LCD char to stdout then prints a new line!.
//note: to print horizontaly across the screen you would need to make a ling horizontal grid
//wide enough to fit the input sting
void display(char *segment) {

	int i,j;

	for (i = 0; i < MAX; i++) {

		for(j =0; j < MAX; j++) {

			//top segement
			if (segment[0] != '0') {
			
				if (i == 0) {
					
					printf("#");
					continue; 
				} 				
			}
			
			//top right segment
			if (segment[1] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j == 6) {
					
						printf("#");
						continue;
					}
				}
			}
			
			//top left segment
			if (segment[2] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j == 0) {
					
						printf("#");
						continue;
					}
				}
			}

			//middle segment
			if (segment[3] != '0') {
				
				if (i == 3) {
				
					printf("#");
					continue;
				}
			}

			//bottom right segment
			if (segment[4] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == 6) {
					
						printf("#");
						continue;
					}
				}
			}

			//bottomleft segment
			if (segment[5] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == 0) {
					
						printf("#");
						continue;
					}
				}
			}

			//bottom segment
			if (segment[6] != '0') {
			
				if (i == MAX - 1) {
				
					printf("#");
					continue;
				}
			}
			
			//prints a space in the void areas of the 7*7 grid
			printf(" ");
		}
		
		//prints a new line after each row in the grid
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
	char input[101];

	//no error checking ONLY input numbers or ascii char > 48 otherwise it will segfault
	puts("enter only numbers to display");
	fgets(input, 101, stdin);

	for (i = 0; i < strlen(input) - 1; i++) { // include the -1 other wize it will include the '\n' from fgets()
	
		//convert the string char eg '1' into the integer 1 to get the correct index in the numbers[] array
		// '0' starts a ascii 48 so subtract 48 to obtain the corrent int value
		int n = input[i] - 48;
		
		//print LCD number to stdout
		display(numbers[n]);
	}

	return 0;
}
