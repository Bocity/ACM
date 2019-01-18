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
        if(cnt>2)
        {
            printf("0\n");
        }else
        if(cnt==2)
        {
//            ll pos[5];
//            memset(pos,0,sizeof pos);
//            for(ll i=1;i<=sz;i++)
//            {
//                if(c3[i]=='1')
//                 {
//                     if(jc==0)
//                        pos[1]++;
//                     else
//                        pos[3]++;
//                 }
//                else
//                {
//                    if(pos[1]==0)
//                        pos[0]++;
//                    else
//                    if(pos[3]==0)
//                    {
//                        pos[2]++,jc=1;
//                    }else
//                    {
//                        pos[4]++;
//                    }
//                }
//            }
printf("6\n");

        }else
        if(cnt==1)
        {
            ll pos[3];
            memset(pos,0,sizeof pos);
            for(ll i=1;i<=sz;i++)
            {
                if(c3[i]=='1')
                    pos[1]++;
                else
                if(pos[1]==0)
                    pos[0]++;
                else
                    pos[1]++;
            }
            ll ans=(pos[0]+pos[1]+pos[2]-1)*2;
            printf("%lld\n",ans);
        }else
        {
            ll ans=pow(2,sz)-1;
            printf("%lld\n",ans);
        }
    }
}
