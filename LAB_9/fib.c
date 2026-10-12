#include<stdio.h>


int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int[] dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    printf("fibonaci number of nth value is :%d ",dp[n]);
}