#include <iostream>
#include <vector>
using namespace std;

// Codeforces 的 tree 題目，通常不是用「節點指標」建立樹。
// 更常見的是 adjacency list：
// graph[x] 裡面放所有和 x 相連的節點。
// 因為 tree 的邊是雙向的，所以 a-b 要存兩次：
// graph[a].push_back(b);
// graph[b].push_back(a);

void dfs(int node, int parent, int depth, const vector<vector<int>>& graph) {
    cout << "節點 " << node
         << "，父節點 " << parent
         << "，深度 " << depth << '\n';

    for (int next : graph[node]) {
        // tree 沒有「左子樹 / 右子樹」的固定方向。
        // 為了避免從子節點又走回父節點，要跳過 parent。
        if (next == parent) {
            continue;
        }

        dfs(next, node, depth + 1, graph);
    }
}

int main() {
    int nodeCount = 5;
    vector<vector<int>> graph(nodeCount + 1);

    // 範例樹：
    // 1 連到 2, 3
    // 2 連到 4, 5
    int edgeA[4]{1, 1, 2, 2};
    int edgeB[4]{2, 3, 4, 5};

    for (int i = 0; i < 4; ++i) {
        int a = edgeA[i];
        int b = edgeB[i];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 從 1 當根開始走。
    // parent 用 0 表示「根節點沒有父節點」。
    dfs(1, 0, 0, graph);

    return 0;
}

/*
補充說明：
1. Codeforces 的 tree 題常見輸入長這樣：
   n
   a1 b1
   a2 b2
   ...
   總共有 n - 1 條邊。
2. 解題時通常先把邊存成 adjacency list，而不是建立 Node* left/right。
3. 為什麼 DFS 要傳 parent？
   因為 tree 的邊是雙向存的。
   例如 1-2 會讓 graph[1] 有 2，也讓 graph[2] 有 1。
   如果不跳過 parent，程式會從 1 走到 2，又從 2 走回 1。
4. 手動推導執行流程：
   dfs(1, 0, 0)
   走到 2，變成 dfs(2, 1, 1)
   走到 4，變成 dfs(4, 2, 2)
   回到 2，再走到 5，變成 dfs(5, 2, 2)
   回到 1，再走到 3，變成 dfs(3, 1, 1)
5. 預期輸出順序和 push_back 的順序有關：
   節點 1，父節點 0，深度 0
   節點 2，父節點 1，深度 1
   節點 4，父節點 2，深度 2
   節點 5，父節點 2，深度 2
   節點 3，父節點 1，深度 1
6. 自己練習：
   把範例邊改成 1-2, 1-3, 3-4, 3-5，觀察深度如何改變。
*/
