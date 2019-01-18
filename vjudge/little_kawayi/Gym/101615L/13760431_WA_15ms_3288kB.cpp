#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-4
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 1000000 + 10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double k, p, x;
    scanf("%lf%lf%lf", &k, &p, &x);
    int m = sqrt(k * p / x + 0.5);
    double ans1 = (m * x + k * p / m) - 1;
    m += 1;
    double ans2 = (m * x + k * p / m);
    double ans = ans1 - ans2 < eps? ans1 : ans2;
    m -= 1;
    double ans3 = (m * x + k * p / m);
    ans = ans - ans3 <eps? ans : ans3;
    // printf("%.3lf %.3lf %.3lf\n", ans1, ans2, ans3);
    printf("%.3lf\n", ans);
    return 0;
}