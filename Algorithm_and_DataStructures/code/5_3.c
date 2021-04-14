#include<stdio.h>

void array_print(int a[],int i,int n){
	if(i == n) return;
	printf("a[%d]: %d\n", i, a[i]);
	i++;
	array_print(a, i, n);
}

int main(int argc, char const* argv[]){
	int a[10] = {3,1,4,1,5,9,2,6,5,3};
	int i = 0 ;
	array_print(a, i,sizeof(a)/sizeof(a[0]));
	return 0;
}