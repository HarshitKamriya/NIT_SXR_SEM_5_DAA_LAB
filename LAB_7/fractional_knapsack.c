#include <stdio.h>

struct Item {
    int profit, weight;
    float ratio;
};

int main() {
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];

    printf("Enter profit and weight of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].profit, &a[i].weight);
        a[i].ratio = (float)a[i].profit / a[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort by profit/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].ratio < a[j].ratio) {
                struct Item temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Fill the knapsack
    for (int i = 0; i < n; i++) {
        if (capacity >= a[i].weight) {
            totalProfit += a[i].profit;
            capacity -= a[i].weight;
        }
        else {
            totalProfit += a[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}