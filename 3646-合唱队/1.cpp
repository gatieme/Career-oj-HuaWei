/*

计算最少出列多少位同学，使得剩下的同学排成合唱队形
说明：

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使
得剩下的K位同学排成合唱队形。


合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，
他们的身高分别为T1，T2，…，TK，   则他们的身高满足存在i（1<=i<=K）使得Ti<T2<......<Ti-1<Ti>Ti+1>......>TK。

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，
可以使得剩下的同学排成合唱队形。
*/

#include <iostream>
using namespace std;




int CountChorus(int *left, int *right, int *input, int n)
{
    //  统计递增序列   j < i
    //  left[i] 中存储了i位置中之前身高小于它的人数
    for(int i = 0; i < n; i++)      //  当前结束位置
    {
        left[i] = 1;

        for(int j = 0; j < i; j++)  //  当前结束位置i之前
        {
            if(input[j] < input[i]      //  当前循环的位置j的身高小于当前结束位置
            && left[i] < left[j] + 1)   //  j之前递增数目小时才累计
            {
                left[i] = left[j] + 1;
            }
        }
    }

    //  统计递减序列
    //  right[i] 中存储了后面身高比i位置的人低的
    for(int i = n - 1; i >= 0; i--)
    {
        right[i] = 1;

        for(int j = n - 1; j > i; j--)
        {
            if(input[j] < input[i]
            && right[i] < right[j] + 1)
            {
                right[i] = right[j] + 1;
            }
        }
    }

    //  8 186 186 150 200 160 130 197 200
    int ans  = 0;
    for(int i = 0; i < n ; i++)
    {
        //cout <<"i = " <<i <<", left = " <<left[i] <<", right = " <<right[i] <<endl;
        if(left[i] + right[i] - 1 > ans)
        {
            //cout <<i <<endl;
            ans = left[i] + right[i] - 1;
        }
    }


    return n-ans;
}

int main()
{
    int n;

    int input[500];
    int left[500],right[500];

    cin>>n;                         //  人数
    for(int i = 0; i < n; i++)
    {
        cin >>input[i];             //  每个人的身高
    }

    cout <<CountChorus(left, right, input, n);

    return 0;
}
