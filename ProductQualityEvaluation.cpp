<<<<<<< HEAD
//
// Created by user on 2026/2/11.
//atcoder trytry
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
    ll nn;
    ll k;
    ll ans=0;
    cin>>nn;
    cin >>k;
    ll s,r;

    for (int i = 0; i < nn; i++) {
        cin >> s >> r;
        if (s*r>=k) {
            ans++;
        }
    }cout<<ans<<endl;


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
=======
//
// Created by user on 2026/2/11.
//atcoder trytry
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
    ll nn;
    ll k;
    ll ans=0;
    cin>>nn;
    cin >>k;
    ll s,r;

    for (int i = 0; i < nn; i++) {
        cin >> s >> r;
        if (s*r>=k) {
            ans++;
        }
    }cout<<ans<<endl;


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
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
