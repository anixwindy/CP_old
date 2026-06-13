//

//
#include <bits/stdc++.h>
 using namespace std;

// 型別縮寫
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// 常用巨集
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb      push_back
#define fi      first
#define se      second

// Yes / No 常數（配合 string solve() 用）
const string yes = "Yes", no = "No";



    string solve() {
        int n;
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vi c(n);  // 反向映射陣列


        //         原始陣列語義：
        // a[i] = x   →   「伐木工 (i+1) 說斧頭 x 是他的」
        // 索引 = 伐木工, 值 = 斧頭
        //
        // 反向映射目標：
        // c[x] = (i+1)  →   「斧頭 x 的聲稱者是伐木工 (i+1)」
        // 索引 = 斧頭, 值 = 伐木工
        //
        // ---
        // 所以 c[a[i] - 1] = i + 1 做的事：
        //
        // a[i]     → 這個值就是斧頭編號，拿來當新索引
        // i + 1    → 原本的索引（伐木工編號），變成新的值
        // -1       → 斧頭編號是 1-based，陣列是 0-based，對齊用
        //



        // 建立反向映射：斧頭 a[i] 的聲稱者是伐木工 (i+1)
        for (int i = 0; i < n; i++) {
            c[a[i] - 1] = i + 1;   // 直接賦值！不是 insert！
        }

        // 比較：c[j] 應該等於 b[j]（斧頭 j+1 的聲稱者 == 真正主人）
        for (int i = 0; i < n; i++) {
            if (c[i] != b[i]) return no;
        }
        return yes;
    }






int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) cout << solve() << "\n";
}

//單組
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout << solve() << "\n";
// }

