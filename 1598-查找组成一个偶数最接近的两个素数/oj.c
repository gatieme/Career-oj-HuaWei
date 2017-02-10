#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//  调试开关
//#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


bool IsPrime(int number);

int GetNearestPrime(int number, int *leftRet, int *rightRet);


int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int num;
    int left, right;
    while(scanf("%d", &num) != EOF)
    {
        dprintf("num = %d\n", num);
        if(GetNearestPrime(num, &left, &right) == 0)
        {
            printf("%d %d\n", left, right);
        }
    }


    return 0;
}


bool IsPrime(int number)
{
    for(int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int GetNearestPrime(int number, int *leftRet, int *rightRet)
{
    if(number <= 5 || number > 10000)
    {
        return -1;
    }

    int left, right;
    for(left = number / 2; left >= 2; left--)
    {
        right = number - left;
        if(IsPrime(left) == true
        && IsPrime(right) == true)
        {
            break;
        }
#if 0
        if(IsPrime(left) != true)
        {
            dprintf("%d is not prime\n", left);
            continue;
        }
        dprintf("%d is prime\n", left);
        right = number - left;
        if(IsPrime(right) == 1)
        {
            dprintf("%d is prime\n", right);
            break;
        }
#endif
    }

    if(left < 2)
    {
        dprintf("can not find\n");
        *leftRet = -1;
        *rightRet = -1;
        return -1;
    }
    else
    {
        dprintf("%d %d\n", *leftRet, *rightRet);
        *leftRet = left;
        *rightRet = right;
        return 0;
    }
}
