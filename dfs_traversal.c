#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void DFS(int adjMatrix[MAX][MAX], int vertices, int startVertex, bool visited[]) {
    visited[startVertex] = true;
    printf("%c ", startVertex + 'A');

    for (int i = 0; i < vertices; ++i) {
        if (adjMatrix[startVertex][i] && !visited[i]) {
            DFS(adjMatrix, vertices, i, visited);
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

    bool visited[MAX] = {false};
    int startVertex;
    printf("Enter the start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(adjMatrix, vertices, startVertex, visited);

    return 0;
}
