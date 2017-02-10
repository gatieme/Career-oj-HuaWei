/*
iNOC产品部--完全数计算
题目描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。异常情况返回-1
 *
 * 完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
 * 它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
 * 例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
 *
 * 给定函数count(int n),用于计算n以内(含n)完全数的个数
 * @param n 计算范围, 0 < n <= 500000
 * @return n以内完全数的个数, 异常情况返回-1
 *
public static int count(int n)
输入描述:
输入一个数字
输出描述:
输出完全数的个数
输入例子:
1000
输出例子:
3
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




//  检查number是不是完全数
int IsPerfectNumber(int number);

//  检查n之内的所有完全数的个数
int PerfectNumberCount(int n);



int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", PerfectNumberCount(n));
    }


    return 0;
}


int IsPerfectNumber(int number)
{
    int sum = 0;
    if(number == 1)
    {
        return 0;
    }

    for(int i = 2;          /* 1 必然是其因子  */
        i <= number / 2;     /* 除本身外最大的因子 <= number / 2 */
        i++)
    {

        if(number % i == 0)
        {
            sum += i;
        }
    }

    return ((sum + 1) == number);

}

int PerfectNumberCount(int n)
{
    int count = 0;
    if(n < 0 || n > 500000)
    {
        return -1;
    }
    for(int num = 1; num <= n; num++)
    {
        if(IsPerfectNumber(num) == 1)
        {
            dprintf("%d\n", num);
            count++;
        }
    }
    return count;
}
