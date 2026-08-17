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
int slectkmin(int arr[],int sp,int ep,int k){
    if(sp == ep){
        if(sp==k-1){
            return arr[sp];
        }
        else{
            return -1;
        }
    }
    int m =  rearrange(arr,sp,ep);
    int left = -1;
    int right = -1;
    if(m==k-1){
        return arr[m];
    }
    else if(m<k-1){
        left = slectkmin(arr,m+1,ep,k);
    } 
    else{
        right = slectkmin(arr,sp,m-1,k);
    }
    if(left != -1) return left;
    if(right != -1) return right;
    return -1;
}
void printarray(int arr[],int n){
    printf("The array values are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]  = {4,4,2,1,9,43,23};
    printarray(arr,7);
    printf("\n");
    int ans = slectkmin(arr,0,6,4);
    printf("the %d min value in array is: %d",4,ans);
    return 0;
}