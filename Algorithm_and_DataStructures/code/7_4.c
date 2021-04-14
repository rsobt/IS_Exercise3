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

int dijkstra(int g, int t, int n, int** dist) {
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
	return cost[t];
}

int main() {
	int n;
	scanf("%d", &n);
	n += 100;
	int** matrix = (int**)malloc(sizeof(int*) * n+100);
	int i, j;
	for (i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * n+100);
	}
	for (i = 0;i < n;i++) {
		for (j = 0; j < n;j++) {
			matrix[i][j] = INF;
		}
	}
	for (i = 1;i <=6;i++) {
		for (j = 0; j < n-10;j++) {
			if ((i + j) % 3 == 0) {
				matrix[i + j-2][j] = 1;
			}
			else if ((i + j) % 4 == 0) {
				matrix[i + j-3][j] = 1;
			}
			else if ((i + j) % 5 == 0) {
				matrix[i + j+3][j] = 1;
			}
			else if ((i + j) % 12 == 0) {
				matrix[i + j-5][j] = 1;
			}
			else if ((i + j) % 15== 0) {
				matrix[i + j+1][j] = 1;
			}
			else if ((i + j) % 20 == 0) {
				matrix[i + j][j] = 1;
			}
			else if ((i + j) % 60 == 0) {
				matrix[i + j-2][j] = 1;
			}
			else {
				matrix[i+j][j] = 1;
			}
		}
	}
	int ans = dijkstra(0, n - 100, n, matrix);
	for (i = 1;i <= 6;i++) {
		if (n - 100 - i >= 0) {
			if (ans > dijkstra(0, n-100 - i, n, matrix) + 1) {
				ans = dijkstra(0, n - 100 - i, n, matrix) + 1;
			}
		}
	}
	
	for (i = n - 100;i < n - 80;i++) {
		if (ans > dijkstra(0, i, n, matrix)) {
			ans = dijkstra(0, i, n, matrix);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}