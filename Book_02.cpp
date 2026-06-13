//
// Created by user on 2026/4/21.
//

#include <iostream>
#include <array>
#include <format>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <cmath>
#include <numbers>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <ranges>
#include <memory>
using namespace std;



int main() {
    auto start =  chrono::high_resolution_clock::now();
    cout<<"----------------------"<<'\n';
    cout<<"----------------------"<<'\n';

    int mice{0};
    int brown{1};
    int black{2};

    mice = brown+black;
    cout<<format("you have {} ",mice)<<(mice ==1 ?"mouse":"mice")<<" in total"<<'\n';
    cout<<"----------------------"<<'\n';

    int ticket_num{200};
    cout<<format("your ticket is {} ",ticket_num)<<"number"<<'\n';
    switch (ticket_num) {
        case 147:
        cout<<"you win first prize"<<endl;
        break;//有break 就出去了
        case 200:
        cout<<"you win second prize"<<endl;
        //沒break  每個case 都會跑
        case 7:
            cout<<"you win thrid prize"<<endl;
        default:
        cout<<"sorry you lose"<<endl;
        break;


    }
    char letter ='e';
    cout<<format("your key letter is {} ",letter)<<'\n';
    switch (letter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout<<" you enter  a vowel."<<endl;
            break;
    }
    cout<<"--------------------------------------------------"<<'\n';
    // --離開迴圈  變數消失--


    // 我們把 input_val 傳給 score 變數來測試語法
    if (int score = 100; score >= 60) {
        std::cout << "及格！ 分數是: " << score << std::endl;
    } else {
        std::cout << "不及格。 分數是: " << score << std::endl;
    }
    // 這裡無法存取 score，測試作用域限制

    std::cout << "-------------------------------------------" << std::endl;

    // 直接在 switch 裡面宣告 choice 並給它值

    switch (int choice1 = 2; choice1) {
        case 1:
            std::cout << "開始遊戲";
            break;
        case 2:
            std::cout << "讀取進度\n";
            break;
    }
    // 出了這裡，choice 就消失了！記憶體乾乾淨淨。

    cout<<"--------------------------------------------------"<<'\n';
    //陣列+迴圈
    double rainfall [4]{1.1,2.5,4.5,7.7};
    double copy [4]{};
    for (size_t i{0}; i < 4; ++i) {
        copy[i] = rainfall[i];

    }
    //輸出方法1

    for (size_t i{0}; i < 4; ++i) {
        cout << copy[i] << " ";
    }
    cout << endl;
    cout<<"--------------------------------------------------"<<'\n';
    //輸出方法2
    for (const auto& value : copy) {
        cout << value << " ";
    }
    cout << endl;
    cout<<"--------------------------------------------------"<<'\n';
    //輸出方法3
    std::array<double, 4> rainfall3 {1.1, 2.5, 4.5, 7.7};
    std::array<double, 4> copy2 = rainfall3; // 直接賦值即可，不需要寫迴圈
    std::ranges::copy(copy, std::ostream_iterator<double>(std::cout, " "));
    cout << endl;

    cout<<"--------------------------------------------------"<<'\n';

    //陣列總和
    int rain[4]={1,2,9,11};
    int sum =0;
    for (int i=0;i<4;i++) {
        sum+=rain[i];
    }cout<<sum<<'\n';
    cout<<"--------------------------------------------------"<<'\n';

    // 基礎：原生靜態陣列
    int arr[5] = {1, 2, 3, 4, 5};//不會出現()
    // ---------------------------------------------------------
    // 1. 原生陣列方式 (Raw Array) - 「最原始的底層」
    // ---------------------------------------------------------
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << (i == 4 ? "" : " ");
    }

    cout<<"\n---------------------------------------------------"<<'\n';
    // ---------------------------------------------------------
    // 2. 智慧指標陣列 (std::unique_ptr) - 「安全管理 Heap 記憶體」
    // ---------------------------------------------------------

    // 宣告一個管理 5 個 int 的保姆
    auto smart_ptr = make_unique<int[]>(5);//只能這樣寫，不會出現{}

    // 將基礎 arr 的資料搬進去 (智慧指標陣列通常用於處理動態大數據)
    for (int i = 0; i < 5; i++) {
        smart_ptr[i] = arr[i];
    }
    for (int i = 0; i < 5; i++) {
        std::cout << smart_ptr[i] << (i == 4 ? "" : " ");
    }

    cout<<"\n---------------------------------------------------"<<'\n';


    // ---------------------------------------------------------
    // 3. STL 容器方式 (std::vector) - 「現實開發的最愛」
    // ---------------------------------------------------------

    // 直接用基礎 arr 初始化 vector
    vector<int> vec(begin(arr), end(arr));//絕不會出現[]
    //要建立空的：std::vector<int> vec; (什麼都不加)
    //
    // 要建立 5 個空間：std::vector<int> vec(5);
    //
    // 要初始化內容：std::vector<int> vec{1, 2, 3};

    // Vector 可以用現代化的 Range-based for loop 輸出
    for (int value : vec) {
        std::cout << value << " ";
    }


    cout<<"\n--------------------------------------------------"<<'\n';







    cout<<"------------------------------------------"<<'\n';
    // //unique_ptr = 責任清楚。
    //
    // shared_ptr = 資源共享。
    //
    // weak_ptr = 安全觀測。
    cout<<"----------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}