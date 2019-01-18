#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int seg[N + 1 << 2], add[N + 1 << 2];
void pushup(int rt)
{
	seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}
void pushdown(int rt, int ln, int rn)
{
	if (add[rt])
	{
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		seg[rt << 1] += add[rt] * ln;
		seg[rt << 1 | 1] += add[rt] * rn;
		add[rt] = 0;
	}
}
void update(int l, int r, int rt, int L, int R, int v)
{
	if (L <= l && r <= R)
	{
		seg[rt] += v * (r - l + 1);
		add[rt] += v;
		return;
	}
	int m = l + r >> 1;
	pushdown(rt, m - l + 1, r - m);
	if (L <= m)
		update(l, m, rt << 1, L, R, v);
	if (m < R)
		update(m + 1, r, rt << 1 | 1, L, R, v);
	pushup(rt);
}
int query(int l, int r, int rt, int L, int R)
{
	if (L <= l && r <= R)
		return seg[rt];
	int m = l + r >> 1;
	pushdown(rt, m - l + 1, r - m);
	int ans = 0;
	if (L <= m)
		ans += query(l, m, rt << 1, L, R);
	if (m < R)
		ans += query(m + 1, r, rt << 1 | 1, L, R);
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		memset(seg, 0, sizeof seg);
		memset(add, 0, sizeof add);
		int area = 0;
		for (int i = 0; i < k; i++)
		{
			int tmp[4];
			cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
			update(1, n, 1, tmp[0] + 1, tmp[0] + tmp[2], tmp[3]);
			area += tmp[2] * tmp[3];
		}
		int l = 1, r = n;
		int wqarea;
		while (l < r)
		{
			int m = l + r >> 1;
			wqarea = query(1, n, 1, 1, m);
			if (wqarea << 1 >= area)//绿洲面积满足条件
				r = m;
			else
				l = m + 1;
		}
		r = n;
		wqarea = query(1, n, 1, 1, l);
		while (l < r)
		{
			int m = l + r + 1 >> 1;
			int area2 = query(1, n, 1, 1, m);
			if (area2 == wqarea)//绿洲面积相同 
				l = m;
			else
				r = m - 1;
		}
		cout << l << endl;
	}
	return 0;
}
