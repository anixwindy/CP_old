//
// Created by user on 2026/4/28.
//
//
// Created by user on 2026/4/28.
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

//map
//do while

using namespace std;

int main() {
    auto start =  chrono::high_resolution_clock::now();
    cout<<"\n--------------------------------------------------"<<'\n';
    cout<<"\n--------------------------------------------------"<<'\n';

    //map 、unordered_map

    // 【宣告與初始化】
    // 語法：map<Key型態, Value型態> 變數名 = { {k1, v1}, {k2, v2} };

    // 1. 有序 map：會自動幫你把 ID 從小到大排好
    map<int, string> order_map = {
        {3, "小明"},
        {1, "小華"},
        {2, "小強"}
    };

    // 2. 無序 map：速度最快，但印出來順序不可預測
    unordered_map<int, string> unorder_map = {
        {100, "工程師"},
        {200, "設計師"},
        {300, "產品經理"}
    };
    unordered_map<char, int> myMap;

    // 方式 A：像陣列一樣直接指定 (最常用)
    myMap['A'] = 65;
    // 方式 B：使用 insert 搭配 pair
    myMap.insert(make_pair('B', 66));
    // 方式 C：使用 emplace (效能稍微好一點點)
    myMap.emplace('C', 67);

    // 語法：[key, value] 會直接把 pair 拆解開來
    for (const auto& [key, value] :order_map ) {
        std::cout << key << " is " << value << std::endl;
    }
    for (const auto& [key, value] : unorder_map) {
        std::cout << key << " is " << value << std::endl;
    }
    for (const auto& [key, value] :myMap ) {
        std::cout << key << " is " << value << std::endl;
    }
    cout<<"-----------------------------------------------------"<<'\n';
    // do while 至少一次


     char reply1{};
     int count1{};
     double temperature1{};
     double total1{};
     do {
         cout<<"enter temperature?";
         cin>>temperature1;
         total1+=temperature1;
         ++count1;
         cout<<"do you want  to enter another? y/n:";
         cin>>reply1;

     }while (tolower(reply1=='y'));
     cout<<"the average temperature is  "<<total1/count1<<'\n';
    cout<<"-----------------------------------------------------"<<'\n';

    size_t table{};
    const size_t table_min {2};
    const size_t table_max {12};
    char reply{};

    do {
        cout << format("What size table would you like ({} to {})? ", table_min, table_max);
        if (!(cin >> table)) break; // 防止輸入非數字導致死迴圈

        if (table < table_min || table > table_max) {
            cout << "Invalid table size entered. Program terminated." << endl;
            return 1; // 這裡會直接結束 main 函式
        }

        // 1. 生成表頭 (加上左上角的空白區塊)
        cout << "      |";
        for (size_t i{1}; i <= table; ++i) {
            // 使用 C++20 format 控制寬度為 3，並補零 (01, 02...)
            cout << format(" {:4}|", i);
        }
        cout << "\n";

        // 2. 分隔線 (動態計算長度)
        cout << string(7 + table * 6, '-') << "\n";

        // 3. 表身
        for (size_t i{1}; i <= table; ++i) {
            cout << format("  {:02}  |", i);
            for (size_t j{1}; j <= table; ++j) {
                cout << format(" {:3} |", i * j);
            }
            cout << "\n";
        }

        cout << "\nDo you want another table (y/n)? ";
        cin >> reply;

    } while (tolower(static_cast<unsigned char>(reply)) == 'y');





    cout<<"-----------------------------------------------------"<<'\n';

    cout << string(20, '-') << endl;
    cout<<"-----------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}