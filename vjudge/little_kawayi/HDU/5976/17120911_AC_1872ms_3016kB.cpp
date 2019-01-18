#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5, M = 1000000000 + 7;
ll sum[N];
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
int main()
{
	cin.tie();
	ios::sync_with_stdio(0);
	sum[1] = 1;
	for (int i = 2; i <= N; i++)
		sum[i] = sum[i - 1] * i % M;
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		ll x = sqrt(2 * n);//项数 
		while (x * (x + 3) > 2 * n)
			x -= 1;
		ll y = n - x * (x + 3) / 2;
		if (y > x)
			cout << (x + 3) * sum[x + 1] % M * qpow(sum[2], M - 2) % M << endl;
		else
			cout << sum[x - y + 1] * (sum[x + 2] * qpow(sum[x - y + 2], M - 2) % M) % M<< endl;
	}
	return 0;
}