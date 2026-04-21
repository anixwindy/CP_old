//
// Created by user on 2026/1/24.
//

// #include <iostream>
#include <format>
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define fastIO do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

void solve() {
    // 這裡寫邏輯
    int n;
    if (!(cin >> n)) return;
    if (n>2 && n%2==0) {
        cout<<"YES"<< "\n";

    }else cout<<"NO"<< "\n";


}



int main() {
    fastIO; // 呼叫加速代碼

    int t = 1;//<--看情況

    while (t--) {
        solve();
    }
    return 0;
}

/*
* #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    // ============ 解題區 ============
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    // ================================
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  // Watermelon只有一組測資,所以這行註解掉

    while(t--) {
        solve();
    }

    return 0;
}
 */