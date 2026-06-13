#include <iostream>
using namespace std;

int main() {
    // 貪心算法：每一步都選目前看起來最好的選擇。
    // 這裡示範用 10、5、1 元硬幣找 28 元，先拿大的硬幣。
    int coins[3]{10, 5, 1};
    int amount{28};

    for (int i{}; i < 3; ++i) {
        int count{amount / coins[i]};
        amount = amount % coins[i];

        cout << coins[i] << " yuan: " << count << '\n';
    }

    return 0;
}

/*
原本容易卡住的觀念：
貪心不是每題都能用，它需要題目本身保證「局部最佳」可以推出「整體最佳」。

正確觀念：
在 10、5、1 這種硬幣系統中，先拿最大面額可以得到最少硬幣數。
但如果硬幣是 4、3、1，要找 6 元，先拿 4 就不是最佳。

手動推導的預期輸出：
10 yuan: 2
5 yuan: 1
1 yuan: 3

可以自己修改練習：
把 amount 改成 37，手動算出每種硬幣會拿幾個。
*/
