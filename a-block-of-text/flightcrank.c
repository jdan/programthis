//Author: flightcrank
//Email: ocaumaxim@gmail.com

//note user must edit source file to chage line width/height

#include <stdio.h>

#define WIDTH  20
#define HEIGHT  5

int main() {

	char current;
	
	//int width = 20;
	//int height = 5;
	int w_count = 0;
	int h_count = 0;

	//open file to process
	FILE *fp;
	fp = fopen("pt.txt","r");

	if (fp == NULL) {
	
		printf("error opening file. does pt.txt exist ?");
		return 1; // exit porgram
	}

	do {
		current = fgetc(fp);
		
		if (current != ' ' && current != '"' && current != '\'') {
		
			printf("%c", current);
			w_count++;

			//max line width reached, reset
			if (w_count == WIDTH) {
				
				printf("\n");
				w_count = 0;
				h_count++;
			}

			//max block height reached, reset
			if(h_count == HEIGHT) {
			
				printf("\n\n");
				h_count = 0;
			}
		}

	} while(current != EOF);
	
	//close file
	fclose(fp);

	return 0;
}

