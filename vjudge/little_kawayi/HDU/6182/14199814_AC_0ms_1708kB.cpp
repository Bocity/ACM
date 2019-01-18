#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll s[20];
	for (int i = 1; i <= 16; i++)
	{
		ll ans = 1;
		for (int j = 1; j <= i; j++)
			ans *= i;
		s[i] = ans;
	}
	ll n;
	while (cin >> n)
	{
		for (int i = 1; i <= 15; i++)
			if (s[i] > n)
			{
				cout << i - 1 << endl;
				goto nxt;
			}
		cout << 15 << endl;
	nxt:;
	}
	return 0;
}