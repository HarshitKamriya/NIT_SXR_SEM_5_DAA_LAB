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
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            ans = i;
            break;
        }
    }
    if(ans==-1){
        printf("Target is not present");
    }
    else{
        printf("The index of target is: %d",ans);
    }
}