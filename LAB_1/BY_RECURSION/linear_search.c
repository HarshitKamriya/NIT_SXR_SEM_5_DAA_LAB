#include<stdio.h>


int linear_search(int arr[],int i,int target){
    if(i==sizeof(arr) / sizeof(arr[0])) return -1;
    if(arr[i]==target) return i;
    return linear_search(arr,i+1,target);
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
    int ans = linear_search(arr,0,target);
    if(ans==-1){
        printf("Target is not present");
    }
    else{
        printf("The index of target is: %d",ans);
    }
}