#include<stdio.h>

int fib(int n){
    if(n==1 || n==0) return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    printf("Enter the no. to calculate the fibonaci no.: ");
    scanf("%d",&n);
    int ans = fib(n);
    printf("The fibonaci of the no. is : %d ",ans);
    return 0;
}