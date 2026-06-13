#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1D DP：最少硬幣數（Coin Change）
// CTF 辨認特徵：一維陣列 + 單層 loop + 往前看舊值更新
// 模式：dp[i] = f(dp[i - something])
// ============================================================
void coin_change() {
    int amount = 11;
    vector<int> coins = {1, 3, 4};

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // base case：湊出 0 需要 0 枚

    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (i >= c && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c] + 1);

    cout << "[Coin Change] amount=" << amount << " => " << dp[amount] << " coins\n";
}

// ============================================================
// 1D DP：最長遞增子序列（LIS）
// CTF 辨認特徵：一維陣列 + 雙層 loop + 條件式更新
// 模式：dp[i] = max over all j<i where arr[j]<arr[i]
// ============================================================
void lis() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = arr.size();

    vector<int> dp(n, 1);  // 每個元素自己就是長度 1 的子序列

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << "[LIS] = " << *max_element(dp.begin(), dp.end()) << "\n";
}

// ============================================================
// 2D DP：Grid 最小路徑和
// CTF 辨認特徵：二維陣列 + 雙層 loop + 依賴左格或上格
// 模式：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost
// ============================================================
void grid_min_path() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int R = grid.size(), C = grid[0].size();

    vector<vector<int>> dp(R, vector<int>(C, 0));
    dp[0][0] = grid[0][0];

    // 填第一行（只能從左來）
    for (int j = 1; j < C; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    // 填第一列（只能從上來）
    for (int i = 1; i < R; i++) dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int i = 1; i < R; i++)
        for (int j = 1; j < C; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

    cout << "[Grid Min Path] = " << dp[R-1][C-1] << "\n";
}

// ============================================================
// 2D DP：0/1 背包（Knapsack）
// CTF 辨認特徵：二維陣列 + 雙層 loop + 選或不選兩個來源
// 模式：dp[i][w] = max(不選: dp[i-1][w], 選: dp[i-1][w-wt]+val)
// ============================================================
void knapsack() {
    int W = 5;
    vector<int> weight = {2, 3, 4};
    vector<int> value  = {3, 4, 5};
    int n = weight.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];  // 不選第 i 個物品
            if (w >= weight[i-1])
                dp[i][w] = max(dp[i][w], dp[i-1][w-weight[i-1]] + value[i-1]);
        }

    cout << "[Knapsack] max value = " << dp[n][W] << "\n";
}

int main() {
    cout << "=== 1D DP: Coin Change ===\n";
    coin_change();

    cout << "\n=== 1D DP: LIS ===\n";
    lis();

    cout << "\n=== 2D DP: Grid Min Path ===\n";
    grid_min_path();

    cout << "\n=== 2D DP: 0/1 Knapsack ===\n";
    knapsack();

    return 0;
}
