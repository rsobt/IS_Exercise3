#include <stdio.h>

int gcd(x,y){
    if(x<y) {
        return gcd(y,x);
    }
    if(x%y == 0 ){
        return(y);
    }else{
        return gcd(y,x%y);
    }
}

int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    int ans = gcd(a,b);
    printf("%d\n",ans);
    return 0;
}