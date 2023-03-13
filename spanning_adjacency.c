#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

int main()
{
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // initialize adjacency matrix to all 0s
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    // read edges and weights from user input and update adjacency matrix
    for (int i = 0; i < num_edges; i++)
    {
        int vertex1, vertex2, weight;
        printf("Enter edge %d and its weight: ", i + 1);
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        adj_matrix[vertex1][vertex2] = weight;
        adj_matrix[vertex2][vertex1] = weight;
    }

    // initialize variables for Prim's algorithm
    int visited[MAX_VERTICES] = {0};
    int key_values[MAX_VERTICES];
    int parent_vertices[MAX_VERTICES];

    // set all key values to infinity and parent vertices to NULL
    for (int i = 0; i < num_vertices; i++)
    {
        key_values[i] = INT_MAX;
        parent_vertices[i] = -1;
    }

    // start from vertex 0
    key_values[0] = 0;

    // construct minimum spanning tree
    for (int i = 0; i < num_vertices - 1; i++)
    {
        // find vertex with minimum key value that is not visited
        int min_key = INT_MAX;
        int min_vertex = -1;
        for (int j = 0; j < num_vertices; j++)
        {
            if (!visited[j] && key_values[j] < min_key)
            {
                min_key = key_values[j];
                min_vertex = j;
            }
        }

        // add vertex to visited set
        visited[min_vertex] = 1;

        // update key values and parent vertices for adjacent vertices
        for (int j = 0; j < num_vertices; j++)
        {
            if (!visited[j] && adj_matrix[min_vertex][j] && adj_matrix[min_vertex][j] < key_values[j])
            {
                key_values[j] = adj_matrix[min_vertex][j];
                parent_vertices[j] = min_vertex;
            }
        }
    }

    // print the minimum spanning tree
    printf("Minimum spanning tree:\n");
    for (int i = 1; i < num_vertices; i++)
    {
        printf("%d - %d\n", parent_vertices[i], i);
    }

    return 0;
}
