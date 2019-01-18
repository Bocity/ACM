#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<int> point[maxn];
int color[maxn];
int lastc[maxn];
int vis[maxn];
int n,m,x,y;
void Init()
{
    for(int i=0;i<maxn;i++)
    {
        color[i]=0;
        point[i].clear();
        vis[i]=0;
        lastc[i]=0;
    }
}
bool check(int s)
{
    if(point[s].size()==0&&color[s]==0)
        return 0;
    queue<int >q;
    q.push(s);
    if(color[s]==0)
        color[s]=1;
    bool jc=0;
    while(!q.empty())
    {
        int pos=q.front();
        q.pop();
        vis[pos]=1;
        for(auto e:point[pos])
        {
            if(color[e]==color[pos])
            {
                jc=1;
                return 0;
            }else
            {
                if(vis[e]==0)
                {
                    color[e]=-color[pos];
                    q.push(e);
                }
            }
        }
    }
    if(jc==1)
        return 0;
    else
        return 1;
}
bool check1(int s)
{
    if(point[s].size()==0&&color[s]==0)
        return 0;
    queue<int >q;
    q.push(s);
    if(color[s]==0)
        color[s]=-1;
    bool jc=0;
    while(!q.empty())
    {
        int pos=q.front();
        q.pop();
        vis[pos]=1;
        for(auto e:point[pos])
        {
            if(color[e]==color[pos])
            {
                jc=1;
                return 0;
            }else
            {
                if(vis[e]==0)
                {
                    color[e]=-color[pos];
                    q.push(e);
                }
            }
        }
    }
    if(jc==1)
        return 0;
    else
        return 1;
}
int main()
{
    while(cin>>n>>m>>x>>y)
    {
        Init();
        int posx,posy;
        for(int i=0;i<m;i++)
        {
            cin>>posx>>posy;
            point[posx].push_back(posy);
            point[posy].push_back(posx);
        }
        for(int i=0;i<x;i++)
        {
            cin>>posx;
            lastc[posx]=1;
        }
        for(int i=0;i<y;i++)
        {
            cin>>posy;
            lastc[posy]=-1;
        }
        int jc=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            for(int i=1;i<=n;i++)
                color[i]=lastc[i];
            int pp=0;
            if(check(i))
                pp++;
            memset(vis,0,sizeof vis);
            for(int i=1;i<=n;i++)
                color[i]=lastc[i];
            if(check1(i))
                pp++;
            if(pp==0)
                jc=1;
        }
        if(!jc)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
    }
}
/*
5 4 0 0
1 3
1 4
3 5
4 5
5 4 1 0
1 3
1 4
3 5
4 5
2
5 4 2 2
1 3
1 4
3 5
4 5
1 2
5 3
5 4 1 0
2 3
2 4
3 5
4 5
1
*/
