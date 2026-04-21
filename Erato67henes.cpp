<<<<<<< HEAD
//
// Created by user on 2026/2/15.
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

    int k;
    cin>>k;
    vi a(k);

    bool flag = false;//沒看到
    for (int i = 0; i <k; ++i) {
        cin>>a[i];
        if (a[i]==67) {
            flag = true;
        }
    }
    //迴圈離開 有沒有找到
    if (flag) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }



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
=======
//
// Created by user on 2026/2/15.
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

    int k;
    cin>>k;
    vi a(k);

    bool flag = false;//沒看到
    for (int i = 0; i <k; ++i) {
        cin>>a[i];
        if (a[i]==67) {
            flag = true;
        }
    }
    //迴圈離開 有沒有找到
    if (flag) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }



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
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}