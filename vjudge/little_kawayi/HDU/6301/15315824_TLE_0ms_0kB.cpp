#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
struct seg
{
	int l, r;
	friend bool operator<(seg& a, seg& b)
	{
		return a.l < b.l;
	}
} s[N];
int ans[N + 1];
int q[N + 1], cnt;
inline void push(const int& x)
{
	q[++cnt] = x;
	for (int i = cnt; i >> 1; i >>= 1)
		if (q[i >> 1] > q[i])
			swap(q[i >> 1], q[i]);
}
inline void pop()
{
	q[1] = q[cnt--];
	for (int i = 1; i << 1 <= cnt;)
	{
		int nxt = i << 1;
		if (nxt + 1 <= cnt)
			nxt += q[nxt] > q[nxt + 1];
		if (q[i] > q[nxt])
			swap(q[i], q[nxt]);
		i = nxt;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			push(i);
		for (int i = 0; i < m; i++)
			cin >> s[i].l >> s[i].r;
		memset(ans, 0, n + 1 << 2);
		int l = 1, r = 1;
		for (int i = 0; i < m; i++)
		{
			while (l < s[i].l)
				if (ans[l])
				{
					//cout << "Push: " << ans[l] << endl;
					push(ans[l++]);
				}
			r = max(r, s[i].l);
			while (r <= s[i].r)
			{
				ans[r++] = q[1];
				//cout << "pop: " << q[1] << endl;
				pop();
			}
		}
		for (int i = 1; i <= n; i++)
			cout << (i == 1 ? "" : " ") << (ans[i] ? ans[i] : 1);
		cout << endl;
	}
	return 0;
}