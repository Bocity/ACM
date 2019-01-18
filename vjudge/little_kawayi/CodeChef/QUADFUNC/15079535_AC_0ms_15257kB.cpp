#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
const int maxn = 1000000 + 10;
ll cal(ll a, ll b, ll c, ll x) {
    return 2 * a * x * x * x + 3 * b * x * x + 6 * c * x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, a, b, c, d, e, f, l, r;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> e >> f >> l >> r;
        ll z = abs(cal(d - a, e - b, f - c, r) - cal(d - a, e - b, f - c, l));
        ll m = 6;
        ll g = __gcd(z, m);
        cout << z / g << '/' << m / g << endl;
    }
    return 0;
}