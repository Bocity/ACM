#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
struct seg
{
	int l, r;
	friend bool operator<(seg a, seg b)
	{
		return a.l < b.l;
	}
} s[N];
int ans[N + 1];

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 1; i <= n; i++)
			q.push(i);
		for (int i = 0; i < m; i++)
			cin >> s[i].l >> s[i].r;
		memset(ans, 0, n + 1 << 2);
		int l = 1, r = 1;
		for (int i = 0; i < m; i++)
		{
			while (l < s[i].l)
				if (ans[l])
					q.push(ans[l++]);
			r = max(r, s[i].l);
			while (r <= s[i].r)
			{
				ans[r++] = q.top();
				q.pop();
			}
		}
		for (int i = 1; i <= n; i++)
			cout << (i == 1 ? "" : " ") << (ans[i] ? ans[i] : 1);
		cout << endl;
	}
	return 0;
}