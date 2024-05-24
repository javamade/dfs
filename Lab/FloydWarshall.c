#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to perform Floyd-Warshall algorithm to find shortest paths between all pairs of vertices
void floydWarshall(int graph[V][V]) {
    int dist[V][V]; // 2D array to store the shortest distances between every pair of vertices

    // Initialize the distance array with the values from the graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update the distance
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path distances between every pair of vertices with row and column labels
    printf("Shortest path distances between every pair of vertices:\n");
    printf("    ");
    for (int j = 0; j < V; j++) {
        printf("%3d ", j); // Column labels (destination vertices)
    }
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%3d ", i); // Row label (source vertex)
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%3d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Driver program to test the Floyd-Warshall algorithm
int main() {
    // Example graph represented by adjacency matrix (use INT_MAX for unreachable edges)
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    // Apply Floyd-Warshall algorithm to find shortest paths between all pairs of vertices
    floydWarshall(graph);

    return 0;
}
