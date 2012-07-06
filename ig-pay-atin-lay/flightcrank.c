//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 101
#define MAX_WORD 21

int first_vowel(char *str) {
	
	int i;

	for(i = 0; i < strlen(str); i++) {
	
		switch (str[i]) {
		
			case 'a':
				
		//		printf("a found at position %d\n",i);
				return i;
			case 'e':
				
		//		printf("e found at position %d\n",i);
				return i;
			case 'i':
				
		//		printf("i found at position %d\n",i);
				return i;
			case 'o':
				
		//		printf("o found at position %d\n",i);
				return i;
			case 'u':
				
		//		printf("u found at position %d\n",i);
				return i;
		}
	}

	return 0;
}

int main() {

	//char current_word[MAX_WORD];
	char str[MAX_INPUT];
	char *p;

	puts("enter string");
	fgets(str, MAX_INPUT, stdin);

	p = strtok(str, " \n");
	
	while(p != NULL) {

		int len = strlen(p);
		int index = 0;
		int i,j;

		index = first_vowel(p);
		
		if (index > 0) {
		
			for (i = index; i < len; i++) {
			
				printf("%c", p[i]);
	
			}
	
			for (j = 0; j < index; j++) {
			
				printf("%c", p[j]);
			
			}
	
			printf("ay\n");

		} else {
		
			printf("%sway\n",p);	
		}

		p = strtok(NULL, " \n");

	}



	return 0;
}
