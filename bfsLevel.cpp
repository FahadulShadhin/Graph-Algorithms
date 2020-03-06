// Given an undirected and unweighted graph. We need to find the level of all nodes from the source node.
// This is a slight modification of BFS algorithm.
// The ocncept of level is better understood in trees.
// level of source node is 0. level[children] = level[parent] + 1.

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int nodes, edges, u, v;
vector<int> graph[MAX];
bool visited[MAX];
int level[MAX];
queue<int> q;

void bfsLevel(int source) {
    q.push(source);
    level[source] = 0;
    visited[source] = true;
    while (!q.empty()){
        int cur = q.front();
        printf("node: %d    level: %d\n", cur, level[cur]);
        q.pop();
        for(int i=0; i<graph[cur].size(); i++){
            if(visited[ graph[cur][i] ] == false){
                level[ graph[cur][i] ] = level[cur] + 1;
                q.push( graph[cur][i] );
                visited[ graph[cur][i] ] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &nodes, &edges);
    for(int i=0; i<edges; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited, false, sizeof visited);

    int source = 1;
    bfsLevel(source);

    return 0;
}