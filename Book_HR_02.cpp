//
// Created by user on 2026/4/24.
//
//
//
// Sample Input
//
// 2 2       //n,q
// 3 1 5 4   //3 [1,5,4]
// 5 1 2 8 9 3 //5 [1,2,8,9,3]
// 0 1         //問 第0列 第1個元素
// 1 3        //問 第1列 第3個元素
// Sample Output
//
// 5
// 9

#include <iostream>  // 第1行：引入輸入輸出工具（像 cin, cout）
#include <vector>    // 第2行：引入動態陣列工具（這題的核心）
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; // 第3行：告訴電腦我們用標準命名空間，不用每次寫 std::

int main() {         // 第4行：程式的起點

    // --- 第一部分：初始化與準備 ---
    int n, q;        // 第5行：宣告兩個整數，n 是陣列數量，q 是問題數量
    cin >> n >> q;   // 第6行：從鍵盤讀入這兩個數字

    // 這裡建立一個「大容器」，裡面裝的是「小容器」
    // 想像成一個書櫃(z)，裡面準備放很多層抽屜(vector<int>)
    vector<vector<int>> z; // 第7行

    // --- 第二部分：填滿資料（外層迴圈跑 n 次，蓋出 n 層抽屜） ---
    for (int i = 0; i < n; i++) { // 第8行：i 從 0 數到 n-1

        int k;       // 第9行：每一層抽屜打算放幾個數字
        cin >> k;    // 第10行：讀入這個數字

        vector<int> temp; // 第11行：建立一個「暫時的小籃子」，準備裝這一層的數字

        // 內層迴圈：把 k 個數字一個一個丟進小籃子裡
        for (int j = 0; j < k; j++) { // 第12行：j 負責數人頭，數到 k 為止
            int value;                // 第13行：準備一個位置放等一下讀到的數字
            cin >> value;             // 第14行：讀入真正的數值
            temp.push_back(value);    // 第15行：把數值塞進籃子的最尾端
        }

        // 關鍵動作：把裝滿數字的小籃子，整層推入大書櫃 z
        z.push_back(temp); // 第16行
    }

    // --- 第三部分：回答問題（跑 q 次問題） ---
    for (int count = 0; count < q; count++) { // 第17行：處理 q 個提問
        int r, c;     // 第18行：r 是哪一層(row)，c 是哪一格(column)
        cin >> r >> c; // 第19行：讀入問題座標

        // 直接從書櫃 z 的第 r 層、第 c 格把數字拿出來並印掉
        cout << z[r][c] << endl; // 第20行
    }

    return 0; // 第21行：程式平安結束
}