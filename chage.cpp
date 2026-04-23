//
// Created by user on 2026/4/21.
//
//["a", "b", "c"] --> ["1: a", "2: b", "3: c"]

//codewars  題目
//不要執行喔

#include <string>
#include <vector>

using namespace std;

vector<string> number(const vector<string> &lines)
{
    // 1. 建立結果容器
    vector<string> result;

    // 2. 效能優化：預先配置記憶體空間，避免 push_back 過程中的動態重分配 (Reallocation)
    result.reserve(lines.size());

    // 3. 疊代處理
    for (size_t i = 0; i < lines.size(); ++i) {
        // 使用 i + 1 作為編號，並組合字串
        // 邏輯：數字 + 分隔符號 + 原字串
        result.push_back(to_string(i + 1) + ": " + lines[i]);
    }

    return result;
}