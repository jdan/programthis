//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>

#define MAX 7

void print(char *segment) {

	int i,j;

	for (i = 0; i < MAX; i++) {

		for(j =0; j < MAX; j++) {

			//top
			if (segment[0] != '0') {
			
				if (i == 0) {
					
					printf("#");
					continue;
				} 				
			}
			
			//top right
			if (segment[1] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j == 6) {
					
						printf("#");
						continue;
					}
				}
			}
			
			//topleft
			if (segment[2] != '0') {
			
				if (i > 0 && i < 3) {
				
					if (j == 0) {
					
						printf("#");
						continue;
					}
				}
			}

			//middle
			if (segment[3] != '0') {
				
				if (i == 3) {
				
					printf("#");
					continue;
				}
			}

			//bottom right
			if (segment[4] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == 6) {
					
						printf("#");
						continue;
					}
				}
			}

			//bottomleft
			if (segment[5] != '0') {
			
				if (i > 3 && i < 6) {
				
					if (j == 0) {
					
						printf("#");
						continue;
					}
				}
			}

			//bottom
			if (segment[6] != '0') {
			
				if (i == MAX - 1) {
				
					printf("#");
					continue;
				}
			}
		
			printf(" ");
		}

		printf("\n");
	}
}

int main() {

	char *numbers[] = {"1110111", "0100100","1101011","1101101","0111100",
			"1011101", "1011111","1100100","1111111","1111100"};

	int i;

	for (i = 0; i < 10; i++) {

		print(numbers[i]);
	}

	return 0;
}
