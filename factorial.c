#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	double n;
	printf("Please enter a number N:\n");
	scanf("%lf\n", &n);

	// factorial function
	for (int i = n-1; i > 0; i--) {
		printf("n = %lf\n", n);
		n = n*i;
	}

	printf("Factorial of N is %lf\n", n);

	return EXIT_SUCCESS;
}