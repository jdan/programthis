//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100 

int main() {
	
	char str[MAX];
	int count,n;
	char *in;
	int *a;

	printf("Enter number sequence seperated by spaces: ");
	fgets(str, MAX - 1, stdin);

	a = (int*) malloc(50); // 50 ints, only need 50 or so because the input string is 100 chars
	count = 0;
	in = strtok(str," \n");	

	while (in != NULL) {
	
		sscanf(in,"%d",&n);
		a[count] = n;
		in = strtok(NULL, " \n");	
		count++;
	}
	
	int p = count - 2; //power
	int f = 0; // final result
	int i;

	for(i = 0; i < count - 1; i++) {
		
		double r = pow((double) a[count - 1], (double) p);
		f += a[i] * r;
		p--;
	}
	
	printf("%d\n", f);

	free(a);

	return 0;
}
