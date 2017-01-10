// QUESTION
//
// Find all positive integer solutions under 1,000 to a^3 + b^3 = c^3 + d^3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// BRUTE FORCE SOLUTION (N^4)
int main(int argc, char *argv[]) {

	int n = 1000;
	int a, b, c, d;

	for (a = 1; a < n; a++) {
		for (b = 1; b < n; b++) {
			for (c = 1; c < n; c++) {
				for (d = 1; d < n; d++) {
					if ((pow(a,3) + pow(b,3) == pow(c,3) + pow(d,3))
						&& (a != b) && (a != c) && (a != d)
						&& (b != c) && (b != d)
						&& (c != d))
						printf("%d   %d   %d   %d\n", a, b, c, d);
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

// EFFICIENT SOLUTION (N^2)