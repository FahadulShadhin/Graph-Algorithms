/*
 >> Given an undirected and unweighted graph.
    This algorithm finds the depth first search(DFS) traversal of the graph starting from a source node.
 >> The algorithm works in O(V+E) time. Where V is the number of vertices(nodes) and E is the number of edges.  
*/

#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int nodes, edges;
vector<int> graph[MAX]; // adjacency list representation of the graph.
bool visited[MAX]; // Checks if a node is visited or not.

void PRINT_GRAPH(int node) {
    cout << node << " ";
}

void dfs(int source) {
    visited[source] = true; // Source node is now visited.
    PRINT_GRAPH(source);

    // Traverse all nodes directly connected with the current node(source) one by one...
    for(int i=0; i<graph[source].size(); i++) {
        int next = graph[source][i];
        if(!visited[next])
            dfs(next); // Recursive call of function dfs.

        if(!visited[next]) 
            PRINT_GRAPH(next);
    }
}

int main() {
    cout << "Total number of nodes:\n";
    cin >> nodes;
    cout << "Total number of edges:\n";
    cin >> edges;

    int u, v;
    cout << "Two nodes which contains an edge between them: \n";
    for(int i=0; i<edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph.
    }

    memset(visited, false, sizeof visited); // Initially all nodes are unvisited.

    int source = 1;

    cout << "\nDFS traversal of the graph:\n";
    dfs(source);
    cout << endl;

    return 0;
}