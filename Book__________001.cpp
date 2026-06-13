
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
    //if (!(cin >> s)) return; // 增加輸入的魯棒性




}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start =  chrono::high_resolution_clock::now();
    cout<<"\n--------------------------------------------------"<<'\n';

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
    cout<<"\n--------------------------------------------------"<<'\n';
    // 計算差值
    auto end =  chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}