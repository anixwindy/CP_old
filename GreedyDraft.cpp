<<<<<<< HEAD
//
// Created by user on 2026/2/21.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vbl vector<bool>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    int t;
    int m;

    cin>>t;
    cin>>m;

    vbl is_taken(m+1,false);
    for (int i = 0; i < t; ++i) {
        int Li;
        cin>>Li;
        vi a(Li);//飲料組合
        for (int j = 0; j < Li; ++j) {
            cin>>a[j];
        }

        int ans = 0;//水
        for (int j = 0; j < a.size(); ++j) {
            int juice =a[j];

            if (!is_taken[juice]) {
                ans = juice;
                is_taken[juice] = true;
                break;
            }
        }
        cout<<ans<<"\n";
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
=======
//
// Created by user on 2026/2/21.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vbl vector<bool>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    int t;
    int m;

    cin>>t;
    cin>>m;

    vbl is_taken(m+1,false);
    for (int i = 0; i < t; ++i) {
        int Li;
        cin>>Li;
        vi a(Li);//飲料組合
        for (int j = 0; j < Li; ++j) {
            cin>>a[j];
        }

        int ans = 0;//水
        for (int j = 0; j < a.size(); ++j) {
            int juice =a[j];

            if (!is_taken[juice]) {
                ans = juice;
                is_taken[juice] = true;
                break;
            }
        }
        cout<<ans<<"\n";
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
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}