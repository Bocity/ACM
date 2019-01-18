#include <bits/stdc++.h>
using namespace std;
double s[15];
double m[15][15];
int main()
{
	int n;
	double d;
	while (cin >> n >> d)
	{
		memset(m, 0, sizeof m);
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		for (int i = 1; i < n; i++)
			m[i][i] = m[i][i % n + 1] = 1,
			m[i][n + 1] = s[i];
		if (n % 2)
		{
			m[n][1] = m[n][n] = 1;
			m[n][n + 1] = s[n];
		}
		else
		{
			for (int i = 1; i <= n; i++)
				m[n][i] = 0;
			m[n][n] = 1;
			m[n][n + 1] = s[n] / 2;
		}
		const double eps = 1e-5;
		for (int i = 1; i <= n; i++)
		{
			int id = -1;
			double minn = 1e9;
			for (int j = i; j <= n; j++)
				if (abs(m[j][i]) > eps && abs(m[j][i]) < minn)
				{
					minn = abs(m[j][i]);
					id = j;
				}
			for (int j = 1; j <= n + 1; j++)
				swap(m[i][j], m[id][j]);
			for (int j = 1; j <= n; j++)
				if (j != i)
				{
					double cg = m[j][i] / m[i][i];
					for (int k = 1; k <= n + 1; k++)
						m[j][k] -= cg * m[i][k];
				}
		}
		for (int i = 1; i <= n; i++)
			m[i][n + 1] *= 1 / m[i][i];
		double ans = 0;
		for (int i = 1; i <= n; i++)
			ans += d * d * sin( (180 - 2 * m[i][n + 1]) * 3.1415926535897932384626 / 180);
		cout << setprecision(3) << fixed << ans / 2 << endl;
	}
} 