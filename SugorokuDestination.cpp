//
// Created by user on 2026/2/14.
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

    int t;
    cin>>t;
    vi a(t+1);
    for (int i = 1; i <= t; i++) {
        cin>>a[i];
    }
    vi  s1(t+1);
    for (int i =t ;i>=1;i--) {
        if (a[i]==i) {
            s1[i]=i;
        }else {
            s1[i]=s1[a[i]];
        }
    }
    for (int i = 1; i <= t; i++) {
        cout<<s1[i];
        if (i<t) {
            cout<<" ";
        };
    }
    cout<<endl;



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