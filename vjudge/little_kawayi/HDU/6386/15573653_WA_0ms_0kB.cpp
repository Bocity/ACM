#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5;
struct edge
{
	int to, val;
};
struct state
{
	int port, pre;
};
int dis[N + 1];
int clr[N + 1];
vector<edge> s[N + 1];
int main()
{
	ios::sync_with_stdio(0);
	int n, k;
	while (cin >> n >> k)
	{
		queue<state> q;
		for (int i = 1; i <= n; i++)
			s[i].clear();
		memset(dis, 0x3f, sizeof dis);
		memset(clr, 0, sizeof clr);
		for (int i = 0; i < k; i++)
		{
			int from, to, val;
			cin >> from >> to >> val;
			s[from].push_back(edge{to, val});
			s[to].push_back(edge{from, val});
		}
		dis[1] = 0;
		q.push(state{1, 0});
		while (!q.empty())
		{
			state now = q.front();
			q.pop();
			for (edge i : s[now.port])
				if ((clr[now.port] != clr[i.to] && dis[now.port] + bool(i.val != now.pre) <= dis[i.to]) ||
					(clr[now.port] == clr[i.to] && dis[now.port] + bool(i.val != now.pre) < dis[i.to]))
				{
					dis[i.to] = dis[now.port] + bool(i.val != now.pre);
					clr[i.to] = clr[now.port];
					q.push(state{i.to, i.val});
				}
		}
		cout << (dis[n] == INF ? -1 : dis[n]) << endl;
	}
	return 0;
}
