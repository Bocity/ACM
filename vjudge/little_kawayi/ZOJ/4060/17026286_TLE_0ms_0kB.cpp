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
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll sz;
        cin>>sz;
        string c1,c2;
        cin>>c1>>c2;
        string c3;
        c3+='0';
        for(ll i=0;i<c1.size();i++)
        {
            if(c1[i]==c2[i])
                c3+='0';
            else
                c3+='1';
        }
        ll cnt=0;
        for(ll i=1;i<=sz;i++)
        {
            if(c3[i]=='1'&&c3[i-1]=='0')
                cnt++;
        }
        if(cnt>2)
        {
            cout<<0<<endl;
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
cout<<6<<endl;

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
            cout<<(pos[0]+pos[1]+pos[2]-1)*2<<endl;
        }else
        {
            cout<<(pow(2,sz)-1)<<endl;
        }
    }
}
