#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
const int maxn = 100000 + 10;
ll a[maxn], sub[maxn];
class FenwickTree {
private:
    ll bit[maxn], N;
    inline ll lowbit(ll x) {
        return x & (-x);
    }
public:
    void init(ll n) {
        N = n;
        memset(bit, 0, sizeof(bit));
    }
    void update(ll x, ll delta) {
        for(ll i = x; i <= N; i += lowbit(i)) {
            bit[i] += delta;
        }
    }
    ll query(ll k) {
        ll ans = 0;
        for(ll i = k; i > 0; i -= lowbit(i)) ans += bit[i];
        return ans;
    }
} ft;
ll solve(ll n) {
    ll ans = 0;
    ft.init(n);
    for(ll i = 1; i <= n; i++) {
        sub[i] = a[i];
    }
    sort(sub + 1, sub + n + 1);
    ll pos = (ll)(unique(sub + 1, sub + n + 1) - sub - 1);
    for(ll i = 1; i <= n; i++) {
        a[i] = (ll)(lower_bound(sub + 1, sub + pos + 1, a[i]) - sub);
    }
    for(ll i = 1; i <= n; i++) {
        ft.update(a[i], 1);
        ans += i - ft.query(a[i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, y;
    while(cin >> n >> x >> y) {
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // cout << solve(n) << endl;
        cout << solve(n) * min(x, y) << endl;
    }
    return 0;
}