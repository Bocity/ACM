#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while (cin >> n)
	{
		ll k = 1;
		while (1)
		{
			ll ans = 1;
			for (int i = 0; i < k; i++)
				ans *= k;
			if (ans < 0 || ans > n)
			{
				k--;
				break;
			}
			k++;
		}
		cout << k << endl;
	}
	return 0;
}