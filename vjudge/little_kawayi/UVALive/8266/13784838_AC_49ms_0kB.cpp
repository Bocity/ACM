#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f3f;
int v[200][200];
int ans[200];
int main()
{
char a = 3;
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	while (cin >> n && n)
	{
		cin >> k;
		memset(ans, 0, sizeof(ans));
		memset(v, 0x3f, sizeof(v));
		for (int i = 0; i < n; i++)
			v[i][i] = 0;
		for (int i = 0; i < k; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			v[tmp1][tmp2] = v[tmp2][tmp1] = 1;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (v[i][j] != inf)
					ans[v[i][j]]++;
		for (int i = 1; i < n; i++)
			if (ans[i])
				cout << i << ' ' << ans[i] << endl;
	}
	return 0;
}