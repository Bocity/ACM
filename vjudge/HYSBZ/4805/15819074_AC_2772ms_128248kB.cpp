#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define RG register
#define MAX 10000000
inline int read()
{
    RG int x=0,t=1;RG char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
int pri[MAX+10],tot;
bool zs[MAX+10];
ll phi[MAX+10];
void pre()
{
    zs[1]=true;phi[1]=1;
    for(int i=2;i<=MAX;++i)
    {
        if(!zs[i])pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&pri[j]*i<=MAX;++j)
        {
            zs[i*pri[j]]=true;
            if(i%pri[j])phi[i*pri[j]]=phi[i]*phi[pri[j]];
            else{phi[i*pri[j]]=phi[i]*pri[j];break;}
        }
    }
    for(int i=1;i<=MAX;++i)phi[i]+=phi[i-1];
}
map<ll,ll> M;
ll Solve(ll x)
{
    if(x<=MAX)return phi[x];
    if(M[x])return M[x];
    ll ret=0;
    for(ll i=2,j;i<=x;i=j+1)
    {
        j=x/(x/i);
        ret+=(j-i+1)*Solve(x/i);
    }
    return M[x]=x*(x+1)/2-ret;
}
int main()
{
    pre();
    int n=read();
    printf("%lld\n",Solve(n));
    return 0;
}