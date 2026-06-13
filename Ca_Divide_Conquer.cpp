#include <iostream>
using namespace std;

int findMaxValue(int numbers[], int left, int right) {
    // 分治法：把大問題切成小問題，解完再合併答案。
    if (left == right) {
        return numbers[left];
    }

    int middle{left + (right - left) / 2};
    int leftMax{findMaxValue(numbers, left, middle)};
    int rightMax{findMaxValue(numbers, middle + 1, right)};

    if (leftMax > rightMax) {
        return leftMax;
    }
    return rightMax;
}

int main() {
    int numbers[6]{3, 9, 2, 11, 5, 7};
    cout << "max = " << findMaxValue(numbers, 0, 5) << '\n';

    return 0;
}

/*
原本容易卡住的觀念：
分治法和普通遞歸很像，但它特別強調「切開、各自解、合併」。

正確觀念：
先找左半邊最大值，再找右半邊最大值。
最後比較兩邊答案，較大的就是整個範圍最大值。

手動推導的預期輸出：
max = 11

可以自己修改練習：
把 numbers 裡的 11 改成 1，重新手動推導最大值。
*/
