#include<stdio.h>

void printarray(int arr[][3],int n,int m){
    printf("The array values are: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void matrix_multiplication(int a[][3],int b[][3],int na,int ma,int nb,int mb){
    if(ma != nb) return ;
    int ans[na][mb];
    for(int i=0;i<na;i++){
        for(int j=0;j<mb;j++){
            int sum = 0;
            for(int k=0;k<ma;k++){
                sum += a[i][k]*b[k][j];
            }
            ans[i][j] = sum;
        }
    } 
    printarray(ans,na,mb);
}
int main(){
    int a[][3]  = {{1,2,3},{4,5,6},{7,8,9}};
    int b[][3]  = {{11,12,13},{14,15,16},{17,18,19}};
    printarray(a,3,3);
    printf("\n");
    printarray(b,3,3);
    printf("\n");
    matrix_multiplication(a,b,3,3,3,3);
    return 0;
}