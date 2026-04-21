<<<<<<< HEAD
//
//
//
//
//判斷質數
//
#include <iostream>

using namespace std;

/**
 * 函數名稱：isPrime
 * 邏輯：判斷一個整數 n 是否為質數
 * 時間複雜度：O(sqrt(n))
 */
bool isPrime(int n1) {
    // 1. 處理邊界條件：小於等於 1 的數不是質數
    if (n1 <= 1) {
        return false;
    }
    // 2. 核心邏輯：從 2 檢查到 n 的平方根
    // 為什麼寫 i * i <= n 而不是 i <= sqrt(n)？
    // 因為 i * i 是整數運算，速度快且不會有浮點數精度問題。
    for (int i = 2; i * i <= n1; i++) {
        // 如果 n 能被 i 整除，說明 n 有除了 1 和自己以外的因數
        if (n1 % i == 0) {
            return false; // 找到因數，立即判定為非質數（合數）
        }
    }
    // 3. 如果迴圈跑完都沒有找到因數，則為質數
    return true;
}

bool isPrimeV3(int n) {
    // 1. 處理基礎特例
    if (n <= 1) return false;
    if (n <= 3) return true; // 2 和 3 是質數
    // 2. 排除所有 2 和 3 的倍數 (快速剪枝)
    if (n % 2 == 0 || n % 3 == 0) return false;
    // 3. 核心：只檢查 6k-1 和 6k+1 的位置
    // 從 5 開始 (5 是第一個 6k-1)，每次跳 6 格
    for (int i = 5; i * i <= n; i += 6) {
        // 檢查 i (即 6k-1) 和 i + 2 (即 6k+1)
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int num;
    cout << "請輸入一個整數：";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " 是質數。" << endl;
    } else {
        cout << num << " 不是質數。" << endl;
    }

    cout<<"--------"<<endl;

    int x;
    cout << "請輸入一個整數again：";
    cin >> x;
    // 2. 在這裡呼叫它
    if (isPrimeV3(x)) {
        cout << x << " 是質數。" << endl;
    } else {
        cout << x << " 不是質數。" << endl;
    }





    return 0;
=======
//
//
//
//
//判斷質數
//
#include <iostream>

using namespace std;

/**
 * 函數名稱：isPrime
 * 邏輯：判斷一個整數 n 是否為質數
 * 時間複雜度：O(sqrt(n))
 */
bool isPrime(int n1) {
    // 1. 處理邊界條件：小於等於 1 的數不是質數
    if (n1 <= 1) {
        return false;
    }
    // 2. 核心邏輯：從 2 檢查到 n 的平方根
    // 為什麼寫 i * i <= n 而不是 i <= sqrt(n)？
    // 因為 i * i 是整數運算，速度快且不會有浮點數精度問題。
    for (int i = 2; i * i <= n1; i++) {
        // 如果 n 能被 i 整除，說明 n 有除了 1 和自己以外的因數
        if (n1 % i == 0) {
            return false; // 找到因數，立即判定為非質數（合數）
        }
    }
    // 3. 如果迴圈跑完都沒有找到因數，則為質數
    return true;
}

bool isPrimeV3(int n) {
    // 1. 處理基礎特例
    if (n <= 1) return false;
    if (n <= 3) return true; // 2 和 3 是質數
    // 2. 排除所有 2 和 3 的倍數 (快速剪枝)
    if (n % 2 == 0 || n % 3 == 0) return false;
    // 3. 核心：只檢查 6k-1 和 6k+1 的位置
    // 從 5 開始 (5 是第一個 6k-1)，每次跳 6 格
    for (int i = 5; i * i <= n; i += 6) {
        // 檢查 i (即 6k-1) 和 i + 2 (即 6k+1)
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int num;
    cout << "請輸入一個整數：";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " 是質數。" << endl;
    } else {
        cout << num << " 不是質數。" << endl;
    }

    cout<<"--------"<<endl;

    int x;
    cout << "請輸入一個整數again：";
    cin >> x;
    // 2. 在這裡呼叫它
    if (isPrimeV3(x)) {
        cout << x << " 是質數。" << endl;
    } else {
        cout << x << " 不是質數。" << endl;
    }





    return 0;
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}