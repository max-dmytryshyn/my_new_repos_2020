#include "stdio.h"
#include "stdlib.h"
#include <ctime>

void fill_with_random(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}
void print_matrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%02d ", matrix[i][j]);
		}
		printf("\n");
	}
}
void print_diagonals(int** matrix, int n) {
	int i = 0;
	for (i = 0; i < n / 2; i++) {
		for (int j = i; j > 0; j--) {
			printf("   ");
		}
		printf("%02d ", matrix[i][i]);
		for (int j = n - 2 * (i + 1); j > 0; j--) {
			printf("   ");
		}
		printf("%02d", matrix[i][n - i - 1]);
		printf("\n");
	}
	if (n % 2 != 0) {
		for (int j = 0; j < n / 2; j++) {
			printf("   ");
		}
		printf("%02d", matrix[i][i]);
		printf("\n");
		i++;
	}
	for (i; i < n; i++) {
		for (int j = n - i - 1; j > 0; j--) {
			printf("   ");
		}
		printf("%02d ", matrix[i][n - i - 1]);
		for (int j = 2*i - n; j > 0; j--) {
			printf("   ");
		}
		printf("%02d", matrix[i][i]);
		printf("\n");
	}
}

int main() {
	srand(time(0));
	int** matrix;
	printf("Input number of lines and columns:\n");
	int n;
	scanf_s("%d", &n);
	matrix = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		matrix[i] = (int*)calloc(n, sizeof(int));
	}
	fill_with_random(matrix, n, n);
	print_matrix(matrix, n, n);
	print_diagonals(matrix, n);
	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
    std::cout << "Changes for git\n";
	free(matrix);
	return 0;
}
