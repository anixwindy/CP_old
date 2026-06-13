#include <bits/stdc++.h>
using namespace std;

// ============================================================
// BFS：圖上最短路（無加權）
// CTF 辨認特徵：queue + visited/dist 陣列 + while(!q.empty())
// ============================================================
void bfs_graph() {
    int n = 5;
    vector<vector<int>> adj(n);
    // 建圖：0-1-2-4，0-3-4
    auto addEdge = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(1,2); addEdge(2,4);
    addEdge(0,3); addEdge(3,4);

    vector<int> dist(n, -1);   // -1 = 未訪問
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {        // 還沒訪問過
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "[BFS graph] dist from 0: ";
    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << "\n";
}

// ============================================================
// BFS：2D Grid 最短路
// CTF 辨認特徵：同上，但展開改成上下左右四個方向
// ============================================================
void bfs_grid() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> dist(R, vector<int>(C, -1));
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    queue<pair<int,int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C
                && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << "[BFS grid] (0,0) -> (3,3) = " << dist[3][3] << " steps\n";
}

// ============================================================
// DFS：遞迴版
// CTF 辨認特徵：recursion + visited 陣列，call stack 就是 DFS stack
// ============================================================
vector<bool> vis;
void dfs_recursive(int u, vector<vector<int>>& adj) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!vis[v])
            dfs_recursive(v, adj);
}

// ============================================================
// DFS：迭代版（顯式 stack）
// CTF 辨認特徵：stack<int> + while(!s.empty()) + visited 判斷
// 編譯器最佳化後的 binary 常把遞迴 DFS 轉成這種形式
// ============================================================
void dfs_iterative(int start, int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int u = s.top(); s.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v])
                s.push(v);
    }
    cout << "\n";
}

int main() {
    cout << "=== BFS Graph ===\n";
    bfs_graph();

    cout << "\n=== BFS Grid ===\n";
    bfs_grid();

    // 給 recursive/iterative DFS 用的圖
    int n = 5;
    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(1,2); addEdge(2,4);
    addEdge(0,3); addEdge(3,4);

    vis.assign(n, false);
    cout << "\n=== DFS Recursive ===\n";
    dfs_recursive(0, adj);
    cout << "\n";

    cout << "\n=== DFS Iterative (stack) ===\n";
    dfs_iterative(0, n, adj);

    return 0;
}
