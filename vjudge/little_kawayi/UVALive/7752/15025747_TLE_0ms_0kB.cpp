#include <bits/stdc++.h>
using namespace std;
int par[100001];
int aim[100001];
int getp(int x)
{
	return par[x] == 0 ? 0 : getp(par[x]) + 1;
}
int geta(int x)
{
	return aim[x] == 0 ? 0 : geta(aim[x]) + 1;
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
	
		for (int i = 1; i <= n; i++)
			cin >> par[i];
		for (int i = 1; i <= n; i++)
			cin >> aim[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (par[i] != aim[i])
			{
				ans += getp(i) + geta(i);
				par[i] = aim[i] = 0;
			}
		cout << ans << endl;
	}
	return 0;
}