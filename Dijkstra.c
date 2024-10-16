#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int src, int dest) {
    int dist[MAX];
    int visited[MAX];
    int parent[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        for (int v = 0; v < n; v++)
            if (visited[v] == 0 && dist[v] <= min)
                min = dist[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Distance from %d to %d: %d\n", src, dest, dist[dest]);
    printf("Path: ");
    int path[MAX], path_size = 0;
    for (int v = dest; v != -1; v = parent[v])
        path[path_size++] = v;

    for (int i = path_size - 1; i > 0; i--)
        printf("%d <", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (enter 0 if no direct path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src, dest;
    printf("Enter the source city (0 to %d): ", n - 1);
    scanf("%d", &src);
    printf("Enter the destination city (0 to %d): ", n - 1);
    scanf("%d", &dest);

    dijkstra(graph, n, src, dest);

    return 0;
}
