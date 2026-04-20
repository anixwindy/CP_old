//
// Created by user on 2026/1/19.
//
#include <iostream>
#include <format>
#include <vector>
#include <algorithm>
using namespace  std;

void test() {
    int n;
    if (!(cin>>n))return;

    vector<long long> a(n);
    long long max_value =0;

    for (int i = 0; i<n ;++i) {
        cin>>a[i];
        if (a[i]>max_value) {
            max_value = a[i];
        }
    }
    cout<<n * max_value<<endl;
}
//為了速度
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        test();
    }



    return 0;
}