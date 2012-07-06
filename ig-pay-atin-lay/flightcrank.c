//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 101

//find the first occurance of a vowel in a string and retun its index
int first_vowel(char *str) {
	
	int i;

	for(i = 0; i < strlen(str); i++) {
	
		switch (str[i]) {
		
			case 'a':
				
				return i;
			case 'e':
				
				return i;
			case 'i':
				
				return i;
			case 'o':
				
				return i;
			case 'u':
				
				return i;
		}
	}

	return 0;
}

int main() {

	char str[MAX_INPUT];
	char *p;

	puts("enter string");
	fgets(str, MAX_INPUT, stdin);
	
	//sreach the input and break it up into words
	p = strtok(str, " \n");
	
	//loop through all the words found
	while(p != NULL) {

		int len = strlen(p);
		int index = 0;
		int i,j;

		index = first_vowel(p);
		
		//words that dont start with a vowel
		if (index > 0) {
		
			//print chars from first vowel onwards
			for (i = index; i < len; i++) {
			
				printf("%c", p[i]);
	
			}
	
			//add the first char to the first vowel
			for (j = 0; j < index; j++) {
			
				printf("%c", p[j]);
			
			}
	
			printf("ay\n");
		
		//the word must start with a vowel
		} else {
		
			printf("%sway\n",p);	
		}
		
		//search next word in the input
		p = strtok(NULL, " \n");
	}

	return 0;
}
