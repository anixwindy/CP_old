#include <iostream>
#include <stack>
#include <string>
using namespace std;

// CF 裡的 stack 常見用途：
// 1. 括號配對
// 2. 最近還沒處理完的東西
// 3. 單調堆疊 monotonic stack
//
// stack 的操作：
// push(x)：把 x 放到最上面。
// top()  ：看最上面是誰。
// pop()  ：把最上面拿掉。
// empty()：判斷 stack 是否空了。

bool isValidParentheses(const string& text) {
    stack<char> waiting;

    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            waiting.push(ch);
        } else {
            if (waiting.empty()) {
                return false;
            }

            char left = waiting.top();
            waiting.pop();

            bool matchRound = (left == '(' && ch == ')');
            bool matchSquare = (left == '[' && ch == ']');
            bool matchCurly = (left == '{' && ch == '}');

            if (!matchRound && !matchSquare && !matchCurly) {
                return false;
            }
        }
    }

    return waiting.empty();
}

int main() {
    string text = "([{}])";

    if (isValidParentheses(text)) {
        cout << text << " 是合法括號\n";
    } else {
        cout << text << " 不是合法括號\n";
    }

    return 0;
}

/*
補充說明：
1. stack 是「後進先出」：
   最後 push 進去的東西，會最先被 top() 看到、被 pop() 拿掉。
2. 括號題為什麼適合 stack？
   因為右括號必須配對「最近的一個還沒配對的左括號」。
   這剛好就是 stack 的 top()。
3. 正確邏輯：
   遇到左括號：push。
   遇到右括號：檢查 top() 是否是對應左括號。
   最後 stack 必須是空的，才代表全部都有配對。
4. 常見錯誤：
   只計算左右括號數量一樣，還不夠。
   例如 "([)]" 數量一樣，但順序錯，所以不是合法括號。
5. 手動推導 "([{}])"：
   '(' push
   '[' push
   '{' push
   '}' 配到 '{'，pop
   ']' 配到 '['，pop
   ')' 配到 '('，pop
   stack 變空，所以合法。
6. 自己練習：
   把 text 改成 "([)]"，觀察為什麼會判斷失敗。
*/
