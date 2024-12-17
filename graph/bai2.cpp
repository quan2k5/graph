#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// ham kiem tra tinh doi xung 
int isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1; 
}

int main() {
    int n, edges;
    int matrix[MAX][MAX] = {0}; 

    printf("Nhap so luong dinh do thi: ");
    scanf("%d", &n);
    printf("Nhap so luong canh do thi: ");
    scanf("%d", &edges);

    printf("Nhap cac canh do thi ( c1, c2 ):\n");
    for (int i = 0; i < edges; i++) {
        int U, V;
        scanf("%d %d", &U, &V);
        matrix[U][V] = 1; 
        matrix[V][U] = 1; 
    }

    printf("\nMa tran ke do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric(matrix, n)) {
        printf("\nMa tran ke nay doi xung.\n");
    } else {
        printf("\nMa tran ke nay khong doi xung.\n");
    }

    return 0;
}
