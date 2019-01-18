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
    LL t;
    scanf("%lld", &t);
    LL x,k;
    while(t--)
    {
        scanf("%lld%lld", &x, &k);
        while(k > 0&&x >= 2)
        {
            x=F(x);
            k--;
        }
        if(k&1) x ^= 1;
        printf("%lld\n",x);
    }
}