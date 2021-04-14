#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int** matrix = (int**)malloc(sizeof(int*) * n);
	int i, j;
	for (i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * n);
	}
	for (i = 0;i < n;i++) {
		for (j = 0; j < n;j++) {
			matrix[i][j] = 0;
		}
	}
	int s, t;
	for (i = 0;i < m;i++) {
		scanf("%d %d", &s, &t);
		matrix[s][t] = 1;
		matrix[t][s] = 1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0;j < n;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}