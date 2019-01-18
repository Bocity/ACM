#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define N 20005
#define Maxn 20005
using namespace std;
typedef long long ll;
const int maxn = 20005;
const long long mod = 1000000007;
int a[maxn]{0};
int f[maxn]{0};
main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        memset(a,0,sizeof a);
        memset(f,0,sizeof f);
        REP(i,1,n + 1){
            cin >> a[i];
        }
        int ans = 0;
        REP(i,1,n){
            bool flag = 1;
            REP(fi,i + 1,n + 1){
                if (a[fi] % a[i] == 0){
                    f[i] = fi;
                    flag = 0;
                    break;
                }
            }
            if (flag) f[i] = 0;
        }
        REP(i,1,n){
            ans +=f[i];
        }
        cout << ans << endl;
    }
    return 0;
}