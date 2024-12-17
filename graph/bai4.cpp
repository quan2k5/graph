#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cau truc Node de luu tru danh sach ke cua do thi
typedef struct Node {
    int vertex;  // Dinh cua node
    struct Node* next;  // Con tro toi node tiep theo
} Node;

// Cau truc Graph de luu tru do thi
typedef struct Graph {
    int numVertices;  // So luong dinh trong do thi
    Node* adjList[MAX];  // Mang danh sach ke cua cac dinh
    int visited[MAX];  // Mang danh dau cac dinh da duoc tham
} Graph;

// Cau truc Queue de ho tro duyet BFS
typedef struct Queue {
    int items[MAX];  // Mang luu tru cac phan tu cua hang doi
    int front, rear;  // Chi so cua phan tu dau va cuoi hang doi
} Queue;

// Ham tao Queue moi
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Ham kiem tra xem Queue co rong hay khong
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Ham them phan tu vao Queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)   
        return;
    if (q->front == -1)   
        q->front = 0;
    q->items[++q->rear] = value;   
}

// Ham lay phan tu ra khoi Queue
int dequeue(Queue* q) {
    if (isEmpty(q))  // Neu Queue rong, tra ve -1
        return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {   
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;   
    }
    return item;
}

// Ham tao do thi moi
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;   
        graph->visited[i] = 0;  
    }
    return graph;
}

// Ham them canh vao do thi (dua vao ma tran danh sach ke)
void addEdge(Graph* graph, int src, int dest) {
    // Them canh src -> dest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Them canh dest -> src (neu do thi vo huong)
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Ham duyet do thi theo BFS (Breadth-First Search)
void bfs(Graph* graph, int startVertex) {
    Queue* q = createQueue();   
    graph->visited[startVertex] = 1;  
    enqueue(q, startVertex);   

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);  
        printf("%d ", currentVertex);   

        Node* temp = graph->adjList[currentVertex];  
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {   
                graph->visited[adjVertex] = 1;  
                enqueue(q, adjVertex);   
            }
            temp = temp->next;  
        }
    }
    printf("\n");   
}

int main() {
    int vertices, edges, startVertex;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &vertices);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);
    Graph* graph = createGraph(vertices);

    printf("Nhap danh sach cac canh (d1,d2):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);   
    }

    printf("Nhap dinh bat dau de duyet BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    return 0;
}
