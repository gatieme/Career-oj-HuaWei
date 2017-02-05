#include <iostream>  
#include <string>  
using namespace std;  

void thead2( )  
{
    cout<<'B';
}  

void thead3( )  
{
    cout<<'C';
}  

void thead4( )  
{
    cout<<'D';
}  

void thead1(int n)  
{
    if(n==0)  
        return;  
    cout<<'A';  
    thead2();  
    thead3();  
    thead4();  
  
    thead1(--n);  
}  
  
int main()  
{
    int N;  
    cin>>N;  
    thead1(N);  
    return 0;  
}  