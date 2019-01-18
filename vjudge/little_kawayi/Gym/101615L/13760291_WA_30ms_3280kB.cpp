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
    double k, p, x;
    scanf("%lf%lf%lf", &k, &p, &x);
    int m = sqrt(k * p / x) + 1;
    double ans = (m * x + k * p / m);
    printf("%.3lf\n", ans);
    return 0;
}