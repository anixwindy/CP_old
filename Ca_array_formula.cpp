#include <iostream>
using namespace std;

int main() {
    // 一維陣列：直接用 index，不需要把它想得很複雜。
    int scores[3]{10, 20, 30};
    cout << "一維 scores[1] = " << scores[1] << '\n';

    // 二維陣列：平常直接用 [row][col]。
    int table[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };

    int row{1};
    int col{2};
    cout << "二維 table[1][2] = " << table[row][col] << '\n';

    // 只有當資料被放成「一整排」時，才需要自己用公式換算。
    int flatTable[6]{1, 2, 3, 4, 5, 6};
    int flatIndex{row * 3 + col}; // 3 是欄數 cols
    cout << "壓成一維後 flatTable[1 * 3 + 2] = "
         << flatTable[flatIndex] << '\n';

    // 三維陣列：平常也可以直接用 [page][row][col]。
    int box[2][2][3]{
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };

    int page{1};
    row = 0;
    col = 2;
    cout << "三維 box[1][0][2] = " << box[page][row][col] << '\n';

    // 三維如果壓成一維，才會需要這種公式。
    int flatBox[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int rows{2};
    int cols{3};
    int flat3dIndex{page * rows * cols + row * cols + col};
    cout << "壓成一維後 index = " << flat3dIndex << '\n';
    cout << "所以 flatBox[" << flat3dIndex << "] = "
         << flatBox[flat3dIndex] << '\n';

    return 0;
}
