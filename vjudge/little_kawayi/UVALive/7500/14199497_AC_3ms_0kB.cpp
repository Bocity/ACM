#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		ull n;
		cin >> n;
		ull l = 0, r = 2e9, mid;
		while (l < r)
		{
			mid = l + r + 1 >> 1;
			ull result = mid * (mid + 1) / 2;
			if (result <= n)
				l = mid;
			else
				r = mid - 1;
		}
		cout << "Case #" << cas << ": " << l * (l + 1) / 2 << endl;
	}
	return 0;
}