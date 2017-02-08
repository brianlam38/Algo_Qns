// ########################################################################
// QUESTION: Implement an algorithm to determine if a string has all unique
//			 characters. What if you cannot use additional data structures?
// ########################################################################

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int duplicateStr(char *string);
// int duplicateStrBetter(char *string);

int main(int argc, char *argv[]) {

	char string[] = "abcdefghijklmnopqrstuvwxyzZASD";	// declaring string literal
														// contains implicit null term
	if (duplicateStr(string)) {
		printf("Duplicate");
	} else {
		printf("No duplicate");
	}

	return EXIT_SUCCESS;
}

// LESS EFFICIENT METHOD O(n^2)
// For each char, iterate through the string.
// If current char = iteration char, the string will have a duplicate
int duplicateStr(char *string) {
	for (int i = 0; string[i] != '\0'; i++) {
		// printf("Testing for %c\n", string[i]);
		int charCount = 0;
		for (int j = 0; string[j] != '\0'; j++) {
			// printf("Against: %c\n", string[j]);
			if (strcmp(&string[i], &string[j]) == 0) charCount++;
			if (charCount > 1) return -1;
		}
	}
	return 0;
}
/*
// MORE EFFICIENT METHOD O(nLogn) + O(n) = O(nlogn)
// 1. Sort string
// 2. Iterate through string. If curr = prev, then duplicate exists.
int duplicateStrBetter(char *string) {
	mergeSort(string);
}
*/




