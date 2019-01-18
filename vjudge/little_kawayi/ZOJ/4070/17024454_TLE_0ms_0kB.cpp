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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int x,k;
    int pos,pos1;
    while(t--)
    {
        cin>>x>>k;
        while(k>0&&x!=0)
        {
            k--;
            x=F(x);
        }
        if(x!=0)
            cout<<x<<endl;
        else
            cout<<(k&1)<<endl;
    }
}
