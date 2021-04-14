#include<stdio.h>

int main(int argc, char const* argv[]){
	int d, m;
	unsigned long long int n;
	//char mes[100];
	unsigned long long int crypt[100];
	scanf("%d %llu %d", &d, &n, &m);
	//scanf("%s", mes);

	for(int i=0; i < m; i++ ){
		int mes;
		scanf("%d", &mes);
		int exp = d;
		unsigned long long int base = mes%n;
		unsigned long long int enc = 1ULL;
		while(exp > 0){
			if(exp & 1){enc = (enc*base)%n;}
			base = (base * base) % n;
			exp >>= 1;
		}
		crypt[i]=enc;
	}
	for(int i = 0 ; i < m; i++){
		printf("%c", crypt[i]);
	}

	printf("\n");

	return 0;
}