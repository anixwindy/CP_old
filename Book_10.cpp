
//
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

int sum(int a[][5], int n) {
    int total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            total += a[i][j];
        }
    }

    return total;
}

int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n--------------------------------------------------"<<'\n';
    cout << string(50, '-') << endl;




    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {10, 20, 30, 40, 50},
        {100, 200, 300, 400, 500}
    };
    //這裡的sum 是我們自己定義的  加總 0~n列的總元素
    cout << sum(arr, 3) << '\n';

    cout<<"\n--------------------------------------------------"<<'\n';





    cout<<"\n--------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}