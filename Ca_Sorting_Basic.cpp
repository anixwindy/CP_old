#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // 排序：把資料整理成固定順序，讓後面的搜尋、雙指針、貪心更好做。
    int numbers[5]{8, 3, 5, 1, 4};
    int length{5};

    sort(numbers, numbers + length);

    for (int i{}; i < length; ++i) {
        cout << numbers[i] << '\n';
    }

    return 0;
}

/*
原本容易卡住的觀念：
sort(numbers, numbers + length) 的第二個位置是「尾端的下一格」。
它不是最後一個元素，而是排序範圍結束的位置。

正確觀念：
numbers 指向第 0 格。
numbers + length 指向最後一格後面的位置。
sort 會排序 [開始, 結束) 這個半開區間。

手動推導的預期輸出：
1
3
4
5
8

可以自己修改練習：
把陣列改成 5 個成績，排序後印出最低分到最高分。
*/
