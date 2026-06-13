//
// Created by user on 2026/5/3.
//
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

//

using namespace std;
struct Student {
    string name;
    int score;
    int age;
};

int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n--------------------------------------------------"<<'\n';
    cout << string(50, '-') << endl;


    Student students[3];

    for (int i = 0; i < 3; ++i) {
        cout << "請輸入第 " << i + 1 << " 位學生的名字：";
        cin >> students[i].name;

        cout << "請輸入第 " << i + 1 << " 位學生的分數：";
        cin >> students[i].score;

        cout << "請輸入第 " << i + 1 << " 位學生的年齡：";
        cin >> students[i].age;

        cout << '\n';
    }

    cout << "學生資料如下：\n";

    for (int i = 0; i < 3; ++i) {
        cout << "第 " << i + 1 << " 位學生\n";
        cout << "名字：" << students[i].name << '\n';
        cout << "分數：" << students[i].score << '\n';
        cout << "年齡：" << students[i].age << '\n';
        cout << '\n';
    }








    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}