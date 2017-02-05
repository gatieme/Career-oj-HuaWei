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

    int num;
    int ret;
    scanf("%d", &num);

    if (num == 1 || num == 2)
    {
        ret = -1;
    }
    else if (num%2==1)
    {
        ret = 2;
    }
    else if (num % 4 == 0)
    {
        ret = 3;
    }
    else if (num % 4 ==2)
    {
        ret = 4;
    }

    printf("%d\n", ret);

    return EXIT_SUCCESS;
}
