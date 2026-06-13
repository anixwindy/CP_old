#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 方式 1：內建二維陣列，列數和欄數都是固定的
    // table1[row][col]：row 代表第幾列，col 代表第幾欄
    int table1[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };

    // 方式 2：std::array 包住 std::array，大小也是固定的
    // 外層 array 有 2 列，內層 array<int, 3> 代表每列有 3 欄
    array<array<int, 3>, 2> table2{{
        {7, 8, 9},
        {10, 11, 12}
    }};

    // 方式 3：vector 裡放 vector，大小可以比較彈性
    // 每一列的長度可以由資料本身決定，競程和練習常用這種寫法
    vector<vector<int>> table3{
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "方式1：內建二維陣列\n";
    // 二維資料常用兩層 for：
    // 外層控制 row，內層控制 col。
    for (int row{}; row < 2; ++row) {
        for (int col{}; col < 3; ++col) {
            cout << table1[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << "\n方式2：std::array 的二維資料\n";
    for (int row{}; row < 2; ++row) {
        for (int col{}; col < 3; ++col) {
            cout << table2[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << "\n方式3：vector 的二維資料\n";
    // vector 的大小可以用 size() 取得，比手動寫死列數欄數更彈性。
    for (int row{}; row < static_cast<int>(table3.size()); ++row) {
        for (int col{}; col < static_cast<int>(table3[row].size()); ++col) {
            cout << table3[row][col] << ' ';
        }
        cout << '\n';
    }

    // 可以自己練習：把 2 和 3 改成其他列數、欄數，觀察輸出怎麼變
    return 0;
}

/*
補充說明：二維陣列的 3 種建立方式

使用者原本問題：
介紹多維陣列 3 種建立方式，並輸出出來。

這份程式示範：
1. int table1[2][3]
   - 內建二維陣列。
   - 列數和欄數都固定。
   - 初學時最直覺，但大小不能在執行中自由改變。

2. array<array<int, 3>, 2>
   - 標準函式庫的固定大小容器。
   - 外層代表列，內層代表欄。
   - 大小仍然固定，但比內建陣列更像一般 C++ 容器。

3. vector<vector<int>>
   - vector 裡面再放 vector。
   - 列數和每列欄數可以比較彈性。
   - 競程或一般練習裡很常見。

正確觀念：
- 不管用哪一種方式，只要概念上是「列 + 欄」，
  存取時通常都會長得像 data[row][col]。
- row 是第幾列。
- col 是第幾欄。
- 輸出二維資料時，通常外層 for 跑 row，內層 for 跑 col。

程式執行順序：
1. 建立 table1、table2、table3 三種二維資料。
2. 印出方式 1 的標題。
3. 用 row 和 col 走訪 table1[row][col]。
4. 印出方式 2 的標題，再走訪 table2[row][col]。
5. 印出方式 3 的標題，再走訪 table3[row][col]。

靜態推導的預期輸出：
方式1：內建二維陣列
1 2 3
4 5 6

方式2：std::array 的二維資料
7 8 9
10 11 12

方式3：vector 的二維資料
13 14 15
16 17 18

和 Book_06.cpp 的差異：
- 這份 Copy_2d_array.cpp 只教一件事：
  二維資料怎麼建立、怎麼用兩層迴圈輸出。
- Book_06.cpp 同時混入指標、new/delete、vector、三維陣列、
  sizeof 推導維度、chrono、format 等多個主題。
- 所以 Book_06.cpp 難，不只是因為多維陣列，而是一次出現太多新觀念。

可以自己修改練習：
1. 把其中一個數字改掉，確認輸出位置是否跟著改。
2. 把 table1 改成 2 x 4，再同步修改迴圈條件。
3. 在每一列前面加上 cout << "第" << row << "列：";

自我檢查：
1. 我能不能先說出資料是幾列幾欄。
2. 我有沒有用 data[row][col] 存取元素。
3. 我知道目前寫法是固定大小，還是可變大小。
*/
