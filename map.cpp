<<<<<<< HEAD
//
// Created by user on 2026/2/28.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    string s;
    if (!(cin >> s)) return;
    vi cnt(26,0);
    int max_map= 0;
    for (auto &c : s) {//鏡子
        cnt[c-'a']++;
        max_map = max(max_map,cnt[c-'a']);
    }for (char c:s){//copy一份
        if (cnt[c-'a']!=max_map) cout<<c;
    }cout<<endl;
/*
 * 1. 電腦眼中的字母（ASCII 碼）電腦其實不認識 a、b、c。
 * 在它眼裡，這些都是數字（ASCII 碼）：'a' = 97'b' = 98'c' = 99...以此類推。2.
 * 減法運算：歸一化（Normalization）我們準備了一個長度為 26 的陣列 cnt，索引（Index）是 0 到 25
 * 。
 * 但字元是 97、98... 怎麼辦？這時我們用相對位移：c - 'a'如果 c 是 'a'： $97 - 97 = 0
 * 對應到 cnt[0]如果 $c$ 是 'b'： $98 - 97 = 1 對應到 cnt[1].
 * 如果 c 是 'z'： 122 - 97 = 25對應到 cnt[25]
 * 3. ++ 的動作cnt[c - 'a']++
 * 整句的意思就是：「找到這個字母對應的那個桶子（$0$ 到 $25$），然後往裡面丟一個硬幣（加 1）。」
 * 四、 批判性思考（Critical Thinking）這段程式碼有一個致命的假設：它假設輸入一定是「小寫英文」。
 * 如果輸入是 A（大寫）？ASCII 碼中 'A' 是 65。計算會變成 $65 - 97 = -32$。cnt[-32]++ 會發生什麼事？
 * 程式會去修改它不該碰的記憶體區域，這就是惡名昭彰的 Buffer Overflow（緩衝區溢位），
 * 這也是為什麼你的程式會突然當機或出現怪事。如
 * 果輸入是空白？
 * ' ' 的 ASCII 是 32。 $32 - 97 = -65$，同樣會讓程式崩潰。
 * 所以，當你看到 cnt[c - 'a'] 時，腦袋裡要立刻反應：這是一個具有「邊界條件限制」的邏輯。
 */


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;


    while(t--) {
        solve();
    }

    return 0;
=======
//
// Created by user on 2026/2/28.
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve() {
    string s;
    if (!(cin >> s)) return;
    vi cnt(26,0);
    int max_map= 0;
    for (auto &c : s) {//鏡子
        cnt[c-'a']++;
        max_map = max(max_map,cnt[c-'a']);
    }for (char c:s){//copy一份
        if (cnt[c-'a']!=max_map) cout<<c;
    }cout<<endl;
/*
 * 1. 電腦眼中的字母（ASCII 碼）電腦其實不認識 a、b、c。
 * 在它眼裡，這些都是數字（ASCII 碼）：'a' = 97'b' = 98'c' = 99...以此類推。2.
 * 減法運算：歸一化（Normalization）我們準備了一個長度為 26 的陣列 cnt，索引（Index）是 0 到 25
 * 。
 * 但字元是 97、98... 怎麼辦？這時我們用相對位移：c - 'a'如果 c 是 'a'： $97 - 97 = 0
 * 對應到 cnt[0]如果 $c$ 是 'b'： $98 - 97 = 1 對應到 cnt[1].
 * 如果 c 是 'z'： 122 - 97 = 25對應到 cnt[25]
 * 3. ++ 的動作cnt[c - 'a']++
 * 整句的意思就是：「找到這個字母對應的那個桶子（$0$ 到 $25$），然後往裡面丟一個硬幣（加 1）。」
 * 四、 批判性思考（Critical Thinking）這段程式碼有一個致命的假設：它假設輸入一定是「小寫英文」。
 * 如果輸入是 A（大寫）？ASCII 碼中 'A' 是 65。計算會變成 $65 - 97 = -32$。cnt[-32]++ 會發生什麼事？
 * 程式會去修改它不該碰的記憶體區域，這就是惡名昭彰的 Buffer Overflow（緩衝區溢位），
 * 這也是為什麼你的程式會突然當機或出現怪事。如
 * 果輸入是空白？
 * ' ' 的 ASCII 是 32。 $32 - 97 = -65$，同樣會讓程式崩潰。
 * 所以，當你看到 cnt[c - 'a'] 時，腦袋裡要立刻反應：這是一個具有「邊界條件限制」的邏輯。
 */


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;


    while(t--) {
        solve();
    }

    return 0;
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}