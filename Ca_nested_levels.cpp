#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 兩層：外層放列，內層放每列的 int
    // fixed2d[列][欄]
    array<array<int, 3>, 3> fixed2d{{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};

    // dynamic2d 也是兩層，只是每一層用 vector，大小比較彈性
    vector<vector<int>> dynamic2d{
        {10, 11, 12},
        {20, 21, 22},
        {30, 31, 32}
    };

    // 三層：page -> row -> col
    array<array<array<int, 2>, 2>, 2> fixed3d{{
        {{{1, 2}, {3, 4}}},
        {{{5, 6}, {7, 8}}}
    }};

    // new[] 可以先做一維，再用公式模擬二維、三維
    // 這裡只是示範舊式手動記憶體觀念；競程通常優先用 vector。
    int* oneDim = new int[3]{100, 101, 102};

    int cols{3};
    int* twoDim = new int[2 * cols]{};
    // 二維公式：row * cols + col
    twoDim[1 * cols + 2] = 99;

    int pages{2};
    int rows{2};
    int depthCols{2};
    int* threeDim = new int[pages * rows * depthCols]{};
    // 三維公式：page * rows * cols + row * cols + col
    threeDim[1 * rows * depthCols + 0 * depthCols + 1] = 77;

    cout << "fixed2d[1][2] = " << fixed2d[1][2] << '\n';
    cout << "dynamic2d[1][2] = " << dynamic2d[1][2] << '\n';
    cout << "fixed3d[1][0][1] = " << fixed3d[1][0][1] << '\n';
    cout << "oneDim[2] = " << oneDim[2] << '\n';
    cout << "twoDim[1][2] -> twoDim[1 * cols + 2] = " << twoDim[1 * cols + 2] << '\n';
    cout << "threeDim[1][0][1] -> threeDim[1 * rows * depthCols + 0 * depthCols + 1] = "
         << threeDim[1 * rows * depthCols + 0 * depthCols + 1] << '\n';

    delete[] oneDim;
    delete[] twoDim;
    delete[] threeDim;
    return 0;
}

/*
補充說明：兩層、三層容器，以及 new[] 模擬多維資料

使用者原本問題：
vector<vector<int>> 和 array<array<int, 3>, 3> 都算兩層嗎？
那三層呢？
傳統 new/delete 的 1 維、2 維、3 維都能做嗎？

這份程式示範：
1. array<array<int, 3>, 3>
   - 外層有 3 個元素。
   - 每個元素都是 array<int, 3>。
   - 所以它是兩層固定大小資料。

2. vector<vector<int>>
   - 外層 vector 裡面放的是 vector<int>。
   - 所以它也是兩層資料。
   - 大小比 array 彈性。

3. array<array<array<int, 2>, 2>, 2>
   - 可以理解成 page -> row -> col。
   - 也就是第幾頁、第幾列、第幾欄。

4. new[]
   - new[] 本身只是配置一整段連續空間。
   - 如果想把它當二維用，要自己把 row 和 col 換算成一維索引。
   - 如果想把它當三維用，也要自己寫索引公式。

重要公式：
1. 一維：
   index

2. 二維：
   row * cols + col

3. 三維：
   page * rows * cols + row * cols + col

程式執行順序：
1. 建立兩層的 fixed2d 和 dynamic2d。
2. 建立三層的 fixed3d。
3. 用 new[] 建立 oneDim、twoDim、threeDim。
4. 對 twoDim 用二維索引公式存入 99。
5. 對 threeDim 用三維索引公式存入 77。
6. 印出代表性的元素。
7. 用 delete[] 釋放 oneDim、twoDim、threeDim。

靜態推導的預期輸出：
fixed2d[1][2] = 6
dynamic2d[1][2] = 22
fixed3d[1][0][1] = 6
oneDim[2] = 102
twoDim[1][2] -> twoDim[1 * cols + 2] = 99
threeDim[1][0][1] -> threeDim[1 * rows * depthCols + 0 * depthCols + 1] = 77

注意：
- 這份程式示範 new/delete 是為了理解舊式寫法。
- 如果只是競程入門，多數情況優先用 vector，比較不容易忘記 delete[]。

可以自己修改練習：
1. 把 fixed2d[1][2] 改成 fixed2d[2][0]，先猜答案。
2. 把 twoDim[1 * cols + 2] = 99; 改成別的位置，自己先算索引。
3. 把 threeDim 的公式改成存到別的 page、row、col。

自我檢查：
1. 我能不能先說出外層容器裡放的是什麼型別。
2. 如果是三層，我能不能翻成「第幾頁 / 第幾列 / 第幾欄」。
3. 如果看到 new[]，我能不能判斷它是一維，還是用公式模擬多維。
*/
