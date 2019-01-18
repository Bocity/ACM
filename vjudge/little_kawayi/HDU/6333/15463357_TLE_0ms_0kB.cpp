#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod =1e9+7;

ll quickpow(ll a,ll b)
{
    ll ans=1,base=a;
    while(b)
    {
        if(b&1)
            ans*=base;
        ans%=mod;
        base*=base;
        base%=mod;
        b>>=1;
    }
    return ans;
}
const int maxn=1e5+10;
ll A[maxn];
ll getans(int x,int y)
{
    if(y==0)
        return 1;
    return ((A[x]*quickpow(A[x-y],mod-2))%mod*quickpow(A[y],mod-2))%mod;
}
int main()
{
    A[1]=1;
    for(int i=2;i<maxn;i++)
    {
        A[i]=i*A[i-1];
        A[i]%=mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll ans=0;
        for(int i=0;i<=m;i++)
        {
            ans+=getans(n,i);

            ans%=mod;
        }
        cout<<ans<<endl;
    }
}
