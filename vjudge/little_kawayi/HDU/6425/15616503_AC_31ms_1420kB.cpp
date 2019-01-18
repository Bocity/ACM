#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353 ;
#define ll long long
ll quickpow(ll x, ll n)
{
    ll res=1;
    ll a=x;
    while(n)
    {
        if(n&1)
            res*=a;
        res%=mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    ll a,b,c,pos1;
    ll num1=0,num2=0;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>pos1>>a>>b>>c;
        ll po1=quickpow(2,(pos1+a));
        ll po2=(1+a+c)*quickpow(2,(pos1+b))%mod;
        ll po3=(a+1)*quickpow(2,pos1)%mod;
        cout<<(po1+po2-po3+2*mod)%mod<<endl;
    }

}
