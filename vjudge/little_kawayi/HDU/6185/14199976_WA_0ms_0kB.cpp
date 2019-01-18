#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
ull qpow(ull d, ull z)
{
	ull ans = 1;
	while (z)
	{
		if (z & 1)
		{
			ans = ans * d % mod;
		}
		z >>= 1;
		d = d * d % mod;
	}
	return ans;
}
int main()
{
	ull n;
	while (cin >> n)
	{
		if (n == 1)
			cout << 1 << endl;
		else
			cout << (1 + qpow(2, n) ) % mod << endl;
	}
	return 0;
}