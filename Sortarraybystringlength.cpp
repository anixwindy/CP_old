//
// Created by user on 2026/4/19.
//
//codewars


//sort  + lambdas  範例  不要執行 看code 即可

// Write a function that takes an array of strings as an argument and
// returns a sorted array containing the same strings, ordered from shortest to longest.
//
// For example, if this array were passed as an argument:
//
// ["Telescopes", "Glasses", "Eyes", "Monocles"]
// Your function would return the following array:
//
// ["Eyes", "Glasses", "Monocles", "Telescopes"]
// All of the strings in the array passed to your function will be different lengths,
// so you will not have to decide how to order multiple strings of the same length.


#include <vector>
#include <string>
#include <algorithm>

using namespace std;
std::vector<std::string> sortByLength(std::vector<std::string> array){
    sort(array.begin(), array.end(), [](const string& s1, const string& s2) {
          return s1.length() < s2.length(); // 核心邏輯：長度短的排前面
      });






    return array;
}