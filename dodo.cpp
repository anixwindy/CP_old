<<<<<<< HEAD
//
// Created by user on 2026/1/29.
//
#include <iostream>
#include <format>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void sum(int),fact(int);


int main() {


    /* auto i=0  auto 被重新定義為類型推導（Type Deduction）。
        如果你寫 auto i = 10;，編譯器會自動推斷 i 是 int。
 ____________________________________
    extern int i：跨檔案的「廣播員」
    當你的專案有多個 .cpp 檔案時，extern 是用來實現「檔案間共享變數」的橋樑。
    它的本質：宣告（Declaration）而非定義（Definition）。
    寫在""函數"外部"""/全域（內部連結性）

    現實情境：
    你在 A.cpp 定義了 int i = 100;。
    你在 B.cpp 想要用這個 i，你就必須寫 extern int i;。放在int main(){}裡

    int i =1 -->int main(){} 和 void ___(){} 中間， 獨自放在所有{} 外
    這告訴編譯器：「i 這傢伙確實存在，但不在我這，等連結器（Linker）來的時候，再去別的檔案找它。」
-------------------------------------
    三、 static int i：多重身分的「隱士」
    static 是 C++ 中最容易讓人混淆的關鍵字，因為它在不同地方有完全不同的邏輯：

    1. 寫在函數內部（局部靜態變數）
    static int i=10;放在函式裡
    行為：函數執行完，變數不會消失。下次進來函數，它還保留上次的值。
    底層邏輯：它不放在 Stack，而是放在 資料段（Data Segment）。它在程式啟動時初始化一次，直到程式結束才銷毀。

    2. 寫在函數外部/全域（內部連結性）
     static int i;-->int main(){} 前面， 獨自放在所有{} 外
    行為：這個變數只能在「該 .cpp 檔案」內使用。
    現實意義：防止命名衝突。即使別的檔案也定義了同名的 static int i，兩者互不干擾。這是一種"""封裝""的展現。

    */




    int a =5;
    fact(a);
    sum(a);

    return 0;

}
//  一個cpp用2個函式  舉例
void fact (int a) {
    int i =1, total=1;
    for ( i=1;i<=a;i++)
        total*=i;
    cout<<format("1*2*3+....{}={}",a,total)<<'\n';
    return;

}

void sum (int a) {
    int i =1, sum=0;
    for ( i=1;i<=a;i++)
        sum+=i;
    cout<<format("1+2+3+....{}={}",a,sum)<<'\n';
    return;

}









=======
//
// Created by user on 2026/1/29.
//
#include <iostream>
#include <format>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void sum(int),fact(int);


int main() {


    /* auto i=0  auto 被重新定義為類型推導（Type Deduction）。
        如果你寫 auto i = 10;，編譯器會自動推斷 i 是 int。
 ____________________________________
    extern int i：跨檔案的「廣播員」
    當你的專案有多個 .cpp 檔案時，extern 是用來實現「檔案間共享變數」的橋樑。
    它的本質：宣告（Declaration）而非定義（Definition）。
    寫在""函數"外部"""/全域（內部連結性）

    現實情境：
    你在 A.cpp 定義了 int i = 100;。
    你在 B.cpp 想要用這個 i，你就必須寫 extern int i;。放在int main(){}裡

    int i =1 -->int main(){} 和 void ___(){} 中間， 獨自放在所有{} 外
    這告訴編譯器：「i 這傢伙確實存在，但不在我這，等連結器（Linker）來的時候，再去別的檔案找它。」
-------------------------------------
    三、 static int i：多重身分的「隱士」
    static 是 C++ 中最容易讓人混淆的關鍵字，因為它在不同地方有完全不同的邏輯：

    1. 寫在函數內部（局部靜態變數）
    static int i=10;放在函式裡
    行為：函數執行完，變數不會消失。下次進來函數，它還保留上次的值。
    底層邏輯：它不放在 Stack，而是放在 資料段（Data Segment）。它在程式啟動時初始化一次，直到程式結束才銷毀。

    2. 寫在函數外部/全域（內部連結性）
     static int i;-->int main(){} 前面， 獨自放在所有{} 外
    行為：這個變數只能在「該 .cpp 檔案」內使用。
    現實意義：防止命名衝突。即使別的檔案也定義了同名的 static int i，兩者互不干擾。這是一種"""封裝""的展現。

    */




    int a =5;
    fact(a);
    sum(a);

    return 0;

}
//  一個cpp用2個函式  舉例
void fact (int a) {
    int i =1, total=1;
    for ( i=1;i<=a;i++)
        total*=i;
    cout<<format("1*2*3+....{}={}",a,total)<<'\n';
    return;

}

void sum (int a) {
    int i =1, sum=0;
    for ( i=1;i<=a;i++)
        sum+=i;
    cout<<format("1+2+3+....{}={}",a,sum)<<'\n';
    return;

}









>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
