#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
#define PI acos(-1.0)
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll k, n, p, T, m, ans;
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    T = 0;
    while (cin >> n >> m) {
        T++;
        ans = qpow(n, m, MOD);
        cout << "Case #" << T << ":" << ans << endl;
    }
    cout << p << endl;

    return 0;
}
