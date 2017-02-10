#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


#define SIZE    1000

#define SWAP(a, b) ((a) ^= (b) ^= (a) ^= (b))
bool GetMinK(unsigned int uiInputNum,
             int *pInputArray,
             unsigned int uiK,
             int *pOutputArray);



int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    int array[SIZE];
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        GetMinK(n, array, k, NULL);

    }



    return 0;
}


bool GetMinK(unsigned int uiInputNum,
             int *pInputArray,
             unsigned int uiK,
             int *pOutputArray)
{
    if(uiInputNum < 0 || uiK < 0 || uiInputNum < uiK
    || pInputArray == NULL)
    {
        return ;
    }
    int uk = 0;
    for(int j  = 0; j < uiInputNum - 1 && j < uiK; j++)
    {
        for(int i = 0; i < uiInputNum - 1 - j; i++)
        {
            if(pInputArray[i] < pInputArray[i + 1])
            {
                SWAP(pInputArray[i], pInputArray[i + 1]);
            }
        }
#if 0
        for(int k = 0; k < uiInputNum; k++)
        {
            printf("%d ", pInputArray[k]);
        }
        printf("\n");
#endif
        //pOutputArray[uk++] = pInputArray[uiInputNum - 1 -j];
        if( j == 0)
        {
            printf("%d", pInputArray[uiInputNum - 1 - j]);
        }
        else
        {
            printf(" %d", pInputArray[uiInputNum - 1 - j]);
        }
    }
    printf("\n");
}
