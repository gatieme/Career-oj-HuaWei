#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include <bitset>


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


//  查找输入整数二进制中1的个数
int FindNumberOf1(int number);

int main( )
{
#ifdef DEBUG
    ifstream fin("in.txt");
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());
#endif
    int number;
    while(cin >>number)
    {
        cout <<FindNumberOf1(number) <<endl;
    }



    return 0;
}


//  查找输入整数二进制中1的个数
int FindNumberOf1(int number)
{
    bitset<32> bit(number);

    return bit.count( );
}
