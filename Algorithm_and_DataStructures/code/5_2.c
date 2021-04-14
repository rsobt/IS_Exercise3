#include<stdio.h>

//return a^n
int power(int a, int n){
	int m, b;
	if(n==1) return a;
	m = n/2;
	b = power(a,m);
	b = b*b;
	if(n%2 == 0 )return b;
	else return b * a;
}

int main(int argc, char const* argv[]){
	int a;
	scanf("%d", &a);
	printf("%d\n", power(2,a)-1);
}