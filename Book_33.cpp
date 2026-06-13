#include <iostream>
#include <vector>

using namespace std;

void print_flat_new_array() {
    int rows{2};
    int cols{3};
    int* matrix = new int[rows * cols]{};

    // 用一維索引模擬二維：row * 欄數 + col
    for (int row{}; row < rows; ++row) {
        for (int col{}; col < cols; ++col) {
            matrix[row * cols + col] = row * 10 + col;
        }
    }

    cout << "方式1：new[] 配一維空間，手動當成二維來印\n";
    for (int row{}; row < rows; ++row) {
        for (int col{}; col < cols; ++col) {
            cout << matrix[row * cols + col] << ' ';
        }
        cout << '\n';
    }

    delete[] matrix;
}

void print_vector_of_vectors() {
    vector<vector<int>> table{
        {10, 11, 12},
        {20, 21, 22}
    };

    cout << "\n方式2：vector<vector<int>>，直接用 table[row][col]\n";
    for (int row{}; row < 2; ++row) {
        for (int col{}; col < 3; ++col) {
            cout << table[row][col] << ' ';
        }
        cout << '\n';
    }
}

void print_three_dimensional_array() {
    double carrots[2][3][4]{
        {
            {12.0, 2.0, 515.0, 4.0},
            {14.0, 2.0, 525.0, 4.1},
            {16.0, 2.0, 535.0, 4.2}
        },
        {
            {10.0, 10.0, 15.0, 5.0},
            {14.0, 8.0, 25.0, 5.1},
            {18.0, 6.0, 35.0, 5.2}
        }
    };

    cout << "\n方式3：內建三維陣列 carrots[page][row][col]\n";
    for (int page{}; page < 2; ++page) {
        cout << "第 " << page << " 層\n";
        for (int row{}; row < 3; ++row) {
            for (int col{}; col < 4; ++col) {
                cout << carrots[page][row][col] << ' ';
            }
            cout << '\n';
        }
    }
}

void print_flat_vector() {
    int rows{2};
    int cols{3};
    vector<int> matrix(rows * cols, 0);

    // 和方式1很像，只是改用 vector 自動管理記憶體
    for (int row{}; row < rows; ++row) {
        for (int col{}; col < cols; ++col) {
            matrix[row * cols + col] = row * 100 + col;
        }
    }

    cout << "\n方式4：vector<int> 配一維空間，手動當成二維來印\n";
    for (int row{}; row < rows; ++row) {
        for (int col{}; col < cols; ++col) {
            cout << matrix[row * cols + col] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    print_flat_new_array();
    print_vector_of_vectors();
    print_three_dimensional_array();
    print_flat_vector();
    return 0;
}
