/*
 >> Given an undirected or directed weighted graph. Weights of all edges are non-negative.
 >> Dijkstra algorithm finds the lengths of the shortest paths from a starting node(source node) to all other nodes.
 >> This algorithm fails when a graph contains negative cycle. 
 >> This algorithm is also known as 'single source shortest path problem'. 
 >> Complexity:
    Dijkstra algorithm is based on bfs appraoch. Bfs algorithm works in O(V+E) time. Where V is the number of vertices(nodes)
    and E is the number of edges. In Dijkstra algorithm priority queue takes extra O(logV) time to sort the nodes 
    every time. So, the complexity of Dijkstra alagorithm is O(VlogV + E).
*/

#include<bits/stdc++.h>
#define MAX      1001
#define INFINITE INT_MAX
#define PII      pair<int, int>
using namespace std;

int nodes, edges, u, v, cost;
vector<PII> graph[MAX]; // Adjacency list representation of the graph.
int dist[MAX]; // Array to store the distance from source node.

void PRINT_SHORTEST_PATH(int source) {
    for(int i=1; i<=nodes; i++) {
        if(i == source) // No need to print shortest path of source node.
            continue; 
        else
            cout << "Shortest path of " << i << " from " << source << " is " << dist[i] << "\n";
    }
    cout << endl;
}

void dijkstra(int source) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    pq.push(make_pair(0, source)); 
    dist[source] = 0; // Distance of source node is zero.

    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].second;
            int cost = graph[cur][i].first;

            /* Path/edge relaxation:
                If distance(u) + cost(u to v) < distance(v), then update distance(v) to distance(u) + cost(u to v).
            */
            if(dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    PRINT_SHORTEST_PATH(source);
}

int main() {
    cout << "Total nodes in the graph: \n";
    cin >> nodes;
    cout << "Total edges in the graph: \n";
    cin >> edges;

    cout << "Two nodes which contains an edge between them and cost of the edge:\n";
    for(int i=0; i<edges; i++) {
        cin >> u >> v >> cost; // 1 <= u,v <= nodes.
        graph[u].push_back(make_pair(cost, v));
        graph[v].push_back(make_pair(cost, u)); // For undirected graph.
    }

    // Initially distance of all nodes are set to infinity.
    for(int i=1; i<=nodes; i++) {
        dist[i] = INFINITE;
    }

    int source = 1;
    cout << "Shortest paths(lowest cost):\n";
    dijkstra(source);

    return 0;
}
