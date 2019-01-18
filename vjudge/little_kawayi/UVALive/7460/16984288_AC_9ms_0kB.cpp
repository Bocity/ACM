#include<bits/stdc++.h>
using namespace std;
int n,s,m;
const int maxn= 5e5+10;
struct node
{
    int s,t,v;
    node (int ss,int tt,int vv)
    {
        s=ss;
        t=tt;
        v=vv;
    }
    node()
    {

    }
    bool operator < (const node &a)const
    {
        if(v==a.v)
            return t>a.t;
        else
            return v<a.v;
    }
};
vector<node> point[maxn];
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<maxn;i++)
            point[i].clear();
        cin>>n>>s>>m;
        memset(vis,0,sizeof vis);
        vector<node> edge;
        for(int i=2;i<=n;i++)
        {
            point[i].push_back(node(i,i/2,abs(i-i/2)%m));
            point[i/2].push_back(node(i/2,i,abs(i-i/2)%m));
        }
        vector<int>ans;
        ans.push_back(s);
        vis[s]=1;
        priority_queue<node> q;
        for(auto e:point[s])
        {
            q.push(e);
        }
        while(!q.empty())
        {
            node pos;
            while(1)
            {
                if(q.empty())
                    break;
                pos=q.top();
                q.pop();
                if(vis[pos.t]==0)
                    break;
            }
            ans.push_back(pos.t);
            vis[pos.t]=1;
            for(auto e:point[pos.t])
            {
                if(vis[e.t]==0)
                q.push(e);
            }
        }
        for(int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans[ans.size()-1]<<endl;
    }
}
