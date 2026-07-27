#include<stdio.h>

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int ans = gcd(a,b);
    printf("The gcd of %d and %d is : %d",a,b,ans);
}