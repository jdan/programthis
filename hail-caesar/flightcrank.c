//Author: flightcrank
//Email: ocaumaxim@gmail.com

#include <stdio.h>

#define MAX 51

int main() {

	char str[MAX];
	char cypher[MAX];
	int shift = 0;	

	puts("enter string: ");
	fgets(str, MAX, stdin);
	
	puts("shift amount: ");
	fscanf(stdin, "%d", &shift);

	int i;

	//loop through the sting
	for (i = 0; i < MAX; i++) {
	
		//peek 1 char ahead, null byte means were at the end of the string
		if(str[i + 1] == 0) {

			//fgets includes the newline, replace the newline with a null byte
			cypher[i] = 0;	
			break;
		}

		//calculate the new caesar acsii value based upon the shift amount
		//and wrap around at ascii value 122 which is 'z'
		int ans = 0;
			
		//lowercase ascii value
		if (str[i] >= 97 && str[i] <= 122) {
					
			//ascii 'a' starts at value 97 so if the current ascii char plus the shift amount is
			//under 122 all we have to do is add the shift amount
			if (str[i] + shift < 122) {
				
				ans = str[i] + shift;
				cypher[i] = ans;
	
			//if the shift amount puts us past the char 'z' we have to wrap 
			//around back to 'a' so we calculate how many positions we have to
			//move with modulus arithmatic.
			//then we add 96 because thats the ascii value where 'a' starts.
			} else {
			
				ans = (str[i] + shift) % 122;
				ans += 96;
				cypher[i] = ans;
			}

		//if the ascii value is uppercase
		} else if (str[i] >= 65 && str[i] <= 90) {
			
			if (str[i] + shift < 90) {

				ans = str[i] + shift;
				cypher[i] = ans;

			} else {

				ans = (str[i] + shift) % 90;
				ans += 64;
				cypher[i] = ans;
			}		
		//ignore all other ascii chars and leave them as is
		} else {

			cypher[i] = str[i];
		}

	}//for loop
	
	puts(cypher);

	return 0;
}
