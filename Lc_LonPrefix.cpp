//
// Created by user on 2026/5/1.
//
//Leetcode
//
//
//Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// //
//要 刪 flower  :  flight ->fligh ->flig->fli ->fl
//
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            // 檢查 strs[i] 是否以 prefix 開頭
            // 如果不是，就把 prefix 變短
            while(strs[i].find(prefix) != 0){
                prefix.pop_back();
            }
        }

        return prefix;
    }
};