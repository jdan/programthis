//Author: flightcrank
//Email: ocaumaxim@gmail.com

//convert ascii values into there binary representation

#include <stdio.h>

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
	
	char str[11];
	
	puts("enter any values less than 10 chars (no white space)");

	scanf("%10s", str);

	int i;

	for (i = 0; i < 11; i++) {

		print_binary_byte(str[i]);
		printf(" ");
	}
	
	printf("\n");
	
	return 0;
}
