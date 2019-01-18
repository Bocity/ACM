#include <bits/stdc++.h>
using namespace std;
int st[100002], ed[100002];
int main()
{
	int n;
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			st[tmp] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			ed[tmp] = i;
		}
		for (int i = n; i; i--)
			if (st[i] != ed[i])
				if (st[i] && ed[i])
					ans += 2;
				else
					ans += 1;
		cout << ans << endl;
	}
	return 0;
}