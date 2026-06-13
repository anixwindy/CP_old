//
// Created by user on 2026/4/24.
//
//Leetcode
//
// 沒有 int main  不要執行喔
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> discovered;


        for (int i = 0; i < nums.size(); i++) {

            // 對於每個數字 nums[i] 來說，其要找到對應的數為 target - nums[i]。
            // 例如，假設 num[i] = 2，其要找的數字就是 target - 2。
            int num_to_find = target - nums[i];


            if (discovered.find(num_to_find) == discovered.end()) {

                // 假使我們從 Hash Table 找不到 num_to_find，
                // 那就先把目前的數字作為 Key、其 Index 作為 Value 暫存起來（未來該數可能是、也可能不是答案之一）。
                discovered[nums[i]] = i;

            } else {

                // 反之，假使在儲存清單存在 num_to_find（意味該數曾經查看過），
                // 代表我們已經找到答案了。
                // 因此回傳 num_to_find 的 Index 及目前所在的 Index。
                return vector<int>{discovered[num_to_find], i};
            }
        }

        return {};
    }
};