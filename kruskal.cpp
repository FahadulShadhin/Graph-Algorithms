// Minimum Spanning Tree usnig Kruskal's algorithm.
// Time Complexity: O(ElogE) or O(ElogV). Where V is the number of nodes and E is the number of edges.

#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int id[MAX], nodes, edges;
pair<int, pair< int, int>> graph[MAX];

// Disjoint-Set portion ////////
void make_set(){
    for(int i=0; i<MAX; i++)
        id[i] = i;
}

int find(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void Union(int x, int y){
    int p = find(x);
    int q = find(y);
    id[p] = id[q];
}
/////////////////////////////////

int kruskal(pair<int, pair<int, int>> graph[]){
    int cost, minimumCost = 0;
    for(int i=0; i<edges; i++){
        // selecting edges one by one in increasong order from the beginning
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        cost = graph[i].first;

        // check if the selected edge is creating a cycle or not
        if(find(x) != find(y)){
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
}

int main() {
    int weight, cost, minimumCost;
    make_set();
    cout << "TOtal nodes in the graph: ";
    cin >> nodes;
    cout << "Total edges in the graph: ";
    cin >> edges;

    cout << "Two nodes having an edge between them and the cost of the path:\n";
    for(int i=0; i<edges; i++){
        int x, y;
        cin >> x >> y >> weight;
        graph[i] = make_pair(weight, make_pair(x, y));
    } 
    // sort the edges in the ascending order
    sort(graph, graph+edges);
    minimumCost = kruskal(graph);
    cout << "Minimum Cost: " << minimumCost << endl;

    return 0;
}
