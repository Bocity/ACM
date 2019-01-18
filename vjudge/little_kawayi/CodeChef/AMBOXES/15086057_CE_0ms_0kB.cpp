#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=3e5+10;

ll a[maxn];
ll n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        ll ans=0;
        ll pos=1;
        while(x>a[pos]&&pos<=n)
        {
            //cout<<x<<endl;
            x=(x%a[pos]==0?x/a[pos]:x/a[pos]+1);
            ans+=x;
            pos++
        }
        ans+=n-pos+1;
        cout<<ans<<endl;
    }
}
/*
5 1
1 1 1 1 1
1
*/
