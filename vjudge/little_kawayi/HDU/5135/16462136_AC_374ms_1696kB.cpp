#include <bits/stdc++.h>
using namespace std;
int n, s[13], v[13];
double dfs(int x, double sum)
{
	double ans = sum;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if ((v[i] | v[j] | v[k]) == 0 && s[i] + s[j] > s[k])
				{
					v[i] = v[j] = v[k] = 1;
					double tmp = (double)(s[i] + s[j] + s[k]) / 2;
					ans = max(ans, dfs(i + 1, sum + sqrt(tmp * (tmp - s[i]) * (tmp - s[j]) * (tmp - s[k])) ));
					v[i] = v[j] = v[k] = 0;
				}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	while (cin >> n && n)
	{
		memset(v, 0, sizeof v);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		sort(s, s + n);
		cout << setprecision(2) << fixed << dfs(0, 0) << endl;
	}
	return 0;
} 