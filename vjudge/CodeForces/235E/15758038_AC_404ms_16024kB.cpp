#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=2005;
#define mod 1073741824 
int gcd[maxn][maxn],mu[maxn],p[maxn],vis[maxn],res;
void init(int n=2000)
{
    res=0;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])p[res++]=i,mu[i]=-1;
        for(int j=0;j<res&&i*p[j]<=n;j++)
        {
            vis[i*p[j]]=1;
            if(i%p[j])mu[i*p[j]]=-mu[i];
            else
            {
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    for(int i=0;i<=n;i++)gcd[i][0]=gcd[0][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            gcd[j][i]=gcd[i][j]=gcd[j][i%j];
}
int deal(int n,int d,int i)
{
    int ans=0;
    for(int j=1;j<=n;j++)
        if(gcd[i][j*d]==1)ans+=n/j;
    return ans;
}
int main()
{
    init();
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int ans=0;
        for(int i=1;i<=a;i++)
        {
            int res=0;
            for(int d=1;d<=min(b,c);d++) 
            {
                res+=((ll)mu[d]*deal(b/d,d,i)*deal(c/d,d,i)%mod+mod)%mod;
                if(res>=mod)res-=mod;
            }
            ans+=(ll)(a/i)*res%mod;
            if(ans>=mod)ans-=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}