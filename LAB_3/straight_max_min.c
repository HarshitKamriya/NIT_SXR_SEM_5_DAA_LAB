#include<stdio.h>


void straight_max_min(int arr[],int n){
    int max = arr[0];
    int min = arr[1];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max  = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
    printf("The max and min elements are %d , %d",max,min);
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    straight_max_min(arr,n);
    return  0;
}