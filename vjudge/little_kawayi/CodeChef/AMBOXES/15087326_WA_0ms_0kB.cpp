#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=3e5+10;

ll a[maxn];
ll p[maxn];
ll n,m;
ll cnt[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    memset(p,0,sizeof p);
    memset(cnt,0,sizeof cnt);

    ll sz=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        if(i!=1&&a[i]==a[i-1]&&a[i]==1)
        {
            sz--;
        }
        p[sz]++;
        sz++;
    }
    for(ll i=sz-1;i>=1;i--)
    {
        cnt[i]=p[i]+cnt[i+1];
    }
//    for(ll i=1;i<sz;i++)
//        cout<<cnt[i]<<" ";
//    cout<<endl;
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        ll ans=0;
        ll pos=1;
        while(x>a[pos]&&pos<sz)
        {
            //cout<<x<<endl;
            x=(x%a[pos]==0?x/a[pos]:x/a[pos]+1);
            //cout<<x<<
            ans+=p[pos]*x;
            pos++;
        }

        ans+=cnt[pos];
        cout<<ans<<endl;
    }
}
/*
5 1
1 1 1 1 1
1
*/
