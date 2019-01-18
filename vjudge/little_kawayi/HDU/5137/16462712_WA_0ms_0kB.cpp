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
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (s[i][j] != 0x3f3f3f3f)
				{
					int tmp = s[i][j];
					s[i][j] = s[j][i] = 0x3f3f3f3f;
					memset(d, 0x3f, sizeof d);
					memset(v, 0, sizeof v);
					d[1] = 0;
					for (int k = 1; k <= n; k++)
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
					s[i][j] = s[j][i] = tmp;
					if (d[n] != 0x3f3f3f3f)
						ans = max(ans, d[n]);
				}
		if (ans == -1)
			cout << "Inf" << endl;
		else
			cout << ans << endl;
	}
	return 0;
} 