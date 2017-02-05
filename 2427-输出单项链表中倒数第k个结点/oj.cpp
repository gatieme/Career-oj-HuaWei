#include <iostream>

using namespace std;

int main()
{
    int a[1000];
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    cout<<a[n-m]<<endl;
    return 0;
}