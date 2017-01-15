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




// What is the runtime of the below code?
// Checks if a number n is prime or not.
boolean isPrime(int n) {					// Runtime = O(sqrt(N))
	for (int x = 2; x * x <= n; x++) {
		if (n % x == 0) {					// Loop starts when x = 2
			return FALSE;					// Loop ends when x = sqrt(N)
		}									// If statement = constant
	}
	return TRUE;
}

// What is the runtime of the below code?
// The code computes N! (N factorial)
int factorial(int n) {					// Runtime = O(N)
	if (n < 0) {
		return -1;						// Recursion from N -> N-1 -> N-2 ... 1
	} else if (n == 0) {
		return 1;
	} else {
		return n *factorial(n - 1)
	}
}

// What is the runtime of the below code?
// The code prints all permutations of a string
void permutation(String str, String prefix) {		// Runtime = O(N!)
	if (str.length() == 0) { // empty string
		System.out.println(prefix);
	} else {
		for (int i = 0; i < str.length(); i++) {
			String rem = str.substring(0, i) + str.substring(i + 1); //
			permutation(rem, prefix + str.charAt(i));
		}
	}
}
// String Permutation examples
a b c = 1	3 letters = 6 permutations
a c b = 2	4 letters = 24 permutations
b a c = 3	SAME AS FACTORIAL
b c a = 4
c a b = 5
c b a = 6

a b c d
a b d c
a c d b
a c b d
a d b c
a d c b
etc...

// In the first permutation, we have N chars in STR and it makes N recursive calls
// Next level, we have N-1 chars in STR and it makes N-1 recursive calls.
// Then N-3, N-4 so on...
// TOTAL = N * (N-1) * (N-2) * ... * 1 = N! calls --> O(N!) runtime



















