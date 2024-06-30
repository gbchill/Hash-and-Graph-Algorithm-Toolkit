#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <cstring> // For memset

#define MAX_VERTICES 130 // Define the maximum number of vertices in the graph

// Function to print the adjacency matrix of the graph
void printAdjacencyMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int n)
{
    std::cout << "\nThe adjacency matrix of G:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

// Function to print vertices with an odd degree
void printOddDegreeVertices(int degrees[MAX_VERTICES], int n)
{
    std::cout << "The odd degree vertices in G:\nO = { ";
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (degrees[i] % 2 != 0)
        {
            if (!first)
                std::cout << " ";
            std::cout << i + 1;
            first = false;
        }
    }
    std::cout << " }\n";
    std::cout << "\n";
}

// Dijkstra's algorithm to find the shortest path from a given source vertex
void dijkstra(int matrix[MAX_VERTICES][MAX_VERTICES], int n, int src)
{
    int dist[MAX_VERTICES];                  // distance from source to each vertex
    bool processed[MAX_VERTICES];            // array to track processed vertices
    memset(processed, 0, sizeof(processed)); // initialize processed array

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    // main loop to process all vertices
    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!processed[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        processed[u] = true;

        // update the distance for each adjacent vertex
        for (int v = 0; v < n; v++)
        {
            if (!processed[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1; // using weight of 1 for each edge
            }
        }
    }

    // print the shortest path lengths from the source
    std::cout << "Single source shortest path lengths from node " << src + 1 << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "  " << i + 1 << ": " << dist[i] << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <graph.txt>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }

    int n, m;
    file >> n >> m;

    if (n >= MAX_VERTICES) // check if the number of vertices exceeds the limit
    {
        std::cerr << "Error: Number of vertices exceeds the maximum limit.\n";
        return 1;
    }

    int matrix[MAX_VERTICES][MAX_VERTICES] = {0}; // adjacency matrix
    int degrees[MAX_VERTICES] = {0};              // degree of each vertex

    // read edges from file and populate the matrix and degrees array
    for (int i = 0; i < m; i++)
    {
        int u, v;
        file >> u >> v;
        u--;
        v--;
        matrix[u][v]++;
        matrix[v][u]++;
        degrees[u]++;
        degrees[v]++;
    }

    file.close();

    // output the adjacency matrix and the odd degree vertices
    printAdjacencyMatrix(matrix, n);
    printOddDegreeVertices(degrees, n);

    // compute shortest paths from each odd degree vertex
    for (int i = 0; i < n; i++)
    {
        if (degrees[i] % 2 != 0)
        {
            dijkstra(matrix, n, i);
        }
    }

    return 0;
}
