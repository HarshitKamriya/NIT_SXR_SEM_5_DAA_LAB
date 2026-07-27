#include<stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    printf("Enter the value of n: ");
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*i;
    }
    printf("The factorial of number is: %d",ans);
    
}