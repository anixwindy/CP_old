//
// Created by user on 2026/5/2.
//
//

#include <iostream>

#include <array>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cctype>
#include <chrono>
#include <format>
#include <iomanip>
#include <limits>
#include <memory>
#include <map>
#include <unordered_map>
#include <numbers>
#include <ranges>
#include <string>
#include <vector>

using namespace std;



int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n--------------------------------------------------"<<'\n';
    cout << string(50, '-') << endl;

//Lambda

        cout << "=== 1. 基本 lambda ===\n";

        auto sayHello = []() {
            cout << "Hello lambda\n";
        };

        sayHello();

        cout << "\n=== 2. lambda 帶參數與回傳值 ===\n";

        auto add = [](int a, int b) {
            return a + b;
        };

        cout << "add(3, 5) = " << add(3, 5) << '\n';

        cout << "\n=== 3. 值捕獲 [x] ===\n";

        int x = 10;

        auto printByValue = [x]() {
            cout << "lambda 裡面的 x = " << x << '\n';
        };

        x = 99;

        cout << "外面的 x = " << x << '\n';
        printByValue();

        cout << "\n=== 4. 參考捕獲 [&x] ===\n";

        int y = 10;

        auto printByReference = [&y]() {
            cout << "lambda 裡面的 y = " << y << '\n';
        };

        y = 99;

        cout << "外面的 y = " << y << '\n';
        printByReference();

        cout << "\n=== 5. 用 lambda 改外部變數 ===\n";

        int count = 0;

        auto addOne = [&count]() {
            count++;
        };

        addOne();
        addOne();
        addOne();

        cout << "count = " << count << '\n';

        cout << "\n=== 6. sort 大到小 ===\n";

        vector<int> nums{5, 2, 9, 1, 7};

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });

        for (int n : nums) {
            cout << n << ' ';
        }
        cout << '\n';

        cout << "\n=== 7. pair 按 second 小到大排序 ===\n";

        vector<pair<int, int>> pairs{
            {1, 50},
            {2, 30},
            {3, 40}
        };

        sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        for (auto p : pairs) {
            cout << p.first << ' ' << p.second << '\n';
        }










    cout<<"\n--------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}