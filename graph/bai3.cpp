#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];    
int recursionStack[MAX]; 
// ham them canh 
void addEdge(int U, int V, int isDirected) {
    graph[U][V] = 1; 
    if (!isDirected) {
        graph[V][U] = 1; 
    }
}

// thuat toan duyet do thi DFS 
int dfsUndirected(int current, int parent, int n) {
    visited[current] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[current][i]) { 
            if (!visited[i]) { 
                if (dfsUndirected(i, current, n)) {
                    return 1; 
                }
            } else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}


int dfsDirected(int current, int n) {
    visited[current] = 1;
    recursionStack[current] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i]) {
            if (!visited[i]) { 
                if (dfsDirected(i, n)) {
                    return 1; 
                }
            } else if (recursionStack[i]) {
                return 1; 
            }
        }
    }
    recursionStack[current] = 0; 
    return 0;
}
int main() {
    int n, edges, isDirected, U, V;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);
    printf("do thi co huong (1) hay vo huong(0): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Nhap cac canh( d1, d2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &U, &V);
        addEdge(U, V, isDirected);
    }
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recursionStack[i] = 0;
    }
    if (isDirected) {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfsDirected(i, n)) {
                    hasCycle = 1;
                    break;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfsUndirected(i, -1, n)) {
                    hasCycle = 1;
                    break;
                }
            }
        }
    }

    if (hasCycle) {
        printf("do thi co chu ki.\n");
    } else {
        printf("do thi khong co chu ki.\n");
    }

    return 0;
}
