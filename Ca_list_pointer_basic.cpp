#include <iostream>
#include <list>

using namespace std;

int main() {
    // std::list 可以想成很多節點串起來：
    // 10 <-> 20 <-> 30
    // 它不像 array 或 vector 那樣適合用 numbers[1] 直接取資料。
    list<int> numbers{10, 20, 30};

    cout << "std::list 不是用 numbers[1] 這種方式讀資料\n";
    cout << "它比較像一個一個節點用指標串起來\n\n";

    auto it = numbers.begin();

    // iterator 可以理解成「目前走到哪個節點」。
    // *it 代表讀取目前節點裡的值。
    cout << "第一個節點的值: " << *it << '\n';

    // list 沒有 numbers[1] 這種隨機索引，所以用 ++it 走到下一個節點。
    ++it;
    cout << "往下一個節點後的值: " << *it << '\n';

    // 這裡拿到第二個元素的位址，只是示範「元素在記憶體中也有位址」
    int* secondAddress = &(*it);

    cout << "第二個元素目前的值: " << *secondAddress << '\n';

    numbers.push_front(5);
    numbers.push_back(40);

    cout << "\n在前面和後面新增元素後:\n";

    for (int value : numbers) {
        cout << value << ' ';
    }

    cout << "\n\n原本第二個元素的位址仍然指向值: ";
    cout << *secondAddress << '\n';

    cout << "\n重點: 平常使用 list 時，用 iterator 走訪，不直接操作內部指標。\n";

    return 0;
}

/*
補充說明：std::list 和指標的關係

使用者原本問題：
你可以教我常見 C++ list 與指針的關係與例子。

這份程式示範：
1. std::list 不是陣列，也不是 vector。
2. std::list 比較像一個一個節點串起來。
3. 平常使用 list 時，通常用 iterator 走訪。
4. list 內部確實和指標概念有關，但初學使用時不需要直接操作 next / prev 指標。

原本可能卡住的觀念：
- 初學者容易把 list 想成另一種陣列，期待可以寫 numbers[1]。
- 但 std::list 不支援這種隨機索引。
- 如果要走到下一個元素，通常用 iterator 做 ++it。

正確觀念：
- numbers.begin() 取得第一個節點的位置。
- *it 讀取目前節點的值。
- ++it 移動到下一個節點。
- &(*it) 可以取得目前元素本身的位址，但平常不需要靠這個操作 list。

程式執行順序：
1. 建立 list<int> numbers{10, 20, 30}。
2. 用 numbers.begin() 取得第一個元素的位置。
3. 用 *it 讀出 10。
4. 用 ++it 走到下一個元素。
5. 再用 *it 讀出 20。
6. 用 &(*it) 取得第二個元素的位址。
7. push_front(5) 和 push_back(40) 在前後新增元素。
8. 用 range for 印出整個 list。
9. 再讀取原本第二個元素的位址，觀察它仍然是 20。

靜態推導的預期輸出重點：
第一個節點的值: 10
往下一個節點後的值: 20
第二個元素目前的值: 20

在前面和後面新增元素後:
5 10 20 30 40

原本第二個元素的位址仍然指向值: 20

可以自己修改練習：
1. 把 numbers 改成 {3, 6, 9}，重新手推 iterator 走到哪裡。
2. 把 push_front(5) 改成 push_front(1)。
3. 多寫一次 ++it，先猜會讀到哪個元素。

自我檢查：
1. 我現在用的是陣列 / vector，還是 list。
2. 如果是 list，我是不是不該期待 numbers[1]。
3. 我能不能分清楚 iterator 是走訪工具，指標是記憶體位址。
*/
