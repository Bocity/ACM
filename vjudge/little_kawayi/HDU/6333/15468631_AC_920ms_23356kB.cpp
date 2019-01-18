////#include<bits/stdc++.h>
////using namespace std;
////#define ll long long
////const ll mod =1e9+7;
////
////ll quickpow(ll a,ll b)
////{
////    ll ans=1,base=a;
////    while(b)
////    {
////        if(b&1)
////            ans*=base;
////        ans%=mod;
////        base*=base;
////        base%=mod;
////        b>>=1;
////    }
////    return ans;
////}
////const ll maxn=1e5+10;
////ll A[maxn];
////ll inv[maxn];
////#define endl "\n"
////ll main()
////{
////    ios::sync_with_stdio(0);
//////    A[0]=1;
//////    for(ll i=1;i<maxn;i++)
//////    {
//////        A[i]=i*A[i-1];
//////        A[i]%=mod;
//////        inv[i]=quickpow(A[i],mod-2);
//////       //cout<<inv[i]<<" ";
//////    }
////    ll t;
////    cin>>t;
////    while(t--)
////    {
////        ll n,m;
////        cin>>n>>m;
////        if(n-m<m)
////            m=n-m;
////        ll ans=0;
////        for(ll i=0;i<=m;i++)
////        {
////            ans+=getans(n,i);
////            ans%=mod;
////        }
////        cout<<ans<<endl;
////    }
////}
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <queue>
//#include <stack>
//#include <map>
//#include <string>
//#include <set>
//#define ms(a,b) memset((a),(b),sizeof((a)))
//using namespace std;
//typedef long long ll;
//const ll INF = 2e9;
//const ll LNF = 9e18;
//const ll mod = 1e9+7;
//const ll inv2=5e8+4;
//const ll maxn = 2e5+10;
//ll A[maxn];
//ll inv[maxn];
//ll n;
//struct Query
//{
//    ll L, R, id;
//}node[maxn];
//
//ll ans[maxn], tmp;
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
//ll a[maxn], num[maxn*10], unit;
//bool cmp(Query a, Query b)
//{
//    if(a.L/unit != b.L/unit) return a.L/unit <b.L/unit;
//    else return a.R<b.R;
//}
//ll getans(ll x,ll y)
//{
//    if(y==0)
//        return 1;
//    return ((A[x]*inv[x-y])%mod*inv[y])%mod;
//}
//void work()
//{
//    tmp = 0;
//    ms(num,0);
//    ll L = 1;
//    ll R = 0;
//    ll ans1=1ll;
//    for(ll i = 0; i<n; i++)
//    {
//        while(L<node[i].L)
//        {
//            ans1=(2ll*ans1-getans(L,R)+mod)%mod;
//            L++;
//        }
//
//        while(L>node[i].L)
//        {
//            ans1=(inv2*(ans1+getans(L-1,R)%mod))%mod;
//            L--;
//        }
//        while(R<node[i].R)
//        {
//            ans1=(ans1+getans(L,R+1))%mod;
//            R++;
//        }
//        while(R>node[i].R)
//        {
//            ans1=(ans1-getans(L,R)+mod)%mod;
//            R--;
//        }
//        cout<<L<<" "<<R<<" "<<ans1<<endl;
//
//        ans[node[i].id] = ans1;
//    }
//}
//void init()
//{
//    A[0]=1;
//    for(ll i=1;i<maxn;i++)
//    {
//        A[i]=i*A[i-1];
//        A[i]%=mod;
//        inv[i]=quickpow(A[i],mod-2);
//       //cout<<inv[i]<<" ";
//    }
//
//}
//ll main()
//{
//    init();
//    cin>>n;
//    for(ll i=0;i<n;i++)
//        cin>>node[i].L>>node[i].R,node[i].id=i;
//    unit = (ll)sqrt(n);
//    sort(node,node+n,cmp);
//    work();
//    for(ll i = 0; i<n; i++)
//        prllf("%lld\n",ans[i]);
//
//}
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const ll mod =1e9+7;
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
//const ll maxn=1e5+10;
//ll A[maxn];
//ll inv[maxn];
//#define endl "\n"
//ll main()
//{
//    ios::sync_with_stdio(0);
////    A[0]=1;
////    for(ll i=1;i<maxn;i++)
////    {
////        A[i]=i*A[i-1];
////        A[i]%=mod;
////        inv[i]=quickpow(A[i],mod-2);
////       //cout<<inv[i]<<" ";
////    }
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        ll n,m;
//        cin>>n>>m;
//        if(n-m<m)
//            m=n-m;
//        ll ans=0;
//        for(ll i=0;i<=m;i++)
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
const ll INF = 2e9;
const ll LNF = 9e18;
const ll mod = 1e9+7;
const ll inv2=5e8+4;
const ll maxn = 2e5+10;
ll A[maxn];
ll inv[maxn];
ll n;
struct Query
{
    ll L, R, id;
}node[maxn];

ll ans[maxn], tmp;

ll quickpow(ll a,ll b)
{
    ll ans=1,base=a;
    while(b)
    {
        if(b&1)
            ans*=base;
        ans=ans%mod;
        base=base*base;
        base=base%mod;
        b>>=1;
    }
    return ans;
}
ll a[maxn], num[maxn*10], unit;
bool cmp(Query a, Query b)
{
    if(a.L/unit != b.L/unit) return a.L/unit <b.L/unit;
    else return a.R<b.R;
}
ll getans(ll x,ll y)
{
    if(y==0)
        return 1;
    return ((A[x]*inv[x-y])%mod*inv[y])%mod;
    //return ((A[x]*quickpow(A[x-y],mod-2))%mod*quickpow(A[y],mod-2))%mod;
}
void work()
{
    tmp = 0;
    ms(num,0);
    ll L = 1;
    ll R = 0;
    ll ans1=1ll;
    for(ll i = 0; i<n; i++)
    {
        while(L<node[i].L)
        {
            ans1=(2ll*ans1-getans(L,R)+mod)%mod;
            //cout<<"t1 "<<L<<" "<<R<<" "<<ans1<<endl;
            L++;
        }
        while(L>node[i].L)
        {
            ans1=(inv2*(ans1+getans(L-1,R)%mod))%mod;
                       //cout<<"t2 "<<L<<" "<<R<<" "<<ans1<<endl;

            L--;
        }
        while(R<node[i].R)
        {
            ans1=(ans1+getans(L,R+1))%mod;
                        //cout<<"t3 "<<L<<" "<<R<<" "<<ans1<<endl;

            R++;
        }
        while(R>node[i].R)
        {
            ans1=(ans1-getans(L,R)+mod)%mod;
                        //cout<<"t4 "<<L<<" "<<R<<" "<<ans1<<endl;

            R--;
        }

        ans[node[i].id] = ans1;
    }
}
void init()
{
    A[0]=1;
    inv[0]=1;
    for(ll i=1;i<maxn;i++)
    {
        A[i]=i*A[i-1];
        A[i]%=mod;
        inv[i]=quickpow(A[i],mod-2);
    }
}
int main()
{
    init();
//    cout<<getans(1,1);
//    cout<<inv[1]<<" "<<quickpow(1,mod-2)<<endl;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>node[i].L>>node[i].R,node[i].id=i;
    unit = (ll)sqrt(n);
    sort(node,node+n,cmp);
//    for(ll i=0;i<n;i++)
//        cout<<node[i].L<<" "<<node[i].R<<" "<<node[i].id<<endl;
    work();
    for(ll i = 0; i<n; i++)
        printf("%lld\n",ans[i]);

}
