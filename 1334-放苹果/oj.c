/*
题目描述
把M个同样的苹果放在N个同样的盘子里，
允许有的盘子空着不放，
问共有多少种不同的分法？
（用K表示）5，1，1和1，5，1 是同一种分法。

输入
每个用例包含二个整数M和N。0<=m<=10，1<=n<=10。<=n<=10<=m<=10

样例输入
7 3

样例输出
8

/*
     * 计算放苹果方法数目

     * 输入值非法时返回-1
     * 1 <= m,n <= 10<><= m,n <= 10<>
     * @param m 苹果数目
     * @param n 盘子数目数
     * @return 放置方法总数
     *

    public static int count(int m, int n)




输入描述:

输入两个int整数


输出描述:

输出结果，int型

输入例子:

7 3

输出例子:


8
*/

#include <stdio.h>
#include <stdlib.h>



//  调试开关
//#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


int AppleCount(int m, int n);

int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int m, n;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        printf("%d\n", AppleCount(m, n));
    }


    return 0;
}


int AppleCount(int m, int n)
{
    /*
    m个苹果, n个盘子

    当m < n时, 肯定有空盘出现, f(m,m).
    当m > n时, 有空盘出现时, 那至少有一个空盘:
        m个苹果, n-1个盘子，f(m,n-1);
    无空盘出现时, 每个盘子至少有一个苹果,
        m - n个苹果, n个盘子，f(m-n,n)
    */
    if (m == 0 || n == 1)
    {
        return 1;
    }
    if (m < n)
    {
        return AppleCount(m, m);
    }
    else
    {

        return AppleCount(m, n - 1) + AppleCount(m - n, n);
    }
}
