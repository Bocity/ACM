#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x!=1)
            ans++;
    }
    cout<<ans<<endl;
    }

}
