#include <iostream>
#include <list>
using namespace std;

// ══════════════════════════════════════
// 1. 單向靜態鏈表（數組模擬）
//    nxt[i] = -1 表示尾端（相當於 nullptr）
// ══════════════════════════════════════
const int N = 100;
int sv[N], snxt[N];
int sh = -1, sc = 0;   // sh: 頭節點 index，sc: 下一個可用格子

void s_push(int v) {   // 從頭插入 O(1)
    sv[sc] = v;
    snxt[sc] = sh;
    sh = sc++;
}
void s_print() {
    for (int i = sh; i != -1; i = snxt[i])
        cout << sv[i] << (snxt[i] != -1 ? " -> " : "\n");
}

// ══════════════════════════════════════
// 2. 雙向靜態鏈表（數組模擬）
//    多一個 prv[] 紀錄前一個節點 index
// ══════════════════════════════════════
int dv[N], dnxt[N], dprv[N];
int dh = -1, dt = -1, dc = 0;  // dh: 頭, dt: 尾

void d_push(int v) {   // 從尾插入 O(1)
    dv[dc] = v;
    dnxt[dc] = -1;
    dprv[dc] = dt;
    if (dt != -1) dnxt[dt] = dc; else dh = dc;  // 原尾的 nxt 指向新節點
    dt = dc++;
}
void d_remove(int i) { // 刪除 index i，O(1)
    if (dprv[i] != -1) dnxt[dprv[i]] = dnxt[i]; else dh = dnxt[i];
    if (dnxt[i] != -1) dprv[dnxt[i]] = dprv[i]; else dt = dprv[i];
}
void d_print() {
    for (int i = dh; i != -1; i = dnxt[i])
        cout << dv[i] << (dnxt[i] != -1 ? " <-> " : "\n");
}

// ══════════════════════════════════════
// 3. STL list（雙向鏈表，動態分配）
// ══════════════════════════════════════
void stl_demo() {
    list<int> L = {1, 2, 3, 4, 5};
    L.push_front(0);   // 頭插
    L.push_back(6);    // 尾插
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (*it == 3) { L.erase(it); break; }  // 刪值 3
    }
    for (int x : L) cout << x << " ";
    cout << '\n';
}

int main() {
    cout << "單向：";
    s_push(3); s_push(2); s_push(1);   // 從頭插：結果順序 1->2->3
    s_print();

    cout << "雙向（刪前）：";
    d_push(1); d_push(2); d_push(3); d_push(4);
    d_print();
    cout << "雙向（刪後）：";
    d_remove(1);   // index 1 的節點，值為 2
    d_print();

    cout << "STL list：";
    stl_demo();

    return 0;
}

/*
【易卡住的觀念】
  - 數組模擬鏈表：index 就是「指標」，-1 就是 nullptr
  - d_remove 要同時修改前後兩側的指向，少一邊就斷鏈
  - STL list 的 iterator 在 erase 後失效，所以要 break

【正確觀念】
  - 靜態鏈表不會真正「刪除」數組格子，只是把指向繞過去
  - 數組版比動態 new/delete 版快，競賽優先用數組版
  - STL list 不支援隨機存取（沒有 L[i]），只能用 iterator 走訪

【手動推導的預期輸出】
  單向：1 -> 2 -> 3
  雙向（刪前）：1 <-> 2 <-> 3 <-> 4
  雙向（刪後）：1 <-> 3 <-> 4
  STL list：0 1 2 4 5 6

【可以自己改的小練習】
  把 d_push 改成從頭插入（d_push_front），
  再試試刪除尾端節點（d_remove(dt)），看輸出是否正確。
*/
