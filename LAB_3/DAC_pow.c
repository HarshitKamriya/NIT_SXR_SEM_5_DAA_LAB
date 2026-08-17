#include<stdio.h>


int pow(int a,int n){
    if(n==0) return 1;
    if(n==1) return a;
    if(n%2 == 0){
        int x = pow(a,n/2);
        return x*x;
    }
    else{
        int x = pow(a,n/2);
        return x*x*a;
    }
}
int main(){
    int a,n;
    printf("Enter the element: ");
    scanf("%d",&a);
    printf("Enter the pow you want to find : ");
    scanf("%d",&n);

    int ans=  pow(a,n);
    printf("the pow of %d is %d and ans is %d",a,n,ans);
    
}