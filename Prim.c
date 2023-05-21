#include <stdio.h>
#include <stdbool.h>
#define INF 99999

int min(int visited[40], int key[40], int vertices) {
    int min = INF;
    int minIndex = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prim(int graph[40][40], int vertices) {
    int parent[40], key[40];
    bool visited[40];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        key[i] = INF;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vertices; i++) {
        int u = min(visited, key, vertices);
        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Edge\tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d-%d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int vertices = 5;
    int graph[40][40] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph, vertices);

    return 0;
}
