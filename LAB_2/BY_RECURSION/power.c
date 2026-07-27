#include<stdio.h>


int power(int a,int b){
    if(a==0) return 0;
    if(b==0) return 1;
    return power(a,b-1)*a;
}

int main(){
    int n,m;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the power m: ");
    scanf("%d",&m);
    int ans = power(n,m);

    printf("power of  n of m value is :%d ",ans);
}