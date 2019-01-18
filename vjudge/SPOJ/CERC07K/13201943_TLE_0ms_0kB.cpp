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
#define MAX 0x3f3f3f
char g[101][101];
int bs[101][101][1<<4];
struct point//记录一个点的信息
{
	int n, m, z = 0;//行，列,状态
};
int n, m;
int fn[4] = { 0,0,-1,1 };
int fm[4] = { -1,1,0,0 };//四个方向
inline bool should(int x, int y,int keys)
{
	if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#')
		return false;//这个点是否越界，是否撞墙
	if ((g[x][y] == 'B' && (!(keys & 1))) ||
		(g[x][y] == 'Y' && (!(keys & 2))) ||
		(g[x][y] == 'R' && (!(keys & 4))) ||
		(g[x][y] == 'G' && (!(keys & 8))))
		return false;//判断遇到门时是否有相应钥匙
	return true;
};
int main()
{
	ios::sync_with_stdio(0);
	while (cin >> n >> m && (n || m))
	{
		point s;
        memset(bs,MAX,sizeof bs);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> g[i][j];
				if (g[i][j] == '*')
					s.n = i, s.m = j;//BYRG信息以二进制存储
			}
		int ans = 0;
		queue<point> q;
        s.z = 0;
        bs[s.n][s.m][s.z] = 0;
		q.push(s);
		point now, nxt;
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			if (g[now.n][now.m] == 'X')
			{
				ans = bs[now.n][now.m][now.z];
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				nxt.n = now.n + fn[i];
				nxt.m = now.m + fm[i];
                nxt.z = now.z;
				if (should(nxt.n, nxt.m, nxt.z))
				{

					if (g[nxt.n][nxt.m] == 'b')
						nxt.z |= 1;
					else if (g[nxt.n][nxt.m] == 'y')
						nxt.z |= 2;
					else if (g[nxt.n][nxt.m] == 'r')
						nxt.z |= 4;
					else if (g[nxt.n][nxt.m] == 'g')
						nxt.z |= 8;
                        bs[nxt.n][nxt.m][nxt.z] = bs[now.n][now.m][now.z] + 1;
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