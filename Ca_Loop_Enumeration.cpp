#include <iostream>
using namespace std;

int main() {
    // 循環枚舉法：用 for 迴圈把「所有可能答案」一個一個試過。
    // 這裡示範：從 1 到 5 裡面，找出兩個數字相加等於 6 的組合。
    int target{6};

    for (int first{1}; first <= 5; ++first) {
        for (int second{first + 1}; second <= 5; ++second) {
            // second 從 first + 1 開始，可以避免重複印出 1 5 和 5 1。
            if (first + second == target) {
                cout << first << " + " << second << " = " << target << '\n';
            }
        }
    }

    return 0;
}

/*
原本容易卡住的觀念：
枚舉不是猜答案，而是有順序地把所有可能性檢查完。

正確觀念：
1. 外層迴圈固定第一個數。
2. 內層迴圈嘗試第二個數。
3. if 負責判斷這組答案是否符合題目條件。

手動推導的預期輸出：
1 + 5 = 6
2 + 4 = 6

可以自己修改練習：
把 target 改成 7，觀察哪些組合會被印出。
*/
