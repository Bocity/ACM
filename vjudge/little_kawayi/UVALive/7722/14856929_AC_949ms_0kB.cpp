#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
const int N = 1e6 + 1;
vector<pii> s[N + 1];
int dp[N + 1];
main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		int n, tmp;
		cin >> tmp >> n;
		for (int i = 0; i <= N; i++)
			s[i].clear();
		for (int i = 0; i < n; i++)
		{
			int l, r, v;
			cin >> tmp >> l >> r >> v;
			l++, r++;
			s[r].push_back(pii(l, v));
		}
		dp[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			dp[i] = dp[i - 1];
			for (int j = 0; j < s[i].size(); j++)
				dp[i] = max(dp[i], dp[s[i][j].first] + s[i][j].second);
		}
		cout << "Case #" << cas << ": " << dp[N] << endl;
	}
	return 0;
}