#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int r_gcd(int a, int b) { //recursive euclid algorithm

	int max = (a > b) ? a : b;
	int min = (a < b) ? a : b;
	
	if (min == 0) {
		return max;
	}
	
	else if (min == 1) {
		return 1;
	}

	else {
		return r_gcd(min, max%min);
	}
}

int i_gcd(int a, int b) { //iterative 

	int max = (a > b) ? a : b;
	int min = (a < b) ? a : b;
	
	while (min != 0) {
		int r = max % min;
		max = min;
		min = r;
	}
	return max;
}
	
