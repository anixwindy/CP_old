//
// Created by user on 2026/3/7.
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
    //這題的限制:每道菜 只能一種胡椒  可撒0~顧客max   <<總庫存
    ll n,m;
    vll v(1005,0);
    vll demandd(1005,0);
    ll total1 =0;
    cin>>n>>m;
    for (ll i = 1; i <= m; ++i) {
        cin>>v[i];//每一種胡椒的庫存量(Max)
    }for (ll j=1;j<=n;++j) {
        ll dash,limit;

        cin>>dash>>limit;//1~n菜  每個菜 胡椒種類--數量
        demandd[dash]+=limit;//陣列i 胡椒  總共多少(最多值，但可灑之值0~max)
    }
    for (ll k = 1; k <= m; ++k) {
        total1+=min(v[k],demandd[k]);
    }cout<<total1<<"\n";


}








int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}