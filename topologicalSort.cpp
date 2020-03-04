#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int nodes, edges, u, v;
vector<int> graph[MAX];
bool visited[MAX];
int in_degree[MAX];

void topologicalSort() {
    memset(visited, false, sizeof visited);
    vector<int> T;
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
            if(visited[graph[cur][i]] == false) {
                in_degree[graph[cur][i]] = in_degree[graph[cur][i]] - 1;
                if(in_degree[graph[cur][i]] == 0) {
                    q.push(graph[cur][i]);
                    visited[graph[cur][i]] = true;
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
    scanf("%d %d", &nodes, &edges);
    for(int i=0; i<edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        //graph[v].push_back(u); // directed graph.
        in_degree[v]++;
    }

    topologicalSort();
    return 0;
}