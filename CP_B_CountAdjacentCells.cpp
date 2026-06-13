//
//
//
//
// Created by user on 2026/6/10.
//
#include <bits/stdc++.h>
 using namespace std;

// 型別縮寫
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// 常用巨集
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb      push_back
#define fi      first
#define se      second

// Yes / No 常數（配合 string solve() 用）
// const string yes = "Yes", no = "No";


string solve() {

    int H,W;
    cin >> H >> W;
    string res="";
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            int neighbors = 0;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 1 && nr <= H && nc >= 1 && nc <= W) {
                    neighbors++;
                }
            }

            // 使用 C++20 std::format 進行漂亮的字串拼接
            // 如果是該行的第一個數字，直接串接；其餘數字前面補空格
            res += std::format("{}{}", (c == 1 ? "" : " "), neighbors);
        }
        // 每處理完一列，就補上換行符號
        res += "\n";
    }

    // 因為你的 main 裡面已經有 cout << solve() << "\n";
    // 為了避免最後輸出多一個空行，我們可以用 pop_back() 把最後一個多出來的 '\n' 削掉
    if (!res.empty()) res.pop_back();

    return res;
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) cout << solve() << "\n";
}


