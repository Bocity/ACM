#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> *v = new vector<int>[n+1];
	v[n].resize(n+1);
	for (int i = 0; i < k; i++)
	{
			int s, t;
			cin >> s >> t;
			v[s].push_back(t);
			v[t].push_back(s);
	}
	queue<int> q;
	bool *vis = new bool[n]();
	int *dis = new int[n+1]();
	memset(vis,1,n);
	for (int i = 0; i < n; i++)
	{
		v[i].push_back(n);
		q.push(i);
	}
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		vis[now] = 0;
		for (int i = 0; i < v[now].size(); i++)
		{
			int nxt = v[now][i];
			if (v[nxt].size() > v[now].size() && dis[nxt] < dis[now] + 1)	
			{
				dis[nxt] = dis[now] + 1;
				if (nxt != n && !vis[nxt])
				{
					q.push(nxt);
					vis[nxt] = 1;
				}
			}
		}
	}
	cout << dis[n] << endl;
	return 0;
}