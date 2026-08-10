#include<stdio.h>


int rearrange(int arr[],int sp,int ep){
    int p1 = sp+1;
    int p2 = ep;
    while(p1<p2){
        while(p1<p2 && arr[p1]<=arr[sp]) p1++;
        while(p1<p2 && arr[p2]>arr[sp]) p2--;
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2]  = temp;
        p1++;
        p2--;
    }
    int temp = arr[sp];
    arr[sp] = arr[p2];
    arr[p2] = temp;
    return p2;
}
void quicksort(int arr[],int sp,int ep){
    if(sp>= ep) return;
    int m =  rearrange(arr,sp,ep);
    quicksort(arr,sp,m-1);
    quicksort(arr,m+1,ep);   
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
    quicksort(arr,0,6);
    printarray(arr,7);
    return 0;
}