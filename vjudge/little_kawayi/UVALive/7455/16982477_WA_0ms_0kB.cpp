#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
double s[11][11], m[101][101];
int n, ans[21];
bool guass(int r, int c)
{
	for (int i = 1; i <= r; i++)
	{
		double mine = 1e9;
		int id = 0;
		for (int j = i; j <= r; j++)
			if (fabs(m[j][i]) > eps && fabs(m[j][i]) < mine)
			{
				mine = fabs(m[j][i]);
				id = j;
			}
		if (id == 0)
			continue;
		for (int j = 1; j <= c; j++)
			swap(m[id][j], m[i][j]);
		for (int j = i + 1; j <= r; j++)
			if (j != i)
			{
				double cg = m[j][i] / m[i][i];
				for (int k = 1; k <= c; k++)
				m[j][k] -= cg * m[i][k];
			}
	}
	int cnt = 0;
	for (int i = 1; i <= r; i++)
		if (fabs(m[i][i]) > eps)
			cnt++;
	if (cnt == c)
		return 0;
	else
		return 1;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				cin >> s[j][k];
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
			
				for (int l = 1; l <= n; l++)
					m[(j - 1) * n + k][(j - 1) * n + l] = s[l][k];
				m[(j - 1) * n + k][(j - 1) * n + k] -= 1;
			}
		ans[i] = guass(n * n, n * n);
		for (int i = 1; i <= n * n; i++)
		{
			for (int j = 1; j <= n * n; j++)
				cout << setw(8) << setprecision(2) << fixed << m[i][j];
			cout << endl;
		}
	}
	for (int i = 1; i <= t; i++)
	{
		if (i % 5 != 1)
			cout << ' ';
		cout << ans[i];
		if (i % 5 == 0 || i == t)
			cout << endl;
	}
	return 0;
}