//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>
#include <string.h>

//find out how many times we need to press a key to get the correct char
//return a 2 value array with index 0 being the key to press and index 1
//being the amount of times to press it
int* char_to_keypress(char c) {
	
	//array of strings with the array index number, acting at the key pad number
	char *key_pad[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	//has to be static to it lasts for the duration of the program, not just duration of the function
	static int key_amount[2];

	key_amount[0] = 0;
	key_amount[1] = 0;
	int i,j;

	//loops through the keypad numbers
	for(i = 0; i < 10; i++) {
		
		//loop through the strings of the current keypad number
		for(j = 0; j < strlen(key_pad[i]); j++) {
		
			//if we find the char were looking for
			if (key_pad[i][j] == c) {
				
				key_amount[0] = i; //keypad number
				key_amount[1] = j + 1;//number of times we press key to get the char
				return key_amount;		
			}
		}
	}
	//char not on keypad
	return NULL;
}

int main() {

	char str[101];
	puts("enter string:");
	fgets(str,101,stdin);

	int i,j;
	int last = 0;
	int *val;

	for (i = 0; i < strlen(str); i++) {
	
		val = char_to_keypress(str[i]);
		
		if (val != NULL) {
			
			if (val[0] == last) {
			
				printf(" ");
			}
	
			for (j = 0; j < val[1]; j++) {
			
				printf("%d",val[0]);
			}
			
			last = val[0];
		}
	}

	printf("\n");

	return 0;
}
