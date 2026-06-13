//
// Created by user on 2026/6/10.
//
#include <cctype>
#include <string>
#include <algorithm>
#include <ranges>


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
int solve() {
    string a;
    string b;
    cin >> a >> b;


    transform(a.begin(), a.end(), a.begin(), [](unsigned char c1){
        return std::tolower(c1);
    });
    transform(b.begin(), b.end(), b.begin(), [](unsigned char c2 ){
        return std::tolower(c2);
    });


  if (a == b) return 0;
  else if (a>b) return 1;
  else return -1;




}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;


    while(t--) {
        cout << solve() << "\n";

    }

    return 0;
}