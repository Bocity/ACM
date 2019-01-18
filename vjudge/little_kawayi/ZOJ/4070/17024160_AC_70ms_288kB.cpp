#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 100000 + 10;
int num[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
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
        while(x >= 2&&k > 0){
            x = F(x);
            k--;
        }
        if(k&1) x ^= 1;
        printf("%lld\n",x);
    }
    

   return 0;
}