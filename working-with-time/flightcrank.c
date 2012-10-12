
#include <stdio.h>

#define DAY 13
#define MONTH 10
#define YEAR 2012

enum months {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int is_leap(int year) {

	if (year % 4 == 0) {
	
		if (year % 400 == 0) {
		
			return 1;
		}

		if (year % 100 == 0) {
		
			return 0;
		}

		return 1;
	} 
	
	return 0;
}

int leap_num(int year) {

	int i;
	int total = 0;


	for (i = 1; i <= year; i++) {
	
		if (is_leap(i)) {
		
			total++;
		}
	}

	return total;
}

int main() {
	
	int leap = leap_num(YEAR - 1);
	int non_leap = (YEAR - 1) - leap;
	int days = 0;

	//jan
	days += (YEAR - 1) * 31;
	
	//feb
	days += (leap * 29) + (non_leap * 28);

	//mar
	days += (YEAR - 1) * 31;

	//apr
	days += (YEAR - 1) * 30;

	//may
	days += (YEAR - 1) * 31;

	//jun
	days += (YEAR - 1) * 30;

	//jul
	days += (YEAR - 1) * 31;

	//aug
	days += (YEAR - 1) * 31;

	//sep
	days += (YEAR - 1) * 30;

	//oct
	days += (YEAR - 1) * 31;

	//nov
	days += (YEAR - 1) * 30;

	//dec
	days += (YEAR - 1) * 31;


	switch (MONTH - 1) {
		
		case JAN:
			
			days += DAY;
		break;
		
		case FEB:
			
			days += 31;//jan	
			days += DAY;
		break;
		
		case MAR:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)){
				
				days += 29;
			} else {
			
				days += 28;
			}

			days += DAY;
		break;

		case APR:

			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)){
				
				days += 29;
			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += DAY;
		break;
		
		case MAY:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += DAY;
		break;
		
		case JUN:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += DAY;
		break;
		
		case JUL:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += DAY;
		break;
		
		case AUG:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += 31;//jul	
			days += DAY;
		break;
		
		case SEP:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += 31;//jul	
			days += 31;//aug	
			days += DAY;
		break;
		
		case OCT:
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += 31;//jul	
			days += 31;//aug	
			days += 30;//sep	
			days += DAY;
		break;
		
		case NOV:
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += 31;//jul	
			days += 31;//aug	
			days += 30;//sep	
			days += 31;//oct	
			days += DAY;

		break;
		
		case DEC:
			
			days += 31;//jan	
			
			//feb
			if (is_leap(YEAR)) {
				
				days += 29;

			} else {
			
				days += 28;
			}

			days += 31;//mar	
			days += 30;//apr	
			days += 31;//may	
			days += 30;//jun	
			days += 31;//jul	
			days += 31;//aug	
			days += 30;//sep	
			days += 31;//oct	
			days += 30;//nov	
			days += DAY;

		break;
		
	}
	
	int d = days % 7;

	switch (d) {
		
		case 1:
			puts("monday");
		break;
		
		case 2:
			puts("tuesday");
		break;

		case 3:
			puts("wednesday");
		break;

		case 4:
			puts("thursday");
		break;

		case 5:
			puts("friday");
		break;

		case 6:
			puts("saturday");
		break;

		case 0:
			puts("sunday");
		break;
	}

	return 0;
}

