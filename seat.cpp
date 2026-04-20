//
// Created by user on 2026/2/28.
//簡單

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

    int n,m;
    cin>>n>>m;
    if (n%2 == 0) {
        if ((n/2)>=m) cout<<"Yes";
        else cout<<"No";
    }if (n%2 != 0) {
        if (((n+1)/2)>=m) cout<<"Yes";
        else cout<<"No";
    }



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