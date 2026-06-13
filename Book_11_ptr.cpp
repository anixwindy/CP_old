//
// Created by user on 2026/5/8.
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

//

// int* p = &a;
//*p =100;取 數值
//p=&b;取址

using namespace std;
//重要
void swapValue(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

struct Student {
    int math;
    int english;
};

void addOne(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = arr[i] + 1;
    }
}



int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n----------------swap-------------------------------"<<'\n';
    cout << string(50, '-') << endl;

        int a = 10;
        int b = 20;

        swapValue(&a, &b);//很重要

        cout << "a = " << a << '\n';
        cout << "b = " << b << '\n';
    cout<<"\n---------------結構體--------------------------"<<'\n';

    Student s{90, 80};
    //等於
    // Student s;
    // s.math = 90;
    // s.english = 80;



    Student* p = &s;

    cout << p->math << '\n';
    cout << p->english << '\n';

    //p->math 其實等於 (*p).math
    p->math = 100;

    cout << s.math << '\n';

    cout<<"\n-------------------"<<'\n';
    cout<<"\n-------------------"<<'\n';

    Student s1{90, 80};
    Student s2{60, 70};

    Student* p4 = &s1;

    cout << "一開始 p->math = " << p4->math << '\n';
    p4 = &s2;
    cout << "改指向後 p->math = " << p4->math << '\n';

    cout<<"\n----------------函數陣列---------------------"<<'\n';
    int data[3] = {10, 20, 30};

    addOne(data, 3);

    for(int i = 0; i < 3; ++i) {
        cout << data[i] << '\n';
    }
    cout<<"\n------------------- const--難爆---------------"<<'\n';
    // const int* p 不可改數值;不會出現 *p=...
    int a1 = 10;
    int b1 = 20;
    const int* p1 = &a1;
    cout << *p1 << '\n';//a1位址 數值=10
    // *p1 = 20;  // 不可以
    a1 = 3;      // 可以，a1位址 數值=3 改值要用a1
    cout << *p1 << '\n';
    p1 = &b1;// 可以，b1位址 數值=20
    cout << *p1 << '\n';

    cout<<"\n---------"<<'\n';
    // int* const p 不能改指向別人;不會出現 p=&...
    int a2 = 10;
    int b2 = 20;
    int* const p2 = &a2;
    cout << *p2 << '\n';
    *p2 = 99;     // 可以//還是a2位址 數值=99
    // p2 = &b2;   // 不可以
    cout << a2 << '\n';
    cout<<"\n-----------------new delete------------------"<<'\n';

    int* p3 = new int{10};
    cout << *p3 << '\n';
    delete p3;
    p3 = nullptr;
    cout<<"\n----------------new/delete--vector----------"<<'\n';
    int size = 5;
    int* arr1 = new int[size];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;
    for (int i = 0; i < size; ++i) {
        cout << arr1[i] << '\n';
    }
    delete[] arr1;
    arr1 = nullptr;

    cout<<"\n-------------------"<<'\n';
    cout<<"\n-------------------"<<'\n';

    vector<int> arr{10, 20, 30, 40, 50};

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << '\n';
    }




    cout<<"\n--------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}