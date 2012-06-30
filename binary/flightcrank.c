//Author: flightcrank
//Email: ocaumaxim@gmail.com

//convert ascii values into there binary representation

#include <stdio.h>

#define MAX 51

void print_binary_byte(char num) {

	//no ascii number is bigger than 127
	//so we know that if we have to print out
	//8 binary digets the first one will always be zero.
	
	printf("0");

	if (num >= 64) {
		
		printf("1");
		num = num - 64;
	
	} else {
	
		printf("0");
	}

	if (num >= 32 && num < 64) {
	
		printf("1");
		num = num - 32;
	
	} else {
		
		printf("0");
	
	}
	
	if (num >= 16 && num < 32) {
	
		printf("1");
		num = num - 16;
	
	} else {
		
		printf("0");
	}
	
	if (num >= 8 && num < 16) {
	
		printf("1");
		num = num - 8;
	
	} else {
		
		printf("0");
	}
	
	if (num >= 4 && num < 8) {
	
		printf("1");
		num = num - 4;
	
	} else {
		
		printf("0");
	}
	
	if (num >= 2 && num < 4) {
	
		printf("1");
		num = num - 2;
	
	} else {
		
		printf("0");
	}

	if (num == 1) {
		
		printf("1");

	} else {
		
		printf("0");
	}
}

int main() {
	
	//string length = MAX
	char str[MAX];
	
	puts("enter any ascii chars");

	fgets(str, MAX, stdin);

	int i;

	for (i = 0; i < MAX; i++) {

		//peek at the next char value in the string
		//if its a null byte were at the end of the string
		//so exit loop early. fgets keeps the newline char.
		//so the current value must be newline, skip that too.
		if (str[i + 1] == 0) {
			break;
		}
		
		print_binary_byte(str[i]);
		printf(" ");
	}
	
	printf("\n");
	
	return 0;
}
