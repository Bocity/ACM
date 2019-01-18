#include <iostream>
#include <cstring>
#include <queue>
#include  <cstdio>
#include  <string>
using namespace std;
int vis[400000]={0};

struct qq
{
    long long x,y,z;
};
long long m,n,x2,y2,z1,z2,k;

long long bfs()
{
    long long sum=0;
    queue<int>q;
    q.push(n);
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
            if (t==m) return vis[t];
            int pp=t+1;
            if (pp<=100000&&pp>=0&&!vis[pp])
            {
                vis[pp]=vis[t]+1;
                q.push(pp);
            }
            pp=t-1;
            if (pp<=100000&&pp>=0&&!vis[pp])
            {
                vis[pp]=vis[t]+1;
                q.push(pp);
            }
            pp=t*2;
            if (pp<=100000&&pp>=0&&!vis[pp])
            {
                vis[pp]=vis[t]+1;
                q.push(pp);
            }

    }
    return -1;
}


int main()
{
while(cin>>n>>m){
    memset(vis,0,sizeof(vis));
vis[n]=0;
cout<<bfs()<<"\n";


}
    return 0;
}
