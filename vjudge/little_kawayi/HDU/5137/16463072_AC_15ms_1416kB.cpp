#include <bits/stdc++.h>
using namespace std;
int s[31][31], d[31], v[31];
int main()
{
	ios::sync_with_stdio(0);
	int n, k;
	while (cin >> n >> k && n)
	{
		memset(s, 0x3f, sizeof s);
		for (int i = 1; i <= n; i++)
			s[i][i] = 0;
		for (int i = 0; i < k; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			s[a][b] = s[b][a] = c;
		}
		int ans = -1;
		for (int i = 2; i < n; i++)
		{
			memset(d, 0x3f, sizeof d);
			memset(v, 0, sizeof v);
			v[i] = 1;
			d[1] = 0;
			for (int k = 1; k < n; k++)
			{
				int mins, mind = 0x3f3f3f3f;
				for (int l = 1; l <= n; l++)
					if (v[l] == 0 && d[l] < mind)
						mins = l, mind = d[l];
				v[mins] = 1;
				for (int l = 1; l <= n; l++)
					if (d[mins] + s[mins][l] < d[l])
						d[l] = d[mins] + s[mins][l];
			}
			ans = max(ans, d[n]);
		}
		if (ans == 0x3f3f3f3f)
			cout << "Inf" << endl;
		else
			cout << ans << endl;
	}
	return 0;
} 