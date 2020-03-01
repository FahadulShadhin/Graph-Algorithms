// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
/*  ## Minimum Spanning Tree ##
    >> Given an undirected and weighted graph.
    >> Prim's algorithm finds a spanning tree of the graph which connects all nodes and the sum of the weight of the edges is minimal.
    >> A spanning tree is a single path in the graph, following which we can reach to any node from any other node.
    >> The spanning tree having the least weight is called a minimum spannning tree.
    >> This algorithm works in O(VlogV+E) time. Where V is the number of nodes and E is the number of edges.
*/
#include<bits/stdc++.h>
#define MAX 1001
#define PII pair<int, int>
using namespace std;

int nodes, edges, u, v, weight;
vector<PII> graph[MAX];
bool visited[MAX];

int prim(int source) {
    memset(visited, false, sizeof visited); // Initially all nodes are unvisited.

    // Min Priority Queue is used to select the cheapest path every time.
    // Inserting the nodes that are connected to growing spanning tree, into the Priority Queue.
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    int minimumCost = 0;

    pq.push( make_pair(0, source) );
    while(!pq.empty()) {
        PII p = pq.top();
        pq.pop();
        int cur = p.second;
        if(visited[cur]) continue; // If already visited, don't visit again.
        minimumCost += p.first;
        visited[cur] = true;

        for(int i=0; i<graph[cur].size(); i++) {
            int next =  graph[cur][i].second;
            if(!visited[next]);
                pq.push( graph[cur][i] );
        }
    }
    return minimumCost;
}

int main() {    
    cout << "Total number of nodes and edges:\n";
    cin >> nodes >> edges;
    cout << "Two nodes having an edge between them and the weight of the edge:\n";
    for(int i=0; i<edges; i++) {
        cin >> u >> v >> weight; // 1 <= u, v <= nodes
        graph[u].push_back( make_pair(weight, v) );
        graph[v].push_back( make_pair(weight, u) );
    }

    int source = 1;
    int minimum_cost = prim(source);
    cout << "Minimum cost:\n";
    cout << minimum_cost << endl;

    return 0;
}
