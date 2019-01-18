#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
int main()
{
	int n;
	while (cin >> n)
	{
		int *s = new int[n + 1]();
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			s[tmp]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i >= 3 && s[i - 2] == 1 && s[i - 1] == 1 && s[i])
			{
				ans++;
				s[i - 2] = s[i - 1] = 0;
				s[i]--;
			}
			ans += s[i] / 2;
			s[i] %= 2;
		}
		cout << ans << endl;
		delete[] s;
	}
	return 0;
}