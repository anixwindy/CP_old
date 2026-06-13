#include <iostream>
using namespace std;

int sumFromOneTo(int number) {
    // 遞歸一定要有停止條件，否則會一直呼叫自己。
    if (number == 1) {
        return 1;
    }

    return number + sumFromOneTo(number - 1);
}

int main() {
    int number{5};
    cout << "sum = " << sumFromOneTo(number) << '\n';

    return 0;
}

/*
原本容易卡住的觀念：
遞歸不是同時執行很多份函式，而是函式呼叫函式，等最深層回傳後再一層層回來。

正確觀念：
sumFromOneTo(5)
= 5 + sumFromOneTo(4)
= 5 + 4 + sumFromOneTo(3)
= 5 + 4 + 3 + 2 + 1

手動推導的預期輸出：
sum = 15

可以自己修改練習：
把 number 改成 10，先手算再看自己編譯後的結果。
*/
