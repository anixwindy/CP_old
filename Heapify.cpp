//
// Created by user on 2026/2/15.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vbool vector<bool>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    ll k;
    cin>>k;

    vll a(k+1);


    for (int i = 1; i <=k; ++i) {
        cin>>a[i];

    }
    vbool v(k+1,false);//訪問陣列
    bool pozz =true;//預設成功

    for (int i = 1; i <=k; ++i) {
        if (v[i]==true) continue;
        vll pos;//不預設 數量，他是位置
        vll num;//不預設 數量,他是數值
        ll curr =i;
        while (curr<=k) {
            v[curr] = true;
            pos.pb(curr);
            num.pb(a[curr]);
            curr *=2;
        }
        sort(all(pos));
        sort(all(num));
        if (pos!=num) {
            pozz = false;
            break;
        }

    }
    if (pozz == true) {
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;





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