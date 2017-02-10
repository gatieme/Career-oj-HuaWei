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
#ifdef DEBUG
    ifstream fin("in.txt");
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());
#endif


    int a, b;
    cin >>a >>b;

    cout <<a <<b <<endl;


    return 0;
}


//http:blog.csdn.net/makamus/article/details/25560235?utm_source=tuicool&utm_medium=referral
bool isIPAddressValid(const char* pszIPAddr)
{
    // 请在此处实现
    if(pszIPAddr ==0 ||pszIPAddr=="")
        return false;
    char *p=const_cast<char*>(pszIPAddr);
    char *pre=0;
    bool flag=true;
    bool last=false;
    int pCount=0; //point number;
    int num=0;
    while(*p==' ')
        p++;
    //if(*p=='.')
    //  return false;
    while(*p!='\0'){
        if (*p!='.')
        {
            if(pCount<3&&(*p>'9'||*p<'0'))
                return false;
            if(pCount==3){
                if(*p!=' '&&(*p>'9'||*p<'0'))
                    return false;
                if(*p==' ')
                    last=true;
                if(last&&*p<='9'&&*p>='0')
                    return false;
            }
            if(flag)
                pre=p;
            flag=false;
        }else{
            pCount++;
            if(!flag){
                if((p-pre>1&&*pre=='0')||(p-pre>3))
                    return false;
                if(p-pre==3){
                    num=(*pre-'0')*100;
                    num+=(*(++pre)-'0')*10;
                    num+=(*(++pre)-'0');
                    
                    if(num>255)
                        return false;
                }
            }else if(p-pre==1){
                    return false;
            }else
                return false;
            flag=true;
            pre=p;
        }
        p++;
    }
    if (pCount!=3 || *pre=='.'|| (p-pre>1&&*pre=='0'))
        return false;
    num=0;
    while(*pre<='9'&&*pre>='0'){
        num=num*10;
        num=num+(pre[0]-'0');
        
        pre++;
    }
    if(num>255)
        return false;
    return true;
}



bool isIPAddressValid(const char* pszIPAddr)
{
    // 请在此处实现
    if(NULL==pszIPAddr) return false;
    int lenIPAddr=strlen(pszIPAddr);
    int startIndex,endIndex;
    //去掉前后空格
    for(startIndex=0;startIndex<lenIPAddr;startIndex++)
        if(pszIPAddr[startIndex]!=' ')
            break;
    for(endIndex=lenIPAddr-1;endIndex>=0;endIndex--)
        if(pszIPAddr[endIndex]!=' ')
            break;
    if(endIndex<=startIndex) return false;
    char inputStr[200];
    int lenInputStr=endIndex-startIndex+1;
    strncpy(inputStr,&pszIPAddr[startIndex],lenInputStr);
    inputStr[lenInputStr]='\0';
    //查找点的合法性
    int countDot=0;
    for(int i=0;i<lenInputStr;i++)
    {
        if(inputStr[i]=='.')
        {
            countDot++;
            if(i==0||i==lenInputStr-1) return false;
            if(inputStr[i-1]<'0'||inputStr[i-1]>'9')
                return false;
            if(inputStr[i+1]<'0'||inputStr[i+1]>'9')
                return false;
        }
    }
    if(countDot!=3) return false;
    char *pCut;
    pCut=strtok(inputStr,".");
    while(NULL!=pCut)
    {
        int num;
        sscanf(pCut,"%d",&num);
        if(num!=0&&pCut[0]=='0') return false;
        if(num>255) return false;
        pCut=strtok(NULL,".");
    }
    return true;
}