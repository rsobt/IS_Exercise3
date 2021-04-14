#include<stdio.h>

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0,tmp;
    while (b) {
        long long t = a / b;
        a -= t * b;
		tmp = a;
		a = b;
		b = tmp;
        u -= t * v;
		tmp = u;
		u = v;
		v = tmp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(int argc, char const* argv[]){
	int e;
	unsigned long long int n;
	int p, q;
	scanf("%d %llu", &e, &n);
	for(int i=2; i<n; i++){
		if(n%i==0){
			p=i;
			q=n/i;
			break;
		}
	}
	int ans = 0;
	printf("%d\n", modinv(e,(p-1)*(q-1) ));

	return 0;
}