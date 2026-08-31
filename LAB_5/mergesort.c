#include<stdio.h>


void merge(int arr[],int sp,int m,int ep){
    int temp[ep-sp+1];
    int p1 = sp;
    int p2 = m+1;
    int p3  = 0;
    while(p1<=m && p2<=ep){
        if(arr[p1]<arr[p2]) temp[p3++] = arr[p1++];
        else temp[p3++] = arr[p2++];
    }
    while(p1<=m){
        temp[p3++] = arr[p1++];
    }
    while(p2<=ep){
        temp[p3++] = arr[p2++];
    }
    for(int i=sp;i<=ep;i++){
        arr[i] = temp[i-sp];
    }
}
void mergesort(int arr[],int sp,int ep){
    if(sp>= ep) return;
    int mid = sp + (ep-sp)/2;
    mergesort(arr,sp,mid);
    mergesort(arr,mid+1,ep);
    merge(arr,sp,mid,ep);
}
void printarray(int arr[],int n){
    printf("The array values are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]  = {4,6,2,1,9,43,23,56};
    printarray(arr,8);
    printf("\n");
    mergesort(arr,0,8);
    printarray(arr,8);
    return 0;
}