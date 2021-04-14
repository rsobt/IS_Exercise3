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
int dis(x,y){
    int ans = y-x;
    if(ans>=0) return ans;
    else return ans * -1 ;
}
int main(void){
    int px,py,qx,qy;
    scanf("%d%d%d%d",&px,&py,&qx,&qy);
    int dx=dis(px,qx), dy=dis(py,qy);
    int ans = gcd(dx,dy) + 1;
    printf("%d\n",ans);
    return 0;
}