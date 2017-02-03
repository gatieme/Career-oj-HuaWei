/*

蛇形矩阵

题目描述
题目说明

蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

样例输入

5

样例输出

1 3 6 10 15

2 5 9 14

4 8 13

7 12

11

4
1 3 6 10 15
1 1+2 1+2+3 1+2+3+4
2 5 9 14
2 2+3 2+3+4
4 8 13
4 4+4
7  12
7 7+5
11

1 2 4 7 11
1 1+1 1+2+1 1+2+3+1 1+2+3+4+1
接口说明

原型

void GetResult(int Num, char * pResult);

输入参数：

        int Num：输入的正整数N

输出参数：

        int * pResult：指向存放蛇形矩阵的字符串指针

        指针指向的内存区域保证有效

返回值：

        void







输入描述:
输入正整数N（N不大于100）



输出描述:
输出一个N行的蛇形矩阵。



输入例子:
4



输出例子:
1 3 6 10

2 5 9

4 8

7
*/

#include <stdio.h>
#include <stdlib.h>



//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


void GetResult(int Num, int *pResult);
void PrintResult(int num, int *pResult);


int pResult[10000];

int main( )
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int num;
    while(scanf("%d", &num) != EOF)
    {
        GetResult(num, pResult);
    }


    return 0;
}



void GetResult(int num, int* pResult)
{
    int start = 2;
    int step = 1;
    int first = 1;
    int i = 0, data;

    for (int row = 0; row < num; ++row)
    {
        //  每行第一个元素, 正好是 (1+2+3+...+row) + 1
        //  首项为1, 尾项为row, 等差为1, 和为 ((1 + row) * row) / 2
        //  1 2 4 7 11
        //  1 1+1 1+2+1 1+2+3+1 1+2+3+4+1
        //  0  1    2     3      4
        first = 1 + ((1 + row) * row) / 2;
        //pResult[i++] = first;
        //printf("%d ", pResult[i - 1]);

        //  每一行如果排除第一个元素, 都是一个以startNum为首项, 等差为step的等差数列
        for(int col = 0; col < num - row; col++)
        {
            //              1       2      2     1      2       2        2
            pResult[i++] = first + col * start + step * col * (col - 1) / 2;
            if(col == 0)
            {
                printf("%d", pResult[i - 1]);
            }
            else
            {
                printf(" %d", pResult[i - 1]);
            }

            //system("PAUSE");
        }

        printf("\n");

        start++;
    }

}
