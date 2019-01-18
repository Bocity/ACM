//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int mod =1e9+7;
//
//ll quickpow(ll a,ll b)
//{
//    ll ans=1,base=a;
//    while(b)
//    {
//        if(b&1)
//            ans*=base;
//        ans%=mod;
//        base*=base;
//        base%=mod;
//        b>>=1;
//    }
//    return ans;
//}
//const int maxn=1e5+10;
//ll A[maxn];
//ll inv[maxn];
//#define endl "\n"
//int main()
//{
//    ios::sync_with_stdio(0);
////    A[0]=1;
////    for(int i=1;i<maxn;i++)
////    {
////        A[i]=i*A[i-1];
////        A[i]%=mod;
////        inv[i]=quickpow(A[i],mod-2);
////       //cout<<inv[i]<<" ";
////    }
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n,m;
//        cin>>n>>m;
//        if(n-m<m)
//            m=n-m;
//        ll ans=0;
//        for(int i=0;i<=m;i++)
//        {
//            ans+=getans(n,i);
//            ans%=mod;
//        }
//        cout<<ans<<endl;
//    }
//}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define ms(a,b) memset((a),(b),sizeof((a)))
using namespace std;
typedef long long ll;
const int INF = 2e9;
const ll LNF = 9e18;
const int mod = 1e9+7;
const int inv2=5e8+4;
const int maxn = 2e5+10;
ll A[maxn];
ll inv[maxn];
int n;
struct Query
{
    int L, R, id;
}node[maxn];

ll ans[maxn], tmp;

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
int a[maxn], num[maxn*10], unit;
bool cmp(Query a, Query b)
{
    if(a.L/unit != b.L/unit) return a.L/unit <b.L/unit;
    else return a.R<b.R;
}
ll getans(int x,int y)
{
    if(y==0)
        return 1;
    return ((A[x]*quickpow(A[x-y],mod-2))%mod*quickpow(A[y],mod-2))%mod;
}
void work()
{
    tmp = 0;
    ms(num,0);
    int L = 1;
    int R = 0;
    ll ans1=1ll;
    for(int i = 0; i<n; i++)
    {
        while(L<node[i].L)
        {
            ans1=(2ll*ans1-getans(L,R)+mod)%mod;
            L++;
        }

        while(L>node[i].L)
        {
            ans1=(inv2*(ans1+getans(L-1,R)%mod))%mod;
            L--;
        }
        while(R<node[i].R)
        {
            ans1=(ans1+getans(L,R+1))%mod;
            R++;
        }
        while(R>node[i].R)
        {
            ans1=(ans1-getans(L,R)+mod)%mod;
            R--;
        }

        ans[node[i].id] = ans1;
    }
}
void init()
{
    A[0]=1;
    for(int i=1;i<maxn;i++)
    {
        A[i]=i*A[i-1];
        A[i]%=mod;
        inv[i]=quickpow(A[i],mod-2);
       //cout<<inv[i]<<" ";
    }

}
int main()
{
    init();
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>node[i].L>>node[i].R,node[i].id=i;
    unit = (int)sqrt(n);
    sort(node,node+n,cmp);
//    for(int i=0;i<n;i++)
//        cout<<node[i].L<<" "<<node[i].R<<" "<<node[i].id<<endl;
    work();
    for(int i = 0; i<n; i++)
        printf("%lld\n",ans[i]);

}
