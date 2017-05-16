
#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[1002][1002],d[10000],x,y,z,minn,pos,ans=0;
bool v[10000];
int main()
{
    cin>>n>>m;
    memset(v,0,sizeof(v));
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      if(i==j)
        a[i][j]=0;
      else
        a[i][j]=10e8+7;
    }
    for (int i=1;i<=m;i++)
    {

        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    v[1]=true;
    for(int i=2;i<=n;i++)
    {

    d[i]=a[1][i];
    }
    for(int i=1;i<n;i++)
    {
    minn=10e8+7;
    pos=-1;
    for(int j=1;j<=n;j++)
    {
      if(!v[j]&&minn>d[j])
      {
        minn=d[j];
        pos=j;
      }
    }
    if (pos==-1) {cout<<-1;return 0;}
    ans+=minn;
    v[pos]=true;
    for(int j=1;j<=n;j++)
    if(!v[j]&&d[j]>a[pos][j])
    d[j]=a[pos][j];
    }
    cout<<ans;
    return 0;
}
