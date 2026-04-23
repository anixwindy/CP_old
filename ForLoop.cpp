//
// Created by user on 2026/4/24.
//
/*
 * For each integer n in the inclusive interval[a,b] :
 *
 *If  1<=n<=9 , then print the English representation of it in lowercase. That is "one" for 1, "two" for 2 , and so on.
 *Else if n>9 and it is an even number, then print "even".
 *Else if n>9 and it is an odd number, then print "odd".
 * Note: [a,b] = {a,a+1....b}
 */

//HackerRank

/*
 *
 * Sample Input
 *
 *    8
 *   11
 *   Sample Output
 *
 * eight
 * nine
 * even
 * odd
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int a{};
    int b{};
    cin>>a>>b;
    string c[]={"","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=a;i<=b;++i){

        if(i>=1 && i<=9){
            cout<<c[i]<<endl;
        }
        else if(i>9){

            if(i&1){
                cout<<"odd"<<endl;
            }else{
                cout<<"even"<<endl;
            }
        }

    }
    return 0;
}
/*
map<int, string> num_map = {
    {1, "one"}, {2, "two"}, {3, "three"},
    {4, "four"}, {5, "five"}, {6, "six"},
    {7, "seven"}, {8, "eight"}, {9, "nine"}
};

if (num_map.count(i)) {
    cout << num_map[i] << endl;
} else {
    // 處理 i > 9 的邏輯
}

*/