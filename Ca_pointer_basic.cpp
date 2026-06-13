#include <iostream>

using namespace std;

int main() {
    cout << "範例 1：指標指向陣列第一格\n";

    int arr[5]{1, 2, 3, 4, 5};

    // arr 在這裡可以當成 arr[0] 的地址。
    // p1 存著 arr[0] 的地址，所以 *p1 會讀到 arr[0] 的值。
    int* p1 = arr;

    cout << "arr[0] = " << arr[0] << '\n';
    cout << "*p1 = " << *p1 << '\n';

    // 指標往下一格，會從 arr[0] 改成指向 arr[1]。
    ++p1;
    cout << "p1 往下一格後，*p1 = " << *p1 << '\n';

    cout << "\n範例 2：指標指向單一變數\n";

    int value{10};

    // &value 代表取得 value 的地址。
    // p2 存著 value 的地址，所以 *p2 可以讀取或修改 value。
    int* p2 = &value;

    cout << "value 原本是 " << value << '\n';
    cout << "*p2 讀到的是 " << *p2 << '\n';

    *p2 = 20;

    cout << "執行 *p2 = 20 之後\n";
    cout << "value 變成 " << value << '\n';

    return 0;
}

/*
補充說明：指標、取地址、解參考

使用者原本問題：
像 int arr[5] = {1,2,3,4,5};
int* p = arr;
cout << *p;
以及
int value = 10;
int* p = &value;
*p = 20;
這種看不懂。

這份程式示範兩件事：
1. 陣列名稱 arr 在很多情況下可以當成第一個元素 arr[0] 的地址。
2. &value 代表取得 value 這個變數的地址。

三個常混淆的符號：
1. int* p;
   - 這是宣告。
   - p 是一個指標，裡面放的是 int 的地址。

2. &value
   - 這是取地址。
   - 意思是拿到 value 這個變數住在哪裡。

3. *p
   - 這是解參考。
   - 意思是去 p 存的那個地址，看裡面的值。
   - 如果寫 *p = 20，就是把 p 指到的那個地方改成 20。

程式執行順序：
1. 建立陣列 arr{1, 2, 3, 4, 5}。
2. int* p1 = arr; 讓 p1 指向 arr[0]。
3. *p1 讀到 arr[0]，所以是 1。
4. ++p1 讓 p1 往下一格，改成指向 arr[1]。
5. 此時 *p1 讀到 arr[1]，所以是 2。
6. 建立變數 value{10}。
7. int* p2 = &value; 讓 p2 指向 value。
8. *p2 讀到 value，所以是 10。
9. *p2 = 20; 透過指標把 value 改成 20。

靜態推導的預期輸出重點：
arr[0] = 1
*p1 = 1
p1 往下一格後，*p1 = 2

value 原本是 10
*p2 讀到的是 10
執行 *p2 = 20 之後
value 變成 20

可以自己修改練習：
1. 把 ++p1 再多做一次，先猜 *p1 會變多少。
2. 把 *p2 = 20 改成 *p2 = 99，觀察 value 應該變成多少。
3. 把 int* p2 = &value; 讀成一句中文：p2 存著 value 的地址。

自我檢查：
1. 看到 int* p，先問：p 是不是用來存地址。
2. 看到 &value，先問：是不是在拿 value 的地址。
3. 看到 *p，先問：是不是要去 p 指到的地方讀值或改值。
*/
