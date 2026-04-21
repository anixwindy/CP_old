#include<iostream>
#include<format>
#include <cstdlib>
#include<vector>



using namespace std;
int main() {

	


	{
		//一元運算子
		int a = 10;
		cout << endl << a << endl;
		cout << +a << endl;
		cout << -a << endl;
		cout << ~a << endl;
		cout << !a << endl;
		cout << endl << "-----------------" << endl;

		/*
		~a 是位元補數運算子，執行的是一補數（所有位元反轉）

		a = 10 → 0000 1010
			~a → 1111 0101 = -11（以二補數解讀）

			所以 ~10 = -11，也可以記為：~n = -(n + 1)


			簡單來說
			概念說明~運算子執行一補數操作（位元反轉）結果解讀用二補數表示法（C++的int標準）

			類比
			就像：

			你用計算機按了某個按鈕（一補數操作）
			螢幕顯示的數字是用某種格式呈現的（二補數表示法）

			「操作」和「表示法」是兩回事！
			~ 做一補數的動作，但得到的數字是用二補數格式儲存和顯示的*/
	}

	{
		/*算術運算子 + - *   / %
		  關係運算子> < >= <= == !=
		  遞增遞減運算子 a++ ++a a-- --a++__[[(visual c++編譯器 該行結束才加)]]
		  簡潔算式+= -= *= /= %=
		  */
		  //記得邏輯，看一下
		int ab = 2;
		int ac = 3;
		ab *= ac++;
		cout << format("ab*=ac++結果ab={},ac={}", ab, ac) << endl;
		int abb = 2;
		int acb = 3;
		abb *= ++acb;
		cout << format("abb*=++acb結果abb={},acb={}", abb, acb) << endl;
		cout << endl << "-----------------" << endl;
	}

	{
		/*邏輯運算子
		&&  ||
		*/
		/*強制轉換資料型態
		(欲轉換資料型態) 變數名稱；
		如(int) a
		(double) b
		預設小轉大 整數轉浮點數 char轉int bool變成0,1

		*/
	}
	
	{
		//ch5選擇性敘述與迴圈
		//if--else if--else
		/*
		min = (a < b) ? a : b;
		運算結果=(判斷邏輯)?__a__:___b__
		等於 if(a<b)
		{_a_;}
		else
		{_b_;}
		*/
		int a = 5, b = 12, min;
		min = (a < b) ? a : b;
		cout << format("a={},b={}", a, b) << endl;
		cout << format("min={}", min) << endl;
		cout << endl << "-----------------" << endl;

	}
	{
		//for 迴圈
		/* ------方法一-------- */
		// 輸出 1 到 10
		for (int i = 0; i < 10; i++) {
			cout << i+1 << " ";
		}
		cout << endl << "---" << endl;
		/* ------方法二-------- */
		// 先準備一個陣列或容器
		int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		// 自動遍歷每個元素
		for (int num : arr) {
			cout << num << " ";
		}
		cout << endl << "---" << endl;
		/* ------方法三-------- */

		// 從 10 到 1
		for (int i = 10; i >= 1; i--) {
			cout << i << " ";
		}
		cout << endl << "---" << endl;
		/* ------方法四-------- */

		// 只輸出奇數：1 3 5 7 9
		for (int i = 1; i <= 10; i += 2) {
			cout << i << " ";
		}

		// 輸出偶數：2 4 6 8 10
		for (int i = 2; i <= 10; i += 2) {
			cout << i << " ";
		}
		cout << endl << "---" << endl;
		/* ------方法五-------- */

		// 同時控制兩個變數
		for (int i = 1, j = 10; i <= 10; i++, j--) {
			cout << i << "," << j << " ";
		}
		// 輸出：1,10 2,9 3,8 4,7 5,6 6,5 7,4 8,3 9,2 10,1
		cout << endl << "---" << endl;


		/* ------方法六-------- */

		for (;;) {  // 三個部分都省略
			static int i = 1;
			if (i > 10) break;
			cout << i << " ";
			i++;
		}
		// 輸出：1 2 3 4 5 6 7 8 9 10

		cout << endl << "-----------------" << endl;

	}
	{
		//非區域變數

		int i, sum = 0;
		for (i = 1; i <= 4; i++)
			sum += i;
		cout << format("1+2+3+4={}", sum)<<endl;
		cout << endl << "---" << endl;
		//區域變數
		/*此時j只在迴圈裡存在，區域變數*/
		int sum1 = 0;
		for (int j = 1; j <= 4; j++) {
			sum1 += i;
			cout << format("j={},sum={}", j, sum) << endl;
		}
		
		cout << endl << "------------------" << endl;
	}
	{
		//while迴圈
		int num, i = 1, sum = 0;
		cout << format("請輸入整數值：\n") ;
		cin >> num;
		/* (條件)   當條件為False 跳出   */
		while (i <= num) {
			sum += i;
			i++;

		}
		cout << format("1+2+...+{}={}", num, sum);
		cout << endl << "-----------------" << endl;
	}
	{
		// do while 迴圈
		
		int n, i = 1, sum = 0;
		do {
			cout << format("請輸入欲累加的最大奇數值：\n");
			cin >> n;
		} while (n < 1 || n % 2 == 0);/*符合條件，你輸入不對，重輸*/
		do {
			sum += i;
			i += 2;

		} while (i <= n);/*符合條件，重跑迴圈；不符合，跳出*/
		cout << format("1+3+...+{}={}\n", n, sum);
		
		cout << endl << "-----------------" << endl;
	}
	{
		// 巢狀迴圈
		int i, j;
		for (i = 1; i <= 3; i++) {
			for (j = 1; j <= 3; j++) {
				cout << format("{}*{}={}\n", i, j, i * j);

			}
		}

		cout << endl << "-----------------" << endl;
	}
	{
		// break 與 continue

		int i;
		for (i = 1; i <= 20; i++) {
			if (i % 4 == 0)
				continue;/*跳過本次迴圈，進入下一次迴圈*/
			if (i % 19 == 0)
				break;/*跳出迴圈*/ 
			cout << format("i={}\n", i);
		}
		cout << format("when loop interruped,i={}\n", i);

		cout << endl << "-----------------" << endl;
	}
	{
		// switch 選擇性敘述
		/*switch 像查目錄一樣，查到目錄後，執行對應的內容*/
		int month ;
		cout << format("請輸入月份(1-12)：\n");
		cin >> month;
		cout << format("month={}\n", month);
		switch (month) {
			case 3:
			case 4:
			case 5:cout << format("春天\n"); break;
			case 6:
			case 7:
			case 8:cout << format("夏天\n"); break;
			case 9:
			case 10:
			case 11:cout << format("秋天\n"); break;
			case 12:
			case 1:
			case 2:cout << format("冬天\n"); break;
			default:cout << format("月份錯誤\n"); break;

		}
		cout << endl << "---" << endl;
		cout << endl << "-----------------" << endl;
	}
	{
		// 


		cout << endl << "---" << endl;
		cout << endl << "-----------------" << endl;
	}
	{
		// 


		cout << endl << "---" << endl;
		cout << endl << "-----------------" << endl;
	}
	{
		// 


		cout << endl << "---" << endl;
		cout << endl << "-----------------" << endl;
	}
	{
		// 


		cout << endl << "---" << endl;
		cout << endl << "-----------------" << endl;
	}
	
	return 0;
}