#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f3f
typedef long long ll;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, a, b;
	cin >> n >> a >> b;
	pair<ll, ll>* m = new pair<ll, ll>[n];
	ll maxs = 0, maxn = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i].first >> m[i].second;
		if (m[i].first << a > maxs + m[i].second)
		{
			maxs = (m[i].first << a) - m[i].second;
			maxn = i;
		}
	}
	m[maxn].first <<= a;
	sort(m, m + n, [](pair<ll,ll> a, pair<ll,ll> b)->bool {return (a.first - a.second) > (b.first - b.second);});
	for (int i = 0; i < n; i++)
		if (i < b && m[i].first > m[i].second)
			ans += m[i].first;
		else
			ans += m[i].second;
	cout << ans << endl;		
	return 0;
}