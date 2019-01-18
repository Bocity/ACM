#include <bits/stdc++.h>
using namespace std;
char s[120][120];
bool vis[120][120];
int r, c, h, w;
const int fr[2] = {1, 0};
const int fc[2] = {0, 1};
struct wd
{
	char s[120][120];
	friend bool operator==(wd a, wd b)
	{
		int flag = 0;
		for (int i = 0; i < h && flag == 0; i++)
			for (int j = 0; j < w && flag == 0; j++)
				if (a.s[i][j] != b.s[i][j])
					flag += 1;
		if (flag == 0)
			return 1;
		if (h == w)
		{
			wd tmp[2];
			tmp[0] = a;
			for (int i = 0; i < 3; i++)
			{
				for (int i = 0; i < w; i++)
					for (int j = 0; j < w; j++)
						tmp[1].s[i][j] = tmp[0].s[w - j - 1][i];
				bool isok = 1;
				for (int i = 0; i < w; i++)
					for (int j = 0; j < w; j++)
						if (tmp[1].s[i][j] != b.s[i][j])
							isok = 0;
				if (isok)
					return 1;
				tmp[0] = tmp[1];
			}
		}
		else
		{
			bool isok = 1;
			for (int i = 0; i < h; i++)
				for (int j = 0; j < w; j++)
					if (a.s[h - i - 1][w - j - 1] != b.s[i][j])
						isok = 0;
			if (isok)
				return 1;
		}
		return 0;
	}
} wds[10000];
int main()
{

	while (cin >> r >> c)
	{
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> s[i][j];
		memset(vis, 0, sizeof vis);
		h = w = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (s[i][j] != '#')
				{
					int tr = i, tc = j;
					while (s[tr][j] != '#')
						h++, tr++;
					while (s[i][tc] != '#')
						w++, tc++;
					goto nxt;
				}
	nxt:;
		int ans = 0;
		for (int i = 1; i < r; i += h + 1)
			for (int j = 1; j < c; j += w + 1)
			{
				for (int x = 0; x < h; x++)
					for (int y = 0; y < w; y++)
						wds[ans].s[x][y] = s[i + x][j + y];
				bool flag = 1;
				for (int i = 0; i < ans; i++)
					if (wds[i] == wds[ans])
						flag = 0;
				if (flag)
					ans += 1;
			}
		cout << ans << endl;
	}
	return 0;
}