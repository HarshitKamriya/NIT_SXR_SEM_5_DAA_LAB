#include<stdio.h>

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("\nEnter the value of target: ");
    scanf("%d",&target);
    int ans = -1;
    int lo =0;
    int hi = n-1;
    while(lo<=hi){
        int m = lo + (hi-lo)/2;
        if(arr[m]==target){
            ans = m;
            break;
        }
        else if(arr[m]<target){
            lo = m+1;
        }
        else{
            hi = m-1;
        }
    }
    if(ans==-1){
        printf("Target is not present");
    }
    else{
        printf("The index of target is: %d",ans);
    }
}