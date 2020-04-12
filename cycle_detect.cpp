#include<bits/stdc++.h>
#define MAX 101
using namespace std;

// n ---> Numner of nodes
// m ---> Number of edges
int n, m;
vector<int> graph[MAX];
int parent[MAX];

int find(int i) {
    if(parent[i] == -1) 
        return i;
    return find(parent[i]);
}

void Union(int x, int y) {
    int x_set = find(x);
    int y_set = find(y);

    if(x_set != y_set) {
        parent[x_set] = y_set;
    }
}

bool is_cycle() {
    for(int i=1; i<=n; i++) 
        parent[i] = -1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            int u = find(i);
            int v = find(graph[i][j]);

            if(u == v) 
                return true;
            else Union(u, v);
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        //graph[v].push_back(u); // Directed graph...
    }

    if(is_cycle()) cout << "Cycle found\n";
    else cout << "No cycle found\n";

    return 0;

}
