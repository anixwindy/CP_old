#include <iostream>
using namespace std;

int main() {
    // 位元運算常用來表示「開或關」、「有或沒有」。
    // 這裡用 3 個位元表示 3 個開關。
    int mask{0};

    mask = mask | (1 << 0); // 打開第 0 個開關。
    mask = mask | (1 << 2); // 打開第 2 個開關。

    for (int bit{}; bit < 3; ++bit) {
        if ((mask & (1 << bit)) != 0) {
            cout << "bit " << bit << " is on\n";
        } else {
            cout << "bit " << bit << " is off\n";
        }
    }

    return 0;
}

/*
原本容易卡住的觀念：
1 << bit 的意思是把 1 移到指定的位元位置。

正確觀念：
| 可以把某個位元打開。
& 可以檢查某個位元是不是 1。
mask 可以把多個 true/false 狀態收在同一個整數裡。

手動推導的預期輸出：
bit 0 is on
bit 1 is off
bit 2 is on

可以自己修改練習：
多加一行 mask = mask | (1 << 1);，觀察三個開關是否都打開。
*/
