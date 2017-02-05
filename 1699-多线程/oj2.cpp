#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;

char g_write[1032];
int num=0;
int iLoop=0;
HANDLE GetThreadEve[4];
HANDLE hThread[4];

unsigned int __stdcall ThreadFun1(PVOID pM)
{
    int M=*(int *)pM;
    iLoop=M;
    while(M!=0)
    {
        WaitForSingleObject(GetThreadEve[0],INFINITE);
        g_write[num]='A';
        num++;
        SetEvent(GetThreadEve[1]);
        M--;
    }
    _endthreadex(0);
    return 0;
}
unsigned int __stdcall ThreadFun2(PVOID pM)
{
    for (int i=0;i<iLoop;i++)
    {
        WaitForSingleObject(GetThreadEve[1],INFINITE);
        g_write[num]='B';
        num++;
        SetEvent(GetThreadEve[2]);
    }
    _endthreadex(0);
    return 0;
}
unsigned int __stdcall ThreadFun3(PVOID pM)
{
    for (int i=0;i<iLoop;i++)
    {
        WaitForSingleObject(GetThreadEve[2],INFINITE);
        g_write[num]='C';
        num++;
        SetEvent(GetThreadEve[3]);
    }
    _endthreadex(0);
    return 0;
}
unsigned int __stdcall ThreadFun4(PVOID pM)
{
    for (int i=0;i<iLoop;i++)
    {
        WaitForSingleObject(GetThreadEve[3],INFINITE);
        g_write[num]='D';
        num++;
        SetEvent(GetThreadEve[0]);
    }
    _endthreadex(0);
    return 0;
}
void init()
{
    GetThreadEve[0] = CreateEvent(NULL,FALSE,TRUE,NULL);
    GetThreadEve[1] = CreateEvent(NULL,FALSE,FALSE,NULL);
    GetThreadEve[2] = CreateEvent(NULL,FALSE,FALSE,NULL);
    GetThreadEve[3] = CreateEvent(NULL,FALSE,FALSE,NULL);
    memset(g_write,NULL,sizeof(g_write));
}
void Release()
{
    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(hThread[2]);
    CloseHandle(hThread[3]);
}
int main()
{
    int Num;
    cin>>Num;
    int *N=NULL;
    init();
    N=(int*)malloc(sizeof(int));
    *N=Num;
    hThread[0]=(HANDLE)_beginthreadex(NULL,0,ThreadFun1,N,0,NULL);
    hThread[1]=(HANDLE)_beginthreadex(NULL,0,ThreadFun2,NULL,0,NULL);
    hThread[2]=(HANDLE)_beginthreadex(NULL,0,ThreadFun3,NULL,0,NULL);
    hThread[3]=(HANDLE)_beginthreadex(NULL,0,ThreadFun4,NULL,0,NULL);
    WaitForMultipleObjects(4,hThread,TRUE,INFINITE);
    Release();
    cout<<g_write<<endl;
    return 0;
}
