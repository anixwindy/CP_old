#include <iostream>
using namespace std;

int main() {
    // 雙指針：用兩個位置一起移動，避免所有組合都重新枚舉。
    // 這個技巧常用在「已排序陣列」。
    int numbers[6]{1, 2, 4, 7, 11, 15};
    int target{15};
    int left{0};
    int right{5};

    while (left < right) {
        int sum{numbers[left] + numbers[right]};

        if (sum == target) {
            cout << numbers[left] << " + " << numbers[right] << " = " << target << '\n';
            break;
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return 0;
}

/*
原本容易卡住的觀念：
雙指針不是固定寫法，重點是知道哪一邊移動後會讓答案變大或變小。

正確觀念：
陣列已排序時，left 往右移，總和通常變大。
right 往左移，總和通常變小。

手動推導的預期輸出：
4 + 11 = 15

可以自己修改練習：
把 target 改成 18，手動追蹤 left 和 right 會怎麼移動。
*/
