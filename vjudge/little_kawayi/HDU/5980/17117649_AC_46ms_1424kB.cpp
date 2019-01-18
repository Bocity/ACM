#include<bits/stdc++.h>
using namespace std;
string pos="10000110";
int f(int x)
{
    string c;
    for(int i=0;i<32;i++)
    {
        c+=((x>>i&1)+'0');
    }
    int ans=0;
    for(int i=0;i<32;i+=8)
    {
        if(c.substr(i,8)==pos)
            ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ans+=f(a);
    }
    cout<<ans<<endl;
}
