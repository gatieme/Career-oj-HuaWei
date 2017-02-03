#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

#include <fstream>
#include <cstring>
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


void DealKey(char *key, char *encrypt);
void DoEncrypt(char *data, char *encrypt);
void Encrypt(char *key, char *data, char *encrypt);


#define SIZE 500
bool Count[26] = { false };
char encrypt[26] = { 0 };

int main( )
{
    //ifstream fin("in.txt");
    //streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");  
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf()); 

    char key[SIZE], data[SIZE];
    cin >>key >>data;


    Encrypt(key, data, encrypt);

    cout << data << endl;
    return 0;
}


void Encrypt(char *key, char *data, char *encrypt)
{
    DealKey(key, encrypt);
    DoEncrypt(data, encrypt);
}

void DealKey(char *key, char *encrypt)
{
    int c = 0;
    //输入字符串去重,转化成大写插入
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
        {
            if (!Count[key[i] - 'a'])
            {
                Count[key[i] - 'a'] = true;
                encrypt[c] = key[i] - 'a' + 'A';
                c++;
            }

        }
        else if (key[i] >= 'A'&&key[i] <= 'Z')
        {
            if (!Count[key[i] - 'A'])
            {
                Count[key[i] - 'A'] = true;
                encrypt[c] = key[i];
                c++;
            }
        }
        else
        {
            exit(-1);
        }
    }


    //字母表剩余的补齐
    for (int j = 0; j < 26; j++)
    {
        if (!Count[j])
        {
            encrypt[c] = 'A' + j;
            c++;
        }
    }
}

void DoEncrypt(char *data, char *encrypt)
{
    //  加密
    for (int k = 0; k < strlen(data); k++)
    {
        if (data[k] >= 'a' && data[k] <= 'z')
        {
            data[k] = encrypt[data[k] - 'a'] - 'A' + 'a';
        }
        else if (data[k] >= 'A'&& data[k] <= 'Z')
        {
            data[k] = encrypt[data[k] - 'A'];
        }
    }
}
