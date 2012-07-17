//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100 

int main() {
	
	char str[MAX];
	int i,p,x;

	printf("Enter number sequence: ");
	fgets(str, MAX - 1, stdin);

	p = strlen(str) - 3;
	printf("p = %d\n", p);

	x = str[p + 1] - 48;
	printf("x = %d\n", x);

	int a = 0;
	// -1 to skip the newline
	for(i = 0; i < strlen(str) - 2; i++) {
		
		double r = pow((double) x, (double) p);
		a += (str[i] - 48) * r;
		p--;	
	}
	
	printf("%d\n", a);

	return 0;
}
