//
// Created by user on 2026/4/27.
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
#include <numbers>
#include <ranges>
#include <string>
#include <vector>

//

using namespace std;


int main() {
    auto start =  chrono::high_resolution_clock::now();
    cout<<"\n--------------------------------------------------"<<'\n';
    cout<<"\n--------------------------------------------------"<<'\n';


    const double pi{3.14159265358979323846};
    const size_t perline{3};
    size_t linecount{};
    for (double radius {0.2};radius<=3.0;radius+=0.5) {
        cout<<fixed<<setprecision(2)<<"radius="<<setw(6)<<radius<<" area= "<<setw(6)<<pi*radius*radius<<'\n';
        if (perline == ++linecount) {
            cout<<'\n';
            linecount = 0;
        }
    }
    cout<<endl;
    cout<<"-----------------------------------------------------"<<'\n';

    unsigned long long limit{};
    cout<<"what upper limit?(1~20)"<<'\n';
    cin>>limit;
    cout<<setw(8)<<"int "<<setw(8)<<"sum  "<<setw(30)<<"factorial"<<endl;

    //factorial 階層
    for (unsigned long long n{1},sum{},factorial{1};n<=limit;++n) {
        sum+=n;
        factorial*=n;
        cout<<setw(7)<<n<<" "<<setw(7)<<sum<<" "<<setw(30)<<factorial<<endl;
    }
    cout<<"-----------------------------------------------------"<<'\n';
    cout<<"upper limit?"<<endl;
    cin>>limit;
    cout<<setw(8)<<"int "<<setw(8)<<"sum  "<<setw(30)<<"factorial"<<endl;
    unsigned int n{};
    unsigned int sum{};
    unsigned long long factorial{1ull};
    while (++n<=limit) {
        sum+=n;
        factorial*=n;
        cout<<setw(7)<<n<<" "<<setw(7)<<sum<<" "<<setw(30)<<factorial<<endl;

    }
    // //尋找最小值演算法、邊界判定
    // unsigned long long factorial{ std::numeric_limits<unsigned long long>::max() }
    // //位元遮罩、硬體狀態設定
    // unsigned long long factorial{ 0xFFFFFFFFFFFFFFFFull }
    // //演算法常數、避免計算溢位
    // unsigned long long factorial{ 1'000'000'000'000'000'000ull };
    // //防止窄化轉換 (Narrowing Conversion)。ex float-->int   3.14-->3
    // unsigned long long factorial{ n }//n其他變數
    //
    //
    // 三、 現代 C++23 的新貴：uz (size_t)
    // 這是在 C++23 標準中新加入的後綴，對於理科邏輯控來說非常舒適：
    //
    // 寫法： for (auto i = 0uz; i < vec.size(); ++i)
    //
    //     痛點解決： vec.size() 的型別是 size_t（無號整數）
    //____________________________________________________
    // 1. 浮點數系列：f 與 L
    // 1.0f (float)：指定為單精度浮點數（32-bit）。
    //
    // 場景： 遊戲開發或 GPU 運算，為了節省記憶體並加快速度。
    //
    // 1.0 (double)：預設值，不加後綴就是 64-bit 雙精度
    // 1.0L (long double)：指定為高精度浮點數（通常為 80-bit 或 128-bit）。
    //
    // 場景： 需要極高精度的科學計算，避免誤差累積。
    //______________________________________________________________
    // 1. 其他後綴（Suffixes）
    // 根據你的硬體需求（位元數）與數學屬性（正負號），後綴有不同的組合：
    //
    // 1u : unsigned int (通常 32-bit)
    // 1l : long (32 或 64-bit，視作業系統而定)
    // 1ul: unsigned long
    // 1ll: long long (確保 64-bit 有號整數)
    //
    // 科學記號（浮點數）: 1e0 (這會被視為 double)
    //
    // 2. 強制型別轉換（Explicit Casting）
    // 如果你不想記後綴，或者該數值來自另一個變數，會使用轉換 SOP：
    //
    // C++ 風格: static_cast<unsigned long long>(1) (這是最安全的作法，編譯器會幫你檢查轉換邏輯)。
    //
    // 函數式: unsigned long long(1)。
    //
    // 3. 十六進位與二進位（視覺化位元邏輯）
    // 在處理底層暫存器或位元運算時，理科思維常使用：
    //
    // 0x1ull: 十六進位。
    // 0b1ull: 二進位（C++14 起支援）。


    cout<<"-----------------------------------------------------"<<'\n';
    int value[]{2,3,5,7,11,13,17,19,23,29};
    int total{0};
    for (int x : value) {
        total+=x;
        cout<<x<<"  ";
    }cout<<"\n\n";
    for (auto x : value) {
        total+=x;
        cout<<x<<"  ";
    }cout<<"\n\n";







    cout<<"-----------------------------------------------------"<<'\n';


    cout<<"-----------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}