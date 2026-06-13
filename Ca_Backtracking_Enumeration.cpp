#include <iostream>
using namespace std;

int chosen[3]{};

void backtrack(int nextNumber, int depth) {
    // 回溯法：先選一個，再往下試；試完就退回來換下一個。
    if (depth == 3) {
        cout << chosen[0] << ' ' << chosen[1] << ' ' << chosen[2] << '\n';
        return;
    }

    for (int number{nextNumber}; number <= 5; ++number) {
        chosen[depth] = number;
        backtrack(number + 1, depth + 1);
        // 這裡不用清掉 chosen[depth]，下一次迴圈會直接覆蓋它。
    }
}

int main() {
    // 從 1 到 5 裡面選 3 個數字，列出所有遞增組合。
    backtrack(1, 0);

    return 0;
}

/*
原本容易卡住的觀念：
回溯不是魔法，它其實是「for 迴圈 + 遞歸」。

正確觀念：
depth 表示目前選到第幾格。
nextNumber 表示下一次最小可以從哪個數字開始選。
return 會回到上一層，上一層的 for 迴圈再換下一個 number。

手動推導的部分預期輸出：
1 2 3
1 2 4
1 2 5
...
3 4 5

可以自己修改練習：
把 depth == 3 改成 depth == 2，改成從 1 到 5 選 2 個數字。
*/
