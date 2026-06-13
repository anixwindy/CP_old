#include <iostream>
#include <vector>
using namespace std;

// ── 雙指針（Two Pointers）──
// 用兩個索引變數（左指針 left、右指針 right）分別從陣列兩端往中間移動。
// 條件式決定哪個指針移動，直到兩者相遇（left >= right）。
// 時間複雜度：O(n)；不需要巢狀迴圈，比暴力 O(n²) 快很多。

// ── 範例 1：在「已排序陣列」找出兩數之和等於 target ──
void find_pair(const vector<int>& arr, int target) {
    int left  = 0;                       // 從最左端開始
    int right = (int)arr.size() - 1;     // 從最右端開始

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << "找到：" << arr[left] << " + " << arr[right]
                 << " = " << target << '\n';
            return;
        } else if (sum < target) {
            ++left;   // 總和太小，左指針右移，換更大的數
        } else {
            --right;  // 總和太大，右指針左移，換更小的數
        }
    }
    cout << "沒有找到\n";
}

// ── 範例 2：判斷字串是否為回文（Palindrome）──
// 回文：從左讀和從右讀一樣，例如 "racecar"
bool is_palindrome(const string& s) {
    int left  = 0;
    int right = (int)s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

int main() {
    // 範例 1：兩數之和
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    find_pair(nums, 14);   // 3 + 11 = 14
    find_pair(nums, 6);    // 1 + 5  = 6
    find_pair(nums, 2);    // 沒有找到

    cout << '\n';

    // 範例 2：回文判斷
    string w1 = "racecar";
    string w2 = "hello";
    cout << w1 << (is_palindrome(w1) ? " 是回文" : " 不是回文") << '\n';
    cout << w2 << (is_palindrome(w2) ? " 是回文" : " 不是回文") << '\n';

    return 0;
}

/*
────────────────────────────────────────────────────────────
易卡住的觀念
────────────────────────────────────────────────────────────
1. 「為什麼 sum < target 要移動 left？」
   陣列已排序 → arr[left] 是目前最小值，arr[right] 是最大值。
   sum 不夠大 → 需要換一個「更大的左值」→ left 右移一格。
   sum 太大   → 需要換一個「更小的右值」→ right 左移一格。

2. 「如果陣列沒有排序，可以用雙指針嗎？」
   通常不行，需先 sort()。雙指針依賴「單調性」(一邊大一邊小)。

3. 「什麼時候用雙指針 vs 滑動視窗？」
   雙指針：兩端往中間收縮，常見於「有序陣列找配對」。
   滑動視窗：left/right 都只往右走，維持一個區間，常見於「子陣列問題」。

────────────────────────────────────────────────────────────
正確觀念
────────────────────────────────────────────────────────────
- left 和 right 是「索引」，不是指標（pointer）語法上沒有 *。
- 迴圈條件 left < right，兩者相遇代表全部比對完畢。
- 雙指針每次只移動一個 → 整個陣列最多走 n 步 → O(n)。

────────────────────────────────────────────────────────────
手動推導預期輸出（find_pair）
────────────────────────────────────────────────────────────
nums = {1, 3, 5, 7, 9, 11}，target = 14
  step1: left=0(1)  right=5(11) sum=12 < 14 → left++
  step2: left=1(3)  right=5(11) sum=14 == 14 → 找到！

target = 6
  step1: left=0(1)  right=5(11) sum=12 > 6  → right--
  step2: left=0(1)  right=4(9)  sum=10 > 6  → right--
  step3: left=0(1)  right=3(7)  sum=8  > 6  → right--
  step4: left=0(1)  right=2(5)  sum=6  == 6 → 找到！

target = 2
  每次 sum 都 ≥ 1+3=4 > 2，left 不斷追趕 right → 不成立 → 沒有找到

預期 cout 輸出：
  找到：3 + 11 = 14
  找到：1 + 5 = 6
  沒有找到

  racecar 是回文
  hello 不是回文

────────────────────────────────────────────────────────────
可以自己改的小練習
────────────────────────────────────────────────────────────
1. 把 target 改成 20，追蹤 left / right 的移動過程。
2. 試著讓 find_pair 改成「找所有配對」（找到後不 return，繼續移動）。
3. 在 is_palindrome 裡加入忽略大小寫的功能（提示：tolower()）。
────────────────────────────────────────────────────────────
*/
