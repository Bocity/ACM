#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define MAX 110000
#define ll long long
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
int n,m;
int tot,pri[MAX];
ll mu[MAX],F[MAX],f[MAX],ans;
bool zs[MAX];
void Mu()
{
    zs[1]=mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!zs[i])pri[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&i*pri[j]<=n;++j)
        {
            zs[i*pri[j]]=true;
            if(i%pri[j])mu[i*pri[j]]=-mu[i];
            else{mu[i*pri[j]]=0;break;}
        }
    }
}
int main()
{
    n=read();m=read();
    if(n>m)swap(n,m);
    Mu();
    for(int i=1;i<=n;++i)F[i]=1ll*(n/i)*(m/i);
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            f[i]+=1ll*mu[j/i]*F[j];
    for(int i=1;i<=n;++i)ans+=1ll*f[i]*i;
    ans=ans*2-1ll*n*m;
    printf("%lld\n",ans);
    return 0;
}