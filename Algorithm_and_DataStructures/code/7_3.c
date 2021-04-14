#include<stdio.h>
#include<stdlib.h>

#define INF 1000000000

void print(int n, int** matrix) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0;j < n;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

void dijkstra(int g, int t, int n, int** dist) {
	int cost[n];
	int used[n];
	int x, y, min;
	for (x = 0; x < n; x++) {
		cost[x] = INF;
		used[x] = 0;
	}
	cost[g] = 0;
	while (1) {
		min = INF;
		int tmp = -1;
		for (x = 0;x < n;x++) {
			if (used[x] == 0 && min > cost[x]) {
				min = cost[x];
				tmp = x;
			}
		}
		if (min == INF) {
			break;

		}
		used[tmp] = 1;
		for (y = 0;y < n;y++) {
			if (cost[y] == min) {
				for (x = 0;x < n;x++) {
					if (cost[x] > dist[x][y] + cost[y])
						cost[x] = dist[x][y] + cost[y];
				}
			}
		}
	}
	printf("%d", cost[t]);
	printf("\n");
}

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
			matrix[i][j] = INF;
		}
	}
	int s, t;
	for (i = 0;i < m;i++) {
		scanf("%d %d", &s, &t);
		matrix[s][t] = 1;
		matrix[t][s] = 1;
	}
	scanf("%d %d", &s, &t);
	dijkstra(s, t, n, matrix);

	return 0;
}