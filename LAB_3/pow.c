#include<stdio.h>


int pow(int a,int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans= ans*a;
    }
    return ans;
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