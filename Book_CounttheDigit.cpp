//
// Created by user on 2026/4/18.
//

//codwars  題目

// Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer.
//
// Square all numbers k (0 <= k <= n) between 0 and n.
//
// Count the numbers of digits d used in the writing of all the k**2.
//
// Implement the function taking n and d as parameters and returning this count.
//
// Examples:
// n = 10, d = 1
// the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
// We are using the digit 1 in: 1, 16, 81, 100. The total count is then 4.
//
// The function, when given n = 25 and d = 1 as argument, should return 11 since
// the k*k that contain the digit 1 are:
// 1, 16, 81, 100, 121, 144, 169, 196, 361, 441.
// So there are 11 digits 1 for the squares of numbers between 0 and 25.
// Note that 121 has twice the digit 1.



//1-n-->取平方
//有幾個 d 阿拉伯數字  數數看
//需要%10==d  數
//需要/=10    去降位(如 千->百-->十...)




#include <bits/stdc++.h>
using namespace std;
class CountDig
{
public:
    static int nbDig(int n, int d)
    {
        int cnt =0;
        for(int k =0;k<=n;++k){
            long long temp = (long long)k * k;
            if( temp ==0 && d==0)cnt+=1;
            while(temp>0){
                if (temp % 10 == d) {
                    cnt++; // 抓到一個標籤！
                }
                temp /= 10; // 剝掉一層皮，往下一位前進
            }
        }
        return cnt;
    }
};
