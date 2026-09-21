#include <stdio.h>

#define V 6
#define E 9

int par[V];
int rank[V];

int find(int x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

int union_sets(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return 0;

    if (rank[px] < rank[py]) {
        par[px] = py;
    } else if (rank[px] > rank[py]) {
        par[py] = px;
    } else {
        par[py] = px;
        rank[px]++;
    }
    return 1;
}

void Kruskal(int arr[][3], int n) {
    int vis[n];
    // for (int i = 0; i < n; i++) vis[i] = 0;

    for (int i = 0; i < n; i++) {
        if (union_sets(arr[i][0], arr[i][1])) {
            vis[i] = 1;
        }
        else{
            vis[i] = 0;
        }
    }

    printf("The edges weights for MST is : \n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) {
            printf("edge from %d to %d with weight %d\n", arr[i][0], arr[i][1], arr[i][2]);
            sum += arr[i][2];
        }
    }
    printf("the toatal cost for MST is : %d",sum);
}

void sort(int arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][2] > arr[j + 1][2]) {
                int temp[3];
                temp[0] = arr[j][0];
                temp[1] = arr[j][1];
                temp[2] = arr[j][2];

                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j][2] = arr[j + 1][2];

                arr[j + 1][0] = temp[0];
                arr[j + 1][1] = temp[1];
                arr[j + 1][2] = temp[2];
            }
        }
    }
}

int main() {
    int edges[E][3] = {
        {3, 5, 1},
        {1, 2, 2},
        {3, 4, 2},
        {0, 1, 4},
        {0, 2, 4},
        {1, 3, 5},
        {2, 3, 5},
        {4, 5, 7},
        {2, 4, 11}
    };

    for (int i = 0; i < V; i++) {
        par[i] = i;
        rank[i] = 0;
    }

    sort(edges, E);
    Kruskal(edges, E);
    return 0;
}