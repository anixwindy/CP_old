#include <iostream>

using namespace std;

void add_one_by_pointer(int* number_ptr) {
    // 這裡的 * 出現在宣告：number_ptr 是「指向 int 的指標」
    // 下面的 * 出現在使用：代表「走到指標指向的那個 int」
    *number_ptr = *number_ptr + 1;
}

void add_one_by_reference(int& number_ref) {
    // 這裡的 & 出現在宣告：number_ref 是 value 的另一個名字
    number_ref = number_ref + 1;
}

int main() {
    int value = 10;

    cout << "原本 value = " << value << '\n';

    // & 出現在運算式：取出 value 的位址
    int* pointer = &value;

    // * 出現在宣告：pointer 是「指向 int 的指標」
    // * 出現在運算式：讀取 pointer 指向的值
    cout << "pointer 指向的值 = " << *pointer << '\n';

    // * 出現在運算式左邊：修改 pointer 指向的值
    *pointer = 20;
    cout << "用 *pointer 修改後，value = " << value << '\n';

    // & 出現在宣告：reference 是 value 的參考，也就是 value 的別名
    int& reference = value;
    reference = 30;
    cout << "用 reference 修改後，value = " << value << '\n';

    add_one_by_pointer(&value);
    cout << "呼叫 add_one_by_pointer(&value) 後，value = " << value << '\n';

    add_one_by_reference(value);
    cout << "呼叫 add_one_by_reference(value) 後，value = " << value << '\n';

    int a = 6;
    int b = 3;

    // * 也可以是乘法
    cout << "a * b = " << a * b << '\n';

    // & 也可以是位元 AND，不是取址，也不是參考
    cout << "6 & 3 = " << (a & b) << '\n';

    return 0;
}

/*
補充說明：C++ 裡 * 和 & 的常見意思

使用者原本問題：
我可以分別問 C++ 裡會出現的 * 和 C++ 裡會出現的 & 有哪些地方會使用到。

這份程式示範：
* 常見意思：
1. int* pointer
   - 宣告指標。
   - pointer 是一個用來存 int 位址的變數。

2. *pointer
   - 解參考。
   - 走到 pointer 指向的位置，讀取或修改那裡的 int。

3. a * b
   - 乘法。

& 常見意思：
1. &value
   - 取址。
   - 取得 value 這個變數的位址。

2. int& reference
   - 宣告參考。
   - reference 是 value 的另一個名字。

3. a & b
   - 位元 AND。
   - 不是取址，也不是參考。

正確觀念：
- 不要只看符號本身，要看它出現的位置。
- 在型別旁邊：通常是宣告指標或參考。
- 在變數前面：& 通常是取址，* 通常是解參考。
- 在兩個值中間：* 通常是乘法，& 通常是位元 AND。

程式執行順序：
1. main() 建立 value = 10。
2. 用 &value 取得 value 的位址，存進 pointer。
3. 用 *pointer 讀取 value。
4. 用 *pointer = 20 修改 value。
5. 用 int& reference = value 建立參考。
6. 用 reference = 30 修改 value。
7. 呼叫 add_one_by_pointer(&value)，用指標讓函式修改 value。
8. 呼叫 add_one_by_reference(value)，用參考讓函式修改 value。
9. 示範 a * b 是乘法。
10. 示範 a & b 是位元 AND。

靜態推導的預期輸出：
原本 value = 10
pointer 指向的值 = 10
用 *pointer 修改後，value = 20
用 reference 修改後，value = 30
呼叫 add_one_by_pointer(&value) 後，value = 31
呼叫 add_one_by_reference(value) 後，value = 32
a * b = 18
6 & 3 = 2

位元 AND 補充：
6 的二進位是 110
3 的二進位是 011
AND 後是     010
010 等於 2

可以自己修改練習：
1. 把 value = 10 改成 value = 100，重新手推輸出。
2. 把 *pointer = 20 改成 *pointer = 50。
3. 把 a = 6、b = 3 改成其他數字，練習位元 AND。

自我檢查：
1. 先看 * 或 & 是在型別旁邊、變數前面，還是兩個值中間。
2. 如果在型別旁邊，通常是在宣告指標或參考。
3. 如果在變數前面，& 通常是取址，* 通常是解參考。
4. 如果在兩個值中間，* 通常是乘法，& 通常是位元 AND。
*/
