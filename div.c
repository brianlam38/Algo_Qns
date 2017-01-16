#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int a = 2;
	int b = 8;

	int count = 0;
	int sum = a;

	while (sum <= b) {
		sum += a;
		count++;
	}
	printf("a / b is:%d\n", count);
	printf("sum is:%d\n", sum);

	return EXIT_SUCCESS;
}