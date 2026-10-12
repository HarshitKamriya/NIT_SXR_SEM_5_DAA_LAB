#include<stdio.h>

int fact(int n){
    if(n==1) return 1;
    return fact(n-1)*n;
}
int main(){
    int n;
    printf("Enter the no. to calculate the factorial: ");
    scanf("%d",&n);
    int ans = fact(n);
    printf("The factorial of the not is : %d ",ans);
    return 0;
}