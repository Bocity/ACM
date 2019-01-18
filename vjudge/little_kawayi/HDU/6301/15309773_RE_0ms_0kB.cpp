#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
struct seg
{
	int l, r;
	friend bool operator<(seg a, seg b)
	{
		return a.l < b.l || a.l == b.l && a.r < b.r;
	}
} s[N];
int stk[N], cnt, ans[N + 1];
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> s[i].l >> s[i].r;
		sort(s, s + m);
		cnt = n;
		for (int i = n - 1, j = 1; i >= 0; i--, j++)
			stk[i] = j;
		for (int i = 1; i <= n; i++)
			ans[i] = 1;
		for (int i = 0; i < m; i++)
		{
			if (i)
			{
				int pre = cnt;
				for (int j = s[i - 1].l, k = min(s[i - 1].r, s[i].l - 1); j <= k; k--)
					stk[cnt++] = ans[k];
				sort(stk + pre, stk + cnt, greater<int>());
			}
			int st = s[i].l;
			if (i)
				st = max(s[i - 1].r + 1, s[i].l);
			for (int j = st; j <= s[i].r; j++)
				ans[j] = stk[--cnt];
		}
		cout << ans[1];
		for (int i = 2; i <= n; i++)
			cout << ' ' << ans[i];
		cout << endl;
	}
	return 0;
}