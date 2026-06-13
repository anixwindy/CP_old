

//
// 1. malloc/free vs new/delete，stack vs heap
//
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <limits.h>
void demo() {
    // ✅ Stack：函式結束就自動消失
    int a = 10;           // 放在 stack
    char buf[64] = "hi";  // 放在 stack

    // ✅ Heap：你要自己 free，不然記憶體洩漏
    int *p = (int*)malloc(sizeof(int));
    *p = 42;
    printf("%d\n", *p);
    free(p);   // 忘記 free → memory leak
    p = nullptr;  // 好習慣：free 後設 nullptr，防止 dangling pointer
}


// // C++ 版本
// void demo_cpp() {
//     int *p = new int(42);   // heap
//     delete p;               // 對應 new 用 delete
//
//     int *arr = new int[10];
//     delete[] arr;           // 陣列要用 delete[]，這是經典錯誤！
// }

// 💡 為什麼 CTF/Pwn 在乎這個？
// heap 上的 malloc 區塊有 metadata（chunk header），
// 攻擊者可以透過 heap overflow 覆寫這些 metadata，
// 達到任意寫入（arbitrary write）。
//

// 這是 heap 上的典型結構
typedef struct Node {
    int data;
    struct Node *next;   // ← 指向下一個 heap chunk 的指標
} Node;

Node* create(int val) {
    Node *n = (Node*)malloc(sizeof(Node));  // 在 heap 上分配
    n->data = val;
    n->next = nullptr;
    return n;
}
//
// ══════════════════════════════
void vuln_gets() {
    char buf[32];
    gets(buf);   // ❌ 你輸入幾個字都收，直接蓋掉 stack
    // 輸入 64 個 A → return address 被覆蓋 → 程式被控制
}
//

// ══════════════════════════════
// strcpy：不檢查目標大小
// ══════════════════════════════
void vuln_strcpy(char *user_input) {
    char buf[32];
    strcpy(buf, user_input);  // ❌ user_input 超過 32 bytes → overflow

    // ✅ 安全版本：
    // strncpy(buf, user_input, sizeof(buf) - 1);
    // buf[sizeof(buf)-1] = '\0';  // strncpy 不保證結尾有 \0！
}

// ══════════════════════════════
// printf(user_input)：Format String Attack
// ══════════════════════════════
void vuln_printf(char *user_input) {
    // ❌ 使用者直接控制格式字串
    printf(user_input);

    // 攻擊者輸入 "%x %x %x %x"
    // → 印出 stack 上的資料（洩漏位址！）

    // 攻擊者輸入 "%n"
    // → 把已印出的字元數「寫入」到對應位址
    // → 任意記憶體寫入！

    // ✅ 安全版本：
    // printf("%s", user_input);
}

// ══════════════════════════════
// fgets：相對安全，但有陷阱
// ══════════════════════════════
void safe_fgets() {
    char buf[32];
    fgets(buf, sizeof(buf), stdin);  // 最多讀 31 bytes + \0

    // ⚠️ 陷阱：fgets 會保留 \n（換行符號）
    // 輸入 "hello\n"，buf = "hello\n\0"
    // 如果你拿去 strcmp 比較，要注意！

    // 去掉結尾的 \n：
    buf[strcspn(buf, "\n")] = '\0';
}

//


// 2. char buf[64]：strlen vs sizeof
//

int main() {
    char buf1[64] = "hello";

    printf("sizeof(buf1) = %zu\n",  sizeof(buf1));   // 64，永遠是陣列宣告大小
    printf("strlen(buf1) = %zu\n",  strlen(buf1));   // 5，數到 \0 為止

    // ⚠️ 危險範例
    char *ptr = "hello";
    printf("sizeof(ptr) = %zu\n",  sizeof(ptr));   // 8（指標大小，不是字串長度！）
    printf("strlen(ptr) = %zu\n",  strlen(ptr));   // 5
    printf("\n_________________________\n");
// 輸出：
// sizeof(buf) = 64
// strlen(buf) = 5
// sizeof(ptr) = 8   ← 新手常被這個坑
// strlen(ptr) = 5

// 💡 CTF Pwn 場景：
// 程式員寫了 if (len < sizeof(buf)) 以為安全，
// 但 sizeof 量的是指標大小（8），不是緩衝區，
// 結果讓你塞入超長字串 → Stack Buffer Overflow。

//
// 3. signed / unsigned 比較陷阱
//

    int   a = -1;
    unsigned int b = 1;

    // ❓ -1 > 1 ？
    if (a > b) {
        printf("a > b（這看起來不合理，但真的印出來了！）\n");
    }

    // 原因：signed 和 unsigned 比較時，
    // signed 會被「隱式轉型」成 unsigned
    // -1 的二進位 = 0xFFFFFFFF = 4294967295（超大！）
    printf("(unsigned)a = %u\n", (unsigned)a);  // 4294967295
    printf("\n_________________________\n");

// 💡 RE 場景：
// 你在 Ghidra/IDA 看到一個比較，
// 如果搞錯 signed/unsigned，
// 你對「這個條件能不能被觸發」的判斷就會完全錯誤。
// 組語指令也不同：jl（signed less）vs jb（unsigned below）。
//
//
// 4. Little-Endian：0x12345678 的 byte 順序
//

    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char*)&x;

    printf("記憶體中的 byte 順序：\n");
    for (int i = 0; i < 4; i++) {
        printf("  地址[%d] = 0x%02X\n", i, p[i]);
    }
    printf("\n_________________________\n");
    //
    //以下看不懂
    //
// 輸出（x86 小端序）：
// 記憶體中的 byte 順序：
//   地址[0] = 0x78   ← 最低位 byte 放在最低地址
//   地址[1] = 0x56
//   地址[2] = 0x34
//   地址[3] = 0x12   ← 最高位 byte 放在最高地址
// 圖解：
// 高地址 → 低地址（概念上）
// 實際記憶體（低地址 → 高地址）：
//
// addr+0  addr+1  addr+2  addr+3
// [ 78 ]  [ 56 ]  [ 34 ]  [ 12 ]
//
// 💡 CTF RE/Pwn 影響：
// 你在 pwntools 送 payload 時，
// p32(0x12345678) 會幫你打包成 \x78\x56\x34\x12，
// 就是 little-endian。搞錯就打不中 return address！

//_______________________________

// // 6. 檔案 I/O
//     //
//
//     char buf[64];
//
//     // ══════════════════════════════
//     // 基本讀檔
//     // ══════════════════════════════
//     FILE *f = fopen("flag.txt", "r");
//     if (!f) {                          // ⚠️ 一定要檢查！
//         perror("fopen failed");
//         return 1;
//     }
//
//     size_t n = fread(buf, 1, 63, f);   // 最多讀 63 bytes（留一格給 \0）
//     buf[n] = '\0';                     // 手動加 nullptr terminator
//     fclose(f);
//
//     printf("Flag: %s\n", buf);

    // ══════════════════════════════
    // CTF 常見：程式讀 flag 後放在記憶體
    // 你的目標是「洩漏」這塊記憶體
    // ══════════════════════════════
    // 攻擊者透過 format string 或 buffer overflow
    // 把 buf 的內容印出來或傳到自己這邊
    printf("\n_________________________\n");

//
// 7. 鏈結串列 — Heap 的骨架
    //

// 這是 heap 上的典型結構


    Node *head = create(1);
    head->next  = create(2);
    head->next->next = create(3);

    // 印出每個 node 的 heap 位址
    for (Node *cur = head; cur; cur = cur->next) {
        printf("data=%d, addr=%p, next=%p\n",
               cur->data, (void*)cur, (void*)cur->next);
    }

    // ══════════════════════════════
    // ⚠️ Use-After-Free 漏洞示範
    // ══════════════════════════════
    Node *victim = head->next;   // victim 指向 node(2)
    free(victim);                // 釋放掉
    // victim 指標還在！

    // 攻擊者在這裡再 malloc 一次，
    // 很可能拿到剛才那塊記憶體
    Node *attacker = (Node*)malloc(sizeof(Node));
    attacker->data = 0xdeadbeef;

    // victim->data 現在是 attacker 寫的值！
    printf("victim->data = 0x%x\n", victim->data);  // 0xdeadbeef
    printf("____________________");

// 輸出：
// data=1, addr=0x55a1b0, next=0x55a1d0
// data=2, addr=0x55a1d0, next=0x55a1f0
// data=3, addr=0x55a1f0, next=(nil)
// victim->data = 0xdeadbeef   ← 被攻擊者污染了！

// 8. 資料轉換 — 整數溢出溫床



    printf("\n atoi 溢出-----\n");
    // ══════════════════════════════
    printf("INT_MAX = %d\n", INT_MAX);          // 2147483647

    int a1 = atoi("2147483648");  // 超過 INT_MAX！
    printf("atoi(2147483648) = %d\n", a1);       // 變成 -2147483648（溢出！）

    int b1 = atoi("-1");
    printf("atoi(-1) = %d\n", b1);               // -1

    // ══════════════════════════════
    printf("---\n真實漏洞：負數當 malloc 大小---_\n");
    // ══════════════════════════════
    char user_input[] = "-1";
    int size = atoi(user_input);    // size = -1

    // size 是 int，但 malloc 參數是 size_t（unsigned）
    // -1 轉成 size_t = 0xFFFFFFFFFFFFFFFF（超大！）
    // malloc 會失敗或行為未定義
    printf("size = %d\n", size);
    printf("(size_t)size = %zu\n", (size_t)size);  // 18446744073709551615

    // ══════════════════════════════
    printf("---\n真實漏洞：負數當陣列索引 \n");
    // ══════════════════════════════
    int arr[10] = {0};
    int idx = atoi("-1");
    arr[idx] = 0xdeadbeef;   // arr[-1]：寫到陣列前面的記憶體！
    // 這可能覆蓋其他重要資料


     printf("---\n安全做法：strtol + 範圍檢查\n");

    long val = strtol(user_input, nullptr, 10);
    if (val < 0 || val > 1024) {
        printf("非法輸入！\n");
        return 1;
    }
    printf("---\n ----\n-----");

//
// 9. 危險字串函數 — 漏洞寶庫
//
    //

// ══════════════════════════════
    printf("---\n ----gets()：最危險的函數，沒有之--\n");


// ══════════════════════════════
    printf("\n---Format String 攻擊實際示範--\n");
// ══════════════════════════════
    printf("_____9____\n");
    int secret = 0xdeadbeef;
    char buf2[64];

    printf("輸入：");
    fgets(buf2, sizeof(buf2), stdin);

    printf(buf2);   // ❌ 漏洞在這裡

    // 如果使用者輸入 "%p %p %p %p %p %p"
    // 輸出會是 stack 上的值：
    // 0x7ffd1234 0x0 0xdeadbeef ...
    //                ↑ secret 可能在這裡被洩漏！

    return 0;
}
// Format String 攻擊實際效果：
// 輸入：%p %p %p %p %p %p
// 0x7ffd5678 (nil) 0xdeadbeef 0x7f1234 0x1 0x401180
//                   ↑ stack 上的 secret 被印出來了！
//
// 🔴 紅隊怎麼想這一切？
// 你學到的紅隊的問題轉化成攻擊gets() 沒有長度限制「那我能填多少？」爆破找 offset
// → 覆蓋 return addressprintf(user_input)「我能控制格式字串？」%p 洩漏位址、%n
// 任意寫入atoi("-1") 變大數「size 有沒有做範圍檢查？」負數繞過 if (size < MAX)
//     → heap 爆炸UAF：free 後指標沒清「什麼時候可以再 malloc 這塊？」精準控制 heap layout
// → 控制物件內容socket / pwntools「我怎麼精準送 payload？」寫自動化 exploit，計時、重試、解析 leak
//
//
// 紅隊核心視角：
//
// 每個「方便」的函數背後都是一個假設。
// gets() 假設使用者不會輸入太長。
// printf(buf) 假設 buf 不含格式符號。
// 打破假設，就是漏洞。