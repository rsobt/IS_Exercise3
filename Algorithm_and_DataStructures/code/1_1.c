#include <stdio.h>
int main(void){
    int a,b,ans=0,i;
    scanf("%d%d",&a,&b);
    if(a<b){
        int tmp = a;
        a=b;
        b=tmp;
    }
    for(i=1;i<=b;i++){
        if(a%i==0&&b%i==0){ans=i;}
    }
    printf("%d\n",ans);
    return 0;
}