// This is an implementation of bfs algorithm in 2d grid.

#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int row, col, sx, sy, dx, dy;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
pair<int, int> p;
queue< pair<int, int> > q;

// Direction array
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

int bfs(int a1, int b1, int a2, int b2) {
    int temp = 0;
    p.first = a1;
    p.second = b1;
    q.push(p);
    visited[a1][b1] = true;

    while(!q.empty()) {
        p = q.front();
        int ux = p.first;
        int uy = p.second;
        q.pop();

        if(ux == a2 && uy == b2) {
            cout << "Shortest path from starting to end:\n" << dist[a2][b2] << "\n";
            temp = 1;
        }
        
        for(int i=0; i<4; i++) {
            int vx = ux + x[i];
            int vy = uy + y[i];

            if((vx>=0 && vx<row) && (vy>=0 && vy<col) && grid[vx][vy] == 0) {
                if(!visited[vx][vy]) {
                    visited[vx][vy] = 1;
                    dist[vx][vy] = dist[ux][uy] + 1;
                    q.push(make_pair(vx, vy));
                }
            }
        }
    }
    if(temp == 0)
        cout << "Not reachable\n";
}

int main() {
    cout << "Number of rows and columns in the grid:\n";
    cin >> row >> col;
    // If grid[i][j] == 0 then path is open, so grid can be traversed through this path.
    // If grid[i][j] == 1 then path is blocked.
    /*
        like:
            1 0 0 1 0
            0 0 1 0 1
            0 0 0 1 0
            1 1 0 1 0
    */
    cout << "2d grid:\n"; 
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> grid[i][j];
        }
    }

    // Starting and destination location must contain 0 in the grid.
    cout << "Starting location:\n";
    cin >> sx >> sy;
    cout << "Destination location:\n";
    cin >> dx >> dy;

    memset(visited, false, sizeof visited); 
    memset(dist, 0, sizeof dist);

    bfs(sx, sy, dx, dy);

    return 0;
}