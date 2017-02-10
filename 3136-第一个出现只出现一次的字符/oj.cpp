/*
找出字符串中第一个只出现一次的字符
题目描述
找出字符串中第一个只出现一次的字符
详细描述：
接口说明
原型：
bool FindChar(char* pInputString, char* pChar);
输入参数：
char* pInputString：字符串
输出参数（指针指向的内存区域保证有效）：
char* pChar：第一个只出现一次的字符
如果无此字符 请输出'.'

输入描述:
输入一串字符
输出描述:
输出一个字符
输入例子:
asdfasdfo

输出例子:
o
 */


#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

#include <fstream>

using namespace std;

//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


#define SIZE 1000

char FirstOnceChar(string words);



int main( )
{
#ifdef DEBUG
    ifstream fin("in.txt");
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());
#endif
    char temp[SIZE];
    while(cin.getline(temp,1024))
    {
        string words = temp;
        cout <<FirstOnceChar(words) <<endl;
    }
    return EXIT_SUCCESS;
}


char FirstOnceChar(string words)
{
    int length = words.length( );
    for(int i = 0; i < length; i++)
    {
            int cnt = count(words.begin( ), words.end( ), words[i]);
            if(cnt == 1)
            {
                return words[i];
            }
    }

    return '.';
}
