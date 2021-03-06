#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[3], r[3], n;
const ll pos2=5e8+4;
const ll mod=1e9+7;
ll sum(ll x)//[0, x]
{
	if (x < 0)
		return 0;
	ll sum1 = (1 + r[0]) * r[0] % mod /2 % mod;
	ll sum2 = (r[1] - r[0] + 1) * (r[0] + 1) % mod;
	if (x > r[1])
		return (sum1 + sum2 + (r[0] + (r[0] - (x - r[1]) + 1)) % mod * (x - r[1]) % mod /2) % mod;
	if (x >= r[0])
		return (sum1 + (r[0] + 1) * (x - r[0] + 1) % mod) % mod;
	return (1 + x + 1) * (x + 1) % mod /2 % mod;
}
int main()
{
	ios::sync_with_stdio(0);
	ll t;
	cin >> t;
	for(ll cas = 1; cas <= t; cas++)
	{
		for (ll i = 0; i < 3; i++)
		{
			cin >> l[i] >> r[i];
			r[i] -= l[i];
		}
		cin >> n;
		n -= l[0] + l[1] + l[2];
		sort(r, r + 3);

		ll L = max(0LL, n - r[2]), R = min(n , r[0] + r[1]);
		ll ans = (sum(R) - sum(L - 1) + mod) % mod;
		cout << "Case #" << cas << ": ";
		if(n < 0)
			cout<< 0 <<endl;
		else
			cout << ans << endl;
	}
	return 0;
}
