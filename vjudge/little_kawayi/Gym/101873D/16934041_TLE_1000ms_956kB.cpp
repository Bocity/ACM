#include<bits/stdc++.h>
using namespace std;
map<string,int> tran;
int n,m;
int cnt=0;
int f[200][200];
int  find(int a,int b)
{
    int x,y;
    x=a,y=b;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int pos=q.front();
        q.pop();
        if(pos==y)
        {
            while(!q.empty())
                q.pop();
            return 1;

        }
        for(int i=1;i<200;i++)
        {
            if(f[pos][i]==1)
            q.push(i);
        }
    }
    q.push(y);
    while(!q.empty())
    {
        int pos=q.front();
        q.pop();
        if(pos==x)
        {
            while(!q.empty())
                q.pop();
            return -1;

        }
        for(int i=1;i<200;i++)
        {
            if(f[pos][i]==1)
            q.push(i);
        }
    }
    return 0;
}
int main()
{
    memset(f,0,sizeof f);
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
        f[tran[a]][tran[b]]=1;
    }
//    for(int i=1;i<=cnt;i++)
//    {
//        for(int j=1;j<=cnt;j++)
//            cout<<f[i][j]<<" ";
//        cout<<endl;
//    }
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
        if(ans==-1)
        {
            cout<<"Alternative Fact"<<endl;
        }else
        {
            cout<<"Fact"<<endl;
        }
    }
}
