// #############################
// B.U.D OPTIMISATION TECHNIQUES
// PART 2: Unnecessary work
// #############################

// Print all positive integer solutions to the equation a^3 + b^3 = c^3 + d^3,
// where a,b,c,d < 1,000. Print only non-trivial solutions (unique solutions, not re-arranged pairs)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000


// Brute force solution O(N^4)
int main(int argc, char *argv[]) {
	int a, b, c, d;
	int count = 0;
	for (a = 1; a < MAX; a++) {
		for (b = 1; b < MAX; b++) {
			for (c = 1; c < MAX; c++) {
				for (d = 1; d < MAX; d++) {
					if ((pow(a,3) + pow(b,3)) == (pow(c,3) + pow(d,3))) {
						count++;
						printf("%d\n", count);
						//printf("%d - %d - %d - %d\n",a,b,c,d);
						break;
						// Small Optimisation: break;
						// There can only be one solution for D, therefore it is pointless
						// to continue checking other values once D is found.
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

// Optimised solution: Calculate value of D
// Optimised from O(N^4) -> O(N^3)
int main(int argc, char *argv[]) {
	int a, b, c, d;
	for (a = 0; a < MAX; a++) {
		for (b = 0; b < MAX; b++) {
			for (c = 0; c < MAX; c++) {
				d = pow((pow(a,3) + pow(b,3) - pow(c,3)), 1/3); // rounds to int
				if ((pow(a,3) + pow(b,3)) == (pow(c,3) + pow(d,3))) { // check that D works
					printf("%d - %d - %d - %d\n", a,b,c,d);
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

-------------------------------------------------------------------------------------------

// #############################
// B.U.D OPTIMISATION TECHNIQUES
// PART 3: Duplicated Work
// #############################

// Using the same problem and brute force algorithm as above, look for DUPLICATED WORK this time.

// Duplicated work: Computing an (a,b) pair and then computing all (c,d) pairs for each (a,b).
// 					We can just compute all (c,d) pairs once. Each time we have an (a,b) pair, we can simply
//					find the matching (c,d) pair in the list.
//					The (c,d) pairs can be inserted into a Hash Table

// Suggested optimised solution = O(N^2)
int main(int argc, char *argv[]) {
	int n = 1000;
	// Generate (c,d) pairs + insert into HT
	for c from 1 to n
		for d from 1 to n
			result = c^3 + d^3
			append (c,d) to list at value map[result]
	// Using HT, map computed (a,b) pairs to corresponding (c,d) pairs
	for a from 1 to n
		for b from 1 to n
			result = a^3 + b^3
			list = map.get(result)
			for each pair in list
				print a, b, pair

	return EXIT_SUCCESS;
}

// Best optmised solution = O(N^2)
// Once we have the map of all (c,d) pairs, we can just use that directly.
// We don't need to generate the (a,b) pairs, they will already be in the map.
int main(int argc, char *argv[]) {
	int n = 1000;
	// Generate (c,d) pairs + insert into HT
	for c from 1 to n
		for d from 1 to n
			result = c^3 + d^3;
		append (c,d) to list at value map[result];
	//
	for each result, list in map
		for each pair1 in list
			for each pair2 in list
				print pair1, pair2

	return EXIT_SUCCESS;
}





