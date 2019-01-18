#include<bits/stdc++.h>
using namespace std;
string pos="1000011";
int f(int x)
{
    string c;
    while(x)
    {
        c+=('0'+x%2);
        x/=2;
    }
    int ans=0;
    int pos1=0;
    while(c.find(pos,pos1)!=-1)
    {
        pos1=c.find(pos,pos1)+7;
        //cout<<pos1<<endl;
        ans++;
    }
    //cout<<ans<<endl;
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
