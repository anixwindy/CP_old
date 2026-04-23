//
// Created by user on 2026/4/24.
//


//std::map 是一種關聯式容器（Associative Container）。它的核心邏輯是儲存一系列的 鍵值對（Key-Value Pairs）
//技術底層在 C++ 標準函式庫中，std::map 通常是以 紅黑樹（Red-Black Tree） 這種自平衡二元搜尋樹來實作的。
//這意味著：自動排序：地圖中的元素會根據「鍵」的大小自動排列（由小到大）。
//時間複雜度：搜尋、插入、刪除的時間複雜度皆為 log n。
//二、 程式邏輯：基本操作範例要使用 map，你必須包含標頭檔 <map>。
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 1. 宣告與初始化
    // map<鍵類型, 值類型> 變數名;
    map<int, string> numberNames;

    // 2. 插入資料 (三種寫法)
    numberNames[1] = "one";                // 最直覺，若鍵不存在則新增，若存在則覆蓋
    numberNames.insert({2, "two"});        // 較正式的寫法
    numberNames.emplace(3, "three");       // 效率更高，直接在容器內構造物件

    // 3. 搜尋資料
    int target = 2;
    if (numberNames.count(target)) {       // 檢查鍵是否存在 (回傳 0 或 1)
        cout << "找到鍵 " << target << ": " << numberNames[target] << endl;
    }

    // 4. 走訪整個 map (使用迭代器或 Range-based for)
    // 元素會按照鍵的大小排序輸出
    for (auto const& [key, val] : numberNames) {
        cout << key << " -> " << val << endl;
    }

    // 5. 刪除資料
    numberNames.erase(1);

    return 0;
}