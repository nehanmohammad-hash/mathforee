// By Nehan mohammad
// 07-October-26, Wednesday, question no: Q33
#include <stdio.h>
#include <stdlib.h>
#include "libs/coeffs.h"

// Sorts array using adjacent comparisons and counts total swaps
int fun(int A[], int n) {
	int swaps = 0;
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= n - i - 2; j++) {
			if (A[j] > A[j + 1]) {
			int temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			swaps++;
			}
		}
	}
	return swaps;
}


int main() {
	int n = 30;
	int A[30];
	double val;
	FILE *fp;
	// Generate random values and scale them to integers up to 100
	uniform("rand_data.txt", n);
	fp = fopen("rand_data.txt", "r");
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%lf", &val);
		A[i] = (int)(val * 100);
		printf("%d ", A[i]);
	}
	
	fclose(fp);
	// Run sorting function and print total swap operations
	int total_swaps = fun(A, n);
	printf("\n Total swap operations: %d\n", total_swaps);
	return 0;
}
						
