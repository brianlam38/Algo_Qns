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

// ###########################
// BALANCED BINARY SEARCH TREE
// ###########################

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


// #############
// PRIME NUMBERS
// #############

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

// ###########
// N FACTORIAL
// ###########

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

// ###################
// STRING PERMUTATIONS
// ###################

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

// #########
// FIBONACCI
// #########

// What is the runtime of the below code?
// The O(branches^depth) pattern for recursive calls apply to this
int fib(int n) {							// Runtime = O(2^n) --> Possible to get O(1.6^N)
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);	// multiple recursive calls
}
// If branches = 2 per call + we can go as deep as N, therefore O(2^n)
// Generally, when there is an algorithm with multiple
// recursive calls, runtime will be exponential.


// What is the runtime of the below code?
// Code prints all Fibonacci numbers from 0 to n.
void allFib(int n) {							// Runtime = O(2^n)
	for (int i = 0; i < n; i++) {				// 2^1 + 2^2 + ... + 2^n = 2^n+1
		System.out.println(i + ": " + fib(i));	// Same time complexity as above example
	}
}

int fib(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}


// What is the runtime of the below code?
// Prints all Fibonacci numbers from 0 to n.
// However, it stores previously computed values in an integer array.
void allFib(int n) {									// Runtime = O(n)
	int memo[] = new int[n + 1];						// At each call to fib(i), we have already computed and stored
	for (int i = 0; i < n; i++) {						// values for fib(i-1) and fib(i-2). We just look up values
		System.out.println(i + ": " + fib(i, memo));
	}
}

int fib(int n, int memop[]) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else if (memo[n] > 0) return memo[n];

	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
	return memo[n];
}
// MEMOIZATION: An optimisation technique by storing results of expensive function calls
///             and returning cached results when the same input occurs again.
// At each call to fib(i), we have already computed and stored values for fib(i-1) and fib(i-2).
// We just look up values, sum them, store the new result and return.
// This takes a constant amount of time.
// EXAMPLE:
fib(1) -> return 1
fib(2)
	fib(1) -> return 1
	fib(0) -> return 0
	store 1 at memo[2]
fib(3)
	fib(2) -> lookup memo[2] -> return 1
	fib(1) -> return 1
	store 2 at memo[3]
fib(4)
	fib(3) -> lookup memo[2] -> return 1
	fib(2) -> lookup memo[3] -> return 2
	store 3 at memo[4]
...

// ################################################################################

// What is the runtime of the below code?
// The function prints powers of 2 up to n.
int powersOf2(int n) {						// Runtime = O(nLogn)
	if (n == 1) {
		System.out.println(1);				// The runtime is the number of times we can
		return 1;							// halve n until we get to the base case (1)
	} else {								// This will take nlogn function calls.
		int prev = powersOf2(n / 2);
		int curr = prev * 2;
		System.out.println(curr);
		return curr;
	}
}

// #############################
// ADDITIONAL BIG O PROBLEM SETS
// #############################
------------------------------------------------------------------------------------
// 1. The following code computes the product of a and b. What is its runtime?
int product(int a, int b) {
	int sum = 0;
	for (int i = 0; i < b: i++) {
		sum += a;
	}
	return sum;
}
// Runtime = O(n)
// Reason: A is added to itself B constant times

------------------------------------------------------------------------------------
// 2. The following code computes a^b. What is its runtime?
int power(int a, int b) {
	if (b < 0) {
		return 0; // error
	} else if (b == 0) {
		return 1;
	} else {
		return a * power(a, b - 1);
	}
}
// Runtime = O(n)   --> Not sure why???

------------------------------------------------------------------------------------
// 3.The following code computes a % b. What is its runtime?
int mod(int a, int b) {
	if (b <= 0) {
		return -1;
	}
	int div = a / b;
	return a - div * b;
}
// Runtime = O(1)	--> Just one iteration for the function
// Code seems incorrect above. Always will return 0???

------------------------------------------------------------------------------------
// 4. The following code performs integer division.
//    What is its runtime (assume a and b are both +ve)?
int div(int a, int b) {
	int count = 0;
	int sum = 0;
	while (sum <= a) {
		sum+= b;
		count++;
	}
	return count;
}
// Runtime = O(n)	--> Iterates from b to a

------------------------------------------------------------------------------------



























