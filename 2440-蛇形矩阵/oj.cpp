#include <iostream>
using namespace std;
int main()
{
    int y,x;
    int n;

    while(cin>>n)
    {
        for(y=1; y<=n; y++)
        {
            for(x=1; x<=n-y; x++)
                cout<<((x+y-1)*(x+y-1)+(x+y-1))/2-y+1<<" ";
            x=n-y+1;
            cout<<((x+y-1)*(x+y-1)+(x+y-1))/2-y+1;
            cout<<endl;
        }
    }
    return 0;
}
