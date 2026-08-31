#include<stdio.h>

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = arr[i];
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[i]<min){
                min = arr[i];
                idx = i;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
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
    selectionsort(arr,7);
    printarray(arr,7);
    return 0;
}