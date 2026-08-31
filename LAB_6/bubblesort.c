#include<stdio.h>

void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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
    bubblesort(arr,7);
    printarray(arr,7);
    return 0;
}