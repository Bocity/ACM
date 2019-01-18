#include<bits/stdc++.h>
using namespace std;
#define ll   long long
struct node
{

    ll x,y;
    bool operator < (const node &pos)
    {
        return x>pos.x;
    }
}a[3];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll sum=0;
        ll ans=0;
        for(int i=0;i<3;i++)
            cin>>a[i].x,sum+=a[i].x;
        for(int i=0;i<3;i++)
            cin>>a[i].y;
           // cout<<a[0].y*(a[2].x-a[1].x)<<" "<<a[1].y*(a[0].x-a[2].x)<<" "<<a[2].y *(  a[1].x-a[0].x)<<endl;
        ans+=( a[0].y*(a[2].x-a[1].x) + a[1].y*(a[0].x-a[2].x)  + a[2].y *(  a[1].x-a[0].x) );
        if(ans%sum==0)
            cout<<ans/sum<<endl;
        else
        cout<<ans/(__gcd(ans,sum))<<"/"<<sum/(__gcd(ans,sum))<<endl;

    }
}
