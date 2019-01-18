#include<bits/stdc++.h>
using namespace std;
map<string,int> tran;
int n,m;
int cnt=0;
int f[200];
int  find(int a,int b)
{
    int x,y;
    x=a,y=b;
    while(f[x]!=x)
    {
        if(f[x]==y)
        {
            return -1;
        }
        x=f[x];
    }
    x=a,y=b;
    while(f[y]!=y)
    {
        if(f[y]==x)
        {
            return 1;
        }
        y=f[y];
    }
    return 0;
}
int main()
{
    for(int i=0;i<200;i++)
        f[i]=i;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string a,a2,a3,a4,b;
        cin>>a>>a2>>a3>>a4>>b;
        if(tran[a]==0)
        {
            cnt++;
            tran[a]=cnt;
            tran[a];
        }
        if(tran[b]==0)
        {
            cnt++;
            tran[b]=cnt;
        }
        f[tran[a]]=tran[b];
    }
    for(int i=0;i<m;i++)
    {
        string a,a2,a3,a4,b;
        cin>>a>>a2>>a3>>a4>>b;
        if(tran[a]==0||tran[b]==0)
        {
            cout<<"Pants on Fire"<<endl;
            continue;
        }
        int ans=find(tran[a],tran[b]);
        if(ans==0)
        {
            cout<<"Pants on Fire"<<endl;
        }else
        if(ans==1)
        {
            cout<<"Alternative Fact"<<endl;
        }else
        {
            cout<<"Fact"<<endl;
        }
    }
}
