#include <bits/stdc++.h>
using namespace std;
int p[31][2], s[201][201];
int main()
{
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n && n)
	{
		memset(s, 0, sizeof s);
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			p[i][0] = x, p[i][1] = y;
			s[x][y] = i;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					for (int l = 1; l <= n; l++)
						if (p[i][0] < p[j][0] && p[i][1] < p[j][1] && p[k][0] < p[l][0] && p[k][1] < p[l][1])
						{
							int tmp[8];
							tmp[0] = i, tmp[3] = j;
							tmp[4] = k, tmp[7] = l;
							tmp[1] = s[p[i][0]][p[j][1]];
							tmp[2] = s[p[j][0]][p[i][1]];
							tmp[5] = s[p[k][0]][p[l][1]];
							tmp[6] = s[p[l][0]][p[k][1]];
							bool flag = 1;
							
							for (int x = 0; x < 8; x++)
								if (tmp[x] == 0)
									flag = 0;
									
							int fuck = 0, shit = 0;
							for (int x = 0; x < 4; x++)
								if (p[k][0] <= p[tmp[x]][0] && p[k][1] <= p[tmp[x]][1]&&
									p[l][0] >= p[tmp[x]][0] && p[l][1] >= p[tmp[x]][1])
									fuck += 1;
							for (int x = 4; x < 8; x++)
								if (p[i][0] <= p[tmp[x]][0] && p[i][1] <= p[tmp[x]][1]&&
									p[j][0] >= p[tmp[x]][0] && p[j][1] >= p[tmp[x]][1])
									fuck += 10;
							for (int x = 0; x < 4; x++)
								if (p[k][0] < p[tmp[x]][0] && p[k][1] < p[tmp[x]][1]&&
									p[l][0] > p[tmp[x]][0] && p[l][1] > p[tmp[x]][1])
									shit += 1;
							for (int x = 4; x < 8; x++)
								if (p[i][0] < p[tmp[x]][0] && p[i][1] < p[tmp[x]][1]&&
									p[j][0] > p[tmp[x]][0] && p[j][1] > p[tmp[x]][1])
									shit += 10;
							if (shit != 40 && shit != 4 && fuck != 0)
								flag = 0;
							if (p[i][0] < p[k][0] && p[j][0] > p[k][0]&&
								p[k][1] < p[i][1] && p[l][1] > p[i][1])
								flag = 0;
							if (p[i][1] < p[k][1] && p[j][1] > p[k][1]&&
								p[k][0] < p[i][0] && p[l][0] > p[i][0])
								flag = 0;
							
							
							if (flag)
							{
								int area = (p[j][0] - p[i][0]) * (p[j][1] - p[i][1]) + (p[l][0] - p[k][0]) * (p[l][1] - p[k][1]);
								if (shit == 40 || shit == 4)
									area = max((p[j][0] - p[i][0]) * (p[j][1] - p[i][1]), (p[l][0] - p[k][0]) * (p[l][1] - p[k][1]));
								if (ans < area)
								{
									ans = area;
								}
							}
						}
		if (ans)
			cout << ans << endl;
		else
			cout << "imp" << endl;
	}
	return 0;
} 