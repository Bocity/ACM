#include <bits/stdc++.h>
#define maxn 105
using namespace std;
vector<int> vec[maxn];
int vis[maxn];
int a[maxn];
queue<int> que;
int n, m;
int ans = 0;
int dfs(int now, int fa, int all, int dis)
{
	int res = a[now];
	if (dis == all)
		return res;
	for (auto &it : vec[now])
	{
		if (!vis[it] || it == fa)
			continue;
		res += dfs(it, now, all, dis + 1);
	}
	return res;
}
bool check(int k)
{
	memset(vis, 0, sizeof vis);
	while (!que.empty())
		que.pop();
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		vis[now] = 1;
		int tmp = dfs(now, 0, k, 0);
		if (tmp >= m)
			return 1;
		for (auto &it : vec[now])
		{
			if (vis[it])
				continue;
			que.push(it);
		}
	}
	return 0;
}
int main()
{
	//freopen("C:\\Users\\12943\\Desktop\\test.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r << endl;
}