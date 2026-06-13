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
using namespace std;
#define SCHOOL_NAME "ABC High School"

struct SimpleStudent {
    string name;
    int age;
    double score;
};

class Student {
private:
    string name;
    int age;
    double score;

public:
    void setData(string n, int a, double s) {
        name = n;
        age = a;
        score = s;
    }

    void print() {
        cout << "學校: " << SCHOOL_NAME << '\n';
        cout << "姓名: " << name << '\n';
        cout << "年齡: " << age << '\n';
        cout << "分數: " << score << '\n';
    }
};

void printSimpleStudent(const SimpleStudent& s) {
    cout << "學校: " << SCHOOL_NAME << '\n';
    cout << "姓名: " << s.name << '\n';
    cout << "年齡: " << s.age << '\n';
    cout << "分數: " << s.score << '\n';
}


int main() {
    auto start =  chrono::high_resolution_clock::now();

    cout<<"\n--------------------------------------------------"<<'\n';
    cout << string(50, '-') << endl;








    SimpleStudent a{"Amy", 20, 90.5};

    printSimpleStudent(a);

    cout << "----------------\n";

    Student b;
    b.setData("Bob", 21, 85.0);
    b.print();









    cout<<"\n--------------------------------------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}
