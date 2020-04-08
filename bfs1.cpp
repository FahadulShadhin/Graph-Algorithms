#include<bits/stdc++.h>
#define MAX 101
using namespace std;

class Graph{
    private:
        int n, e;
        vector<int> graph[MAX];
        bool visited[MAX];
    public:
        void create_graph() {
            cin >> n >> e;
            for(int i=0; i<e; i++) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        void bfs(int source) {
            memset(visited, false, sizeof(visited));
            queue<int>  q;
            q.push(source);
            visited[source] = true;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                cout << cur << " ";
                for(int i=0; i<graph[cur].size(); i++) {
                    int next = graph[cur][i];
                    if(!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
};

int main() {
    Graph g;
    g.create_graph();
    g.bfs(1);
    cout << endl;

    return 0;
}
