#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int rtnums[10001], dis[10001], vis[10001];
vector<pii> v[10001];
int main()
{
	int n, m, k, tmp;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> tmp;
	for (int i = 0; i < m; i++)
	{
		int s, t, d;
		cin >> s >> t >> d;
		v[s].push_back(pii(t,d));
		v[t].push_back(pii(s,d));
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	rtnums[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		vis[now] = 0;
		for (auto i : v[now])
		{
			if (dis[i.first] >= dis[now] + i.second)
			{
				if (dis[i.first] == dis[now] + i.second)
					rtnums[i.first] += rtnums[now];
				else
				{
					dis[i.first] = dis[now] + i.second;
					rtnums[i.first] = rtnums[now];
				}
				if (vis[i.first] == 0)
				{
					q.push(i.first);
					vis[i.first] = 1;
				}
			}
		}
	}
	if (rtnums[n] > 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
7}