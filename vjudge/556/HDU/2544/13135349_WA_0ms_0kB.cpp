#include<bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f
bool vis2[200][200]{0};
int main()
{
	//init		
int dis[101];
		int vis[101];
	int n, k;
	while (cin >> n >> k && (n || k))
	{
		//从1开始计数
		memset(vis2,0,sizeof vis2);
		vector<pair<int, int> > *v = new vector<pair<int, int> >[n + 1];
		while (k--)
		{
			int tmp1, tmp2, tmp3;
			cin >> tmp1 >> tmp2 >> tmp3;
			//if (vis2[tmp1][tmp2] || vis2[tmp2][tmp1] || tmp1 == tmp2) while(1);
			vis2[tmp1][tmp2] = 1;
			v[tmp1].push_back(pair<int, int>{ tmp2, tmp3 });
			v[tmp2].push_back(pair<int, int>{ tmp1, tmp3 });
		}
		//dij

		for (int i = 1; i <= n; i++)
		{
			dis[i] = MAX;
			vis[i] = 0;
		}//初始化两个数组

		auto cmp = [&](int a, int b)->bool {return dis[a] > dis[b]; };
		priority_queue<int, vector<int>, decltype(cmp)> p{ cmp };//优先队列
		dis[1] = 0;
		p.push(1);
		vis[1] = -1;
		while (!p.empty())
		{
			int dq = p.top();
			p.pop();
			// if (vis[dq]) continue;
			// vis[dq] = 1;
			for (int i = 0; i < v[dq].size(); i++)
				if (dis[v[dq][i].first]-dis[dq]  > v[dq][i].second)
				{
					dis[v[dq][i].first] = dis[dq] + v[dq][i].second;
					if (!vis[v[dq][i].first])
					{
						vis[v[dq][i].first] = -1;
						p.push(v[dq][i].first);
					}
				}
		}
		cout << dis[n] << endl;
	}
	return 0;
}
// 3 4

// 1 3 22
// 2 3 17
// 1 2 36
// 1 2 3
