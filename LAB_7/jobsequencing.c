#include <stdio.h>

struct Job {
    int id, deadline, profit;
};

int main() {
    int n, total = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job a[n];

    printf("Enter deadline and profit:\n");
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        scanf("%d %d", &a[i].deadline, &a[i].profit);
    }

    // Sort jobs by decreasing profit
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].profit < a[j + 1].profit) {
                struct Job temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = -1;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = (a[i].deadline < n ? a[i].deadline : n) - 1;
             j >= 0; j--) {

            if (slot[j] == -1) {
                slot[j] = i;
                total += a[i].profit;
                break;
            }
        }
    }

    printf("\nScheduled Jobs:\n");

    for (int i = 0; i < n; i++) {
        if (slot[i] != -1)
            printf("Job %d ", a[slot[i]].id);
    }

    printf("\nMaximum Profit = %d\n", total);

    return 0;
}