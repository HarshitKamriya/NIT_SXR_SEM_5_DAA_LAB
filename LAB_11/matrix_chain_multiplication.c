#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1], dp[n + 1][n + 1];

    printf("Enter dimensions: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    // Base case
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum Multiplications = %d\n", dp[1][n]);

    return 0;
}