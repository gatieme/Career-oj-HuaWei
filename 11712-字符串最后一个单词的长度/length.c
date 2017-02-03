/*************************************************************************
    > File Name: length.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Fri 20 Jan 2017 10:30:08 AM CST
 ************************************************************************/

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



int findword(const char *pch)
{
        char *p = (char *)pch;
        char *t;

        if (pch[0] == '\0')
                return 0;

        // 跳到句尾
        while (*(++p));

        // 过滤字符
        while (!(*p >= 'a' && *p <= 'z') &&
               !(*p >= 'A' && *p <= 'Z'))
                p--;

        // 记住最后一个字母的位置
        t = p;

        // 向前搜索空格或句子第一个字母
        while (*p != ' ' && p != (pch - 1))
                p--;

        return t - p;
}


#define SIZE 100
int main()
{
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        int         length;
        char        str[SIZE];

        while(gets(str) != NULL)
        {
                length = findword(str);
                printf("%d\n", length);
        }

        return EXIT_SUCCESS;
}
