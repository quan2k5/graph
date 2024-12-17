#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX
void dijkstra(int graph[MAX][MAX], int n, int BATDAU) {
    int distance[MAX];
    int visited[MAX] = {0};
    int i, j, minDistance, nextVertex;
    for (i = 0; i < n; i++) {
        distance[i] = INF;
    }
    distance[BATDAU] = 0; 
    for (i = 0; i < n - 1; i++) {
        minDistance = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                nextVertex = j;
            }
        }
        
        visited[nextVertex] = 1; 
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[nextVertex][j] != 0 && distance[nextVertex] != INF &&
                distance[nextVertex] + graph[nextVertex][j] < distance[j]) {
                distance[j] = distance[nextVertex] + graph[nextVertex][j];
            }
        }
    }
    printf("Khoang cach ngan nhat tu dinh %d den cac dinh khac:\n", BATDAU);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("Dinh %d: Khong the di toi\n", i);
        } else {
            printf("Dinh %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int n, edges, i, j, BATDAU, DINH1, DINH2, weight;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach cac canh (DINH1 DINH2 trong so):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &DINH1, &DINH2, &weight);
        graph[DINH1][DINH2] = weight;   
        graph[DINH2][DINH1] = weight;   
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &BATDAU);

    dijkstra(graph, n, BATDAU);

    return 0;
}
