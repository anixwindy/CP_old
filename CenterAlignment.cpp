<<<<<<< HEAD
//
// Created by user on 2026/2/14.
//
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second


void solve() {
    int t;
    cin>>t;
    vs s(t);
    int large =0;

    for (int i = 0; i < t; i++) {
        cin>>s[i];
        large =max(large,(int)s[i].size());//比大小
    }
    for (int i = 0; i < t; i++) {
        int space = (large - (int)s[i].size())/2;//左右
        cout<<string(space,'.')<<s[i]<<string(space,'.')<<endl;
    }






}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--) {
        solve();
    }
    return 0;
=======
//
// Created by user on 2026/2/14.
//
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second


void solve() {
    int t;
    cin>>t;
    vs s(t);
    int large =0;

    for (int i = 0; i < t; i++) {
        cin>>s[i];
        large =max(large,(int)s[i].size());//比大小
    }
    for (int i = 0; i < t; i++) {
        int space = (large - (int)s[i].size())/2;//左右
        cout<<string(space,'.')<<s[i]<<string(space,'.')<<endl;
    }






}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--) {
        solve();
    }
    return 0;
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}