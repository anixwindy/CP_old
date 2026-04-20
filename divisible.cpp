//
// Created by user on 2026/1/30.
//

#include <bits/stdc++.h>
#include <format>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    // ============ 在這裡寫你的解題code ============

    int n;
    cin >> n;

    vi a(105);
    int left  =1 ;
    int right =n;
    bool flag1=true;//開關 確認左右
    for (int i=n-1;i>=0;i--) {
        if (flag1) {
            a[i]=right;
            right--;
        }else {
            a[i]=left;
            left++;
        }flag1=!flag1;//抓完大換小，抓完小換大
    }
    for (int j=0;j<n;j++) {
        cout<<a[j]<<" ";
    }cout<<endl;





    // ============================================
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}