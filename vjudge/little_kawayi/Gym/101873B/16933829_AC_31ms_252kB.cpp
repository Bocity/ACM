#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 1e9 + 7;
ll n, m, c;
bool v[N];
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> c;
    ll ans = 0;//c * qpow(m, M - 2);
    ll nc = qpow(c, n * n);
    for (ll i = 0; i < m; i++)
        ans = (ans + qpow(nc, __gcd(i, m) ) ) % M;
    ans = ans * qpow(m, M - 2) % M;
    cout << ans << endl;
}
