// ########################################################################
// QUESTION: Implement an algorithm to determine if a string has all unique
//			 characters. What if you cannot use additional data structures?
// ########################################################################

// Extra Notes:
// Difference between ASCII / Unicode string
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

// int duplicateStr(char *string);
int duplicateStrBetter(char *string);
int stringLen(char *string);

int main(int argc, char *argv[]) {

	char string[] = "abcdefghijZklmnopqrstuvwxyzZASD";	// declaring string literal
														// contains implicit null term
	if (duplicateStrBetter(string)) {
		printf("Duplicate");
	} else {
		printf("No duplicate");
	}

	return EXIT_SUCCESS;
}

// ###################################
// METHOD 1 | O(n^2) time | O(1) space
// ###################################
// 1. For each char, iterate through the string to check duplicates
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

// #################################
// METHOD 2 | O(n) time | O(1) space	- MOST EFFICIENT
// #################################
// 1. Create an array of boolean values. T/F indicates if char exists in string
// 2. Iterate through string to see if char occurs twice.

int duplicateStrBetter(char *string) {
	if (stringLen(string) > 128) return FALSE;

	// Create char set + initialise all to FALSE
	int charSet[128];
	for (int i = 0; i < 128; i++) {
		charSet[i] = FALSE;
	}

	// Iterate through string to count # of characters repeated.
	for (int j = 0; j < stringLen(string); j++) {
		int val = string[j];
		if (charSet[val] == TRUE) {
			return FALSE;
		}
	}

	// No duplicate found, return TRUE.
	return TRUE;
}

int stringLen(char *string) {
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		count++;
	}
	return count;
}

/*
// #####################################
// METHOD 3 | O(nlogn) time | O(x) space
// #####################################
// 1. Sort string
// 2. Iterate through string. If curr = prev, then duplicate exists.

int duplicateStrBetter(char *string) {
	mergeSort(string);

	return 0;
}
*/






