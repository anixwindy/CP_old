<<<<<<< HEAD
//
// Created by user on 2026/2/16.
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

const ll INF = 1e9+7;
const ll MAXN = 300008;

ll n;
ll a[MAXN];
ll memo[MAXN][7]; // memo[i][last] 代表：處理到第 i 個位置，且前一個數字是 last 時的最少操作數
//
// memo[i][last]=-1)工作還沒做。memo[i][last]>=0) 工作做完了，這是成果。


/*
 * 我們可以用**「找演員」**來比喻：現在的代價 (cost)：
 * 你想在位置 i 請數字 j 來演。
 * 如果 j 剛好就是原本就在那裡的 a[i]，免費（$0$）；
 * 如果不是，你得花錢請他來演（1）。
 * 問未來的價格 (solve(i + 1, j))：
 * 你打了通電話給後面的位置說：「嘿！如果我這格選了 j，你們後面那幾萬個人最少要花多少錢才能排好？」
 * 總價計算：
 * 我的手續費 (cost) + 後面的總報價 (solve) = 如果我選 j 的總成本。
 * 挑最便宜的 (min)：你有 6 個演員可以選，每個演員都會給你一個「總成本」，
 * 你用 res = min(res, ...) 把最省錢的那一個記下來。
 */




// 遞迴函數：i 為當前處理位置，last 為前一個位置的數字
int  solve(int i , int last) {
    if (i>n) return 0;// 1. 終止條件：如果處理超過序列長度，代表不需要再修改，回傳 0
    if (memo[i][last]!=-1)return memo[i][last];// 2. 記憶化：如果這個狀態（第 i 位，前一位是 last）算過了，直接回傳結果
    int res =INF;
    // 3. 嘗試在當前位置 (i) 填入數字 j (1~6)
    for (int j = 1; j <=6; ++j) {
        // 4. 判斷邏輯：如果 i 是第一位 (last=0) 或是與前一位相鄰 (非同面且非對面)
        if (last == 0||(j!=last && j+last !=7)) {
            int cost  =(a[i]== j?0:1);// 如果填入的 j 跟原本 a[i] 一樣，代價是 0，否則代價是 1
            res =min(res,solve(i+1,j)+cost);// 轉移：目前的最小代價 = min(原本, 下一步的結果 + 目前代價)
        }
    }
    return memo[i][last]=res; // 5. 把res存入memo並回傳return
}

void solve02() {
    cin>>n;// 讀取序列長度
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        for (int j = 0; j <=6; ++j) {
            memo[i][j] = -1;// 每一組測資進來，都要初始化當前長度會用到的 memo 空間

        }

    }
    cout<<solve(1,0)<<endl;// 執行完所有輸入後，才計算一次答案並輸出
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve02();
    }

    return 0;
}





=======
//
// Created by user on 2026/2/16.
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

const ll INF = 1e9+7;
const ll MAXN = 300008;

ll n;
ll a[MAXN];
ll memo[MAXN][7]; // memo[i][last] 代表：處理到第 i 個位置，且前一個數字是 last 時的最少操作數
//
// memo[i][last]=-1)工作還沒做。memo[i][last]>=0) 工作做完了，這是成果。


/*
 * 我們可以用**「找演員」**來比喻：現在的代價 (cost)：
 * 你想在位置 i 請數字 j 來演。
 * 如果 j 剛好就是原本就在那裡的 a[i]，免費（$0$）；
 * 如果不是，你得花錢請他來演（1）。
 * 問未來的價格 (solve(i + 1, j))：
 * 你打了通電話給後面的位置說：「嘿！如果我這格選了 j，你們後面那幾萬個人最少要花多少錢才能排好？」
 * 總價計算：
 * 我的手續費 (cost) + 後面的總報價 (solve) = 如果我選 j 的總成本。
 * 挑最便宜的 (min)：你有 6 個演員可以選，每個演員都會給你一個「總成本」，
 * 你用 res = min(res, ...) 把最省錢的那一個記下來。
 */




// 遞迴函數：i 為當前處理位置，last 為前一個位置的數字
int  solve(int i , int last) {
    if (i>n) return 0;// 1. 終止條件：如果處理超過序列長度，代表不需要再修改，回傳 0
    if (memo[i][last]!=-1)return memo[i][last];// 2. 記憶化：如果這個狀態（第 i 位，前一位是 last）算過了，直接回傳結果
    int res =INF;
    // 3. 嘗試在當前位置 (i) 填入數字 j (1~6)
    for (int j = 1; j <=6; ++j) {
        // 4. 判斷邏輯：如果 i 是第一位 (last=0) 或是與前一位相鄰 (非同面且非對面)
        if (last == 0||(j!=last && j+last !=7)) {
            int cost  =(a[i]== j?0:1);// 如果填入的 j 跟原本 a[i] 一樣，代價是 0，否則代價是 1
            res =min(res,solve(i+1,j)+cost);// 轉移：目前的最小代價 = min(原本, 下一步的結果 + 目前代價)
        }
    }
    return memo[i][last]=res; // 5. 把res存入memo並回傳return
}

void solve02() {
    cin>>n;// 讀取序列長度
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        for (int j = 0; j <=6; ++j) {
            memo[i][j] = -1;// 每一組測資進來，都要初始化當前長度會用到的 memo 空間

        }

    }
    cout<<solve(1,0)<<endl;// 執行完所有輸入後，才計算一次答案並輸出
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve02();
    }

    return 0;
}





>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
