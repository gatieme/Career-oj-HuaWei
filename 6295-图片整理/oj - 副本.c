//图片整理

#include <iostream>
#include <string>
using namespace std;

int main()
{
        char temp;
        string str;
        cin >> str;
        for (int i = 0; i < str.length();i++)
        {
                for (int j = i + 1; j <str.length(); j++)
                {
                        if (str[i]>str[j])
                        {
                                temp = str[i];
                                str[i] = str[j];
                                str[j] = temp;
                        }
                }
        cout << str[i];
        }
        return 0;
}