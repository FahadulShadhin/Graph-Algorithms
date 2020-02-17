/*
 >> Given an undirected and unweighted graph. 
    This algorithm finds the breath first search(BFS) traversal of the graph starting from a source node. 
 >> We can also find the shortest path of every node from the source node. 
 >> Parent of a node can also be found from the algorithm.
 >> The algorithm works in O(V+E) time, where V is number of vertices(nodes) and E is the number of edges.
*/

#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

vector<int> graph[MAX]; // Adjacency list representation of the graph.
queue<int> q;
bool visited[MAX]; // Checks a node is visited or not.
int dist[MAX]; // Stores the distance of a node from source node.
int parent[MAX]; // Stores parent node of a node.

void PRINT_GRAPH(int node) {
    cout << node << " ";
}

void bfs(int source) {
    q.push(source);
    visited[source] = true; // Source node is now visited.
    parent[source] = -1; // Source does not have any parent.

    while (!q.empty()) {
        // Pop the front node from the queue and show it as output.
        int cur = q.front();
        q.pop();
        PRINT_GRAPH(cur);

        // Traverse all nodes directly connected with the current node(cur) one by one...
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];

            // If node 'next' is not visited before then push it to stack and mark it as visited.
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                dist[next] = dist[cur] + 1; // Shortest path from source node.
                parent[next] = cur; // Parent of 'next' is 'cur'.
            }
        }
    }
} 

int main() {
    int nodes, edges;
    cout << "Total nodes in the graph: \n";
    cin >> nodes;
    cout << "Total edges in the graph: \n";
    cin >> edges;

    cout << "Two nodes which contains an edge between them: \n";
    for(int i=0; i<edges; i++) {
        int u, v;
        cin >> u >> v; // 1 <= u,v <= nodes.
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph.
    }

    memset(visited, false, sizeof visited); // Initially no node is visited.

    int source = 1;

    cout << "BFS traversal of the graph: ";
    bfs(source);
    cout << "\n\n";

    cout << "Shortest path of a node from source node: ";
    for(int i=1; i<=nodes; i++) 
        cout << dist[i] << " ";
    cout << "\n\n";

    cout << "parent of a node: \n";
    for(int i=1; i<=nodes; i++)
        cout <<"Parent of node " << i << " is " << parent[i] << "\n";
    cout << endl;

    return 0;
}