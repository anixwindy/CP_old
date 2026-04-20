//
// Created by user on 2026/2/22.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    ll n,k,l;
    cin>>n>>k>>l;
    vll a(n);

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(all(a));

    // 理科條例：初始的外部空間 (距離兩側邊界的距離)
    ll g0 = a[0];
    ll gN = l - a[n - 1];

    // 程式邏輯：收集並排序所有「內部間隙」
    vll gaps;
    for (int i = 0; i < n - 1; ++i) {
        gaps.push_back(a[i + 1] - a[i]);
    }
    sort(gaps.rbegin(), gaps.rend());

    // 前綴和：用來快速計算「前 m 大的間隙總和」
    vll pref(gaps.size() + 1, 0);
    for (size_t i = 0; i < gaps.size(); ++i) {
        pref[i + 1] = pref[i] + gaps[i];
    }

    ll ans = 0;
    ll max_m = min(k, n - 1); // 最多只能消除 min(K, N-1) 個間隙

    // 枚舉：我們要花 m 個誘餌去「內部捏合」，剩下的 K-m 個誘餌拿來「外部折返跑」
    for (ll m = 0; m <= max_m; ++m) {
        if (m == k) {
            // 所有誘餌都拿去捏合了，沒有剩餘次數可以折返跑
            ans = max(ans, pref[m] / 2);
        } else {
            ll c = k - m; // 剩下的誘餌拿來折返跑

            // 策略一：第一步先往左邊 (0) 跑
            ll t0 = c * g0 + (c - 1) * gN + c * pref[m];

            // 策略二：第一步先往右邊 (L) 跑
            ll tL = (c - 1) * g0 + c * gN + c * pref[m];

            ans = max({ans, t0, tL});
        }
    }
    cout << ans << "\n";
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}