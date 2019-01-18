#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define MAX 0x3f3f3f3f
vector<pair<int, int> > v[200];
int main()
{		

	//init
	int dis [101] = {0} ;
int vis [101] = {0} ;

	int n, k;
	while (cin >> n >> k && (n || k))
	{		
		if (n > 100 || n <=0 || k <= 0) while(1);
		//从1开始计数
		//vector<pair<int, int> > *v = new vector<pair<int, int> >[n + 5];
		for(int i = 0; i <= n; ++i) v[i].clear();
		while (k--)
		{
			int tmp1, tmp2, tmp3;
			cin >> tmp1 >> tmp2 >> tmp3;
			if (tmp1 > 100 || tmp1 <= 0 || tmp2 <=0 || tmp2 > 100) while(1);
			v[tmp1].push_back(pair<int, int>{ tmp2, tmp3 });
			v[tmp2].push_back(pair<int, int>{ tmp1, tmp3 });
		}
		//dij

		for (int i = 1; i <= n; i++)
		{
			dis[i] = MAX;
			vis[i] = 0;
		}//初始化两个数组
		auto cmp = [dis](int a, int b)->bool {return dis[a] > dis[b]; };
		priority_queue<int, vector<int>, decltype(cmp)> p{ cmp };//优先队列
		dis[1] = 0;
		p.push(1);
		vis[1] = -1;
		while (!p.empty())
		{
			int dq = p.top();
			p.pop();
			if (dq == n)
				break;
			vis[dq] = 1;
			for (int i = 0; i < v[dq].size(); i++)
				if (dis[v[dq][i].first] > dis[dq] + v[dq][i].second)
				{
					dis[v[dq][i].first] = dis[dq] + v[dq][i].second;
					if (!vis[v[dq][i].first])
					{
						p.push(v[dq][i].first);
					}
				}
		}
		cout << dis[n] << endl;
	}
	return 0;
}