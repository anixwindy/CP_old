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

//多維陣列~~~~~~~~~~~難~~~~~~~~~~~~~~

using namespace std;



void processMatrix() {
    int rows = 100;
    int cols = 50;

    // 1. 動態配置：在 Heap 區段要一塊連續的記憶體
    int* matrix = new int[rows * cols]{}; // {} 保證全部初始化為 0
    // 2. 寫入資料：邏輯上的 i 列 j 行，轉換為一維物理索引
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // 公式：i * 總欄數 + j
            matrix[i * cols + j] = i + j;
        }
    }
    cout << "Value at (2, 3): " << matrix[2 * cols + 3] << endl;
    // 4. 手動釋放：非常重要！
    // 凡是出現 new []，就必須成對出現 delete []
    delete[] matrix;
    matrix = nullptr; // 安全習慣：釋放後將指標歸零
}

void processVectorMatrix() {
    int rows = 100;
    int cols = 50;

    // 1. 宣告與初始化：建立 100 列，每一列是 50 個元素的 vector，初始值為 0
   vector<vector<int>> vecMatrix(rows, vector<int>(cols, 0));

    // 2. 存取資料：可以直接使用多維陣列的語法
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vecMatrix[i][j] = i + j;
        }
    }

    cout << "Value at (2, 3): " << vecMatrix[2][3] << endl;

    // 3. 函式結束時，資源會被自動清空！
}

int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n--------------------------------------------------"<<'\n';
    cout<<"\n---------範例 函式01-----------------------------"<<'\n';
    processMatrix(); // 在這裡呼叫它

    cout<<"\n-------------end--------------------------------"<<'\n';

    cout<<"\n-----範例現代C++20 函式02-----------------------------------"<<'\n';
    processVectorMatrix(); // 在這裡呼叫它
    cout<<"\n---------------end---------------------------------"<<'\n';
    cout<<"\n----範例_書本 靜態 函式03---------------------------------"<<'\n';
    double carrots[][3][4] {
        {
            {12,2,515,4.0},
            {14,2,525,4.1},
            {16,2,535,4.2},

        },
    {
            {10,10,15,5.0},
            {14,8,25,5.1},
            {18,6,35,5.2},

        }
    };
    // 取得維度大小 (理科思維：不要硬寫死數字)
    int pages = sizeof(carrots) / sizeof(carrots[0]);       // 2
    int rows  = sizeof(carrots[0]) / sizeof(carrots[0][0]); // 4
    int cols  = sizeof(carrots[0][0]) / sizeof(double);     // 4

    for (int p = 0; p < pages; ++p) {
        cout << format("--- 第 {} 層 (Page {}) ---\n", p, p);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // 使用 :format 控制小數點與對齊
                cout << format("{:>8.1f} ", carrots[p][r][c]);
            }
            cout << "\n"; // 換列
        }
        cout << "\n"; // 層與層之間空一行
    }
    cout<<"\n------------------end-----------------------------"<<'\n';
    cout<<"\n------範例現代C++20 Codeforce函式04---------------------"<<'\n';
    // 1. 定義維度 (現實中的規模)
    int rowss = 3;
    int colss = 4;
    // 2. 配置連續記憶體 (RAII 方案)
    // 優點：自動管理記憶體，不需 delete；且記憶體物理上連續，快取友好。
    vector<int> matrix(rowss * colss, 0);
    // 3. 寫入資料：模擬二維操作
    for (int i = 0; i < rowss; ++i) {
        for (int j = 0; j < colss; ++j) {
            // 套用公式 i * C + j
            matrix[i * colss + j] = i * 10 + j;
        }
    }
    // 4. 讀取資料：使用 :format 輸出
    cout << "矩陣內容如下：\n";
    for (int i = 0; i < rowss; ++i) {
        for (int j = 0; j < colss; ++j) {
            int value = matrix[i * colss + j];
            cout << format("[{:2}] ", value);
        }
        cout << "\n";
    }
    // 5. 資源釋放
    // 不需要手動 delete！當 matrix 離開範圍時，vector 的解構子會自動回收 Heap 空間。

    cout<<"\n----------------end--------------------------"<<'\n';
    cout<<"\n--------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}