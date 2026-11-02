#include <stdio.h>

#define V 4
#define INF 99999

int main(void) {
    int dist[V][V] = {
        {0,   5, INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    for (int via = 0; via < V; via++) {
        for (int from = 0; from < V; from++) {
            for (int to = 0; to < V; to++) {
                if (dist[from][via] != INF && dist[via][to] != INF &&
                    dist[from][via] + dist[via][to] < dist[from][to]) {
                    dist[from][to] = dist[from][via] + dist[via][to];
                }
            }
        }
    }

    printf("All-pairs shortest-path distances:\n");
    for (int from = 0; from < V; from++) {
        for (int to = 0; to < V; to++) {
            if (dist[from][to] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[from][to]);
            }
        }
        printf("\n");
    }

    return 0;
}