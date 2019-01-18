#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> v[10001];
int rtnums[10001], dis[10001];
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
	memset(dis, 0x3f, sizeof(dis));
	function<bool(int, int)> cmp = [&](int a, int b)->bool
	{
		return dis[a] > dis[b];
	};
	priority_queue<int,vector<int>, decltype(cmp)> que(cmp);
	dis[1] = 0;
	rtnums[1] = 1;
	que.push(1);
	while (!que.empty())
	{
		int now = que.top();
		que.pop();
		if (now == n)
			break;
		for (pii i : v[now])
		{
			if (dis[i.first] >= dis[now] + i.second)
			{
				if (dis[i.first] == dis[now] + i.second)
					rtnums[i.first] += rtnums[now];
				else
				{
					rtnums[i.first] = rtnums[now];
					dis[i.first] = dis[now] + i.second;
				}
				que.push(i.first);
			}
		}
	}
	if (rtnums[n] > 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}