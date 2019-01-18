#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N = 1e6, M = 998244353;
ll p[N + 1]{1};
ll invp[N + 1]{1};
ll qpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % M;
		b >>= 1;
		a = a * a % M;
	}
	return ans;
}
ll c(ll a, ll b)
{
	if (a < b)
		return 0;
	else
		return p[a] * invp[b] % M * invp[a - b] % M;
}
int main()
{
	for (int i = 1; i <= N; i++)
	{
		p[i] = p[i - 1] * i % M;
		invp[i] = qpow(p[i], M - 2);
	}
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		ll ans = c(k + m - 1, m - 1);
		for (int i = 1; k >= i * n; i++)
		{
			if (i % 2)
				ans = (ans - c(m, i) * c(k - i * n + m - 1, m - 1) % M + M) % M;
			else
				ans = (ans + c(m, i) * c(k - i * n + m - 1, m - 1) % M) % M;
		}
		cout << ans << endl;
	}
	return 0;
}