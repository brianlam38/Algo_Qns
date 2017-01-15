// ################################
// Big O. Time complexity analysis.
// ################################

// What is the runtime of the below code?			// Runtime = O(N^2)
void printUnorderedPairs(int array[]) {				
	for (int i = 0; i < array.length; i++) {		// N/2 = pairs , N+1 = val of each pair
		for (int j = i+1; j < array.length; j++) {  // N/2 * N+1 = N^2/2 roughly = O(N^2)
			int sum = array[i] + array[j];
			printf("%d", sum);
		}
	}
}

// What is the runtime of the below code?
void printUnorderedPairs(int arrayA[], int arrayB[]) {		// Runtime = O(ab)
	for (int i = 0; i < arrayA.length; i++) {				
		for (int j = 0; j < arrayB.length; j++) {			// The if statement is O(1) time
			if (arrayA[i] < arrayB[j]) {					// For each elt of arrayA, inner loop goes through B iterations
				print arrayA[i] + arrayB[j];				// O(N^2) is INCORRECT, as there are TWO DIFFERENT INPUTS		
			}
		}
	}
}

// What is the runtime of the below code?
void printUnorderedPairs(int arrayA[], int arrayB[]) {		// Runtime = O(ab)
	for (int i = 0; i < arrayA.length; i++) {				
		for (int j = 0; j < arrayB.length; j++) {			// Nothing has changed here.
			for (int k  = 0; k < 100000; k++) {				// 100,000 units is still constant
				print arrayA[i] + arrayB[j];
			}
		}
	}
}

// What is the runtime of the below code?			// Runtime = O(N)
void reverseArray(int array[]) {
	for (int i = 0; i < array.length/2; i++) {		// Only one loop.
		int other = array.length-i-1;				// Length/2 doesn't affect BigO time
		int temp = array[i];
		array[i] = array[other];
		array[other] = temp;
	}
}

// Question:
// Suppose we had an algorithm that took in an array of strings, sorted each string,
// and then sorted the full array. What would the runtime be?
//
// To reduce confusion:
// Let S = length of the longest string
// Let A = length of the longest array
// 1. Sorting each string = O(SLogS) --> Sorting all strings separately = O(A * SLogS)
// 2. Sort all the strings together = O(A * SLogA)
//	  Each string comparison takes O(S). There are O(ALogA) comparisons.
// 3. Combining both together and simplifying = O(A*S(LogA + LogS))

// What is the runtime of the below code?
// The function sums the values of all the
// nodes in a balanced binary search tree.
int sum(Node node) {							// Runtime = O(N)
	if (node == null) {							// Simplified from O(2^LogN)
		return 0;
	}
	return sum(node.left) + node.value + sum(node.right);
}
// Runtime of a recursive function = O(branches^depth)
// In a Balanced Binary Search Tree, if there
// are N total nodes then depth is roughly LogN











