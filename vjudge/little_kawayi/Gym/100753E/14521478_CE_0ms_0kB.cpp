#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> v[10001];
int prert[10001], nowrt[10001], rtnums, dis[10001];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> prert[i];
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
	que.push(1);
	while (!que.empty())
	{
		int now = que.top();
		que.pop();
		for (pii i : v[now])
		{
			if (dis[i.first] >= dis[now] + i.second)
			{
				if (dis[i.first] == dis[now] + i.second)
				{
					rtnums += 1;	
				}
				else
				{
					rtnums = 1;
					dis[i.first] = dis[now] + i.second;
				}
				nowrt[i.first] = now;
				que.push(i.first);
			}
		}
	}
	bool flag = 1;
	for (int i = 1; i < k; i++)
		if (nowrt[prert[i]] != prert[i - 1])
			flag = 0;
	if ( (rtnums == 1 && flag == 0) || rtnums > 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}