#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
struct grid
{
	int r, c;
};
char **m;
int **s;
int main()
{
	int r, c, d;
	cin >> r >> c >> d;
	d += 1;
	s = new int*[r + 2];
	m = new char*[r + 2];
	for (int i = 0; i < r + 2; i++)
		s[i] = new int[c + 2](),
		m[i] = new char[c + 2]();
	for (int i = 0; i <= r + 1; i++)
		s[i][0] = s[i][c + 1] = 1;
	for (int i = 0; i <= c + 1; i++)
		s[0][i] = s[r + 1][i] = 1;
	grid st, ed;
	queue<grid> q;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 'S')
				st.r = i, st.c = j;
			if (m[i][j] == 'F')
				ed.r = i, ed.c = j;
			if (m[i][j] == 'M')
			{
				s[i][j] = 1;
				q.push(grid{i, j});
			}
		}
	
	const int wardr[4] = {1, -1, 0, 0};
	const int wardc[4] = {0, 0, 1, -1};
	while (!q.empty())
	{
		grid now = q.front();
		q.pop();
		if (s[now.r][now.c] == d)
			continue;
		for (int i = 0; i < 4; i++)
		{
			grid nxt{now.r + wardr[i], now.c + wardc[i]};
			if (s[nxt.r][nxt.c] == 0)
			{
				s[nxt.r][nxt.c] = s[now.r][now.c] + 1;
				q.push(nxt);
			}
		}
	}
	int ans = 0;
	if (s[st.r][st.c] == 0)
		q.push(st);
	while (!q.empty())
	{
		grid now = q.front();
		q.pop();
		if (now.r == ed.r && now.c == ed.c)
			break;
		for (int i = 0; i < 4; i++)
		{
			grid nxt{now.r + wardr[i], now.c + wardc[i]};
			if (s[nxt.r][nxt.c] == 0)
			{
				s[nxt.r][nxt.c] = s[now.r][now.c] - 1;
				q.push(nxt);
			}
		}
	}
	/*
	for (int i = 1; i <= r; i++)
	{
		for ( int j = 1; j <= c; j++)
			cout << setw(3) << s[i][j];
		cout << endl;
	}
	*/
	if (s[ed.r][ed.c] < 0)
		cout << -s[ed.r][ed.c] << endl;
	else
		cout << -1 << endl;
    return 0;
}