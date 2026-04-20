//
// Created by user on 2026/2/11.
//Atcoder
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    // ============ 在這裡寫你的解題code ============
    int k;
    cin>>k;
    vc L(k),R(k);
    for (int i = 0; i < k; ++i) {
        cin>>L[i]>>R[i];
    }
    int count = 0;
    //最後面右手無人
    for (int i = 0; i < k-1; ++i) {
        if (R[i]==L[i+1]) count++;
    }
    cout << count << endl;


    // ============================================
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