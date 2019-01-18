#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[100] = {1,0,0,0,1,0,1,0,2,1};
LL F(LL x){
    LL ans = 0;

    while(x > 0){
        ans += a[x%10];
        x /= 10;
    }
    return ans;
}
int main(void)
{

    int T;
    cin>>T;

    while(T--){
        LL x,k;

        scanf("%lld%lld",&x,&k);
        while(x !=0&&k > 0){
            x = F(x);
            k--;
        }
        if(k&1) x ^= 1;
        printf("%lld\n",x);
    }


   return 0;
}


