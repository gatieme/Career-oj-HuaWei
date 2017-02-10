#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//#define DEBUG
#ifdef DEBUG
#define dprintf printf
#else
#define dprintf 0 && printf
#endif


#define SIZE    20


bool CheckIpData(char *ip)
{
    int ipdata[4];
    char *taken = NULL;
    int i = 0;
    if(ip == NULL || ipdata == NULL)
    {
        return 1;
    }
    else if(strlen(ip) == 0)
    {
        return 1;
    }

    /* 把ip地址的四个int型数据取出来 */
    taken = strtok(ip, ".");
    i = 0;

    while(taken != NULL)
    {
        if(i > 4)
        {
            break;
        }
        ipdata[i] = atoi(taken);
        dprintf("data = %d\n", ipdata[i]);
        if(ipdata[i] > 255 || ipdata[i] < 0)
        {
            return false;
        }
        i++;
        taken = strtok(NULL, ".");
    }

    /* 判断是否合法 */
    if(i != 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    char ip[SIZE];

    while(scanf("%s", ip) != EOF)
    {
        if(CheckIpData(ip) == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
