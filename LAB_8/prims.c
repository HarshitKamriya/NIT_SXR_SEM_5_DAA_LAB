#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5   // Number of vertices

// Structure for heap node
typedef struct {
    int vertex;
    int key;
} HeapNode;

// Min-Heap structure
typedef struct {
    int size;
    int capacity;
    int *pos;
    HeapNode **array;
} MinHeap;

HeapNode* newHeapNode(int v, int key) {
    HeapNode* node = (HeapNode*) malloc(sizeof(HeapNode));
    node->vertex = v;
    node->key = key;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->pos = (int*) malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode**) malloc(capacity * sizeof(HeapNode*));
    return heap;
}

void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;

    if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = heap->array[smallest];
        HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    HeapNode* root = heap->array[0];
    HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(MinHeap* heap, int v, int key) {
    int i = heap->pos[v];
    heap->array[i]->key = key;

    while (i && heap->array[i]->key < heap->array[(i-1)/2]->key) {
        heap->pos[heap->array[i]->vertex] = (i-1)/2;
        heap->pos[heap->array[(i-1)/2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

int isInMinHeap(MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

void primMST(int graph[V][V]) {
    int parent[V];  
    int key[V];     

    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        parent[v] = -1;
        key[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, key[v]);
        heap->pos[v] = v;
    }

    key[0] = 0;
    heap->array[0] = newHeapNode(0, key[0]);
    heap->pos[0] = 0;
    heap->size = V;

    while (heap->size > 0) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(heap, v) && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                decreaseKey(heap, v, key[v]);
            }
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primMST(graph);

    return 0;
}
