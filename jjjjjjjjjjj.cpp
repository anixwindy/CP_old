
#include <iostream>
#include <format>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <cmath>
#include <numbers>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cctype>


using namespace std;


struct Timer {
    int energy = 100;
};
enum class Day:unsigned char{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday,Unknown};//為了從1開始  不是從0開始直觀

int main() {
    /*
     * 這是註解 對齊的樣板，不對齊，後面code會跑掉
     */
    auto start =  chrono::high_resolution_clock::now();
    cout<<"----------------------"<<'\n';
    cout<<"----------------------"<<'\n';

    cout<<"Hello World!"<<'\n';
    cout<<format("Hello= {}\n",10);
    cout<<"-----------"<<'\n';
    Timer t{}; // 你本意：創立一個 energy 為 100 的物件
     cout << t.energy<<'\n'; //取屬性

    vector<int> v{1,2,3,4,5};
    cout<<v[0]<<'\n';
    cout<<"-----------"<<'\n';

    int c{1111};
    float b{};
    b = static_cast<float>(c);
    cout<<b<<'\n';
    cout<<"-----------"<<'\n';
    unsigned int a{11};
    unsigned int cc{256};
    cout<<a<<'\n';
    auto result{static_cast<unsigned int>(a<<4)};// int 注意32位元， << 等於*2的n次方
    cout<<result<<'\n';
    auto rresult{static_cast<unsigned int>(cc>>4)};// int 注意32位元， << 等於/2的n次方
    cout<<rresult<<'\n';//當你的目的是「二進位資料處理」時  選 unsigned (補 0)
    cout<<"-----------"<<'\n';//當你的目的是「快速數學運算」時  選 int (補 1)
    cout<<"-----------"<<'\n';//左移 都補0；右移signed (有符號，如 int)	視正負號而定 (正補0, 負補1)
    //注意 除不盡
    int mathValue{-5};
    int mmm{-5};
    mathValue = mathValue >> 1;
    mmm = mmm/2;
    cout<<mathValue<<'\n';
    cout<<mmm<<'\n';
    cout<<"----------------------------"<<'\n';
    //其他位元操作 全部跳過
    //下面是  列舉 資料型態
    cout<<"---------------------日期例子----------------------------------------"<<'\n';
    Day day{Day::Monday};
    switch (day) {
        case Day::Monday:
             cout << "週一：憂鬱的一週開始，建議多喝咖啡。" <<  endl;
            break;
        case Day::Tuesday:
        case Day::Wednesday:
        case Day::Thursday:
             cout << "平日：持續工作中..." <<  endl;
            break;
        case Day::Friday:
             cout << "週五：準備迎接週末，心情愉快。" <<  endl;
            break;
        case Day::Saturday:
        case Day::Sunday:
             cout << "週末：放假放起來！" <<  endl;
            break;
            // 理科嚴謹性：雖然 Day 只有七種，但加上 default 是個好習慣
        default:
             cout << "錯誤：未知的日期狀態。" <<  endl;
            break;
    }
    cout<<"-----------"<<'\n';
    cout<<"-----------"<<'\n';

     map< string, Day> dayMap = {
        {"Monday",    Day::Monday},
        {"Tuesday",   Day::Tuesday},
        {"Wednesday", Day::Wednesday},
        {"Thursday",  Day::Thursday},
        {"Friday",    Day::Friday},
        {"Saturday",  Day::Saturday},
        {"Sunday",    Day::Sunday}
    };

    string input{"Monday"};
    cout << "請輸入星期名稱 (如 Monday): ";

    // 2. 查找邏輯 (理科嚴謹性：檢查是否存在)
    Day target;
    if (dayMap.count(input)) {
        // 如果地圖裡有這個鍵
        target = dayMap[input];
    } else {
        target = Day::Unknown;
    }
    // 3. 根據轉換結果執行邏輯
    if (target == Day::Monday) {
         cout << "收到！週一啟動！" <<  endl;
    }else if (target == Day::Tuesday||target == Day::Wednesday||target == Day::Thursday) {
         cout << "平日：持續工作中..." <<  endl;
    }else if (target == Day::Friday) {
         cout << "週五：準備迎接週末，心情愉快。" <<  endl;
    }else if (target == Day::Saturday||target == Day::Sunday) {
         cout << "週末：放假放起來！" <<  endl;
    }else if (target == Day::Unknown) {
         cout << "我不認識這個日期..." <<  endl;
    }
    cout<<"-------------------日期例子-end-----------------------------"<<'\n';
    cout<<"-----------"<<'\n';
    cout<<"-----------"<<'\n';

    //float__double__long double
    //浮點都是 signed

    //數學函數
    //abs(arg)，ceil(arg)，floor(arg)，exp(arg)，log(arg)，log10(arg)，pow(arg1,arg2)，sqrt(arg)，round(arg)
    //1 rad= 180度/pi=57.2958度
    /*
     *1  rad：大約一個等邊三角形的角度（60度）再縮一點點。
     *1.57  rad：就是 pi/2，也就是 90度
     *3.14 rad：就是 pi，也就是 180度
     *6.28 rad：就是 2pi，也就是 $60度
     */
    double angle {1};
    double agle{3.14};
    double cos_value {cos(angle)};
    cout<<cos_value<<'\n';
    cout<<cos(agle)<<'\n';
    double pi = numbers::pi;

    cout << cos(pi) << '\n'; // 輸出會是 -1
    cout<<"-------------------------------------------------"<<'\n';
    //跳過格式化串流輸出，format  可替代
    /*
     * 語法非常直觀：
     *format("格式字串", 變數1, 變數2, ...);
     *在 {} 內部，你可以定義精確的輸出邏輯，其語法縮寫為：
     *{ [索引] : [填充][對齊][寬度][.精度][類型] }
     *
     *
     *<：左對齊（預設）
     *>：右對齊
     *^：置中對齊（這是舊式 cout 做不到的）
     *
     *b：二進位
     *x：十六進位
     *d：十進位
     *
     *
     *.n：代表保留小數點後 n 位。
     *f：固定小數點格式。
     *
     */

    string s1 =  format("{:-^10}", "Hi");
    // 結果: "----Hi----"
    // 寬度 10，左對齊
    string s2 =  format("{:<10}", "C++");
    cout << s1 << "\n" << s2 <<'\n';
    cout<<"-----------"<<'\n';
    int num = 255;
     //  代表顯示前綴 (如 0x)，X 代表大寫
    cout << format("十六進位: {:#X}\n", num); // 0XFF
    cout << format("二進位: {:b}\n", num);
    double pi1 = 3.1415926535;
    // 保留小數點後 2 位
    std::cout << std::format("圓周率: {:.2f}\n", pi1); // 3.14
    // {0} 代表第一個變數，{1} 代表第二個
    std::cout << std::format("{1} 愛 {0}", "C++", "我"); // 我 愛 C++
    cout<<'\n'<<"-----------"<<'\n';
    //c++ 運算子優先權與結合性
    cout<<"-----------"<<'\n';
    cout<<"-----------"<<'\n';
    //比較運算子 < <= > >= == !=
    //+ - * /優於比較運 算 子

    cout<<"-----IF 敘述------"<<'\n';


    // //'A' 的 ASCII 是 65，'Z' 是 90；'a' 是 97，'z' 是 122

    cout<<"------------------------------"<<'\n';
    //檢查
    // isupper(c) islower(c) isalpha(c)  isdigit(c) isxdigit(c)
    //isalnum(c) isspace(c) isblank(c) ispunct(c)  isprint(c) iscntrl(c) isgraph(c)
    //
    //邏輯運算子 && || !

    //_----------------------------------------------

    //3. 位元運算子的「主場」：何時必用 << 與 >>：
    //A. 計算 2^n次方______在處理二進位相關問題時，寫 1 << n 比寫 pow(2, n) good
    //
    //B. 線段樹 (Segment Tree)_____的索引在線段樹中，左子節點通常是 p * 2，右子節點是 p * 2 + 1。
    //
    //競賽選手慣用：左子節點：p << 1右子節點：p << 1 | 1（這裡用 | 1 代替 + 1 是因為 p << 1 必定是偶數，最後一位必定是 0）。
    //
    //C. 狀態壓縮 (Bitmask)____當你要表示「集合中的第 i 個元素」時，1 << i 是唯一的選擇。
    //_----------------------------------------------
    //_----------------------------------------------

    //xor  類似 !=   相同0 不同1
    //xor自反性。單位律。結合律/交換律。
    //位元反 ~  公式  -(X+1)
    //
    //________________________________________________________________________
    // ~ 的常見用法：
    // 找不到資料會回傳 -1；；-1  位元數全 都是 1 ；因為 ~(-1) 的結果剛好是 0。
    //
    //  if (~x) 常用來代替 if (x != -1)。
    //
    //  x & ~1 可以快速把一個數字的最後一位清成 0（不管它原本是 0 還是 1）。
    //「變小取偶」；如果是偶數，就保持不動。
    //
    //if (x & 1)：這代表「如果是奇數就執行」。//x&1 要等於1 為/2餘1  為奇數
    //if (!(x & 1))：這代表「如果是偶數就執行」。
    //

    int age{11};
    int balanceee{1000};
    if ((age<20)!=(balanceee>=100000)){
        cout<<"You can borrow money."<<'\n';
    }

    cout<<"------------------------------"<<'\n';
    vector<int> v6 = {10, 20, 30, 40};
    // 假設我們用一個會回傳 -1 的搜尋邏輯
    int target00= 50;
    int index = -1; // 預設沒找到
    // 邏輯：~(-1) 會變成 0 (false)，其餘數字翻轉後都不會是 0
    if (~index) {
        //不等於-1
        cout << "找到了！索引在：" << index << endl;
    } else {
        cout << "沒找到 (-1 翻轉後變 0，所以進到這裡)" << endl;
    }


    cout<<"------------------------------"<<'\n';
    int aa = 7;
    int bb = -7;
    // 7 (0111) & ~1 (1110) = 0110 (6)
    cout << "7 處理後變成：" << (aa & ~1) << endl;
    // 8 (1000) & ~1 (1110) = 1000 (8)
    cout << "-7 處理後變成：" << (bb & ~1) << endl;

    cout<<"------------------------------"<<'\n';

    int nn3{99};
    int nn4{0};
    // 如果 n 的最後一位是 1，代表是奇數
    if (nn3 & 1) {
        cout << nn3 << " 是奇數 (Odd)" << endl;
    }
    // 如果 n 的最後一位「不是」1，代表是偶數
    if (!(nn3 & 1)) {
        cout << nn3 << " 是偶數 (Even)" << endl;
    }
    if (!nn4) {
        cout<<"等於0"<<endl;
    }


    cout<<"x != -1"<<endl;
    cout<<"x & ~1"<<endl;
    cout<< "(x & 1)"<<endl;
    cout<<"!(x & 1)"<<endl;
    cout<<"n << 1 相當於 n * 2"<<endl;
    cout<<"n >> 1 相當於 n / 2。"<<endl;
    cout<<"n & 1 相當於 n % 2（判斷奇偶數，這比 % 快得多）"<<endl;
    cout<<"檢查是否為 0： if (!x) 等於 if (x == 0)。 "<<endl;
    cout<<" 雙重否定 (!!)：這是為了把任何非零數字標準化為 1。例如 !!5 會變成 1。"<<endl;





    cout<<"------------------------------"<<'\n';








    cout<<"----------------------"<<'\n';
    cout<<"----------------------"<<'\n';
    auto end =  chrono::high_resolution_clock::now();
    // 計算差值
    chrono::duration<double> diff = end - start;
    cout << "Time spent: " << diff.count() << " s" <<  endl;
    return 0;
}