#include<stdio.h>
#define N 12

void DFS(int a[N][N], int i, int j){
	if(i<0||i>=N||j<0||j>=N) return;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = { 0, 0,-1, 1};
	for(int k = 0; k < sizeof(dx)/sizeof(dx[0]); k++){
		if(a[i+dx[k]][j+dy[k]]==1){
			a[i+dx[k]][j+dy[k]] = 0;
			DFS(a, i+dx[k], j+dy[k]);
		}
	}
}

int main(){
	int i, j, ans = 0;
	int grid[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(grid[i][j]==1){
				grid[i][j]==0;
				ans++;
				DFS(grid, i, j);
			}
		}
	}
	printf("%d\n", ans);
}