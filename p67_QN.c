// Given an array of distinct integer values, count the number of pairs of integers
// that have difference k.

#include <stdio.h>
#include <stdlib.h>

#define sizeOfA 7

void intPairs(int *a, int k);

int main(int argc, char *argv[]) {
	int a[] = {1, 7, 5, 9, 2, 12, 3};
	int k = 2;
	intPairs(a,k);

	return EXIT_SUCCESS;
}

void intPairs(int *a, int k) {
	for (int i = 0; i < sizeOfA ; i++) {
		for (int j = 0; j < sizeOfA; j++) {
			if (a[i] - a[j] == 2) {
				printf("{%d,%d}", a[i], a[j]);
			}
		}
	}
}