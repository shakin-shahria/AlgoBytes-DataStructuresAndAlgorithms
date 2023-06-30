#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100


typedef struct Graph {
  int numVertices;
  int *visited;
  int **adj;
  int *parent;
} Graph;





  Graph *createGraph(int n) {
  Graph*  graph = malloc(sizeof(Graph));
  graph->numVertices = n;
  graph->visited = malloc(n * sizeof(int));
  graph->adj = malloc(n * sizeof(int *));
  graph->parent = malloc(n * sizeof(int));



  for (int i = 0; i < n; i++) {
    graph->visited[i] = 0;
    graph->adj[i] = malloc(n * sizeof(int));
    graph->parent[i] = -1;
    for (int j = 0; j < n; j++) {
      graph->adj[i][j] = 0;
    }
  }

  return graph;
}


void addEdge(Graph *graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
  // bfs search
  void bfs(Graph *graph, int s) {
  int queue[MAX_VERTICES];
  int front = 0;
  int rear = 0;

  queue[rear] = s;
  rear++;

  while (front < rear) {
    int u = queue[front];
    front++;

    if (graph->visited[u] == 1) {
      continue;
    }

    graph->visited[u] = 1;

    for (int v = 0; v < graph->numVertices; v++) {
      if (graph->adj[u][v] == 1 && graph->visited[v] == 0) {
        queue[rear] = v;
        rear++;
        graph->parent[v] = u; // update parent of vertex v
      }
    }
  }
}

int main(void) {
  Graph *graph = createGraph(5);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 0);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 3);

  bfs(graph, 2);

  // print parent of each vertex
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Parent of vertex %d: %d\n", i, graph->parent[i]);
  }

  return 0;
}
