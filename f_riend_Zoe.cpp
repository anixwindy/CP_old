//
// Created by user on 2026/4/10.
//
/*
* Make a program that filters a list of strings and returns a list with only your friends name in it.

If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours! Otherwise, you can be sure he's not...

Input = ["Ryan", "Kieran", "Jason", "Yous"]
Output = ["Ryan", "Yous"]

Input = ["Peter", "Stephen", "Joe"]
Output = []
 */


//codewars   不要執行  看邏輯；太多細節


#include <string>
#include <vector>

using namespace std;

std::vector<std::string> friendOrFoe(const std::vector<std::string>& input) {
    // Good luck!
    vector<string> tt;

    for(int i=0;i<input.size();++i){
        if(input[i].size()==4){
            tt.push_back(input[i]);

        }

    }return tt;