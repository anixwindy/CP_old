<<<<<<< HEAD
//
// Created by user on 2026/2/11.
//Atcoder
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
    // ============ 在這裡寫你的解題code ============
    int nn;
    int kk;
    cin>>nn>>kk;

    ll count1 =0;

    vi a(nn),b(nn),c(nn);

    for (int i = 0; i < nn; ++i) {
        cin>>a[i]>>b[i];
        c[i]=a[i]-b[i];//插植
        count1+=(ll)a[i];//原價總和
    }
    sort(all(c));
    for (int i = 0; i < kk; ++i) {
        count1-=c[nn-1-i];//從nn-1往回
    }
    cout<<count1<<endl;





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
=======
//
// Created by user on 2026/2/11.
//Atcoder
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
    // ============ 在這裡寫你的解題code ============
    int nn;
    int kk;
    cin>>nn>>kk;

    ll count1 =0;

    vi a(nn),b(nn),c(nn);

    for (int i = 0; i < nn; ++i) {
        cin>>a[i]>>b[i];
        c[i]=a[i]-b[i];//插植
        count1+=(ll)a[i];//原價總和
    }
    sort(all(c));
    for (int i = 0; i < kk; ++i) {
        count1-=c[nn-1-i];//從nn-1往回
    }
    cout<<count1<<endl;





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
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}