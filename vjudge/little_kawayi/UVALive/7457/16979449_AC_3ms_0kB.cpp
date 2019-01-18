#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mod;
    cin>>mod;
    int a,b;
    while(cin>>a&&a)
    {
        cin>>b;
        int pos=1;
        int i;
        for( i=1;i<10000;i++)
        {
            pos=pos*a%mod;
            if(pos==b)
            {
                cout<<i<<endl;break;
            }

        }
        if(i==10000)
            cout<<0<<endl;
    }
}
