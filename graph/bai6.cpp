#include <stdio.h>

#define MAX 100

// Ham tinh bac cua cac dinh trong do thi
void calculateDegree(int graph[MAX][MAX], int n, int isDirected) {
    int degree[MAX] = {0};  // Mang luu tru bac cua cac dinh
    int maxDegree = 0, maxDegreeVertex = 0;  // Bien luu tru bac lon nhat va dinh co bac lon nhat

    // Duyet qua tat ca cac cap dinh de tinh bac
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                degree[i]++;  // Tang bac cua dinh i
                if (!isDirected) {
                    degree[j]++;  // Neu do thi vo huong, tang bac cua dinh j
                }
            }
        }
    }

    // In ra bac cua tung dinh
    printf("Bac cua tung dinh:\n");
    for (int i = 0; i < n; i++) {
        printf("Dinh %d: %d\n", i, degree[i]);
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];  // Cap nhat bac lon nhat
            maxDegreeVertex = i;    // Cap nhat dinh co bac lon nhat
        }
    }

    printf("\nDinh co bac lon nhat: %d\n", maxDegreeVertex);
}

int main() {
    int graph[MAX][MAX];  // Mang 2 chieu luu tru ma tran ke cua do thi
    int n, edges, isDirected;  // Bien luu tru so dinh, so canh va kien truc cua do thi
    int DINH1, DINH2;  // Bien luu tru cac dinh cua moi canh

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);
    printf("Do thi co huong? (1 = Co huong, 0 = Vo huong): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach cac canh (DINH1 DINH2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &DINH1, &DINH2);
        graph[DINH1][DINH2] = 1;  
        if (!isDirected) {
            graph[DINH2][DINH1] = 1;   
        }
    }

    calculateDegree(graph, n, isDirected);

    return 0;
}
