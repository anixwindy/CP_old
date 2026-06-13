#include <iostream>
using namespace std;

int main() {
    // 二分法需要資料已排序，才能每次丟掉一半範圍。
    int numbers[7]{2, 4, 6, 8, 10, 12, 14};
    int target{10};
    int left{0};
    int right{6};
    int answer{-1};

    while (left <= right) {
        int middle{left + (right - left) / 2};

        if (numbers[middle] == target) {
            answer = middle;
            break;
        } else if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << "index = " << answer << '\n';
    return 0;
}

/*
原本容易卡住的觀念：
二分法不是一直除以 2，而是根據 middle 的值縮小搜尋範圍。

正確觀念：
陣列必須先排序。
numbers[middle] 太小，答案只可能在右半邊。
numbers[middle] 太大，答案只可能在左半邊。

手動推導的預期輸出：
index = 4

可以自己修改練習：
把 target 改成 7，觀察 answer 為什麼最後會保持 -1。
*/
