#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int s[26][26];
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			cin >> s[i][j];
	int **dp = new int*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[26]();
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 26; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
			for (int k = 0; k < 26; k++)
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + s[k][j]);
		}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 26; i++)
		ans = min(ans, dp[n - 1][i]);
	cout << ans << endl;
	//system("pause");
	return 0;
}