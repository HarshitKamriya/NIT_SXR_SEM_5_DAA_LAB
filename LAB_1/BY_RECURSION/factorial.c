#include<stdio.h>


int factorial(int n){
    if(n == 0 || n == 1) return *n;
    return factorial(n-1)*(n);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Enter the value of n: ");
    int ans = factorial(n);
    printf("The factorial of number is: %d",ans);
    
}