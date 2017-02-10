#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
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



#define JOKER   "joker JOKER"
//  比较两手排
string ComparePoker(string left, string right);


int main( )
{
#ifdef DEBUG
    ifstream fin("in.txt");
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());
#endif

    string str, left, right;
    int seq = -1;
    while(getline(cin, str))
    {

        seq = str.find('-');        //  两手牌之间用-分隔

        left = str.substr(0, seq);
        right = str.substr(seq + 1);
        //debug <<left <<", " <<right <<endl;

        cout <<ComparePoker(left, right) <<endl;
    }

    return 0;
}


int GetPokerValue(char ch)
{
    int ret;
    if(ch >= '3' && ch <= '9')
    {
        ret = (ch - '0');
    }
    else if (ch == '1') /*  下一位必定是0  */
    {
        ret = 10;
    }
    else
    {
        switch(ch)
        {
            case 'J' :
                ret = 11;
                break;
            case 'Q' :
                ret = 12;
                break;
            case 'K' :
                ret = 13;
                break;
            case 'A' :
                ret = 14;
                break;
            case '2' :
                ret = 15;
                break;
            default :  // ' ', '0'
                ret = -1;
        }
    }
    return ret;
}

vector<int> GetPokerData(string poker)
{
    vector<int> data;
    int value;
    for(unsigned int i = 0; i < poker.length( ); i++)
    {
        if((value = GetPokerValue(poker[i])) != -1)
        {
            data.push_back(value);
        }
    }

    return data;
}

/*
大小规则跟大家平时了解的常见规则相同
个子, 对子, 三个比较牌面大小
顺子比较最小牌大小
炸弹大于前面所有的牌
炸弹之间比较牌面大小；
对王是最大的牌

left > right return 1
left == right return 0
left < right return -1
*/
int ComparePokerData(vector<int> left, vector<int> right)
{
    if(left.size( ) == 4 && right.size( ) == 4) /*  都是炸弹  */
    {
        return left[0] - right[0];
    }
    else if(left.size( ) == 4)  /* left是炸弹, right不是  */
    {
        return 1;
    }
    else if(right.size( ) == 4) /* left不是炸弹, right是  */
    {
        return -1;
    }
    //  已经排除了大小王, 都不是炸弹,
    //  则只能是个子，对子，顺子（连续5张）
    //  只能同种类型比较
    else if(left.size( ) == right.size( ))  /* 同种类型的牌比较大小  */
    {
        return left[0] - right[0];
    }
    else        /* 不是同种类型无法比较大小*/
    {
        return -2;
    }
}

//  比较两手排
string ComparePoker(string left, string right)
{
    if(left == JOKER || right == JOKER)
    {
        return JOKER;
    }

    vector<int> leftData = GetPokerData(left);
    vector<int> rightData = GetPokerData(right);

    int ret = ComparePokerData(leftData, rightData);
    if(ret == 1 || ret == 0)
    {
        return left;
    }
    else if(ret = -1)
    {
        return right;
    }
}
