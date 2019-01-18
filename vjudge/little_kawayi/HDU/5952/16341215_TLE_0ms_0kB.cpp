#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn=105;
int use[maxn];
int pos[maxn];
int dg[maxn];
int mapp[maxn][maxn];
int n,m,s;
int  ans=0;
bool dfs(int nowx,int dep)
{
    if(dep==s)
    {
        ans++;
        return 0;
    }
    memset(pos,0,sizeof pos);
    for(int i=nowx+1; i<=n; i++)
    {
        if(mapp[nowx][i]==0)
        {
            if(use[i]==1)
                pos[i]=1;
            use[i]=0;
        }
    }
    for(int i=nowx+1; i<=n; i++)
    {
        if(use[i]==1&&dg[i]>=(s-dep-1))
            dfs(i,dep+1);
    }
    for(int i=nowx+1; i<=n; i++)
        if(pos[i]==1)
        {
            use[i]=1;
            pos[i]=0;
        }
}
void init()
{
    for(int i=1; i<maxn; i++)
        use[i]=1;
    memset(mapp,0,sizeof mapp);
    memset(dg,0,sizeof dg);
    ans=0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m>>s;
        int x,y;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            mapp[min(x,y)][max(x,y)]=1;
            dg[min(x,y)]++;
        }


//        n=100,s=10;

//            for(int i=1;i<=50;i++)
//        for(int j=i+1;j<=i+20;j++)
//            mapp[i][j]=mapp[j][i]=1,dg[i]++,dg[j]++;
//        for(int i=1;i<=20;i++)
//            for(int j=1;j<=20;j++)
//                if(i!=j)
//                mapp[min(i,j)][max(i,j)] =1,dg[i]++,dg[j]++;
//        for(int i=21;i<=40;i++)
//            for(int j=21;j<=40;j++)
//                if(i!=j)
//                mapp[min(i,j)][max(i,j)] =1,dg[i]++,dg[j]++;
//        for(int i=41;i<=60;i++)
//            for(int j=41;j<=60;j++)
//                if(i!=j)
//               mapp[min(i,j)][max(i,j)] =1,dg[i]++,dg[j]++;
//        for(int i=61;i<=80;i++)
//            for(int j=61;j<=80;j++)
//                if(i!=j)
//                mapp[min(i,j)][max(i,j)] =1,dg[i]++,dg[j]++;
//                for(int i=81;i<=100;i++)
//            for(int j=81;j<=100;j++)
//                if(i!=j)
//                mapp[min(i,j)][max(i,j)] =1,dg[i]++,dg[j]++;

        for(int i=1; i<=n; i++)
        {
            dfs(i,1);
            for(int i=1; i<maxn; i++)
                use[i]=1;
        }
        cout<<ans<<endl;
    }
}
