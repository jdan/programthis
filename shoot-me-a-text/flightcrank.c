//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

int* char_to_keypress(char c) {

	char *key_pad[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	static int key_amount[2];

	key_amount[0] = 0;
	key_amount[1] = 0;
	int i,j,k;

	for(i = 0; i < 10; i++) {
		
		for(j = 0; j < strlen(key_pad[i]); j++) {
		
			
			if (key_pad[i][j] == c) {
				
				for (k = 0; k < j + 1; k++) {
					
					//printf("%d", i);
					key_amount[1] = j;
				}
				
				key_amount[0] = i;
				key_amount[1]++;
				return key_amount;		
			}
		}
	}

	return NULL;
}

int main() {

	char *str = "programthis";
	
	int i,j;
	int last = 0;
	int *val;

	for (i = 0; i < strlen(str); i++) {
	
		val = char_to_keypress(str[i]);
		
		if (val[0] == last) {
			
			printf(" ");
		}


		for (j = 0; j < val[1]; j++) {
		
			printf("%d",val[0]);
		}
		
		last = val[0];
	}

	printf("\n");

	return 0;
}
