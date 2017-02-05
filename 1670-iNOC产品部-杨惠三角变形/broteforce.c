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
    int n;
    int in[20][40],out=-1;

    memset(in, 0, sizeof(int)* 800);

    scanf("%d", &n);

    // 暴力的方法
    // 设置一个足够大的数组存储生成的杨辉三角，然后进行判断就行
    in[0][n-1] = 1;
    in[n - 1][0] = 1;
    in[n-1][2*n - 2] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < 2 * n - 2; j++)
        {
            in[i][j] = in[i - 1][j - 1] + in[i - 1][j] + in[i - 1][j + 1];

            if (i == n - 1)
            {
                if (!(in[i][j] & 1))    //  是偶数
                {
                    out = j + 1;
                    break;
                }
            }
        }
    }
    printf("%d\n", out);
    return 0;
}
