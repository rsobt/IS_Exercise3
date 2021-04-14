#include<stdio.h>
#include<stdlib.h>

#define INF 1000000000

int C(int d, int N, int M, int* x){
	int last =  0;
	for(int i = 1; i < M; i++){
		int crt = last + 1;
		while(crt < N && x[crt] - x[last] < d){
			crt ++;
		}
		if(crt == N)return 0 ;
		last = crt;
	}
	return 1;
}

int main (){
	int  N ,M;
	scanf("%d%d", &N, &M);
	int x[N];
	for(int i = 0 ; i < N; i++){
	    scanf("%d", &x[i]);
	    
	}

	int lb =  0, ub = INF;

	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		if(C(mid, N, M, x) == 1)lb = mid;
		else ub = mid;
	}
	
	printf("%d\n", lb);
}