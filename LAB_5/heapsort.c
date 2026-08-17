#include<stdio.h>


void heapify(int arr[],int i,int n){
    int l = i*2;
    int r = i*2+1;
    int largest = i;
    if(l<n && arr[l]>arr[i]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,largest,n);
    }
    
}
void build_heap(int arr[],int n){
    int start = (n+2-1)/2;
    for(int i=start;i>=0;i--){
        heapify(arr,i,n);
    }
}
void heap_sort(int arr[],int n){
    build_heap(arr,n);
    for(int i=n-1;i>0;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr,0,i);
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
    heap_sort(arr,7);
    printarray(arr,7);
    return 0;
}