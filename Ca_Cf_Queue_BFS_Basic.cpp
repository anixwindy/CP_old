#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// CF 裡的 queue 常見用途：BFS。
// BFS 適合處理「一步一步擴散」的問題，例如：
// 1. 無權重圖的最短距離
// 2. 迷宮最少步數
// 3. 一層一層處理節點
//
// queue 的操作：
// push(x)  ：把 x 放到隊伍後面。
// front()  ：看隊伍最前面是誰。
// pop()    ：把最前面的人拿掉。
// empty()  ：判斷隊伍是否空了。

int main() {
    int nodeCount = 5;
    vector<vector<int>> graph(nodeCount + 1);

    // 範例圖：
    // 1 - 2 - 4
    // |   |
    // 3   5
    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[2].push_back(5);
    graph[5].push_back(2);

    vector<int> distance(nodeCount + 1, -1);
    queue<int> waiting;

    int start = 1;
    distance[start] = 0;
    waiting.push(start);

    while (!waiting.empty()) {
        int current = waiting.front();
        waiting.pop();

        for (int next : graph[current]) {
            // distance[next] != -1 代表已經走過，不要重複放進 queue。
            if (distance[next] != -1) {
                continue;
            }

            distance[next] = distance[current] + 1;
            waiting.push(next);
        }
    }

    for (int node = 1; node <= nodeCount; ++node) {
        cout << "從 1 到 " << node << " 的最少邊數是 "
             << distance[node] << '\n';
    }

    return 0;
}

/*
補充說明：
1. queue 是「先進先出」：
   先 push 進去的節點，會先被 front() 取出。
2. BFS 為什麼可以算無權重圖最短距離？
   因為它會先處理距離 0，再處理距離 1，再處理距離 2。
   第一次走到某個節點時，就是最短距離。
3. 手動推導：
   start = 1，distance[1] = 0
   從 1 可以走到 2, 3，所以 distance[2] = 1, distance[3] = 1
   從 2 可以走到 4, 5，所以 distance[4] = 2, distance[5] = 2
4. 預期輸出：
   從 1 到 1 的最少邊數是 0
   從 1 到 2 的最少邊數是 1
   從 1 到 3 的最少邊數是 1
   從 1 到 4 的最少邊數是 2
   從 1 到 5 的最少邊數是 2
5. 自己練習：
   把 start 改成 4，手動推導每個節點距離會怎麼變。
*/
