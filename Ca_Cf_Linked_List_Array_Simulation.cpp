#include <iostream>
using namespace std;

// Codeforces 題目裡很少真的要你手刻 Node* 指來指去。
// 常見做法是：用陣列模擬 linked list。
// nextNode[x] 表示 x 的右邊是誰。
// prevNode[x] 表示 x 的左邊是誰。
// 0 在這裡代表「沒有下一個 / 沒有上一個」。

void printList(int head, const int nextNode[]) {
    int current = head;

    while (current != 0) {
        cout << current << ' ';
        current = nextNode[current];
    }

    cout << '\n';
}

int main() {
    const int maxNode = 7; // 這個範例會用到 1,2,3,4,5,6
    int nextNode[maxNode]{};
    int prevNode[maxNode]{};

    int head = 1;

    // 建立串列：1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 4; ++i) {
        nextNode[i] = i + 1;
        prevNode[i + 1] = i;
    }

    cout << "原本串列: ";
    printList(head, nextNode);

    // 模擬 Codeforces 常見操作：刪掉某個節點。
    // 刪掉 3 的重點不是 delete 記憶體，而是讓 2 直接連到 4。
    int removed = 3;
    int left = prevNode[removed];
    int right = nextNode[removed];

    if (left != 0) {
        nextNode[left] = right;
    } else {
        head = right;
    }

    if (right != 0) {
        prevNode[right] = left;
    }

    nextNode[removed] = 0;
    prevNode[removed] = 0;

    cout << "刪掉 3 後: ";
    printList(head, nextNode);

    // 再示範插入：把 6 插在 2 的後面。
    int newNode = 6;
    int after = 2;
    int oldRight = nextNode[after];

    nextNode[after] = newNode;
    prevNode[newNode] = after;
    nextNode[newNode] = oldRight;

    if (oldRight != 0) {
        prevNode[oldRight] = newNode;
    }

    cout << "2 後面插入 6: ";
    printList(head, nextNode);

    return 0;
}

/*
補充說明：
1. 教科書 linked list 常看到 Node* next，對初學者會覺得很多指標在繞。
2. Codeforces 更常見的思路是「模擬連結關係」：
   - nextNode[x] 記錄 x 的右邊是誰。
   - prevNode[x] 記錄 x 的左邊是誰。
3. 刪除節點 3：
   原本 2 -> 3 -> 4
   修改後 2 -> 4
   所以要改的是 nextNode[2] 和 prevNode[4]。
4. 插入節點 6 到 2 後面：
   原本 2 -> 4
   修改後 2 -> 6 -> 4
5. 手動推導預期輸出：
   原本串列: 1 2 3 4 5
   刪掉 3 後: 1 2 4 5
   2 後面插入 6: 1 2 6 4 5
6. 自己練習：
   把 removed 改成 1，觀察 head 為什麼要更新。
   把 after 改成 5，觀察插在尾端時 oldRight 會是 0。
*/
