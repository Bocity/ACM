#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 500000;
int n,m,k;
int L=1,R=0;
long long Ans=0;
struct BIT {
    ll a[N], n;
    void init(int i) {
        memset(a, 0, sizeof a);
        n = i;
    }
    inline int lowbit(int x) {
        return (x & -x);
    }
    void update(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) a[i] += v;
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i; i -= lowbit(i)) res += a[i];
        return res;
    }
} T;
int t;
int main(){
    //ios::sync_with_stdio(false);
    string s;
    scanf("%d", &t); 
    int casee=0;
    while(t--){
        T.init(N);
        casee++;
        scanf("%d", &n); 
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            T.update(i,x);
        }
        int i=0;
        printf("Case %d:\n",casee);
        int x,y;
        while(cin>>s){
            if (s=="End")break;
            scanf("%d%d",&x,&y); 
            if (s=="Add"){
                T.update(x,y);
            }
            if (s=="Sub"){
                int q=T.sum(x)-T.sum(x-1);
                if (q<y) y = q;
                T.update(x,-y);
            }
            if (s=="Query")
            {
               if (x>y) swap(x,y);
                printf("%lld\n",T.sum(y)-T.sum(x-1));
            }

        }
    }
    return 0;
}