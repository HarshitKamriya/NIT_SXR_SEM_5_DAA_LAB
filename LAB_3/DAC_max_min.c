#include <stdio.h>

void dac_max_min(int arr[], int i, int j, int res[]) {
    if (i == j) {
        res[0] = arr[i]; // max
        res[1] = arr[i]; // min
        return;
    }

    if (i == j - 1) {
        if (arr[i] < arr[j]) {
            res[0] = arr[j];
            res[1] = arr[i];
        } else {
            res[0] = arr[i];
            res[1] = arr[j];
        }
        return;
    }

    int mid = (i + j) / 2;
    int left[2], right[2];

    dac_max_min(arr, i, mid, left);
    dac_max_min(arr, mid + 1, j, right);

    // max
    res[0] = (left[0] > right[0]) ? left[0] : right[0];
    // min
    res[1] = (left[1] < right[1]) ? left[1] : right[1];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int res[2];
    dac_max_min(arr, 0, n - 1, res);

    printf("The min and max elements are %d, %d\n", res[1], res[0]);
    return 0;
}
