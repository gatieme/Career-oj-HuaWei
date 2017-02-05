#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <set>
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



#define SIZE 2001
int fama(int n, int *weight, int *num);

int main( )
{
    //ifstream fin("in.txt");
    //streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());

    int n;
    int weight[SIZE];
    int num[SIZE];

    while(cin >>n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >>weight[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >>num[i];
        }

        cout <<fama(n, weight, num) <<endl;
    }

    return 0;
}

int fama(int n, int *weight, int *num)
{
    set<int> iset;
    int i, j;
    int sum = 0;
    set<int>::iterator iter;

    for(i = 0; i < n; i++)
    {
        sum += weight[i] * num[i];
    }
    iset.insert(sum);   //  最大的可能结果

    for(i = 0; i < n; i++)
    {
        iter = iset.begin( );
        while(iter != iset.end())
        {
            for(j = 0; j <= num[i]; j++)
            {
                iset.insert(*iter - j * weight[i]);
            }
            ++iter;
        }
    }


    return iset.size();
}
