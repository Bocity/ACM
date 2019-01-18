#include <bits/stdc++.h>
using namespace std;
#define int long long
char s[150001];
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		vector<int> q[2];
		bool now = 0;
		for (int i = 0; i < n; i++)
			q[now].push_back(i);
		int cs = 0;
		cout << "Case #" << cas << ": ";
		for (;q[now].size() > 1 && cs < 20 && cs < n; cs++)
		{
			now = !now;
			char maxn = 0;
			for (int i : q[!now])
				maxn = max(maxn, s[i]);
			for (int i : q[!now])
				if (s[i] == maxn)
					q[now].push_back( (i * i + 1) % n);
			q[!now].reserve(0);
			cout << maxn;
		}
		int nxt = q[now].front();
		for (;cs < n; cs++)
		{
			cout << s[nxt];
			nxt = (nxt * nxt + 1) % n;
		}
		cout << endl;
	}
	return 0;
}