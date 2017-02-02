// #############################
// B.U.D OPTIMISATION TECHNIQUES
// PART 1: Bottlenecks
// #############################

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

// O(n^2) solution
// The bottleneck here is REPEATED SEARCH for the "other side" of the pair.
// This will be the main thing to optimize
void intPairs(int *a, int k) {
	for (int i = 0; i < sizeOfA ; i++) {
		for (int j = 0; j < sizeOfA; j++) {
			if (a[i] - a[j] == 2) {
				printf("{%d,%d}", a[i], a[j]);
			}
		}
	}
}

// Optimized solution
void intPairs(int *a, int k) {
	// Sort the array = O(nlogn)
	mergeSort(int *a);
	// For each elt x, iterate until x+k = y is found, then go to the next elt.
	for (int i = 0; i < sizeOfA; i++) {
		for (int j = 0; j < sizeOfA; i++) {
			if (a[i] + k == a[j]) {
				printf("{%d,%d}", a[i], a[j]);
				break;
			}
		}
	}
}

// Suggested Optimized solution #1
// 1. Sorting the array O(nLogn)
// 2. Binary Search to find the "other side" of the pair O(nLogn)

// Suggested Optimized solution #2
// 1. Operate on an unsorted array using a HASH TABLE
//    Put your array into a Hash Table.
//	  To see if x+k or x-k exists in the array, simply look it up in the Hash Table O(N)
	  i.e. if((a[i] + k) || (a[i] - k)) count++;
	  // if x+k or x-k is TRUE, increment count
// 2. Binary search to find the "other side" of the pair O(nLogn)









