#include <stdio.h>

int sum = 0;
int bound;

/**
 * Read from user keyboard
 * array: target array to store input
 * size: array capacity
 */
void put(int* array, int size) {
	if (size > 0) {
		scanf("%d", array);
		put(array + 1, size - 1);
	}
}

/**
 * Calculate square value of all stored number
 * array: array which hold the values
 * size: array capacity
 * yield: variable to store calculation result
 */
void squaresum(int* array, int size, int* yield) {
	int index = size - 1;
	if (index >= 0) {
		if (array[index] > 0) {
			sum += (array[index] * array[index]);
		}
		// repeat
		squaresum(array, size - 1, yield);
	} else {
		*yield = sum;
	}	
}

/**
 * Read input as the problem specified
 * matrix: array which hold the values
 * summary: array to store the calculation results
 * i: iterator
 */
void read_input(int** matrix, int* summary, int i) {
	sum = 0;
	if (i < bound) {
		int size;
		scanf("%d", &size);
		matrix[i] = (int *)malloc(sizeof(int) * size);
		put(matrix[i], size);
		squaresum(matrix[i], size, &summary[i]);
		// repeat
		read_input(matrix, summary, i+1);
	}
}

/**
 * Print all results
 * results: array which hold the calculation results
 * i: iterator
 */
void print_output(int* results, int i) {
	if (i < bound) {
		printf("%d\n", results[i]);
		print_output(results, i + 1);
	}
}

int main() {
	scanf("%d", &bound);
	int** matrix = (int **)malloc(sizeof(int *) * bound);
	int* sum_matrix = (int *)malloc(sizeof(int) * bound);
	read_input(matrix, sum_matrix, 0);
	print_output(sum_matrix, 0);
}