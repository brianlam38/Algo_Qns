// ########################################################################
// QUESTION: Implement an algorithm to determine if a string has all unique
//			 characters. What if you cannot use additional data structures?
// ########################################################################

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int duplicateStr(char *string);

int main(int argc, char *argv[]) {

	char string[] = "abcdefghijklmnopqrstuvwxyzZASD";

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
		char currStr = string[i];
		int charCount = 0;
		for (int j = 0; string[j] != '\0'; j++) {
			// printf("Against: %c\n", string[j]);
			if (currStr == string[j]) charCount++;
			if (charCount > 1) return -1;
		}
	}
	return 0;
}

// MORE EFFICIENT METHOD O(nLogn)
// Iterate through the string. For each char, if next = prev, then the
// string will have a duplicate
// Runtime = O(nLogn) + O(n) = O(nLogn)




