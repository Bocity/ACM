#include<bits/stdc++.h>
using namespace std;
int sg[105][105];
int getsg(int x,int y)
{
    if(x==y)
    {
        return 10004;
    }
    if(sg[x][y]!=-1)
    {
        return sg[x][y];
    }
    int b[10005]={0},q=min(x,y);
    for(int i=1;i<x;++i)
    {
        b[getsg(x-i,y)]=1;
    }
    for(int i=1;i<y;++i)
    {
        b[getsg(x,y-i)]=1;
    }
    for(int i=1;i<q;++i)
    {
        b[getsg(x-i,y-i)]=1;
    }
    for(int i=0;i<10005;++i)
    {
        if(b[i]==0)
        {
            return sg[x][y]=i;
        }
    }
}
int main()
{
    memset(sg,-1,sizeof(sg));
    int n,ans=0,x,y,f=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        if(x==y)
        {
            f=1;
        }
        ans^=getsg(x,y);
    }
    if(ans||f)
    {
        cout<<'Y';
    }
    else
    {
        cout<<'N';
    }
    return 0;
}