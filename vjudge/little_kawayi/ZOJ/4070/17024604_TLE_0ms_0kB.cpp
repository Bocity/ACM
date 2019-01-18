#include<bits/stdc++.h>
using namespace std;
int a[10]={1,0,0,0,1,0,1,0,2,1};
#define LL long long
LL F(LL x){
    LL ans = 0;

    while(x > 0){
        ans += a[x%10];
        x /= 10;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,k;
        cin>>x>>k;
        while(k!=0)
        {
            k--;
            x=F(x);
            if(x==0)
                break;
        }
        if(k&1) x ^= 1;
        cout<<x<<endl;
    }
}
