#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define dprintf printf
#else
#define dprintf 0 && printf
#endif


#define SIZE    20


// 把ip地址的四个int型数据取出来
// return 1, IP地址非法
// return 0, 正确取出
int GetIpData(int *ipdata, char *ip)
{
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
        ipdata[i] = atoi(taken);
        dprintf("data = %d\n", ipdata[i]);
        if(ipdata[i] > 255 || ipdata[i] < 0)
        {
            return 1;   // ip地址非法
        }
        i++;
        taken = strtok(NULL, ".");
    }

    /* 判断是否合法 */
    if(i != 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//  将IP地址数据ipdata与mask数据相与
//  结果存储在ipcommon中
void GetNetCommon(int *ipcommon, int *ipdata, int *mask)
{
    /* 将mask与ip1运算 */
    for(int i = 0; i < 4; i++)
    {
        ipcommon[i] = (mask[i] & ipdata[i]);
        dprintf("%d & %d = %d\n", mask[i], ipdata[i], ipcommon[i]);
    }
}

int checkNetSegment(char *mask, char *ip1, char *ip2)
{
    int maskdata[4] = { 0 };
    int ipdata1[4] = { 0 };
    int ipdata2[4] = { 0 };

    int ipcommon1[4] = { 0 };
    int ipcommon2[4] = { 0 };

    if(strlen(mask) == 0
    || strlen(ip1) == 0
    || strlen(ip2) == 0)
    {
        return 1;
    }

    //  将ip地址转换为整数数组
    if(GetIpData(maskdata, mask) != 0
    || GetIpData(ipdata1, ip1) != 0
    || GetIpData(ipdata2, ip2) != 0)
    {
        return 1;   // ip地址非法
    }



    //  将两个ip域与子网掩码相与
    GetNetCommon(ipcommon1,  ipdata1, maskdata);
    GetNetCommon(ipcommon2, ipdata2, maskdata);


    /* 判断是否在同一个网段 */
    for(int i = 0; i < 4; i++)
    {
        if(ipcommon1[i] != ipcommon2[i])
        {
            return 2;
        }
    }

    return 0;
}

int main()
{

    char mask[SIZE], ip1[SIZE], ip2[SIZE];

    while(scanf("%s%s%s", mask, ip1, ip2) != EOF)
    {
        printf("%d\n", checkNetSegment(mask, ip1, ip2));
    }
    return 0;
}
