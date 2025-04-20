//Program in C for Breadth First Search Traversal (BFS)
#include <stdio.h>
#include <stdlib.h>
// Structure for a node in adjacency list
struct Node 
{
    int dest;
    struct Node* next;
};
// Structure for adjacency list
struct AdjList 
{
    struct Node* head;
};
// Structure for a graph
struct Graph 
{
    int V;
    struct AdjList* array;
};
// Function to create a new node
struct Node* newNode(int dest) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph with V vertices
struct Graph* createGraph(int V) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    // Create an array of adjacency lists. Size of array will be V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}
// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) 
{
    // Add an edge from src to dest
    struct Node* newNode1 = newNode(dest);
    newNode1->next = graph->array[src].head;
    graph->array[src].head = newNode1;
    // Since graph is undirected, add an edge from dest to src also
    struct Node* newNode2 = newNode(src);
    newNode2->next = graph->array[dest].head;
    graph->array[dest].head = newNode2;
}
// Function to perform Breadth First Search traversal of the graph
void BFS(struct Graph* graph, int startVertex) 
{
    // Array to keep track of visited vertices
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;
    // Create a queue for BFS
    int queue[graph->V];
    int front = 0, rear = 0;
    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) 
    {
        // Dequeue a vertex from queue and print it
        int vertex = queue[front++];
        printf("%d ", vertex);
        // Get all adjacent vertices of the dequeued vertex vertex. If an adjacent vertex has not been visited, mark it visited and enqueue it
        struct Node* temp = graph->array[vertex].head;
        while (temp != NULL) 
        {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) 
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    free(visited);
}
int main() 
{
    int V, E, src, dest;
    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    // Create a graph with V vertices
    struct Graph* graph = createGraph(V);
    // Input edges
    for (int i = 0; i < E; i++) 
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    // Input the start vertex for BFS traversal
    int startVertex;
    printf("Enter the start vertex for BFS traversal: ");
    scanf("%d", &startVertex);
    printf("Breadth First Search Traversal starting from vertex %d: ", startVertex);
    BFS(graph, startVertex);
    printf("\n");
    return 0;
}
