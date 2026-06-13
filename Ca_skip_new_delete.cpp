#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 競程常見：一維資料直接用 vector
    // vector 會自己管理記憶體，不需要你手動 new/delete。
    vector<int> scores{10, 20, 30, 40};

    // 二維資料也常直接用 vector<vector<int>>
    // 外層代表 row，內層代表 col。
    vector<vector<int>> grid{
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "一維 vector:\n";
    for (int i{}; i < static_cast<int>(scores.size()); ++i) {
        cout << "scores[" << i << "] = " << scores[i] << '\n';
    }

    cout << "\n二維 vector:\n";
    for (int row{}; row < static_cast<int>(grid.size()); ++row) {
        for (int col{}; col < static_cast<int>(grid[row].size()); ++col) {
            cout << grid[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << "\n不用 new/delete，也能處理很多競程常見資料。\n";
    return 0;
}

/*
補充說明：競程入門可不可以先不主學 new/delete

使用者原本問題：
我能不能放棄學 new/delete？
我只會玩 Codeforces、AtCoder，當成業餘興趣而已。

這份程式示範：
1. 一維資料可以直接用 vector<int>。
2. 二維資料可以直接用 vector<vector<int>>。
3. 不用 new/delete，也能處理很多競程常見資料。

正確觀念：
- 如果只是玩 Codeforces / AtCoder，new/delete 不是現在最優先的主線。
- 你可以先把重點放在：
  1. 陣列索引
  2. vector
  3. string
  4. 二層迴圈
  5. map / set / queue 這類常見容器
- 但不建議完全不知道 new/delete 是什麼。
- 至少要知道：
  1. new 是手動配置記憶體。
  2. delete 是手動釋放記憶體。
  3. 現代競程大多可以先用 vector 取代。

程式執行順序：
1. 建立一維 scores。
2. 建立二維 grid。
3. 用一層迴圈印出 scores。
4. 用兩層迴圈印出 grid。
5. 最後印出提示文字。

靜態推導的預期輸出重點：
scores[0] = 10
scores[1] = 20
scores[2] = 30
scores[3] = 40

1 2 3
4 5 6

不用 new/delete，也能處理很多競程常見資料。

可以自己修改練習：
1. 把 scores 多加幾個值。
2. 把 grid 改成 3 x 3。
3. 把某個元素改掉，自己先猜輸出會變哪裡。

自我檢查：
1. 這題真的需要手動記憶體嗎，還是 vector 就夠了。
2. 我現在卡住的是演算法，還是卡在語法細節。
3. 如果看到別人的 new/delete，我至少能不能認出它是在手動管理記憶體。
*/
