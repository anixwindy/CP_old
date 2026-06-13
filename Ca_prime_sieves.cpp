#include <iostream>
#include <vector>
using namespace std;

// 這個函式只負責把質數表印出來。
// const vector<int>& 的意思是：
// 1. 不複製整份 vector，節省時間。
// 2. const 保證這個函式不會修改 primes。
void printPrimes(const vector<int>& primes) {
    for (int prime : primes) {
        cout << prime << ' ';
    }
    cout << '\n';
}

// 埃氏篩 Sieve of Eratosthenes
// 目的：找出 2 到 limit 之間的所有質數。
//
// 核心想法：
// 1. 先假設每個數都是質數。
// 2. 從 2 開始，如果 i 還是質數，就把 i 的倍數標成不是質數。
// 3. 最後沒被標掉的數，就是質數。
vector<int> eratosthenesSieve(int limit) {
    // isPrime[x] == true 代表目前先認為 x 是質數。
    vector<bool> isPrime(limit + 1, true);

    // primes 用來保存最後找到的質數。
    vector<int> primes;

    // 0 和 1 不是質數，先手動排除。
    isPrime[0] = false;
    isPrime[1] = false;

    // 只需要處理到 i * i <= limit。
    // 因為如果一個合數有因數，至少有一個因數會 <= sqrt(limit)。
    for (int i{2}; i * i <= limit; ++i) {
        if (isPrime[i]) {
            // 從 i * i 開始標記，而不是從 i * 2。
            // 原因：比 i * i 小的倍數，前面已經被更小的質數處理過。
            //
            // 埃氏篩的特色：
            // 一個合數可能會被不同質數重複標記。
            // 例如 30 可能被 2、3、5 的倍數流程碰到。
            for (int multiple{i * i}; multiple <= limit; multiple += i) {
                isPrime[multiple] = false;
            }
        }
    }

    // 把仍然是 true 的數字收集起來。
    for (int i{2}; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// 歐拉篩 Euler's Sieve，又稱線性篩
// 目的：一樣是找出 2 到 limit 之間的所有質數。
//
// 核心想法：
// 每個合數只被「最小質因數」標記一次。
// 所以它的時間複雜度可以做到 O(N)。
vector<int> eulerSieve(int limit) {
    // isComposite[x] == true 代表 x 已經被確認是合數。
    // composite 是「合數」的意思。
    vector<bool> isComposite(limit + 1, false);

    // primes 保存目前已經找到的質數。
    // 歐拉篩會邊找質數，邊用這些質數去標記合數。
    vector<int> primes;

    // i 從 2 掃到 limit，每個數都會被處理一次。
    for (int i{2}; i <= limit; ++i) {
        // 如果 i 沒有被標記成合數，代表它是質數。
        if (!isComposite[i]) {
            primes.push_back(i);
        }

        // 用目前已知的質數 prime 去標記 i * prime。
        for (int prime : primes) {
            // 超過 limit 就不用繼續標記。
            if (i * prime > limit) {
                break;
            }

            // 把 i * prime 標記成合數。
            // 例：i = 6, prime = 5，代表 30 是合數。
            isComposite[i * prime] = true;

            // 這行是歐拉篩最重要的地方。
            //
            // 如果 i 可以被 prime 整除：
            // 1. prime 就是 i 的某個質因數。
            // 2. 後面再用更大的質數去乘 i，會讓合數被重複標記。
            // 3. 所以這裡要 break。
            //
            // 直覺記法：
            // 歐拉篩靠這個 break，讓每個合數只被最小質因數標記一次。
            if (i % prime == 0) {
                break;
            }
        }
    }

    return primes;
}

int main() {
    // 想練習可以先改這個數字，例如改成 50 或 100。
    int limit{30};

    // 兩種方法找出來的質數應該一樣。
    // 差別在於內部「標記合數」的方式不同。
    cout << "埃氏篩找到的質數：";
    printPrimes(eratosthenesSieve(limit));

    cout << "歐拉篩找到的質數：";
    printPrimes(eulerSieve(limit));

    return 0;
}

/*
補充說明：埃氏篩與歐拉篩的差異

使用者原本問題：
你給我埃氏篩 Sieve of Eratosthenes、歐拉篩法 Euler's Sieve，又稱線性篩；
你之前的 cpp 是甚麼方式取質數？

後續補充：
希望在 Copy_prime_sieves.cpp 裡面直接放註解，方便比較，不要只靠 .md 看說明。

這份程式示範：
1. eratosthenesSieve()
   - 埃氏篩。
   - 用質數去標記它的倍數。
   - 某些合數可能被重複標記。

2. eulerSieve()
   - 歐拉篩，也叫線性篩。
   - 每個合數只被自己的最小質因數標記一次。

和之前 Copy_prime_methods.cpp 的關係：
- Copy_prime_methods.cpp 前半段的 isPrime() 是單一數字試除法。
- Copy_prime_methods.cpp 後半段列出 limit 以內質數的部分是埃氏篩。
- 不是歐拉篩。

原本可能卡住的觀念：
1. isPrime(n) 是判斷一個數字是不是質數。
2. 埃氏篩是找出 1 到 N 的所有質數。
3. 歐拉篩也是找出 1 到 N 的所有質數，但標記合數的方式更精準。

正確觀念：
- 如果只問一個數字 n 是不是質數，可以用試除法，檢查到 sqrt(n)。
- 如果要找出 1 到 N 的所有質數，通常用篩法。
- 埃氏篩時間複雜度常記成 O(N log log N)。
- 歐拉篩因為每個合數只被標記一次，所以時間複雜度是 O(N)。

程式執行順序：
1. main() 設定 limit = 30。
2. 呼叫 eratosthenesSieve(30)。
3. 埃氏篩先假設所有數字都是質數。
4. 從 2 開始，把質數的倍數標成不是質數。
5. 收集仍然是質數的數字。
6. 呼叫 eulerSieve(30)。
7. 歐拉篩從 2 掃到 30。
8. 如果目前數字還沒被標記成合數，就加入質數表。
9. 用目前已知的質數去標記 i * prime。
10. 如果 i % prime == 0，代表這個 prime 是 i 的最小質因數，標記完就停止。

靜態推導的預期輸出：
埃氏篩找到的質數：2 3 5 7 11 13 17 19 23 29
歐拉篩找到的質數：2 3 5 7 11 13 17 19 23 29

可以自己修改練習：
1. 把 limit 改成 50，觀察兩種方法輸出是否一樣。
2. 在埃氏篩的內層迴圈加 cout，觀察哪些倍數被標記。
3. 在歐拉篩的內層迴圈加 cout，觀察 i * prime 何時被標記。

自我檢查：
1. 如果只判斷一個數字，用試除法即可。
2. 如果要找一整段質數，先想到篩法。
3. 埃氏篩重點是「質數標記倍數」。
4. 歐拉篩重點是「每個合數只被最小質因數標記一次」。
5. 競賽裡通常用 vector，不用自己手動 new/delete。
*/
