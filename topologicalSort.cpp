/*
  >> Given a Directed Acyclic Graph(DAG). Topological sorting for a DAG is ordering the nodes in such a way that for
     a directed edge uv, node u comes before node v in the ordering.
  >> Topological sort is only possibls in a DAG.
  >> This algorithm works in O(V+E) time. Where V is the number of nodes and E is the number of edges.
*/

#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int nodes, edges, u, v;
vector<int> graph[MAX];
bool visited[MAX];
int in_degree[MAX]; // Array to store in_degree of a node.

void topologicalSort() {
    memset(visited, false, sizeof visited);
    vector<int> T; // Topsort ordering array.
    queue<int> q;

    for(int i=1; i<=nodes; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        T.push_back(cur);
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(visited[next] == false) {
                in_degree[next] = in_degree[next] - 1;
                if(in_degree[next] == 0) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }

    printf("Topological sort: \n");
    for(int i=0; i<T.size(); i++) 
        printf("%d ", T[i]);
    printf("\n");
}

int main() {
    cout << "Number of nodes and edges:\n";
    cin >> nodes >> edges;
    cout << "Directed edges between two nodes:\n";
    for(int i=0; i<edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        //graph[v].push_back(u); // directed graph.
        in_degree[v]++;
    }

    topologicalSort();
    return 0;
}
