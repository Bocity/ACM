#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll quick_pow(ll a, ll b)
{
	a %= MOD;
	ll ans = 1 % MOD;
	while (b)
	{
		if (b & 1)
			ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ans;
}
ll A[2000001];
int main()
{
	ios::sync_with_stdio(0);
	A[0] = 1;
	for (int i = 1; i <= 2e6; i++)
		A[i] = A[i - 1] * i % MOD;
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1;
			while (tmp1--)
				cin >> tmp2;
		}
		int N = k - n, M = n;
		cout << "Case #" << cas << ": " << A[N + M - 1] * quick_pow(A[M - 1], MOD - 2) % MOD * quick_pow(A[N], MOD - 2) % MOD << endl;
	}
	return 0;
}