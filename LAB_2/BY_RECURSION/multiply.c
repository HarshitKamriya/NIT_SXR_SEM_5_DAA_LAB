#include<stdio.h>


int multiply(int n,int m){
    if(m==0) return 0;
    return multiply(n,m-1)+n;
}

int main(){
    int n,m;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enterh the value of m to multiply : ");
    scanf("%d",&m);
    int ans = multiply(n,m);
    printf("the multiplicatin of the given number is: %d",ans);
}