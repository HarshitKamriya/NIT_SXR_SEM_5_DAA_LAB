#include <stdio.h>

#define N 4

void add(int A[N][N], int B[N][N], int C[N][N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[N][N], int B[N][N], int C[N][N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[N][N], int B[N][N], int C[N][N], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N];
    int M5[N][N], M6[N][N], M7[N][N];
    int X[N][N], Y[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, X, k);
    add(B11, B22, Y, k);
    strassen(X, Y, M1, k);

    // M2 = (A21 + A22)B11
    add(A21, A22, X, k);
    strassen(X, B11, M2, k);

    // M3 = A11(B12 - B22)
    sub(B12, B22, Y, k);
    strassen(A11, Y, M3, k);

    // M4 = A22(B21 - B11)
    sub(B21, B11, Y, k);
    strassen(A22, Y, M4, k);

    // M5 = (A11 + A12)B22
    add(A11, A12, X, k);
    strassen(X, B22, M5, k);

    // M6 = (A21 - A11)(B11 + B12)
    sub(A21, A11, X, k);
    add(B11, B12, Y, k);
    strassen(X, Y, M6, k);

    // M7 = (A12 - A22)(B21 + B22)
    sub(A12, A22, X, k);
    add(B21, B22, Y, k);
    strassen(X, Y, M7, k);

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, X, k);
    sub(X, M5, Y, k);
    add(Y, M7, C11, k);

    // C12 = M3 + M5
    add(M3, M5, C12, k);

    // C21 = M2 + M4
    add(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    sub(M1, M2, X, k);
    add(X, M3, Y, k);
    add(Y, M6, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    printf("Enter first matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, N);

    printf("Resultant Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}