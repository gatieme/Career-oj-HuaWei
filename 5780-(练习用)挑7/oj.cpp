#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>


using namespace std;


#define  IsMultipleOfSeven(number) ((number) % 7 == 0)
bool IsPositionOfSeven(int number)
{
    int temp = number;
    while(temp)
    {
        if(temp % 10 == 7)
        {
            break;
        }
        temp = temp / 10;
    }
    return temp != 0;
}


int main()
{
    int N = 0, num = 0;
    int count = 0, temp = 0;

    while(cin >> N)
    {
        count = 0;
        for(num = 7; num <= N; num++)
        {
            /* 判断该数据有没有包含7 */
            if(IsMultipleOfSeven(num) == true
            || IsPositionOfSeven(num) == true)
            {
                //cout <<num <<endl;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
