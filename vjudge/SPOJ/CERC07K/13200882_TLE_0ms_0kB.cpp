#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define endl "\n"
#define MAX 0x3f3f3f3f
char g[101][101];
int bs[101][101];
char vis[101][101];
struct point//记录一个点的信息
{
	int n, m;//行，列
};
int n, m;
int fn[4] = { 0,0,-1,1 };
int fm[4] = { -1,1,0,0 };//四个方向
inline bool should(int x, int y, int keys)
{
	if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#' || vis[x][y] == keys)
		return false;//这个点是否越界，是否撞墙，是否重复多余访问
	if ((g[x][y] == 'B' && !(keys & 1)) ||
		(g[x][y] == 'Y' && !((keys >> 1) & 1)) ||
		(g[x][y] == 'R' && !((keys >> 2) & 1)) ||
		(g[x][y] == 'G' && !((keys >> 3) & 1)))
		return false;//判断遇到门时是否有相应钥匙
	return true;
};
int main()
{
	ios::sync_with_stdio(0);
	while (cin >> n >> m && (n || m))
	{
		point s;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				vis[i][j] = -1, bs[i][j] = 0;
				cin >> g[i][j];
				if (g[i][j] == '*')
					s.n = i, s.m = j;//BYRG信息以二进制存储
			}
		int ans = 0;
		queue<point> q;
		q.push(s);
		vis[s.n][s.m] = 0;
		point now, nxt;
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			if (g[now.n][now.m] == 'X')
			{
				ans = bs[now.n][now.m];
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				nxt.n = now.n + fn[i];
				nxt.m = now.m + fm[i];
				if (should(nxt.n, nxt.m, vis[now.n][now.m]))
				{
					bs[nxt.n][nxt.m] = bs[now.n][now.m] + 1;
					vis[nxt.n][nxt.m] = vis[now.n][now.m];
					if (g[nxt.n][nxt.m] == 'b')
						vis[nxt.n][nxt.m] |= 1;
					else if (g[nxt.n][nxt.m] == 'y')
						vis[nxt.n][nxt.m] |= 2;
					else if (g[nxt.n][nxt.m] == 'r')
						vis[nxt.n][nxt.m] |= 4;
					else if (g[nxt.n][nxt.m] == 'g')
						vis[nxt.n][nxt.m] |= 8;
					q.push(nxt);
				}
			}
		}
		if (ans)
			cout << "Escape possible in " << ans << " steps." << endl;
		else
			cout << "The poor student is trapped!" << endl;
	}
	return 0;
}