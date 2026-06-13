//
// Created by user on 2026/4/27.
//
//Leetcode

// Example 1:
//
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:
//
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
//
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//


#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string s0 = to_string(x);
        string s = s0;
        reverse(s.begin(), s.end());
        if(s0==s){
            return true;
        }else{
            return false;
        }

    }
};