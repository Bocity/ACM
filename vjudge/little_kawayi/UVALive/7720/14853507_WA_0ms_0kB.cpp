#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll quick_pow(ll a, ll b)
{
	a %= mod;
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		int n;
		cin >> n;
		ll ans = 1;
		
		while (n--)
		{
			int x, l, r;
			cin >> x >> l >> r;
			ans = ans * quick_pow(x, l) % mod * (1 - quick_pow(x, r - l + 1)) % mod * quick_pow(1 - x, mod - 2) % mod;
		}
		cout << "Case #" << cas << ": " << ans  << endl;
	}
	return 0;
}