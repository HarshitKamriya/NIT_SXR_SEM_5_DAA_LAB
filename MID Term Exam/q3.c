#include<stdio.h>

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = arr[i];
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min  = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}
void printarray(int arr[],int n){
    printf("\nThe array values are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[6] = {6,5,4,3,2,1};
    
    printarray(arr,6);
    selectionsort(arr,6);
    printarray(arr,6);
    return 0;
}