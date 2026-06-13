#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int number) {
    // 質數必須大於等於 2。
    // 0、1、負數都不是質數。
    if (number < 2) {
        return false;
    }

    // 只需要檢查到 i * i <= number，不用一路除到 number - 1。
    for (int i{2}; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int target{29};
    int limit{30};

    cout << "單一數字質數判斷\n";
    cout << target << " 是質數嗎？";

    if (isPrime(target)) {
        cout << "是\n";
    } else {
        cout << "不是\n";
    }

    // 用 vector 管理陣列大小，競賽中通常不需要自己 new/delete。
    // prime[x] == true 代表目前先認為 x 是質數。
    vector<bool> prime(limit + 1, true);
    prime[0] = false;
    prime[1] = false;

    // 這段是埃氏篩：
    // 找到一個質數 i，就把 i 的倍數標成不是質數。
    for (int i{2}; i * i <= limit; ++i) {
        if (prime[i]) {
            for (int multiple{i * i}; multiple <= limit; multiple += i) {
                prime[multiple] = false;
            }
        }
    }

    cout << "\n" << limit << " 以內的質數：";
    for (int i{2}; i <= limit; ++i) {
        if (prime[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}

/*
補充說明：質數判斷、篩法、以及競程中通常不用 new/delete

使用者原本問題：
質數有甚麼方式用 C++ 寫？
new / delete 算是不用使用對吧，在算法競賽裡？

這份程式示範兩種常見方式：
1. isPrime(number)
   - 判斷單一數字是不是質數。
   - 只檢查到 i * i <= number。

2. vector<bool> prime + 兩層迴圈
   - 用埃氏篩列出 limit 以內的所有質數。
   - 先假設每個數都是質數，再把質數的倍數標成不是質數。

原本可能卡住的觀念：
1. 以為判斷質數一定要從 2 除到 number - 1。
2. 以為大小會變的陣列一定要用 new。
3. 以為用了 new 之後忘記 delete 也沒關係。

正確觀念：
- 質數是只能被 1 和自己整除的整數，而且必須大於等於 2。
- 判斷單一數字時，只要檢查到 i * i <= number。
- 原因是如果 number 有一個比平方根大的因數，
  一定也會有一個比平方根小的對應因數。
- 如果要找很多個質數，篩法通常比每個數字都重新試除有效率。

競程中的 new/delete：
- 大小固定且不大：可以用普通陣列。
- 大小由輸入決定：優先用 vector。
- 多組資料要重設：重新建立 vector 或用 assign。
- 多數 Codeforces / AtCoder 入門題，不需要自己手動 new/delete。

程式執行順序：
1. main() 設定 target = 29 和 limit = 30。
2. 呼叫 isPrime(29)。
3. isPrime() 從 2 開始檢查是否能整除 29。
4. 沒有找到可以整除的數，所以回傳 true。
5. 程式印出 29 是質數。
6. 建立 prime 陣列，先假設 0 到 30 都是質數。
7. 把 0 和 1 設成不是質數。
8. 從 2 開始，把質數的倍數標成不是質數。
9. 最後從 2 到 30 輸出仍然被標記為質數的數字。

靜態推導的預期輸出：
單一數字質數判斷
29 是質數嗎？是

30 以內的質數：2 3 5 7 11 13 17 19 23 29

可以自己修改練習：
1. 把 target 改成 1、2、25、97，觀察判斷結果。
2. 把 limit 改成 100，觀察篩法列出的質數。
3. 在 isPrime() 的迴圈裡加 cout，觀察實際檢查了哪些除數。

自我檢查：
1. 先確認數字是否小於 2。
2. 判斷單一數字時，檢查條件是否寫成 i * i <= number。
3. 如果要找一整段範圍內的質數，優先想篩法。
4. 如果只是需要大小由輸入決定的陣列，先想 vector，不要急著用 new/delete。
*/
