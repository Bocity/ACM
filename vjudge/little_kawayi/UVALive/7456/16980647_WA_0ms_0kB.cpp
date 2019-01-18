#include <bits/stdc++.h>
using namespace std;
vector<int> s[101];
int n, m, r, fb;
bool v[101];
int dfs(int now, int pre)
{
	v[now] = 1;
	int ans = 1;
	for (int i : s[now])
		if (i != pre && i != fb && v[i] == 0)
			ans += dfs(i, now);
	return ans;
}
int main()
{
	while (cin >> n >> r >> m && n)
	{
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		int mins = 101, ans = 101;
		for (fb = 1; fb <= n; fb++)
			if (fb != r)
			{
				memset(v, 0, sizeof v);
				int rst = dfs(r, 0);
				if (rst < mins || rst == mins && fb < ans)
				{
					mins = rst;
					ans = fb;
				}
				
			}
		cout << ans << endl;
	}
}