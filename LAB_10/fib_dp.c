#include<stdio.h>


int fib(int n,int dp[]){
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n];
    int a = fib(n-1,dp);
    int b = fib(n-2,dp);
    int temp = a+b;
    dp[n] = temp;
    return temp;
}


int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }
    int ans = fib(n,dp);
    printf("fibonaci number of nth value is :%d ",ans);
}