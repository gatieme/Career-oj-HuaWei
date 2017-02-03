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


int main( )
{
    ifstream fin("in.txt");  
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");  
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf()); 
    int a, b;
    cin >>a >>b;

    cout <<a <<b <<endl;


    return 0;
}
