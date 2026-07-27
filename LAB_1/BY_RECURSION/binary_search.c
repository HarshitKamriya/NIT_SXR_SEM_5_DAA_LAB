#include<stdio.h>


int binary_search(int arr[],int lo,int hi,int target){
    if(lo>hi) return -1;
    int m = lo+(hi-lo)/2;
    if(arr[m]==target){
        return m;
    }
    else if(arr[m]<target){
        return binary_search(arr,m+1,hi,target);
    }
    else{
        return binary_search(arr,lo,m-1,target);
    }
}
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
    int ans = binary_search(arr,0,n-1,target);
    if(ans==-1){
        printf("Target is not present");
    }
    else{
        printf("The index of target is: %d",ans);
    }
}