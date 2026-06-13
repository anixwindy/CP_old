//
// Created by user on 2026/5/3.
//
//
//
// Example 1:
//
// Input: s = "()"
//
// Output: true
//
// Example 2:
//
// Input: s = "()[]{}"
//
// Output: true
//
// Example 3:
//
// Input: s = "(]"
//
// Output: false
//
// Example 4:
//
// Input: s = "([])"
//
// Output: true
//
// Example 5:
//
// Input: s = "([)]"
//
// Output: false
//
// Constraints:
//
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
//
//

// 它的意思是：
//
// 目前看到的右括號 c	它應該配的左括號 mp[c]
// ')'    _________    	'('
// ']'	   _________     '['
// '}'	   _________      '{'


class Solution {
public:
    bool isValid(string s) {
        vector<char> a;
        map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // 如果 c 是左括號
            if (c == '(' || c == '[' || c == '{') {
                a.push_back(c);
            }
            else {
                if (a.empty()) {
                    return false;
                }

                if(a[a.size()-1]==mp[c]){

                    a.pop_back();
                }
                else{
                    return false;
                }
            }

        }
        if (a.empty()) {
            return true;
        }else{
            return false;
        }
    }

};

