//
// Created by user on 2026/5/23.
//
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define SIZE1 5
void func(int arr[])		/* 自訂函數func() */
{
    int i;
    printf("\n在func()裡，陣列arr元素的位址為\n");
    for(i=0;i<SIZE;i++)
        printf("arr[%d]=%2d,位址為%p\n",i,arr[i],&arr[i]);
}

void show(int a[]) 			/* 自訂函數show() */
{
    int i;
    for(i=0;i<SIZE1;i++)
        printf("%d ",a[i]); 		/* 印出陣列的內容 */
    printf("\n");
}


void bubble(int a[])		/* 自訂函數bubble() */ {
    int i,j,temp;
    for(i=1;i<SIZE1;i++)
        for(j=0;j<(SIZE1-i);j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

void bubble2(int a[])  		/* 氣泡排序函數 */
{
    int i,j,temp;
    int flag=0;				/* 設定flag為0 */

    for(i=1;(i<SIZE1)&&(!flag);i++)
    {
        flag=1;
        for(j=0;j<(SIZE1-i);j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];			/* 對換陣列內的值 */
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
    }
}




int main() {
    printf("\n_________________________\n");

        int A[2][4][3]={{{21,32,65},
                              {78,94,76},
                             {79,44,65},
                             {89,54,73}},
                              {{32,56,89},
                             {43,23,32},
                             {32,56,78},
                             {94,78,45}}};

        int i,j,k,max=A[0][0][0];	/* 設定max為A陣列的第一個元素 */

        for(i=0;i<2;i++)	   		/* 外層迴圈 */
            for(j=0;j<4;j++)		/* 中層迴圈 */
                for(k=0;k<3;k++)		/* 內層迴圈 */
                    if(max<A[i][j][k])
                        max=A[i][j][k];

        printf("max=%d\n",max);	/* 印出陣列的最大值 */
    printf("\n_________________________\n");
    printf("\n_________________________\n");
    int ij,B[SIZE]={20,8,13};

    printf("在main()裡，陣列A元素的位址為\n");
    for(ij=0;ij<SIZE;ij++)
        printf("A[%d]=%2d,位址為%p\n",ij,A[ij],&A[ij]);
    func(B);				/* 這是傳址呼叫的機制 */

    printf("\n_________________________\n");
    printf("\n_________________________\n");
    int data[SIZE1]={26,5,81,7,63};

    printf("Before process...\n");
    show(data);				/* 印出陣列內容 */
    bubble(data);				/* 呼叫bubble()函數 */
    printf("After process...\n");
    show(data); 				/* 印出陣列內容 */

    printf("\n_________________________\n");
    printf("\n_________________________\n");
    int data2[SIZE1]={26,5,81,7,63};

    printf("Before process...\n");
    show(data2);
    bubble2(data2);
    printf("After process...\n");
    show(data2);
    printf("\n_________________________\n");
    printf("\n_________________________\n");
    //char S[字串數目][字串長度]
    char S[3][10]= {"Tom","Lily","James Lee"};
    int o;

    for(o=0;o<3;o++)
        printf("S[%d]=%s\n",o,S[o]);    /* 印出字串陣列內容 */
    printf("\n");
    for(o=0;o<3;o++)	/* 印出字串陣列元素的位址 */
    {
        printf("S[%d]=%p\n",o,S[o]);
        printf("address of S[%d][0]=%p\n\n",o,&S[o][0]);
    }


    return 0;

}