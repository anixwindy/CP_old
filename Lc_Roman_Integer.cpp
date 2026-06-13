//
// Created by user on 2026/4/28.
//
//Roman to Integer

//Leetcode

// Example 1:
//
// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:
//
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:
//
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.



#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:

    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int sum{0};
        for (int i = 0; i < s.size(); i++) {
            // 邏輯核心：如果當前比後面的小，就減去當前值；否則加上
            // 技巧：i < s.size() - 1 確保不會越界
            if (i < s.size() - 1 && m[s[i]] < m[s[i+1]]) {
                sum -= m[s[i]];
            } else {
                sum += m[s[i]];
            }
        }



        return sum;


    }
};