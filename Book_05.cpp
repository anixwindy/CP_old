//
// Created by user on 2026/4/29.
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

int main() {
    auto start =  chrono::high_resolution_clock::now();
    cout << string(50, '-') << endl;
    cout<<"-----------------------------------------------------"<<'\n';

    for (int i = 0; i < 9; i++) {
        // [標記 A] 每一圈的進入點：無論如何都會執行

        // if (i==1) {
        //     /* pass */               // 或者是直接寫註解，或空白
        // }
        if (i == 2) {

            std::cout << std::format("   >> 偵測到 i == 2，執行 continue 指令 <<\n");
            continue;
            // 這裡之後「物理性無視」
            std::cout << "這行字永遠不會出現在螢幕上\n";
        }
        if (i == 7) {

            std::cout << std::format("   >> 偵測到 i == 7，執行 break指令 <<\n");
            break;
            // 這裡之後「物理性無視」
            std::cout << "這行字永遠不會出現在螢幕上\n";
        }
        //continue 擊殺最近的for迴圈 執行i+1
        //break 擊殺最近的for迴圈 離開迴圈
        std::cout << std::format("--- [第 {} 圈] 正常結束 ---\n", i);
    }
    std::cout << "【已離開】所有迴圈執行完畢。\n\n";
    cout<<"-----------------------------------------------------"<<'\n';

    const int max_length{100};
    char text[max_length];
    std::cin.getline(text, max_length);
    std::cout << std::format("你剛才輸入的是：[{}]\n", text);
    std::cout << std::format("這串文字總長度為：{} 字元\n", std::strlen(text));

    cout<<"-----------------------------------------------------"<<'\n';
    std::string text1;
    std::cout << "請輸入一段文字：\n";
    // 這是全域函式版的 getline，針對 std::string 設計
    std::getline(std::cin, text1);
    std::cout << std::format("你剛才輸入的是：[{}]\n", text1);
    std::cout << std::format("這串文字總長度為：{} 字元\n", text1.length());








    cout<<"-----------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}