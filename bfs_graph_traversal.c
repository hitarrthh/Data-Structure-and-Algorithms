#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void BFS(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%c ", currentVertex+'A');

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(adjMatrix, vertices, startVertex);

    return 0;
}
