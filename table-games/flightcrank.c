//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

#define MAX 101

int max_word_length(char *str, char delim) {

	size_t num = strlen(str);
	int i;
	int max_count = 0;
	int count = 0;

	for (i = 0; i < num; i++) {
		
		if (str[i] == delim || str[i] == '\n') {
		
			if (count > max_count) {
			
				max_count = count;
				count = 0; //reset count
				continue; //skip delim char
			}

			//if the biggest word is in the middle if a list
			//the above if statement wont be met, so we must reset the count here too
			count = 0; //reset count
		}
	
		count++;
	}

	return max_count;
}

void print_table(char *title, char *str, char delim) {

	unsigned int list_num = strlen(str);
	unsigned int title_num = strlen(title);
	int longest_word = max_word_length(str, ' ');
	int max = 0; 	
	int count = 0;
	int i;

	//replace the newline that fgets records with a null byte
	title[title_num -1] = 0;
	//update the title_num to refelct the above change
	title_num--;

	if (title_num < longest_word) {
		
		max = longest_word;
	
	} else {
	
		max = title_num;	
	}

	printf("length of biggest word in list %d\n",max);

	//heading top
	printf("+");

	for (i = 0; i < max + 2; i++) {// the 2 compinstes for the spaces added "| " and " |"
		
		printf("-");
	}

	puts("+");

	//heading title
	printf("| %s",title);

	for (i = title_num; i < max; i++) { 
						
		printf(" ");
	}

	puts(" |");
	//heading bottom
	printf("+");

	for (i = 0; i < max + 2; i++) {
		
		printf("-");
	}

	puts("+");

	//data
	printf("| ");

	//loops theough all chars in the enterd string
	for (i = 0; i < list_num; i++) {

		//if we get to the delim char or the end of the string print out a newline
		if (str[i] == delim || str[i] == '\n') {
			
			//the current word will test test testing yeah ha grandmahave the count var at its max value
			//by this point because the delimiter has been reached
			//figuer out the number of spaces to print to have the 
			//right side line mach up to the longest word in the string
			if (count < max) { 
				
				int diff = max - count;
				int j;
				
				for(j = 0; j < diff; j++) {
					
					printf(" ");
				}
			}
			
			//now we can print the line and a newline char, and start the next line off.
			
			if (str[i] == '\n') {
			
				printf(" |\n");

			} else {
			
				printf(" |\n| ");
			}

			count = 0;//reset count for the next word
			continue;//we reached the delim, we dont want it added to a word so go back the 
				 //the start of the loop, which will i++ for us putting us to te start of the next word
		}
		
		//print out the char, and increase a counter that counts
		//the number of chars in the word
		printf("%c",str[i]);
		count++;
	}

	//bottom
	printf("+");

	for (i = 0; i < max + 2; i++) {
		
		printf("-");
	}

	puts("+");
}

int main() {

	char list[MAX];
	char title[MAX];

	puts("Enter a title for the list");	
	fgets(title, MAX, stdin);

	puts("Enter a list of words sepeated by spaces");	
	fgets(list, MAX, stdin);

	print_table(title, list, ' ');	

	return 0;
}
