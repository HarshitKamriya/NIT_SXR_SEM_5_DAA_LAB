#include <stdio.h>
#include <string.h>

int lcs(char a[], char b[], int i, int j, int dp[][50]) {
    int n = strlen(a);
    int m = strlen(b);

    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(a, b, i + 1, j + 1, dp);
    } else {
        int x = lcs(a, b, i + 1, j, dp);
        int y = lcs(a, b, i, j + 1, dp);
        return dp[i][j] = (x > y) ? x : y;
    }
}

int main() {
    char a[50], b[50];
    int dp[50][50];

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Enter a string a: \n");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\r\n")] = '\0';

    printf("Enter a string b: \n");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\r\n")] = '\0';

    int ans = lcs(a, b, 0, 0, dp);
    printf("Longest common subsequence length is: %d\n", ans);
    return 0;
}