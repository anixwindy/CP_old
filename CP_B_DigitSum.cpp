//
// Created by user on 2026/6/12.
//
//
//
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
    int n;
    cin >> n;
    int sum;cin>>sum;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {

        // ← 這裡是你空掉的地方，補上去
        string si = to_string(i);      // 把 i 轉字串
        int ds = 0;
        for (char c : si) {            // 走訪每個字元
            ds += (c - '0');           // 字元 → 數字
        }

        if (ds == sum) cnt++;
    }

    return to_string(cnt);
}







int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;// 如果有複數測資時可以打開
    while (t--) cout << solve() << "\n";
}



