// Floyd warshall algorithm finds the shortest distances between every pair of nodes in a directed and weighted graph.
// This algorithm is also known as 'All pair shortest path algorithm'.
// The algorithm works in O(V^3) time. Where V is the number of vertices.

#include<bits/stdc++.h>
#define INF 10000
#define v   4 // Number of nodes.
using namespace std;

void floydWarshall(int graph[][v]) {
    int dist[v][v]; // solution matrix.

    // Initialized the solution matrix, dist[][] as same as the input matrix.
    // Now we will work from here and find shortest paths.
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Path relaxation.
    // If distance from node i to node k + distance from node k to node j < distance from node i to node j,
    // then set distance from i to j = distance from i to k + distance from k to j.
    for(int k=0; k<v; k++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Printing the solution matrix.
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            // If dist[i][j](shortest distance from node i to node j) is still INFINITE,
            // then it is impossible to reach from node i to node j.
            if(dist[i][j] == INF)
                cout << "INF" << "\t";
            else 
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // Initial shortest distances of nodes are stored in a matrix.
    // weighted and directed graph.
    // Adjacency matrix representation of a graph.
    // Diagonal values are 0, because shortest distance from one node to itself is 0 !
    int graph[v][v] = { {0, 3, INF, INF},
                        {2, 0, 2, INF},
                        {INF, 5, 0, INF},
                        {20, INF, 8, 0},
                      };              

    floydWarshall(graph);
    
    return 0;
}