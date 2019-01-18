#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-3
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int maxn = 20005;
long double n, m, k, d, t;
const long long mod = 1000000007;
long double check(long double fuck){
    if (d > fuck && k > fuck) return fuck / t;
    long double dd = d;
    if (dd < k){
        dd = ceil(k / dd) * dd;
    }
    if (dd == k) return fuck / t;
    long double ans1 = 0;
    long double ans2 = 0;
    long double ans3 = 0;
    ans1 += ll(fuck / dd) * dd;
    //if (ans1 - 0 == 0) return fuck/t;
    ans2 += ans1 - ll(fuck / dd) * k;
    if (ans1 < fuck){
        if (fuck - ans1 > k){
            ans2 += fuck - ans1 - k;
        }
    }
    ans3 = fuck - ans2;
    return ans2 / (2 * t) + ans3 / t;
}
int main() {
    ios::sync_with_stdio(0);
    cin >> k >> d >> t;
    cout << ll(t) << endl;
    long double l = t,r;
    r = 2 * t;
    int pp = 0;
    while(fabs(r - l) > eps){
        pp ++;
        if (pp > 200) break;
        long double  mid = l + (r - l) / 2;
        //cout << mid <<" "<<check(mid) << endl;
        //cout << l << " " << r << endl;
        if (check(mid) > 1){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << fixed << setprecision(1) << r <<endl;
    return 0; 
}
