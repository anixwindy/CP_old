#include <array>
#include <concepts>
#include <iostream>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <vector>

using namespace std;

// C++20：concept 可以限制模板參數，讓錯誤訊息比較接近「型別不符合」
// 這裡示範的是「模板限制」，不是初學者一開始就必須熟練的語法。
template <typename T>
concept Number = is_arithmetic_v<T>;

template <Number T>
T add_numbers(T left, T right) {
    return left + right;
}

void show_cpp11() {
    cout << "=== C++11 ===\n";

    // C++11：nullptr 代表空指標，比舊式 NULL 更明確
    int* pointer = nullptr;
    if (pointer == nullptr) {
        cout << "nullptr: pointer 目前沒有指向任何 int\n";
    }

    // C++11：auto 讓編譯器從右邊推導型別
    auto score = 90;
    cout << "auto score = " << score << '\n';

    // C++11：範圍 for，適合一個一個讀容器裡的值
    vector<int> numbers{1, 2, 3, 4};
    cout << "range for:";
    for (int value : numbers) {
        cout << ' ' << value;
    }
    cout << "\n";

    // C++11：lambda，小型匿名函式
    auto is_even = [](int value) {
        return value % 2 == 0;
    };
    cout << "lambda is_even(4): " << is_even(4) << "\n\n";
}

void show_cpp14() {
    cout << "=== C++14 ===\n";

    // C++14：make_unique，建立 unique_ptr 比直接 new 更安全
    auto number = make_unique<int>(42);
    cout << "make_unique number = " << *number << '\n';

    // C++14：lambda 參數可以使用 auto
    auto bigger = [](auto left, auto right) {
        if (left > right) {
            return left;
        }
        return right;
    };
    cout << "generic lambda bigger(3, 8): " << bigger(3, 8) << "\n\n";
}

void show_cpp17() {
    cout << "=== C++17 ===\n";

    // C++17：structured binding，可以把 tuple/pair 的內容拆出來
    tuple<string, int> student{"Amy", 18};
    auto [name, age] = student;
    cout << "structured binding: " << name << ", " << age << '\n';

    // C++17：optional 表示「可能有值，也可能沒有值」
    optional<int> maybe_score = 95;
    if (maybe_score.has_value()) {
        cout << "optional score = " << maybe_score.value() << '\n';
    }

    optional<int> empty_score;
    if (!empty_score.has_value()) {
        cout << "optional empty_score 目前沒有值\n";
    }

    // C++17：string_view 可以只看字串，不一定要複製一份
    string text = "C++17 string_view";
    string_view view = text;
    cout << "string_view: " << view << "\n\n";
}

void print_span(span<int> values) {
    cout << "span values:";
    for (int value : values) {
        cout << ' ' << value;
    }
    cout << '\n';
}

void show_cpp20() {
    cout << "=== C++20 ===\n";

    // C++20：concept 限制 add_numbers 只能接收數字型別
    cout << "concept add_numbers(10, 20): " << add_numbers(10, 20) << '\n';

    // C++20：span 可以用同一個函式觀察陣列或 vector 的一段資料
    array<int, 3> fixed_numbers{7, 8, 9};
    vector<int> dynamic_numbers{10, 20, 30, 40};

    print_span(fixed_numbers);
    print_span(dynamic_numbers);

    cout << '\n';
}

int main() {
    cout << "C++11 / C++14 / C++17 / C++20 常見差異小範例\n\n";

    // 依版本順序示範，方便比較「新標準只是慢慢加功能」。
    show_cpp11();
    show_cpp14();
    show_cpp17();
    show_cpp20();

    cout << "重點：可以用 C++20 編譯，但不一定每行都要寫很新的語法。\n";

    return 0;
}

/*
補充說明：C++11 / C++14 / C++17 / C++20 常見差異

使用者原本問題：
給我範例看看吧!! 很多行程式碼沒關係。

這份程式示範：
1. show_cpp11()
   - nullptr：明確表示空指標。
   - auto：讓編譯器從右邊推導型別。
   - range for：一個一個走訪容器內容。
   - lambda：小型匿名函式。

2. show_cpp14()
   - make_unique：比直接 new 更安全地建立 unique_ptr。
   - generic lambda：lambda 參數可以用 auto。

3. show_cpp17()
   - structured binding：把 tuple / pair 內容拆成變數。
   - optional：表示可能有值，也可能沒有值。
   - string_view：只觀察字串，不一定複製字串。

4. show_cpp20()
   - concept：限制模板參數，例如本例只接受數字型別。
   - span：用同一個函式觀察陣列或 vector 的一段資料。

正確觀念：
- C++11、14、17、20 不是不同語言。
- 它們都是 C++，只是標準版本不同。
- 新版本通常保留舊版語法，再加入新功能。
- 用 C++20 編譯時，仍然可以寫很基礎的 C++，不用每行都用新語法。

程式執行順序：
1. main() 印出總標題。
2. 呼叫 show_cpp11()。
3. 呼叫 show_cpp14()。
4. 呼叫 show_cpp17()。
5. 呼叫 show_cpp20()。
6. 最後印出提醒：可以用 C++20 編譯，但不用每行都寫新語法。

靜態推導的預期輸出重點：
C++11 / C++14 / C++17 / C++20 常見差異小範例
nullptr: pointer 目前沒有指向任何 int
auto score = 90
range for: 1 2 3 4
lambda is_even(4): 1
make_unique number = 42
generic lambda bigger(3, 8): 8
structured binding: Amy, 18
optional score = 95
optional empty_score 目前沒有值
string_view: C++17 string_view
concept add_numbers(10, 20): 30
span values: 7 8 9
span values: 10 20 30 40

可以自己修改練習：
1. 把 numbers{1, 2, 3, 4} 改成更多數字。
2. 把 maybe_score = 95 改成空的 optional<int> maybe_score;。
3. 把 fixed_numbers{7, 8, 9} 改成 5 個數字，觀察 span 是否仍能印出。

自我檢查：
1. 先確認自己用的是 C++11、C++17 還是 C++20。
2. 如果語法看不懂，先問它是在做型別推導、容器走訪、資源管理，還是模板限制。
3. 不要急著用最新寫法，先用自己看得懂的基礎寫法確認邏輯。
4. 如果編譯器說某個語法不存在，檢查是否沒有開對標準版本。
*/
