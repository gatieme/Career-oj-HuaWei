#include<iostream>
#include<algorithm>
#include<ctype.h>


using namespace std;

int BeautyName(char a[])  //计算一个字符串的最大漂亮度
{
	int b[26] = {0};  //存储每个字符的个数
	int sum = 0;


        //  计算每个字符出现的次数
	for(int i=0; a[i]!='\0'; i++)
    {
        b[tolower(a[i])-'a']++;
    }

    //  按照出现次数排序
	sort(b, b + 26);

    //  出现次数越多给它的漂亮度越高
    //  从而使得可能的漂亮度最高
    for(int i = 25; i >= 0 && b[i] != 0; i--)
    {
		sum += (i + 1) * b[i];
    }

    return sum;
}

int main()
{
	int M;
	char array[100][100];

    cin >>M;
	getchar( ); //清除回车

    for(int i=0;i<M;i++)
	{
        gets(array[i]);
    }

    for(int i=0;i<M;i++)
	{
        cout<<BeautyName(array[i])<<endl;
    }

	return 0;
}
