#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pow(ll x,ll n)
{
    ll ans=1;
    ll pos=1;
    while(n)
    {
        if(n&1)
            ans*=pos;
        pos*=x;
        n>>=1;
    }
    return ans;
}
const int maxn=1e6+10;
char c1[maxn],c2[maxn],c3[maxn];
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll sz;
        scanf("%lld",&sz);
        scanf("%s",&c1);
        scanf("%s",&c2);
        c3[0]='0';
        for(int i=0;i<sz;i++)
        {
            if(c1[i]==c2[i])
                c3[i+1]='0';
            else
                c3[i+1]='1';
        }
        ll cnt=0;
        for(ll i=1;i<=sz;i++)
        {
            if(c3[i]=='1'&&c3[i-1]=='0')
                cnt++;
        }
        // printf("     %lld\n", cnt);
        if(cnt>2)
        {
            printf("0\n");
        }else
        if(cnt==2)
        {
            printf("6\n");
        }else
        if(cnt==1)
        {
            printf("%lld\n",sz*2-2);
        }else
        {
            ll ans=sz*(sz+1)/2;
            printf("%lld\n",ans);
        }
    }
}