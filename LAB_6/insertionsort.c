#include<stdio.h>

void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else{
                break;
            }
        }
    }
}
void printarray(int arr[],int n){
    printf("The array values are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]  = {4,6,2,1,9,43,23};
    printarray(arr,7);
    printf("\n");
    insertionsort(arr,7);
    printarray(arr,7);
    return 0;
}