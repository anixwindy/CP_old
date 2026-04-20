//
// Created by user on 2026/1/7.
//
#include <iostream>
#include <vector>
#include <format>
#include <memory> // 必須包含這個標頭檔
#include <algorithm> // C++20 的 ranges 在這裡或 <ranges>
using namespace std;
// 1. 定義：把 test 函式放在 main 之外
void test() {
    // 建立智慧指標，它管理一塊存放 100 的堆積（Heap）記憶體
    auto my_data = std::make_unique<int>(100);
    std::cout << "在 test 函式內，值為: " << *my_data << std::endl;
} // <--- 關鍵！當執行到這個右大括號時，my_data 會「死掉」，它管理的記憶體也會自動回收


int main() {

    std::vector<int> v = {3, 1, 4, 1, 5, 9};

    // 這是 C++20 的寫法，不需要 .begin() 和 .end()


    for (int n : v) std::cout << n << " ";
    return 0;
}