#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string c;
        cin>>c;
        long long ans=0;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]=='H')
                ans+=1;
            else
            if(c[i]=='C')
            ans+=12;
            else
                ans+=16;
        }
        cout<<ans<<endl;
    }
}
