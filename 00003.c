
//指標


#include <stdio.h>
#include <stdlib.h>
void by_address(int *x) {
    *x = 999;
}
void by_value(int x) {
    x = 999;
}





int global = 1;  // 全域變數

int main(void)
{
    int a,b=5;		/* 宣告變數a與b，但變數a沒有設定初值 */
    double c=3.14;

    printf("a=%4d, sizeof(a)=%d, 位址為%d\n",a,sizeof(a),&a);
    printf("b=%4d, sizeof(b)=%d, 位址為%d\n",b,sizeof(b),&b);
    printf("c=%4.2f, sizeof(c)=%d, 位址為%d\n",c,sizeof(c),&c);
    printf("---------------------");



    int local = 1;           // Stack 變數
    int *heap = malloc(4);   // Heap 變數

    printf("\n global : %p\n", &global);
    printf("local  : %p\n", &local);
    printf("heap   : %p\n", heap);
    printf("main() : %p\n", main);   // 函式的位址
    free(heap);
    heap = nullptr;
    //傳值
    int aa = 1;
    printf("aa  : %p\n", &aa);
    printf("--\n");
    by_value(aa);
    printf("aa  : %p\n", &aa);
    printf("aa  : %d\n", aa);
    //傳 址

    int ab = 1;
    printf("ab  : %p\n", &ab);
    printf("--\n");
    by_address(&ab);
    printf("ab  : %p\n", &ab);
    printf("ab : %d\n", ab);


    return 0;
}

