//Author: flightcrank
//Email: ocaumaxim@gmail.com


//NOTE: just prints to stdout, use redirection operator '>' to output to a new file

#include <stdio.h> 
#include <string.h> 

#define MAX 101

int main () {

	//line buffer
	char line[MAX];

	//open file to process
	FILE *fp;
	fp = fopen("input.txt","r");

	if (fp == NULL) {
	
		printf("error opening file. does pt.txt exist ?");
		return 1; // exit porgram
	}
	
	//loop throught each line in the file.
	while (fgets(line, MAX - 1, fp) != NULL) {

		int i;

		//search string in reverse
		for (i = strlen(line); i >= 0; i--) {
		
			//fgets seems to add a '\n' if there isnt one.
			//so the last line will contain a '\n' aswell
			if (line[i] == '\n') {
			
				//if whitespace is found, replace with the newline
				//and end string with a new null byte
				if (line[i - 1] == ' ' || line[i - 1] == '\t') {
				
					line[i - 1] = '\n';
					line[i] = 0;
				}
			}	
		}
		
		//print out line (or write/append to a file)
		printf("%s", line);
	}

	//close file
	fclose(fp);	

	return 0;
}
