#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG




int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int num, temp;
    int ret = -1;
    scanf("%d", &num);

    if (num == 1 || num == 2)
    {
        printf("%d", -1);
        return 0;
    }

    for (int i = 1; i <= num; i++)    //  走一半就可以
    {
        temp = GetPos(num, i);
        if (!(temp & 1))                //  判断是否是偶数
        {
            ret = i;
            break;
        }
    }

    printf("%d\n", ret);
    return 0;
}

int GetPos(int line, int i)
{
    if (i < 1 || i >line * 2 - 1)
    {
        return 0;
    }
    else if (i == 1 || i == line * 2 - 1)
    {
        return 1;
    }
    else
    {
        return GetPos(line - 1, i - 2) + GetPos(line - 1, i - 1) + GetPos(line - 1, i);
    }
}

