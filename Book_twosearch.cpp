//
// Created by user on 2026/5/11.
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

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢位寫法

        if (arr[mid] == target)  return mid;        // 找到
        else if (arr[mid] < target) left = mid + 1; // 去右半
        else                    right = mid - 1;    // 去左半
    }
    return -1;
}

// ▶ 範例 2：lower_bound — 找第一個 >= target 的位置
//   （C++ STL 也有 std::lower_bound，這裡手寫理解原理）
int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) left  = mid + 1;
        else                   right = mid;
    }
    return left;
}

// ▶ 範例 3：二分法應用 — 找平方根（整數版）
int mySqrt(int x) {
    if (x == 0) return 0;
    int left = 1, right = x, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid * mid <= x) { ans = mid; left  = mid + 1; }
        else                {             right = mid - 1; }
    }
    return ans;
}

void demo_binary_search() {
    cout << "===== 一、二分法 =====\n";

    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    cout << "陣列: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "找 23 → 索引: " << binarySearch(arr, 23) << "\n";  // 5
    cout << "找 50 → 索引: " << binarySearch(arr, 50) << "\n";  // -1

    vector<int> arr2 = {1, 3, 3, 5, 7, 9};
    cout << "第一個 >= 3 的位置: " << lowerBound(arr2, 3) << "\n"; // 1
    cout << "第一個 >= 4 的位置: " << lowerBound(arr2, 4) << "\n"; // 3

    cout << "sqrt(25) = " << mySqrt(25) << "\n";  // 5
    cout << "sqrt(8)  = " << mySqrt(8)  << "\n";  // 2
    cout << "\n";
}




void solve() {




}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    demo_binary_search();
    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}