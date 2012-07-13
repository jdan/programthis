//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID 25
#define MAX 100

//create grid
char word_grid[GRID][GRID];

void print_grid() {

	int i,j;

	for(i = 0; i < GRID; i++){
		
		for(j = 0; j < GRID; j++) {
		
			printf("%c ",word_grid[i][j]);
		}	
	
		printf("\n");
	}
}

void fill_grid() {

	int i,j;

	for(i = 0; i < GRID; i++){
		
		for(j = 0; j < GRID; j++) {
			
			if (word_grid[i][j] == ' ') {
				
				word_grid[i][j] = rand() % 26 + 97;
			}
		}	
	
	}
}

int place_word_h(int x, int y, char word[], int len) {

	int i;
	int count = 0;

	//loop through each place in the word_grid
	//and place each char of the word in one space
	for (i = x; i < GRID; i++) {
		
		word_grid[y][i] = word[count];
		count++;
		
		//exit function with success
		if (count > len) {
			return 0;
		}
	}
	

	return 1;
}

int place_word_v(int x, int y, char word[], int len) {

	int i;
	int count = 0;

	//loop through each place in the word_grid
	//and place each char of the word in one space
	for (i = y; i < GRID; i++) {
		
		word_grid[i][x] = word[count];
		count++;
		
		//exit function with success
		if (count > len) {
		
			return 0;
		}
	}

	return 1;
}

//see if word will fit properly in the grid vertically
int word_fit_v(int x, int y, char word[], int len) {

	int i;
	int count = 0;
	
	for (i = y; i < GRID; i++) {

		//loop through each place in the word_grid vertically
		if (word_grid[i][x] == ' ' || word_grid[i][x] == word[count]) {
			
			if (count == len) {
			
				return 0;
	
			} else {
			
				count++;
			}
	
		//cant place word there no empty space
		//or incompatible letter already in that space
		} else {
	
			return 1;
		}
	}
	

	return 1;
}
			
//see if word will fit properly in the grid horizontally
int word_fit_h(int x, int y, char word[], int len) {

	int i;
	int count = 0;

	//loop through each place in the word_grid horizontally	
	for (i = x; i < GRID; i++) {
			
		//if the space in the grid is empty
		//or
		//if it has the same letter already in it.
		if(word_grid[y][i] == ' ' || word_grid[y][i] == word[count]) {
			
			if (count == len) {
				
				return 0;

			} else {
			
				count++;
			}
		//cant place word there no empty space
		//or incompatible letter already in that space
		} else {
		
			return 1;
		}
	}
	

	return 1;
}

int main() {

	int i,j;
	char line[MAX];

	//populate grid
	for(i = 0; i < GRID; i++){
		
		for(j = 0; j < GRID; j++) {
		
			word_grid[i][j] = ' ';
		}	
	}

	//open file to process
	FILE *fp;
	fp = fopen("words.txt","r");

	if (fp == NULL) {
	
		printf("error opening file. does pt.txt exist ?");
		return 1; // exit program
	}

	//loop throughout each line in the file.
	while (fgets(line, MAX - 1, fp) != NULL) {

		int len;
		int rx;
		int ry;
		int r;

		len = strlen(line);
		
		//strlen includes the null byte
		//we only need exact letters of out word
		if (line[len - 1] == '\n') {
			
			line[len -1] = 0; //replace '\n' with null for better printing to stdout
			len -= 2;//compensate for original nullbyte and '\n'

		} else {
			
			len--;
		}
			
		//attempt to randomly place word in the grid.
		while (1) {
		
			r = random() % 2;
			rx = rand() % GRID;
			ry = rand() % GRID;

			//horizontal
			if (r == 0) {	
			
				//will fit the grid left to right
				if(len < GRID - rx) {
				
					if (word_fit_h(rx,ry,line,len) == 0) {
						
						place_word_h(rx,ry,line,len);
						break;
					}
				}

			//vertical
			} else {
			
				//will fit in grid top down
				if (len + ry < GRID) {
				
					if (word_fit_v(rx, ry, line, len) == 0) {
						
						place_word_v(rx,ry,line,len);
						break;
					}
				}
			}
		}
		
		printf("%s\n",line);
	}
	
	//close file
	fclose(fp);

	print_grid();//print out grid before the junk letters are printed
	printf("\n");
	fill_grid();
	printf("\n");
	print_grid();

	return 0;
}
