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


//  查找输入整数二进制中1的个数
int FindNumberOf1(int number);

int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int number;
    while(scanf("%d", &number) != EOF)
    {
        printf("%d\n", FindNumberOf1(number));
    }


    return 0;
}


//  查找输入整数二进制中1的个数
int FindNumberOf1(int number)
{
    int count = 0;
    int i = 0;
    unsigned long flag = 1;


    while(flag != 0)
    {
        if((number & flag) != 0)
        {
            count++;
        }
        flag <<= 1;
    }

    return count;
}
