<<<<<<< HEAD
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
    int a;
    int maxx=0;
    cin>>a>>maxx;
    vi b(a);

    for (int i = 0; i < a; ++i) {
        cin>>b[i];
        if (b[i]<maxx) {
            maxx=b[i];
            cout<<1<<"\n";
        }else  {
             cout<<0<<"\n";
        }
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
    int a;
    int maxx=0;
    cin>>a>>maxx;
    vi b(a);

    for (int i = 0; i < a; ++i) {
        cin>>b[i];
        if (b[i]<maxx) {
            maxx=b[i];
            cout<<1<<"\n";
        }else  {
             cout<<0<<"\n";
        }
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