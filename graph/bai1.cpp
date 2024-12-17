#include<stdio.h>
#define V 4
 
void addEdge(int matrix[V][V], int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;  
} 

void printMatrix(int matrix[V][V]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V ; j++){
			printf("%d \t", matrix[i][j]);
		}
		printf("\n"); 
	}	
}
int main(){
	int matrix[V][V] = {0};
	addEdge(matrix, 0,1);
	addEdge(matrix, 0,2); 
	addEdge(matrix, 1,2);
	addEdge(matrix, 2,3);
	
//	int matrix[v][v] = {{0,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,0}};
	printMatrix(matrix); 
	return 0; 
} 
