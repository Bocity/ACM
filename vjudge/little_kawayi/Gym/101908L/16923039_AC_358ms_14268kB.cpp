#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m; 
vector<int> s[N];//树 
int w[N];//点权 
int son[N], dep[N], siz[N], par[N], top[N], dfn[N], stamp;//树链剖分 
int val[N << 2], tag[N << 2];//线段树
void dfs1(int now, int pre, int deep)
{
	siz[now] = 1;
	par[now] = pre;
	dep[now] = deep;
	int maxson = 0;
	for (int i : s[now])
		if (i != pre)
		{
			dfs1(i, now, deep + 1);
			siz[now] += siz[i];
			if (siz[i] > maxson)
			{
				maxson = siz[i];
				son[now] = i;
			}
		}
}
void dfs2(int now, int tp)
{
	dfn[now] = ++stamp;
	top[now] = tp;
	if (son[now])
		dfs2(son[now], tp);
	for (int i : s[now])
		if (i != par[now] && i != son[now])
			dfs2(i, i);
}
void pushup(int rt)
{
	val[rt] = val[rt << 1] + val[rt << 1 | 1];
}
void pushdown(int ln, int rn, int rt)
{
	if (tag[rt])
	{
		val[rt << 1] += tag[rt] * ln;
		val[rt << 1 | 1] += tag[rt] * rn;
		tag[rt << 1] += tag[rt];
		tag[rt << 1 | 1] += tag[rt];
		tag[rt] = 0;
	}
}
void update(int l, int r, int rt, const int& L, const int& R, const int& V)
{
	if (L <= l && r <= R)
	{
		val[rt] += (r - l + 1) * V;
		tag[rt] += V;
		return;
	}
	int m = l + r >> 1;
	pushdown(m - l + 1, r - m, rt);
	if (L <= m)
		update(l, m, rt << 1, L, R, V);
	if (m < R)
		update(m + 1, r, rt << 1 | 1, L, R, V);
	pushup(rt);
}
int query(int l, int r, int rt, const int& L, const int& R)
{
	if (L <= l && r <= R)
		return val[rt];
	int m = l + r >> 1;
	pushdown(m - l + 1, r - m, rt);
	int ans = 0;
	if (L <= m)
		ans += query(l, m, rt << 1, L, R);
	if (m < R)
		ans += query(m + 1, r, rt << 1 | 1, L, R);
	pushup(rt);
	return ans;
}
void update_path(int u, int v, int V)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		update(1, n, 1, dfn[top[u]], dfn[u], V);
		u = par[top[u]];
	}
	update(1, n, 1, dfn[min(u, v)], dfn[max(u, v)], V);
}
int query_path(int u, int v)
{
	int ans = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		ans += query(1, n, 1, dfn[top[u]], dfn[u]);
		u = par[top[u]];
	}
	ans += query(1, n, 1, dfn[min(u, v)], dfn[max(u, v)]);
	return ans;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		s[u].push_back(v);
		s[v].push_back(u);
	}
	dfs1(1, 1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		update_path(a, b, 1);
		cout << query_path(c, d) << endl;
		update_path(a, b, -1);
	}
	return 0;
}