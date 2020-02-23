// This is an implementation of Bellman-Ford algorithm.
// This algorithm finds the shortest paths from a source node to all other nodes.
// The algorithm also detects negative cycle in a graph.

#include<bits/stdc++.h>
#define MAX      1001
#define INFINITE INT_MAX
using namespace std;

int nodes, edges;
int dist[MAX], edge_u[MAX], edge_v[MAX], edge_weight[MAX];

void bellman_ford(int source) {
    dist[source] = 0;
    bool negative_cycle = false;

    for(int step = 1; step<=nodes; step++) {
        bool flag = false;
        for(int i=0; i<edges; i++) {
            int u = edge_u[i];
            int v = edge_v[i];
            int weight = edge_weight[i];

            if(dist[u] + weight < dist[v]) {
                flag = true;
                if(step == nodes) 
                    negative_cycle = true;
                dist[v] = dist[u] + weight;
            }
        }  
        if(flag == false)
            break; 
    }

    if(negative_cycle == false) {
        cout << "shortest path:\n";
        for(int i=1; i<=nodes; i++)
            cout << i << " " << dist[i] << "\n";
    } 
    else
        cout << "Negative cycle detected\n"; 
}

int main() {
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) 
        cin >> edge_u[i] >> edge_v[i] >> edge_weight[i];

    for(int i=1; i<=nodes; i++)
        dist[i] = INFINITE;
    
    int source = 1;
    bellman_ford(source);

    return 0;
}