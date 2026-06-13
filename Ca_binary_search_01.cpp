#include <iostream>
#include <vector>
using namespace std;

// ── 二分法（Binary Search）──
// 在「已排序陣列」中，每次把搜尋範圍對半砍掉。
// 時間複雜度：O(log n)；n=1000000 只需約 20 次比較。

// ── 版本 1：找「恰好等於 target」的索引 ──
int binary_search_exact(const vector<int>& arr, int target) {
    int left  = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {              // 注意：left == right 仍要比
        int mid = left + (right - left) / 2;  // 避免 (left+right) 溢位

        if (arr[mid] == target) {
            return mid;                  // 找到，回傳索引
        } else if (arr[mid] < target) {
            left = mid + 1;              // target 在右半，丟掉左半
        } else {
            right = mid - 1;             // target 在左半，丟掉右半
        }
    }
    return -1;                           // 找不到
}

// ── 版本 2：找「第一個 >= target」的索引（lower_bound 概念）──
// 常用於：找插入位置、計數、範圍查詢
int lower_bound_manual(const vector<int>& arr, int target) {
    int left  = 0;
    int right = (int)arr.size();         // 注意右邊界是 size()，非 size()-1

    while (left < right) {               // 注意：left == right 時已收斂
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;                 // arr[mid] >= target，保留 mid
        }
    }
    return left;                         // 第一個 >= target 的位置
}

int main() {
    vector<int> nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    // 版本 1：精確搜尋
    int idx = binary_search_exact(nums, 23);
    if (idx != -1)
        cout << "找到 23，在索引 " << idx << '\n';
    else
        cout << "找不到\n";

    idx = binary_search_exact(nums, 10);
    if (idx != -1)
        cout << "找到 10，在索引 " << idx << '\n';
    else
        cout << "10 不在陣列中\n";

    cout << '\n';

    // 版本 2：lower_bound
    cout << "第一個 >= 16 的位置：" << lower_bound_manual(nums, 16) << '\n'; // 4
    cout << "第一個 >= 15 的位置：" << lower_bound_manual(nums, 15) << '\n'; // 4（15不存在，插入點）
    cout << "第一個 >= 100 的位置：" << lower_bound_manual(nums, 100) << '\n'; // 10（尾端）

    return 0;
}

/*
────────────────────────────────────────────────────────────
易卡住的觀念
────────────────────────────────────────────────────────────
1. 「while (left <= right) 還是 while (left < right)？」
   版本 1（精確搜尋）：<= ，因為 left==right 那格還沒比。
   版本 2（lower_bound）：< ，right 設為 size()，收斂時 left==right 就是答案。
   兩種各有用途，混用就容易差一格（off-by-one）。

2. 「mid = (left + right) / 2 有什麼問題？」
   left=2^30, right=2^30 → left+right 溢位 int。
   改成 mid = left + (right - left) / 2 永遠安全。

3. 「找不到時為什麼回傳 -1 不是 0？」
   索引 0 是合法位置，-1 是「無效值」慣例，讓呼叫端能分辨。

4. 「二分法一定要排序嗎？」
   是的。沒排序就沒有單調性，無法判斷往左還是往右縮。

────────────────────────────────────────────────────────────
正確觀念
────────────────────────────────────────────────────────────
- 每次迴圈把範圍對半：n → n/2 → n/4 → … → 1，共 log₂n 步。
- mid = left + (right - left) / 2 是標準寫法。
- lower_bound 的右界是 size()（開區間），回傳的是「插入仍保持有序的位置」。
- C++ 標準庫有 std::lower_bound、std::upper_bound，原理相同。

────────────────────────────────────────────────────────────
手動推導預期輸出（版本 1，搜尋 23）
────────────────────────────────────────────────────────────
nums = {2,5,8,12,16,23,38,56,72,91}，索引 0~9
target = 23

step1: left=0  right=9  mid=4  arr[4]=16 < 23 → left=5
step2: left=5  right=9  mid=7  arr[7]=56 > 23 → right=6
step3: left=5  right=6  mid=5  arr[5]=23 == 23 → 回傳 5  ✓

target = 10
step1: left=0  right=9  mid=4  arr[4]=16 > 10 → right=3
step2: left=0  right=3  mid=1  arr[1]=5  < 10 → left=2
step3: left=2  right=3  mid=2  arr[2]=8  < 10 → left=3
step4: left=3  right=3  mid=3  arr[3]=12 > 10 → right=2
left(3) > right(2) → 回傳 -1  ✓

預期 cout 輸出：
  找到 23，在索引 5
  10 不在陣列中

  第一個 >= 16 的位置：4
  第一個 >= 15 的位置：4
  第一個 >= 100 的位置：10

────────────────────────────────────────────────────────────
可以自己改的小練習
────────────────────────────────────────────────────────────
1. 搜尋 91（最後一個元素）和 2（第一個元素），追蹤 mid 怎麼移動。
2. 實作 upper_bound：找「第一個 > target」的索引（只改一個符號）。
3. 用 lower_bound_manual 計算陣列中有幾個數等於某個值：
   count = upper_bound_pos - lower_bound_pos
────────────────────────────────────────────────────────────
*/
