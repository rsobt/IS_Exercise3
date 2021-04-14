#include<stdio.h>

int main(int argc, char const* argv[]){
	int e;
	unsigned long long int n;
	char mes[100];
	unsigned long long int crypt[100];
	scanf("%d %llu", &e, &n);
	scanf("%s", mes);

	int i = 0;
	while(mes[i]!='\0'){
		int exp = e;
		unsigned long long int base = mes[i]%n;
		unsigned long long int enc = 1ULL;
		while(exp > 0){
			if(exp & 1){enc = (enc*base)%n;}
			base = (base * base) % n;
			exp >>= 1;
		}
		crypt[i]=enc;
		printf("%llu ", crypt[i]);
		i++;
	}
	printf("\n");

	return 0;
}