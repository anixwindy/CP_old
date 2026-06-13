//
// Created by user on 2026/5/23.
//
// 1. 位元操作 ⭐⭐⭐⭐⭐ — RE 的語言
// c// 這些在 RE 裡是家常便飯
// data ^ 0x42        // XOR 加密，CTF最常見的混淆
// flags & 0x0F       // 取低4位
// val << 3           // 左移 = 乘8
// val >> 1           // 右移 = 除2
// ~mask              // 位元反轉
//
// 為什麼這麼重要？
// 你在 IDA/Ghidra 看組語，看到的就是這些
// 幾乎所有 CTF 的簡單加密都是 XOR 變形
//
// 你需要會的：
//
// 看到 xor eax, 0x42，能立刻知道這是在做什麼
// 手算簡單的 XOR 解密腳本（用 Python 寫）
// 理解 bitmask（遮罩）怎麼取特定位元


2. 字串處理函數 ⭐⭐⭐⭐⭐ — 漏洞寶庫

這不是「怎麼用字串」，而是「哪些函數有洞，洞在哪」

// 危險函數 → PWN 的目標
gets(buf)                  // ❌ 沒有長度限制，直接爆
strcpy(dst, src)           // ❌ 不檢查 dst 大小
strcat(dst, src)           // ❌ 同上
sprintf(buf, fmt, ...)     // ❌ 可能溢出
printf(user_input)         // ❌❌❌ Format String Attack！

// 相對安全但還是要懂
fgets(buf, n, stdin)       // 有長度，但 \n 的行為要注意
strncpy(dst, src, n)       // 有陷阱：不保證 null 結尾
snprintf(buf, n, fmt, ...) // 比 sprintf 安全
你要做的實驗：
// c// 跑這個，看看會發生什麼事
// char buf[8];
// gets(buf);  // 輸入 "AAAAAAAAAAAAAAAAAAAAAA"
// // → Segmentation fault！為什麼？Stack 被蓋掉了
//
// 這個「為什麼」的答案，就是 Stack Overflow 的核心原理


3. 資料轉換函數 ⭐⭐⭐⭐ — 整數溢出的溫床
catoi("2147483648")   // int 最大值是 2147483647，這裡會發生什麼？
atoi("-1")           // 如果拿去當陣列索引？
strtol(str, NULL, 16) // 16進位轉換，RE 常見

// 真實漏洞場景：

cint size = atoi(user_input);  // 使用者輸入 "-1"
char *buf = malloc(size);     // malloc(-1) = malloc(超大數字)
memcpy(buf, data, size);      // 爆炸
這叫做 Integer Overflow / Signedness Bug，是真實的 PWN 漏洞類型
你要知道：

// int 的範圍（-2^31 ~ 2^31-1）
// signed vs unsigned 的轉換陷阱
// atoi vs strtol 的差異
//

// 4. 動態記憶體 ⭐⭐⭐⭐⭐ — Heap PWN 的地基
// cvoid *ptr = malloc(64);   // 向 OS 要記憶體
// free(ptr);                // 還回去
// ptr = realloc(ptr, 128);  // 重新調整大小
//
// // 你需要理解的不是怎麼用，而是底層發生什麼

// malloc(64) 實際上配置的 chunk 長這樣：
//
// [ prev_size ][ size | flags ]  ← chunk header (metadata)
// [ 你的64 bytes 資料          ]  ← 你拿到的 pointer 指這裡
// [ next chunk...               ]


// 三大漏洞類型：
// Use-After-Free  → free 之後還繼續用 ptr
// Double-Free     → 同一個 ptr free 兩次
// Heap Overflow   → 寫超過 malloc 的大小，蓋到下一個 chunk 的 header
//



5. 鏈接串列 ⭐⭐⭐⭐ — Heap 的骨架
// //
// 關鍵認知：glibc 的 malloc 內部就是用鏈接串列管理 free chunk！
//


// Free chunk 的結構：
// [ size ][ fd pointer ] → 指向下一個 free chunk
//         [ bk pointer ] → 指向上一個 free chunk
// 所以當你做 Heap PWN，你在做的事情就是：
// 「偽造鏈接串列的指標，讓程式跳到你想要的地方」
// 你需要會的：
//
// 手刻單向、雙向鏈接串列
// 理解 fd / bk 指標的操作邏輯
// 不需要做到很複雜的應用，重點是理解指標如何連接


6. 檔案 I/O ⭐⭐⭐
cFILE *f = fopen("flag.txt", "r");
fread(buf, 1, 64, f);
fclose(f);


// RE：分析程式讀取了什麼檔案，怎麼解析格式
// PWN：有些題目會 open("/proc/self/maps") 讀記憶體佈局
// 偶爾 PWN 題的 flag 是從檔案讀的，要能操控 fopen 的路徑




// Call Stack（呼叫堆疊）→ ⭐⭐⭐⭐⭐ 非常重要！
// Stack ADT（資料結構）→ ⭐⭐ 認識就好
//

// Stack 長這樣：
// [ local vars of b  ]
// [ saved rbp        ]  ← 舊的 frame pointer
// [ return address   ]  ← ★ Buffer Overflow 要蓋的目標
// [ local vars of a  ]
// [ ...              ]



// Stack/Queue 作為資料結構：在 RE 中看到程式用到它們，能認出來就好
//
// 8. 樹 ⭐⭐（初學者暫時跳過）

// 🎯 重新整理「學習優先順序」
// 第一優先（現在就學）：
// ✅ 位元操作
// ✅ 字串危險函數（重點是漏洞角度）
// ✅ 動態記憶體底層（chunk 結構）
// ✅ Call Stack 原理

// 第二優先（做題時補）：
// 📌 資料轉換函數（整數溢出那塊）
// 📌 鏈接串列（heap exploit 前補）
// 📌 檔案 I/O
//
// 之後需要再學：
// ⏳ 符號/測試函數（ctype）
// ⏳ Stack/Queue ADT
// ⏳ 樹（進階 heap 才需要）
//
