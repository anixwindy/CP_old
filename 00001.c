//
// Created by user on 2026/5/21.
//
#include <stdio.h>
#include <stdlib.h>

#define Square n*n
int main() {

    int a =6;
    int b;
    char name[10];
    printf("hello world \t %d\ninput",a);
    scanf("%d",&b);
    printf("input");
    scanf("%s",name);
    printf("%d %s \n",b,name);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    printf("%x\n", 255);   // 輸出什麼？
    printf("%p\n", main);

    fflush(stdout);
    printf("__________________________\n");
    int larger;
    a > b ?(larger=a) :(larger=b);
    printf("%d大\n",larger);
    printf("__________________________\n");

    int n=9;
    printf("%d",Square);
    printf("__________________________\n");
    int aa[3] ;//4byte *3
    float bb[3];//4byte *3
    double cc[3];//8byte *3
    char dd[3];//1byte *3
    long long ee[3];//8byte *3
    printf("整個大小%d %d %d %d %d \n",sizeof(aa),sizeof(bb),sizeof(cc),sizeof(dd),sizeof(ee));

    printf("\n_________________________\n");

    int i, age[3];
    for (i=0;i<3;i++) {
        printf("INPUt",i);
        scanf("%d",&age[i]);

    }
    for (i=0;i<3;i++) {
        printf("age[%d]=%d\n",i,age[i]);

    }
    printf("\n_________________________\n");
    #define ROW 2		/* 定義ROW為2 */
    #define COL 3
    int ii,j;
    int A[ROW][COL]={{1,2,3},{5,6,8}};	/* 宣告陣列A並設定初值 */
    int B[ROW][COL]={{3,0,2},{3,5,7}};  	/* 宣告陣列B並設定初值 */

    printf("Matrix A+B=\n");
    for(ii=0;ii<ROW;ii++)			/* 外層迴圈，用來控制列數 */
    {
        for(j=0;j<COL;j++)		/* 內層迴圈，用來控制行數 */
            printf("%3d",A[ii][j]+B[ii][j]); 		/* 計算二陣列相加 */
        printf("\n");
    }



    return 0;
}