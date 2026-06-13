#include <iostream>
using namespace std;

// 書上常看到這種寫法，通常是競賽或線上題目的習慣。
// const int 表示 N 是編譯期固定常數，可以拿來當陣列大小。
const int N = 100000 + 9;
long long a[N]{};

int main() {
    int n{5};

    for (int i{1}; i <= n; ++i) {
        a[i] = i * 10;
    }

    for (int i{1}; i <= n; ++i) {
        cout << a[i] << '\n';
    }

    return 0;
}

/*
原本容易卡住的觀念：
const int N = 1e5 + 9; long long a[N]; 不是公式，而是先預留夠大的陣列空間。

正確觀念：
1e5 表示 100000。
+ 9 是多留一點空間，避免題目用 1-based index 時不小心超界。
long long 用來存比較大的整數，比 int 更不容易溢位。
a 放在全域區，通常比放在 main 裡更不容易因為陣列太大造成 stack 問題。

手動推導的預期輸出：
10
20
30
40
50

可以自己修改練習：
把 n 改成 3，確認只會使用 a[1]、a[2]、a[3]。
*/
